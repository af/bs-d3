/* Interpolators for sequential color scales
 * See https://github.com/d3/d3-scale-chromatic#diverging
 */

type interpolator('a) = D3_Scale.interpolator('a);

[@bs.module "d3-scale-chromatic"] external interpolateBrBG : interpolator(string) = "interpolateBrBG";
[@bs.module "d3-scale-chromatic"] external interpolatePRGn : interpolator(string) = "interpolatePRGn";
[@bs.module "d3-scale-chromatic"] external interpolatePiYG : interpolator(string) = "interpolatePiYG";
[@bs.module "d3-scale-chromatic"] external interpolatePuOr : interpolator(string) = "interpolatePuOr";
[@bs.module "d3-scale-chromatic"] external interpolateRdBu : interpolator(string) = "interpolateRdBu";
[@bs.module "d3-scale-chromatic"] external interpolateRdGy : interpolator(string) = "interpolateRdGy";
[@bs.module "d3-scale-chromatic"] external interpolateRdYlBu : interpolator(string) = "interpolateRdYlBu";
[@bs.module "d3-scale-chromatic"] external interpolateRdYlGn : interpolator(string) = "interpolateRdYlGn";
[@bs.module "d3-scale-chromatic"] external interpolateSpectral : interpolator(string) = "interpolateSpectral";

[@bs.module "d3-scale-chromatic"] external interpolateBlues : interpolator(string) = "interpolateBlues";
[@bs.module "d3-scale-chromatic"] external interpolateGreens : interpolator(string) = "interpolateGreens";
[@bs.module "d3-scale-chromatic"] external interpolateGreys : interpolator(string) = "interpolateGreys";
[@bs.module "d3-scale-chromatic"] external interpolateOranges : interpolator(string) = "interpolateOranges";
[@bs.module "d3-scale-chromatic"] external interpolatePurples : interpolator(string) = "interpolatePurples";
[@bs.module "d3-scale-chromatic"] external interpolateReds : interpolator(string) = "interpolateReds";

[@bs.module "d3-scale-chromatic"] external interpolateViridis : interpolator(string) = "interpolateViridis";
[@bs.module "d3-scale-chromatic"] external interpolateInferno : interpolator(string) = "interpolateInferno";
[@bs.module "d3-scale-chromatic"] external interpolateMagma : interpolator(string) = "interpolateMagma";
[@bs.module "d3-scale-chromatic"] external interpolatePlasma : interpolator(string) = "interpolatePlasma";
[@bs.module "d3-scale-chromatic"] external interpolateWarm : interpolator(string) = "interpolateWarm";
[@bs.module "d3-scale-chromatic"] external interpolateCool : interpolator(string) = "interpolateCool";
[@bs.module "d3-scale-chromatic"] external interpolateCubehelixDefault : interpolator(string) = "interpolateCubehelixDefault";
[@bs.module "d3-scale-chromatic"] external interpolateBuGn : interpolator(string) = "interpolateBuGn";
[@bs.module "d3-scale-chromatic"] external interpolateBuPu : interpolator(string) = "interpolateBuPu";
[@bs.module "d3-scale-chromatic"] external interpolateGnBu : interpolator(string) = "interpolateGnBu";
[@bs.module "d3-scale-chromatic"] external interpolateOrRd : interpolator(string) = "interpolateOrRd";
[@bs.module "d3-scale-chromatic"] external interpolatePuBuGn : interpolator(string) = "interpolatePuBuGn";
[@bs.module "d3-scale-chromatic"] external interpolatePuBu : interpolator(string) = "interpolatePuBu";
[@bs.module "d3-scale-chromatic"] external interpolatePuRd : interpolator(string) = "interpolatePuRd";
[@bs.module "d3-scale-chromatic"] external interpolateRdPu : interpolator(string) = "interpolateRdPu";
[@bs.module "d3-scale-chromatic"] external interpolateYlGnBu : interpolator(string) = "interpolateYlGnBu";
[@bs.module "d3-scale-chromatic"] external interpolateYlGn : interpolator(string) = "interpolateYlGn";
[@bs.module "d3-scale-chromatic"] external interpolateYlOrBr : interpolator(string) = "interpolateYlOrBr";
[@bs.module "d3-scale-chromatic"] external interpolateYlOrRd : interpolator(string) = "interpolateYlOrRd";

[@bs.module "d3-scale-chromatic"] external interpolateSinebow : interpolator(string) = "interpolateSinebow";
[@bs.module "d3-scale-chromatic"] external interpolateRainbow : interpolator(string) = "interpolateRainbow";
