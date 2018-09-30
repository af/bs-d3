/*
 * arc-related functions from d3-shape
 * https://github.com/d3/d3-shape#arcs
 */
type t;

[@bs.module "d3-shape"] external make : unit => t = "arc";

[@bs.send] external innerRadius : t => float => t = "";
[@bs.send] external outerRadius : t => float => t = "";
[@bs.send] external cornerRadius : t => float => t = "";
[@bs.send] external startAngle : t => float => t = "";
[@bs.send] external endAngle : t => float => t = "";
[@bs.send] external padAngle : t => float => t = "";
