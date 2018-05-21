[@bs.module "d3-selection"] external selection : unit => D3_Selection.t = "";
[@bs.module "d3-selection"] external selectNode : Dom.node => D3_Selection.t = "select";
[@bs.module "d3-selection"] external select : string => D3_Selection.t = "";
[@bs.module "d3-selection"] external selectAll : string => D3_Selection.t = "";
