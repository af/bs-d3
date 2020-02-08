/*
 * arc-related functions from d3-shape
 * https://github.com/d3/d3-shape#arcs
 */
type t;

[@bs.module "d3-shape"] external make : unit => t = "arc";

[@bs.send] external innerRadius : t => float => t = "innerRadius";
[@bs.send] external outerRadius : t => float => t = "outerRadius";
[@bs.send] external cornerRadius : t => float => t = "cornerRadius";
[@bs.send] external startAngle : t => float => t = "startAngle";
[@bs.send] external endAngle : t => float => t = "endAngle";
[@bs.send] external padAngle : t => float => t = "padAngle";
[@bs.send] external centroid : t => 'a => (float, float) = "centroid";
