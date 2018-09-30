module S = D3.Selection;
let fmtFloat = D3.Helpers.fmtFloat;

let data = Players.data;
let width = 900.;
let height = 500.;
let margin = D3.Helpers.{t: 20., r: 20., b: 20., l: 30.};


module X = D3.Scale.MakeLinearFloat();
module Y = D3.Scale.MakeLinearFloat();

let _ = X.(
  instance
  |. domain([|0., float_of_int(Array.length(data) - 1)|])
  |. range([|0., width|])
);

let maxPoints = D3.Array.max_(data, ~accessor=((player: Players.t) => player.total), ());
let _ = Y.(
  instance
  |. domain([|0., float_of_int(maxPoints)|])
  |. range([|height, 0.|])
);

let svg = D3.Helpers.makeContainer(".barchart", {width, height, margin});

/* Draw x and y axes on the svg */
svg
|. S.append("g")
|. S.attr("class", "axis xAxis")
|. S.attr("transform", "translate(0," ++ (fmtFloat(height -. margin.t) ++ ")"))
|. S.callAxis(D3.Axis.makeBottom(X.instance));

svg
|. S.append("g")
|. S.attr("class", "axis yAxis")
|. S.callAxis(D3.Axis.makeLeft(Y.instance));

let barWidth = ((width -. margin.l -. margin.r) /. (Array.length(data) |> float_of_int))
  |> fmtFloat;

/* Draw bars for each data point */
svg
|. S.selectAll(".bar")
|. S.data(data)
|. S.enter
|. S.append("rect")
|. S.classed("bar", true)
|. S.attr("width", barWidth)
|. S.attrFn("y", (d: Players.t, _, _) => Y.call(d.total |> float_of_int))
|. S.attrFn("x", (_, idx, _) => X.call(idx |> float_of_int))
|. S.attrFn("height", (d: Players.t, _, _) => (height -. margin.b -. Y.call(d.total |> float_of_int)));
