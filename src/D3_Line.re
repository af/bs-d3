/*
 * line-related functions from d3-shape
 * https://github.com/d3/d3-shape#lines
 */
type t;

[@bs.module "d3-shape"] external make : unit => t = "line";

[@bs.send] external x : t => (('a, int, array('a)) => float) => t = "";
[@bs.send] external y : t => (('a, int, array('a)) => float) => t = "";
[@bs.send] external defined : t => (('a, int, array('a)) => bool) => t = "";
[@bs.send] external curve : t => D3_Curve.t => t = "";
[@bs.send] external context : t => 'a => t = "";
[@bs.send] external getContext : t => unit => 'a = "context";
