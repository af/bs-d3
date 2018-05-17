/*
 * area-related functions from d3-shape
 * https://github.com/d3/d3-shape#areas
 */
type t;

type accessor('a) = ('a, int, array('a)) => float;

[@bs.module "d3-shape"] external make : unit => t = "area";

[@bs.send.pipe : t] external x : accessor('a) => t = "";
[@bs.send.pipe : t] external x0 : accessor('a) => t = "";
[@bs.send.pipe : t] external x1 : accessor('a) => t = "";
[@bs.send.pipe : t] external y : accessor('a) => t = "";
[@bs.send.pipe : t] external y0 : accessor('a) => t = "";
[@bs.send.pipe : t] external y1 : accessor('a) => t = "";

[@bs.send.pipe : t] external defined : (('a, int, array('a)) => bool) => t = "";
[@bs.send.pipe : t] external curve : D3_Curve.t => t = "";
[@bs.send.pipe : t] external context : 'a => t = "";
[@bs.send.pipe : t] external getContext : unit => 'a = "context";
[@bs.send.pipe : t] external lineX0 : unit => 'a = "";
[@bs.send.pipe : t] external lineX1 : unit => 'a = "";
[@bs.send.pipe : t] external lineY0 : unit => 'a = "";
[@bs.send.pipe : t] external lineY1 : unit => 'a = "";
