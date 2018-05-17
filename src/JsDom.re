/* Quick'n dirty bindings to JsDom, for tests only */

[@bs.module "jsdom"] [@bs.new] external make : string => 'a = "JSDOM";
[@bs.module "d3-selection"] external selectAny : 'a => D3.Selection.t = "select";

let attachD3 = dom => selectAny(dom##window##document##body);
