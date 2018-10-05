/* Interpolators for sequential color scales
 * See https://github.com/d3/d3-scale-chromatic#diverging
 */

type interpolator('a) = D3_Scale.interpolator('a);

[@bs.module "d3-scale-chromatic"] external interpolateBrBG : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePRGn : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePiYG : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuOr : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdBu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdGy : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdYlBu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdYlGn : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateSpectral : interpolator(string) = "";

[@bs.module "d3-scale-chromatic"] external interpolateBlues : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateGreens : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateGreys : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateOranges : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePurples : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateReds : interpolator(string) = "";

[@bs.module "d3-scale-chromatic"] external interpolateViridis : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateInferno : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateMagma : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePlasma : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateWarm : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateCool : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateCubehelixDefault : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateBuGn : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateBuPu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateGnBu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateOrRd : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuBuGn : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuBu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolatePuRd : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateRdPu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlGnBu : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlGn : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlOrBr : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateYlOrRd : interpolator(string) = "";

[@bs.module "d3-scale-chromatic"] external interpolateSinebow : interpolator(string) = "";
[@bs.module "d3-scale-chromatic"] external interpolateRainbow : interpolator(string) = "";
