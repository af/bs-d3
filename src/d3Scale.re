/*
 * d3-scale
 * https://github.com/d3/d3-scale#api-reference
 */

/* TODO: This allows scales to be invoked (eg `x(0)`), but not all d3 scales map from float to float */
type scaleT = float => float;

external scaleLinear : unit => scaleT = "" [@@bs.module "d3-scale"];
external scaleLog : unit => scaleT = "" [@@bs.module "d3-scale"];
external scalePow : unit => scaleT = "" [@@bs.module "d3-scale"];
external scaleSqrt : unit => scaleT = "" [@@bs.module "d3-scale"];
external scaleTime : unit => scaleT = "" [@@bs.module "d3-scale"];

/* Bindings for methods on range objects */
/* TODO: implement missing methods */
external domain : array float => scaleT = "" [@@bs.send.pipe: scaleT];
external range : array 'a => scaleT = "" [@@bs.send.pipe: scaleT];
external rangeRound : array 'a => scaleT = "" [@@bs.send.pipe: scaleT];
external clamp : bool => scaleT = "" [@@bs.send.pipe: scaleT];

external ticks : int => array 'a = "" [@@bs.send.pipe: scaleT];
