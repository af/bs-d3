/*
 * d3-shape
 * https://github.com/d3/d3-shape#api-reference
 */

type lineT;

external line : unit => lineT = "selection" [@@bs.module "d3-shape"];
external lineX : ('a => int => array 'a => float) = "" [@@bs.send.pipe: lineT];
external lineY : ('a => int => array 'a => float) = "" [@@bs.send.pipe: lineT];
