/*
 * area-related functions from d3-shape
 * https://github.com/d3/d3-shape#areas
 */
type t;

type accessor('a) = ('a, int, array('a)) => float;

[@bs.module "d3-shape"] external make : unit => t = "area";

[@bs.send] external x : t => accessor('a) => t = "";
[@bs.send] external x0 : t => accessor('a) => t = "";
[@bs.send] external x1 : t => accessor('a) => t = "";
[@bs.send] external y : t => accessor('a) => t = "";
[@bs.send] external y0 : t => accessor('a) => t = "";
[@bs.send] external y1 : t => accessor('a) => t = "";

[@bs.send] external defined : t => (('a, int, array('a)) => bool) => t = "";
[@bs.send] external curve : t => D3_Curve.t => t = "";
[@bs.send] external context : t => 'a => t = "";
[@bs.send] external getContext : t => unit => 'a = "context";
[@bs.send] external lineX0 : t => unit => 'a = "";
[@bs.send] external lineX1 : t => unit => 'a = "";
[@bs.send] external lineY0 : t => unit => 'a = "";
[@bs.send] external lineY1 : t => unit => 'a = "";
