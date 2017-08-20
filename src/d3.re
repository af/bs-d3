/*
 * https://github.com/d3/d3/blob/master/API.md
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

/*let (minEx, maxEx) = (extent [|4., 5., -1., 4.|]);*/
/*Js.log2 minEx maxEx;*/
/*Js.log (min [|4., 5.|]);*/
/*Js.log (max [|4., 5.|]);*/
/*Js.log (extent [|4., 5., -1., 4.|]);*/
/*Js.log (sum [|4., 5., -1., 4.|]);*/
/*Js.log (mean [|4., 5., -1., 4.|]);*/
/*Js.log (median [|4., 5., -1., 4.|]);*/
/*Js.log (quantile [|4., 5., -1., 4.|] 0.25);*/
/*Js.log (variance [|4., 5., -1., 4.|]);*/
/*Js.log2 "deviation:" (deviation [|4., 5., -1., 4.|]);*/
