/*
 * line-related functions from d3-shape
 * https://github.com/d3/d3-shape#lines
 */
type t;

[@bs.module "d3-shape"] external make : unit => t = "line";

[@bs.send] external x : t => (('a, int, array('a)) => float) => t = "x";
[@bs.send] external y : t => (('a, int, array('a)) => float) => t = "y";
[@bs.send] external defined : t => (('a, int, array('a)) => bool) => t = "defined";
[@bs.send] external curve : t => D3_Curve.t => t = "curve";
[@bs.send] external context : t => 'a => t = "context";
[@bs.send] external getContext : t => unit => 'a = "context";
