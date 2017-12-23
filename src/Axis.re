/*
 * d3-axis
 * https://github.com/d3/d3-axis#api-reference
 */
type t;

[@bs.module "d3-axis"] external makeTop : Scale.t => t = "axisTop";

[@bs.module "d3-axis"] external makeBottom : Scale.t => t = "axisBottom";

[@bs.module "d3-axis"] external makeLeft : Scale.t => t = "axisLeft";

[@bs.module "d3-axis"] external makeRight : Scale.t => t = "axisRight";
