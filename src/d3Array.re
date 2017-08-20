/*
 * d3-array
 * https://github.com/d3/d3-array/blob/master/README.md
 */

type fs = array float;

/* Statistics */
/* Note: some of these only take floats for now, where only numeric types appear to make sense */
external min_ : array 'a => accessor::('b => 'a)? => unit => 'a = "min" [@@bs.module "d3-array"];
external max_ : array 'a => accessor::('b => 'a)? => unit => 'a = "max" [@@bs.module "d3-array"];
external extent : array 'a => accessor::('b => 'a)? => unit => ('a, 'a) = "" [@@bs.module "d3-array"];
external sum : fs => accessor::('a => float)? => unit => float = "" [@@bs.module "d3-array"];
external mean : fs => accessor::('a => float)? => unit => float = "" [@@bs.module "d3-array"];
external median : array 'a => accessor::('b => 'a)? => unit => 'a = "" [@@bs.module "d3-array"];
external quantile : fs => float => accessor::('a => float)? => unit => float = "" [@@bs.module "d3-array"];
external variance : fs => accessor::('a => float)? => unit => float = "" [@@bs.module "d3-array"];
external deviation : fs => accessor::('a => float)? => unit => float = "" [@@bs.module "d3-array"];

/* Search */
external scan : array 'a => comp::('a => 'a => 'b)? => unit => int = "" [@@bs.module "d3-array"];
external bisectLeft : array 'a => 'a => lo::int? => hi::int? => unit => int = "" [@@bs.module "d3-array"];
external bisect : array 'a => 'a => lo::int? => hi::int? => unit => int = "" [@@bs.module "d3-array"];
external bisectRight : array 'a => 'a => lo::int? => hi::int? => unit => int = "" [@@bs.module "d3-array"];
/* TODO: bisector, see https://github.com/d3/d3-array/blob/master/README.md#bisector */
external ascending : 'a => 'a => int = "" [@@bs.module "d3-array"]; /* TODO: this can also return NaN */
external descending : 'a => 'a => int = "" [@@bs.module "d3-array"]; /* TODO: this can also return NaN */
