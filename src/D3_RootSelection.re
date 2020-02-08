/*
 * d3-selection bindings, for use from the root (without an existing selection)
 * See D3_Selection.re for operations on existing selections
 *
 * https://github.com/d3/d3-selection#api-reference
 */
[@bs.module "d3-selection"]
external selection: unit => D3_Selection.t = "selection";

[@bs.module "d3-selection"]
external selectNode: Dom.node => D3_Selection.t = "select";

[@bs.module "d3-selection"]
external select: string => D3_Selection.t = "select";

[@bs.module "d3-selection"]
external selectAll: string => D3_Selection.t = "selectAll";