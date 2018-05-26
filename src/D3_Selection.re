/*
 * d3-selection
 * https://github.com/d3/d3-selection#api-reference
 */
type t;
type group;     /* TODO: this isn't usable yet, grep for "current group" in the d3 docs above */

[@bs.send] external select : t => string => t = "";
[@bs.send] external selectAll : t => string => t = "";
[@bs.send] external append : t => string => t = "";
[@bs.send] external insert : t => string => t = "";
[@bs.send] external remove : t => t = "";
[@bs.send] external attr : t => (string, 'a) => t = "";
[@bs.send] external attrFn : t => string => (('a, int, group) => 'c) => t = "attr";
[@bs.send] external classed : t => (string, bool) => t = "";
[@bs.send] external classedFn : t => (string, ('a, int, group) => bool) => t = "classed";

[@bs.send] external style : t => (string, string) => t = "";
[@bs.send] external styleFn : t => (string, ('a, int, group) => string) => t = "style";
[@bs.send] external textFn : t => (('a, int, group) => string) => t = "text";
[@bs.send] external filter : t => string => t = "";
[@bs.send] external filterFn : (t, [@bs.this] ('a => bool)) => t = "filter";
[@bs.send] external filterFnWithIndex : (t, [@bs.this] (('a, 'b, int) => bool)) => t = "filter";
[@bs.send] external sort : t => (('a, 'a) => float) => t = "";
[@bs.send] external order : t => unit => t = "";
[@bs.send] external raise : t => unit => t = "";
[@bs.send] external lower : t => unit => t = "";
[@bs.send] external merge : t => t => t = "";
[@bs.send] external data : t => array('a) => t = "";
[@bs.send] external datum : t => array('a) => t = "";
[@bs.send] external empty : t => unit => bool = "";
[@bs.send] external size : t => int = "";

[@bs.send] external enter : t => t = "";
[@bs.send] external exit : t => t = "";
[@bs.send] external text : t => string = "";

[@bs.send] external callAxis : t => D3_Axis.t => t = "call";
