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


module Make = (S: ScaleType) => {
  let scale = switch (S.scale) {
  | Linear => _makeLinear()
  | Log => _makeLog()
  | Pow => _makePow()
  | Sqrt => _makeSqrt()
  | Time => _makeTime()
  };

  /* TODO: there is almost certainly a better way to implement this */
  let call: ((t, S.domainT) => S.rangeT) = [%raw (scale, x) => "{return scale(x)}"];
  let invert: ((t, S.rangeT) => S.domainT) = [%raw (scale, x) => "{return scale.invert(x)}"];

  [@bs.send] external domain : t => array(S.domainT) => t = "";
  [@bs.send] external range : t => array(S.rangeT) => t = "";
  [@bs.send] external rangeRound : t => array(S.rangeT) => t = "";
  [@bs.send] external clamp : t => bool => t = "";
  [@bs.send] external ticks : t => int => array(S.domainT) = "";
};
