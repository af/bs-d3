/*
 * d3-array
 * https://github.com/d3/d3-array/blob/master/README.md
 */

/* TODO: extra (optional) accessor parameter for every d3-array function */
external min : array float => float = "" [@@bs.module "d3-array"];
external max : array float => float = "" [@@bs.module "d3-array"];
external extent : array float => (float, float) = "" [@@bs.module "d3-array"];
external sum : array float => float = "" [@@bs.module "d3-array"];
external mean : array float => float = "" [@@bs.module "d3-array"];
external median : array float => float = "" [@@bs.module "d3-array"];
external quantile : array float => float => float = "" [@@bs.module "d3-array"];
external variance : array float => float = "" [@@bs.module "d3-array"];
external deviation : array float => float = "" [@@bs.module "d3-array"];
