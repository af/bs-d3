/*
 * d3-selection
 * https://github.com/d3/d3-selection#api-reference
 */
type t;
type group;     /* TODO: this isn't usable yet, grep for "current group" in the d3 docs above */

[@bs.send] external select : t => string => t = "select";
[@bs.send] external selectAll : t => string => t = "selectAll";
[@bs.send] external append : t => string => t = "append";
[@bs.send] external insert : t => string => t = "insert";
[@bs.send] external remove : t => t = "remove";
[@bs.send] external attr : t => (string, 'a) => t = "attr";
[@bs.send] external attrFn : t => string => (('a, int, group) => 'c) => t = "attr";
[@bs.send] external classed : t => (string, bool) => t = "classed";
[@bs.send] external classedFn : t => (string, ('a, int, group) => bool) => t = "classed";

[@bs.send] external style : t => (string, string) => t = "style";
[@bs.send] external styleFn : t => (string, ('a, int, group) => string) => t = "style";
[@bs.send] external textFn : t => (('a, int, group) => string) => t = "text";
[@bs.send] external filter : t => string => t = "filter";
[@bs.send] external filterFn : (t, [@bs.this] ('a => bool)) => t = "filter";
[@bs.send] external filterFnWithIndex : (t, [@bs.this] (('a, 'b, int) => bool)) => t = "filter";
[@bs.send] external sort : t => (('a, 'a) => float) => t = "sort";
[@bs.send] external order : t => unit => t = "order";
[@bs.send] external raise : t => unit => t = "raise";
[@bs.send] external lower : t => unit => t = "lower";
[@bs.send] external merge : t => t => t = "merge";
[@bs.send] external data : t => array('a) => t = "data";
[@bs.send] external datum : t => array('a) => t = "datum";
[@bs.send] external empty : t => unit => bool = "empty";
[@bs.send] external size : t => int = "size";

[@bs.send] external enter : t => t = "enter";
[@bs.send] external exit : t => t = "exit";
[@bs.send] external text : t => string = "text";

[@bs.send] external callAxis : t => D3_Axis.t => t = "call";
