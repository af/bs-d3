/*
 * d3-selection
 * https://github.com/d3/d3-selection#api-reference
 */

type t;

external selectRoot : unit => t = "selection" [@@bs.module "d3-selection"];
external select : string => t = "" [@@bs.module "d3-selection"];
external selectNode : Dom.node => t = "" [@@bs.module "d3-selection"];
external selectAll : string => t = "" [@@bs.module "d3-selection"];
external window : Dom.node => Dom.node = "" [@@bs.module "d3-selection"];

external subSelect : string => t = "select" [@@bs.send.pipe: t];
external subSelectAll : string => t = "selectAll" [@@bs.send.pipe: t];
external filter : string => t = "" [@@bs.send.pipe: t];  /* TODO: filter by fn */
external append : string => t = "" [@@bs.send.pipe: t];
external insert : string => t = "" [@@bs.send.pipe: t];
external remove : t = "" [@@bs.send.pipe: t];
external attr : string => 'a => t = "" [@@bs.send.pipe: t];
external classed : string => bool => t = "" [@@bs.send.pipe: t];
external classedFn : string => ('a => int => bool) => t = "classed" [@@bs.send.pipe: t];
external style : string => string => t = "" [@@bs.send.pipe: t];
external styleFn : string => ('a => int => string) => t = "style" [@@bs.send.pipe: t];
external text : string => t = "" [@@bs.send.pipe: t];
external textFn : ('a => int => string) => t = "text" [@@bs.send.pipe: t];

external data : array 'a => t = "" [@@bs.send.pipe: t];
external enter : t = "" [@@bs.send.pipe: t];
external exit : t = "" [@@bs.send.pipe: t];

external callAxis : Axis.t => t = "call" [@@bs.send.pipe: t];
