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
[@bs.module "d3-scale"] external _makeLinear : unit => t = "scaleLinear";
[@bs.module "d3-scale"] external _makeLog : unit => t = "scaleLog";
[@bs.module "d3-scale"] external _makePow : unit => t = "scalePow";
[@bs.module "d3-scale"] external _makeSqrt : unit => t = "scaleSqrt";
[@bs.module "d3-scale"] external _makeTime : unit => t = "scaleTime";


module MakeContinuous = (S: ScaleType) => {
  /* Store D3's mutable scale object in the module as `instance` */
  let instance = switch (S.scale) {
  | Linear => _makeLinear()
  | Log => _makeLog()
  | Pow => _makePow()
  | Sqrt => _makeSqrt()
  | Time => _makeTime()
  };

  let call = (value: S.domainT): S.rangeT => {
    /* TODO: there is almost certainly a better way to invoke the scale here */
    let inner: (t, S.domainT) => S.rangeT = [%raw (scale, x) => "{return scale(x)}"];
    inner(instance, value);
  };
  [@bs.send] external invert : t => S.rangeT => S.domainT = "";

  [@bs.send] external domain : t => array(S.domainT) => t = "";
  [@bs.send] external range : t => array(S.rangeT) => t = "";
  [@bs.send] external rangeRound : t => array(S.rangeT) => t = "";
  [@bs.send] external clamp : t => bool => t = "";
  [@bs.send] external ticks : t => int => array(S.domainT) = "";
};


/* alias for the most common type of scale */
module MakeLinearFloat = () => {
  include MakeContinuous({
    type domainT = float;
    type rangeT = float;
    let scale = Linear;
  });
};

type interpolator = float => string;

/* Interpolators for sequential color scales
 * See https://github.com/d3/d3-scale-chromatic#diverging
 */
[@bs.module "d3-scale-chromatic"] external interpolateBrBG : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePRGn : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePiYG : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuOr : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdBu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdGy : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdYlBu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdYlGn : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateSpectral : interpolator = "";

[@bs.module "d3-scale-chromatic"] external interpolateBlues : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateGreens : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateGreys : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateOranges : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePurples : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateReds : interpolator = "";

[@bs.module "d3-scale-chromatic"] external interpolateViridis : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateInferno : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateMagma : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePlasma : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateWarm : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateCool : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateCubehelixDefault : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateBuGn : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateBuPu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateGnBu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateOrRd : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuBuGn : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuBu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuRd : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdPu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlGnBu : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlGn : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlOrBr : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlOrRd : interpolator = "";

[@bs.module "d3-scale-chromatic"] external interpolateSinebow : interpolator = "";
[@bs.module "d3-scale-chromatic"] external interpolateRainbow : interpolator = "";

/* Rough WIP for sequential scales */
/* TODO: would be nice to paramaterize D3.Scale.t instead of having a completely separate type here */
type sequential;
[@bs.module "d3-scale"] external makeSequential : interpolator => sequential = "scaleSequential";

/* FIXME: these are pretty ugly */
[@bs.send] external sequentialDomain : sequential => array('a) => sequential = "domain";
let sequentialCall: (sequential => float => float) = [%raw (scale, x) => "{return scale(x)}"];
