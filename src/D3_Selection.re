type t;

[@bs.send.pipe : t] external select : string => t = "";
[@bs.send.pipe : t] external selectAll : string => t = "";
[@bs.send.pipe : t] external append : string => t = "";
[@bs.send.pipe : t] external insert : string => t = "";
[@bs.send.pipe : t] external remove : t = "";
[@bs.send.pipe : t] external attr : (string, 'a) => t = "";
[@bs.send.pipe : t] external classed : (string, bool) => t = "";
[@bs.send.pipe : t] external classedFn : (string, ('a, int) => bool) => t = "classed";

[@bs.send.pipe : t] external style : (string, string) => t = "";
[@bs.send.pipe : t] external styleFn : (string, ('a, int) => string) => t = "style";
[@bs.send.pipe : t] external textFn : (('a, int) => string) => t = "text";
[@bs.send.pipe : t] external filter : string => t = ""; /* TODO: filter by fn */
[@bs.send.pipe : t] external sort : (('a, 'a) => float) => t = "";
[@bs.send.pipe : t] external order : unit => t = "";
[@bs.send.pipe : t] external raise : unit => t = "";
[@bs.send.pipe : t] external lower : unit => t = "";
[@bs.send.pipe : t] external merge : t => t = "";
[@bs.send.pipe : t] external data : array('a) => t = "";
[@bs.send.pipe : t] external datum : array('a) => t = "";

[@bs.send.pipe : t] external enter : t = "";
[@bs.send.pipe : t] external exit : t = "";
[@bs.send.pipe : t] external text : string = "";

[@bs.send.pipe : t] external callAxis : D3_Axis.t => t = "call";
