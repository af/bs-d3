/*
 * line-related functions from d3-shape
 * https://github.com/d3/d3-shape#lines
 */

type t;
type curve;

external make : unit => t = "line" [@@bs.module "d3-shape"];
external x : ('a => int => array 'a => float) => t = "" [@@bs.send.pipe: t];
external y : ('a => int => array 'a => float) => t = "" [@@bs.send.pipe: t];
external defined : ('a => int => array 'a => bool) => t = "" [@@bs.send.pipe: t];
external curve : curve => t = "" [@@bs.send.pipe: t];
external context : 'a => t = "" [@@bs.send.pipe: t];
external getContext : unit => 'a = "context" [@@bs.send.pipe: t];

/* curves (may want to move these to a separate module?) */
external curveBasis : curve = "" [@@bs.module "d3-shape"];
external curveBasisClosed : curve = "" [@@bs.module "d3-shape"];
external curveBasisOpen : curve = "" [@@bs.module "d3-shape"];
external curveBundle : curve = "" [@@bs.module "d3-shape"];
external curveCardinal : curve = "" [@@bs.module "d3-shape"];
external curveCardinalClosed : curve = "" [@@bs.module "d3-shape"];
external curveCardinalOpen : curve = "" [@@bs.module "d3-shape"];
external curveCatmullRom : curve = "" [@@bs.module "d3-shape"];
external curveCatmullRomClosed : curve = "" [@@bs.module "d3-shape"];
external curveCatmullRomOpen : curve = "" [@@bs.module "d3-shape"];
external curveLinear : curve = "" [@@bs.module "d3-shape"];
external curveLinearClosed : curve = "" [@@bs.module "d3-shape"];
external curveMonotoneX : curve = "" [@@bs.module "d3-shape"];
external curveMonotoneY : curve = "" [@@bs.module "d3-shape"];
external curveNatural : curve = "" [@@bs.module "d3-shape"];
external curveStep : curve = "" [@@bs.module "d3-shape"];
external curveStepAfter : curve = "" [@@bs.module "d3-shape"];
external curveStepBefore : curve = "" [@@bs.module "d3-shape"];

/* TODO: custom curve API */
