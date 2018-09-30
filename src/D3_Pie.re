/*
 * pie-related functions from d3-shape
 * https://github.com/d3/d3-shape#pies
 */
type wrapped('a) = Js.t({
  .
  data: 'a,
  value: float,
  index: int,
  startAngle: float,
  endAngle: float,
  padAngle: float,
});

type inner('a) = array('a) => array(wrapped('a));

[@bs.module "d3-shape"] external make : unit => inner('a) = "pie";

[@bs.send] external value : inner('a) => ('a => float) => inner('a) = "";
[@bs.send] external sort : inner('a) => option('a => 'a => int) => inner('a) = "";

/* TODO: make this work (bucklescript seems to have trouble allowing a higher-order fn) */
/*[@bs.module "d3-shape"] external make : unit => array('a) => array(wrapped(')a)) = "pie";*/

