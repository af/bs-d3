/*
 * d3-axis
 * https://github.com/d3/d3-axis#api-reference
 */
type t;

[@bs.module "d3-axis"] external makeTop : D3_Scale.t => t = "axisTop";
[@bs.module "d3-axis"] external makeBottom : D3_Scale.t => t = "axisBottom";
[@bs.module "d3-axis"] external makeLeft : D3_Scale.t => t = "axisLeft";
[@bs.module "d3-axis"] external makeRight : D3_Scale.t => t = "axisRight";
