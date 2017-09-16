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
external makeLinear : unit => t = "scaleLinear" [@@bs.module "d3-scale"];
external makeLog : unit => t = "scaleLog" [@@bs.module "d3-scale"];
external makePow : unit => t = "scalePow" [@@bs.module "d3-scale"];
external makeSqrt : unit => t = "scaleSqrt" [@@bs.module "d3-scale"];
external makeTime : unit => t = "scaleTime" [@@bs.module "d3-scale"];

/* Bindings for methods on range objects */
/* TODO: implement missing methods */
external domain : array float => t = "" [@@bs.send.pipe: t];
external range : array 'a => t = "" [@@bs.send.pipe: t];
external rangeRound : array 'a => t = "" [@@bs.send.pipe: t];
external clamp : bool => t = "" [@@bs.send.pipe: t];

external ticks : int => array 'a = "" [@@bs.send.pipe: t];
