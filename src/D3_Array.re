/*
 * d3-array
 * https://github.com/d3/d3-array/blob/master/README.md
 */

/* Statistics */
/* Note: some of these only take floats for now, where only numeric types appear to make sense */
[@bs.module "d3-array"] external min_ : (array('a), ~accessor: 'a => 'b=?, unit) => 'b = "min";
[@bs.module "d3-array"] external max_ : (array('a), ~accessor: 'a => 'b=?, unit) => 'b = "max";
[@bs.module "d3-array"] external extent : (array('a), ~accessor: 'a => 'b=?, unit) => array('b) = "extent";
[@bs.module "d3-array"]
external extentTuple : (array('a), ~accessor: 'a => 'b=?, unit) => ('b, 'b) =
  "extent";
[@bs.module "d3-array"] external sum : (array('a), ~accessor: 'a => float=?, unit) => float = "sum";
[@bs.module "d3-array"] external mean : (array('a), ~accessor: 'a => float=?, unit) => float = "mean";
[@bs.module "d3-array"] external median : (array('a), ~accessor: 'a => 'b=?, unit) => 'a = "median";
[@bs.module "d3-array"] external quantile : (array('a), float, ~accessor: 'a => float=?, unit) => float =
  "quantile";
[@bs.module "d3-array"] external variance : (array('a), ~accessor: 'a => float=?, unit) => float = "variance";
[@bs.module "d3-array"] external deviation : (array('a), ~accessor: 'a => float=?, unit) => float = "deviation";


/* Search */
[@bs.module "d3-array"] external scan : (array('a), ~comp: ('a, 'a) => 'b=?, unit) => int = "scan";
[@bs.module "d3-array"]
external bisectLeft : (array('a), 'a, ~lo: int=?, ~hi: int=?, unit) => int = "bisectLeft";
[@bs.module "d3-array"] external bisect : (array('a), 'a, ~lo: int=?, ~hi: int=?, unit) => int = "bisect";
[@bs.module "d3-array"]
external bisectRight : (array('a), 'a, ~lo: int=?, ~hi: int=?, unit) => int = "bisectRight";

/* TODO: bisector, see https://github.com/d3/d3-array/blob/master/README.md#bisector */
[@bs.module "d3-array"] external ascending : ('a, 'a) => int = "ascending"; /* TODO: this can also return NaN */
[@bs.module "d3-array"] external descending : ('a, 'a) => int = "descending"; /* TODO: this can also return NaN */
