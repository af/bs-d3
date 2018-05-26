/* ported (and simplified) Reason version of a basic d3 line chart
 * via https://bl.ocks.org/d3noob/402dd382a51a4f6eea487f9a35566de0 */
module S = D3.Selection;

let sampleData = [|1, 5, 6, 9, 10, 1, 3, 7, 6, 4, 5|];
let margin = 20.;
let width = 900.;
let height = 500.;
let curve = D3.Curve.catmullRom;

/* Little util to format floats for svg/html attributes (without the trailing ".") */
let fmtFloat = x => x |. int_of_float |. string_of_int;

/* TODO: create an alias in the bindings for this common case */
module LinearFloat = {
  type domainT = float;
  type rangeT = float;
  let scale = D3.Scale.Linear;
};
module X = D3.Scale.Make(LinearFloat);
module Y = D3.Scale.Make(LinearFloat);

let xScale = X.(
  scale
  |. domain([|0., float_of_int(Array.length(sampleData) - 1)|])
  |. range([|0., width|])
);

let yScale = Y.(
  scale
  |. domain([|0., float_of_int(D3.Array.max_(sampleData, ()))|])
  |. range([|height, 0.|])
);

let valueLine =
  D3.Line.make()
  |. D3.Line.x((_, idx, _) => X.call(xScale, float_of_int(idx)))
  |. D3.Line.curve(curve)
  |. D3.Line.y((value, _, _) => Y.call(yScale, value));

let area =
  D3.Area.make()
  |. D3.Area.x((_, idx, _) => X.call(xScale, float_of_int(idx)))
  |. D3.Area.curve(curve)
  |. D3.Area.y1((value, _, _) => Y.call(yScale, value))
  |. D3.Area.y0((_, _, _) => height -. margin);

let svg =
  D3.select("body")
  |. S.append("svg")
  |. S.attr("width", width +. 2. *. margin)
  |. S.attr("height", height +. 2. *. margin)
  |. S.append("g")
  |. S.attr(
       "transform",
       "translate(" ++ fmtFloat(margin) ++ "," ++ fmtFloat(margin) ++ ")"
     );

/* Draw a line with the data */
svg
|. S.append("path")
|. S.datum(sampleData)
|. S.attr("fill", "none")
|. S.attr("stroke-width", "3")
|. S.attr("stroke", "#337")
|. S.attr("class", "line")
|. S.attr("d", valueLine);

/* Draw an area fill with the data */
svg
|. S.append("path")
|. S.datum(sampleData)
|. S.attr("fill", "#ddf")
|. S.attr("stroke", "none")
|. S.attr("d", area);

/* Draw circles for each data point */
svg
|. S.selectAll("circle")
|. S.data(sampleData)
|. S.enter
|. S.append("circle")
|. S.attr("fill", "#337")
|. S.attrFn("cx", (_, idx, _) => X.call(xScale, idx |> float_of_int))
|. S.attrFn("cy", (value, _, _) => Y.call(yScale, value))
|. S.attr("r", 3);

svg
|. S.append("g")
|. S.attr("transform", "translate(0," ++ (fmtFloat(height -. margin) ++ ")"))
|. S.callAxis(D3.Axis.makeBottom(xScale));

svg |. S.append("g") |. S.callAxis(D3.Axis.makeLeft(yScale));
