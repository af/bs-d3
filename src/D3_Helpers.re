module S = D3_Selection;

type margin = {
  t: float,
  b: float,
  l: float,
  r: float,
}

type dimensions = {
  width: float,
  height: float,
  margin,
};


/* When formatting floats for html/svg attributes, ensure whole numbers have
 * a trailing "0". eg "5.0" instead of the "5." we get from Js.Float.toString() */
let fmtFloat = x => {
  let str = Js.Float.toString(x);
  let lastChar = String.get(str, String.length(str) - 1);
  (lastChar == '.') ? (str ++ "0") : str;
};


let makeContainer = (rootSelector, chartDims) => {
  let {margin} = chartDims;

  D3_RootSelection.select(rootSelector)
  |. S.append("svg")
  |. S.attr("width", chartDims.width +. margin.l +. margin.r)
  |. S.attr("height", chartDims.height +. margin.t +. margin.b)
  |. S.append("g")
  |. S.attr(
       "transform",
       "translate(" ++ fmtFloat(margin.l) ++ "," ++ fmtFloat(margin.t) ++ ")"
     );
};

