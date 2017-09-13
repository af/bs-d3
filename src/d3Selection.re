/*
 * d3-selection
 * https://github.com/d3/d3-selection#api-reference
 */

type selectionT;

external selectRoot : unit => selectionT = "selection" [@@bs.module "d3-selection"];
external select : string => selectionT = "" [@@bs.module "d3-selection"];
external selectNode : Dom.node => selectionT = "" [@@bs.module "d3-selection"];
external selectAll : string => selectionT = "" [@@bs.module "d3-selection"];

external subSelect : string => selectionT = "" [@@bs.send.pipe: selectionT];
external subSelectAll : string => selectionT = "" [@@bs.send.pipe: selectionT];
external append : string => selectionT = "" [@@bs.send.pipe: selectionT];
external attr : string => 'a => selectionT = "" [@@bs.send.pipe: selectionT];
external data : array 'a => selectionT = "" [@@bs.send.pipe: selectionT];

external callAxis : D3Axis.axisT => selectionT = "call" [@@bs.send.pipe: selectionT];
