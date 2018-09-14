module S = D3.Selection;

let sampleData = [|1, 5, 6, 9, 20, 1, 3, 12, 2|];
let margin = 30.;
let width = 900.;
let height = 500.;

let fmtFloat = x => x |. int_of_float |. string_of_int;

module X = D3.Scale.MakeLinearFloat();
module Y = D3.Scale.MakeLinearFloat();

let _ = X.(
  instance
  |. domain([|0., float_of_int(Array.length(sampleData) - 1)|])
  |. range([|0., width|])
);

let _ = Y.(
  instance
  |. domain([|0., float_of_int(D3.Array.max_(sampleData, ()))|])
  |. range([|height, 0.|])
);

let svg =
  D3.select("body")
  |. S.append("svg")
  |. S.attr("width", width +. (2. *. margin))
  |. S.attr("height", height +. (2. *. margin))
  |. S.append("g")
  |. S.attr(
       "transform",
       "translate(" ++ fmtFloat(margin) ++ "," ++ fmtFloat(margin) ++ ")"
     );

svg
|. S.append("g")
|. S.attr("class", "axis xAxis")
|. S.attr("transform", "translate(0," ++ (fmtFloat(height -. margin) ++ ")"))
|. S.callAxis(D3.Axis.makeBottom(X.instance));

svg
|. S.append("g")
|. S.attr("class", "axis yAxis")
|. S.callAxis(D3.Axis.makeLeft(Y.instance));

svg
|. S.selectAll(".node")
|. S.data(sampleData)
|. S.enter
|. S.append("circle")
|. S.attr("class", "bubble")
|. S.attr("cx", (_, idx, _) => X.call(idx))
|. S.attr("cy", height /. 2.)
|. S.attr("r", (d, _, _) => d * 10);
