/*
 * d3-scale
 * https://github.com/d3/d3-scale#api-reference
 */
type t;

type scaleT =
  | Linear
  | Log
  | Pow
  | Sqrt
  | Time;

module type ScaleType = {
  type domainT;
  type rangeT;

  let scale: scaleT;
};

/* TODO: Make these inaccessible (.rei file?) */
[@bs.module "d3-scale"] external _makeLinear: unit => t = "scaleLinear";
[@bs.module "d3-scale"] external _makeLog: unit => t = "scaleLog";
[@bs.module "d3-scale"] external _makePow: unit => t = "scalePow";
[@bs.module "d3-scale"] external _makeSqrt: unit => t = "scaleSqrt";
[@bs.module "d3-scale"] external _makeTime: unit => t = "scaleTime";

module MakeContinuous = (S: ScaleType) => {
  /* Store D3's mutable scale object in the module as `instance` */
  let instance =
    switch (S.scale) {
    | Linear => _makeLinear()
    | Log => _makeLog()
    | Pow => _makePow()
    | Sqrt => _makeSqrt()
    | Time => _makeTime()
    };

  let call = (value: S.domainT): S.rangeT => {
    /* TODO: there is almost certainly a better way to invoke the scale here */
    let inner: (t, S.domainT) => S.rangeT = [%raw
      (scale, x) => "{return scale(x)}"
    ];
    inner(instance, value);
  };
  [@bs.send] external invert: (t, S.rangeT) => S.domainT = "invert";

  [@bs.send] external domain: (t, array(S.domainT)) => t = "domain";
  [@bs.send] external range: (t, array(S.rangeT)) => t = "range";
  [@bs.send] external rangeRound: (t, array(S.rangeT)) => t = "rangeRound";
  [@bs.send] external clamp: (t, bool) => t = "clamp";
  [@bs.send] external ticks: (t, int) => array(S.domainT) = "ticks";
};

/* alias for the most common type of scale */
module MakeLinearFloat = (()) => {
  include MakeContinuous({
    type domainT = float;
    type rangeT = float;
    let scale = Linear;
  });
};

/* Rough WIP for sequential scales */
/* TODO: would be nice to paramaterize D3.Scale.t instead of having a completely separate type here */
type sequential;
type interpolator('a) = float => 'a;

[@bs.module "d3-scale"]
external makeSequential: interpolator('a) => sequential = "scaleSequential";

/* FIXME: these are pretty ugly */
[@bs.send]
external sequentialDomain: (sequential, array('a)) => sequential = "domain";
let sequentialCall: (sequential, float) => float = [%raw
  (scale, x) => "{return scale(x)}"
];