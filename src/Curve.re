/*
 * curve-related functions from d3-shape
 * https://github.com/d3/d3-shape#curves
 */
type t;

[@bs.module "d3-shape"] external basis : t = "curveBasis";
[@bs.module "d3-shape"] external basisClosed : t = "curveBasisClosed";
[@bs.module "d3-shape"] external basisOpen : t = "curveBasisOpen";
[@bs.module "d3-shape"] external bundle : t = "curveBundle";
[@bs.module "d3-shape"] external cardinal : t = "curveCardinal";
[@bs.module "d3-shape"] external cardinalClosed : t = "curveCardinalClosed";
[@bs.module "d3-shape"] external cardinalOpen : t = "curveCardinalOpen";
[@bs.module "d3-shape"] external catmullRom : t = "curveCatmullRom";
[@bs.module "d3-shape"] external catmullRomClosed : t = "curveCatmullRomClosed";
[@bs.module "d3-shape"] external catmullRomOpen : t = "curveCatmullRomOpen";
[@bs.module "d3-shape"] external linear : t = "curveLinear";
[@bs.module "d3-shape"] external linearClosed : t = "curveLinearClosed";
[@bs.module "d3-shape"] external monotoneX : t = "curveMonotoneX";
[@bs.module "d3-shape"] external monotoneY : t = "curveMonotoneY";
[@bs.module "d3-shape"] external natural : t = "curveNatural";
[@bs.module "d3-shape"] external step : t = "curveStep";
[@bs.module "d3-shape"] external stepAfter : t = "curveStepAfter";
[@bs.module "d3-shape"] external stepBefore : t = "curveStepBefore";
/* TODO: custom curve API */
