/*
 * d3-array
 * https://github.com/d3/d3-array/blob/master/README.md
 */

type arr = array float;

/* type for the extra (optional) accessor parameter for every d3-array function */
type accessorT = float => float;

external min_ : arr => accessor::accessorT? => unit => float = "min" [@@bs.module "d3-array"];
external max_ : arr => accessor::accessorT? => unit => float = "max" [@@bs.module "d3-array"];
external extent : arr => accessor::accessorT? => unit => (float, float) = "" [@@bs.module "d3-array"];
external sum : arr => accessor::accessorT? => unit => float = "" [@@bs.module "d3-array"];
external mean : arr => accessor::accessorT? => unit => float = "" [@@bs.module "d3-array"];
external median : arr => accessor::accessorT? => unit => float = "" [@@bs.module "d3-array"];
external quantile : arr => float => accessor::accessorT? => unit => float = "" [@@bs.module "d3-array"];
external variance : arr => accessor::accessorT? => unit => float = "" [@@bs.module "d3-array"];
external deviation : arr => accessor::accessorT? => unit => float = "" [@@bs.module "d3-array"];
