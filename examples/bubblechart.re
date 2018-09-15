module S = D3.Selection;

let sampleData = Players.data;
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

let maxGoals = D3.Array.max_(sampleData, ~accessor=((player: Players.t) => player.g), ());
let _ = Y.(
  instance
  |. domain([|0., float_of_int(maxGoals)|])
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
|. S.attr("transform", "translate(0," ++ (fmtFloat(height) ++ ")"))
|. S.callAxis(D3.Axis.makeBottom(X.instance));

svg
|. S.append("g")
|. S.attr("class", "axis yAxis")
|. S.callAxis(D3.Axis.makeLeft(Y.instance));

/* Add bubbles to the chart */
svg
|. S.selectAll(".node")
|. S.data(sampleData)
|. S.enter
|. S.append("circle")
|. S.attrFn("class", (d: Players.t, _, _) => "bubble " ++ d.pos)
|. S.attr("title", (d: Players.t, _, _) => d.name)
|. S.attr("cx", (_, idx, _) => X.call(idx))
|. S.attr("cy", (d: Players.t, _, _) => Y.call(float_of_int(d.g)))
|. S.attr("r", (d: Players.t, _, _) => d.salary *. 3.);
