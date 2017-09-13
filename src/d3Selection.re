/*
 * d3-selection
 * https://github.com/d3/d3-selection#api-reference
 */

type t;

external selectRoot : unit => t = "selection" [@@bs.module "d3-selection"];
external select : string => t = "" [@@bs.module "d3-selection"];
external selectNode : Dom.node => t = "" [@@bs.module "d3-selection"];
external selectAll : string => t = "" [@@bs.module "d3-selection"];

external subSelect : string = "" [@@bs.send.pipe: t];
external subSelectAll : string = "" [@@bs.send.pipe: t];
external append : string = "" [@@bs.send.pipe: t];
external attr : string => 'a = "" [@@bs.send.pipe: t];
external data : array 'a = "" [@@bs.send.pipe: t];

external callAxis : D3Axis.t = "" [@@bs.send.pipe: t];
