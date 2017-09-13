/*
 * d3-scale
 * https://github.com/d3/d3-scale#api-reference
 */

type t;

external scaleLinear : unit => t = "" [@@bs.module "d3-scale"];
external scaleLog : unit => t = "" [@@bs.module "d3-scale"];
external scalePow : unit => t = "" [@@bs.module "d3-scale"];
external scaleSqrt : unit => t = "" [@@bs.module "d3-scale"];
external scaleTime : unit => t = "" [@@bs.module "d3-scale"];

/* TODO: how to handle invocation of range functions?
 * eg. `var r = scaleLinear().domain([0,10]).range([0, 100]);
 *      r(80);`
 */

/* Bindings for methods on range objects */
/* TODO: implement missing methods */
external domain : array float = "" [@@bs.send.pipe: t];
external range : array 'a = "" [@@bs.send.pipe: t];
external rangeRound : array 'a = "" [@@bs.send.pipe: t];
external clamp : bool = "" [@@bs.send.pipe: t];

external ticks : int => array 'a = "" [@@bs.send.pipe: t];
