module S = D3.Selection;

let sampleData = Players.data;
let margin = 30.;
let width = 900.;
let height = 500.;

let fmtFloat = x => x |. int_of_float |. string_of_int;

module X = D3.Scale.MakeLinearFloat();
module Y = D3.Scale.MakeLinearFloat();

let maxPoints = D3.Array.max_(sampleData, ~accessor=((player: Players.t) => player.total), ());
let minPoints = D3.Array.min_(sampleData, ~accessor=((player: Players.t) => player.total), ());
let _ = X.(
  instance
  |. domain([|float_of_int(minPoints), float_of_int(maxPoints)|])
  |. range([|0., width|])
);

let maxGoals = D3.Array.max_(sampleData, ~accessor=((player: Players.t) => player.g), ());
let _ = Y.(
  instance
  |. domain([|0., float_of_int(maxGoals)|])
  |. range([|height, 0.|])
);

let svg =
  D3.select(".bubblechart")
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

/* Add <g> wrappers for each bubble to the chart */
let cell = svg
|. S.selectAll(".bubbleCell")
|. S.data(sampleData)
|. S.enter
|. S.append("g")
|. S.classed("bubbleCell", true)
|. S.attrFn("transform", (d: Players.t, _, _) => {
    let x = X.call(float_of_int(d.total));
    let y = Y.call(float_of_int(d.g));
    "translate(" ++ fmtFloat(x) ++ "," ++ fmtFloat(y) ++ ")";
});

/* add the actual bubble */
cell
|. S.append("circle")
|. S.attrFn("class", (d: Players.t, _, _) => "bubble " ++ d.pos)
|. S.attrFn("title", (d: Players.t, _, _) => d.name)
|. S.attr("cx", 0)
|. S.attr("cy", 0)
|. S.attrFn("r", (d: Players.t, _, _) => sqrt(d.salary) *. 8.);

/* each "cell" has a <g> that contains text elements: */
let textBox = cell
|. S.append("g")
|. S.classed("textBox", true)
|. S.attr("transform", "translate(20, 0)");

textBox
|. S.append("text")
|. S.classed("name", true)
|. S.textFn((d: Players.t, _, _) => d.name);

textBox
|. S.append("text")
|. S.classed("position", true)
|. S.attr("y", 12)
|. S.textFn((d: Players.t, _, _) => d.pos);
