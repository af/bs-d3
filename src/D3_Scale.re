/*
 * d3-scale
 * https://github.com/d3/d3-scale#api-reference
 */
/* TODO: This allows scales to be invoked (eg `x(0)`), but not all d3 scales map from float to float */
type t = float => float;

/*
 type v =
   | Linear
   | Log
   | Pow
   | Sqrt
   | Time;
 */
/* TODO: consider using a single make() and passing the scale type in (using v, above?): */
[@bs.module "d3-scale"] external makeLinear : unit => t = "scaleLinear";
[@bs.module "d3-scale"] external makeLog : unit => t = "scaleLog";
[@bs.module "d3-scale"] external makePow : unit => t = "scalePow";
[@bs.module "d3-scale"] external makeSqrt : unit => t = "scaleSqrt";
[@bs.module "d3-scale"] external makeTime : unit => t = "scaleTime";

/* Bindings for methods on range objects */
/* TODO: implement missing methods */
[@bs.send] external domain : t => array(float) => t = "";
[@bs.send] external range : t => array('a) => t = "";
[@bs.send] external rangeRound : t => array('a) => t = "";
[@bs.send] external clamp : t => bool => t = "";
[@bs.send] external ticks : t => int => array('a) = "";

