/*
 * line-related functions from d3-shape
 * https://github.com/d3/d3-shape#api-reference
 */

type t;

external make : unit => t = "line" [@@bs.module "d3-shape"];
external x : ('a => int => array 'a => float) => t = "" [@@bs.send.pipe: t];
external y : ('a => int => array 'a => float) => t = "" [@@bs.send.pipe: t];
