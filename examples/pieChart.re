module S = D3.Selection;
let fmtFloat = D3.Helpers.fmtFloat;

/* Generate a map of "team code" => "players from that team in the top 100 scorers" */
module M = Belt.Map.String;
let teamMap = Belt.Array.reduce(Players.data, M.empty, (acc, p) => {
  let prevCount = M.getWithDefault(acc, p.team, 0);
  acc |. M.set(p.team, prevCount + 1);
});

/* For the chart, the data will be tuples of team codes and the # of top scorers on that team */
type teamTuple = (M.key, int);
let data = (teamMap |. M.toArray);

let width = 900.;
let height = 500.;
let margin = D3.Helpers.{t: 20., r: 20., b: 20., l: 30.};
let radius = min(width, height) *. 0.4;

let pie = D3.Pie.make()
|. D3.Pie.sort(None)
|. D3.Pie.value(((_, playerCount)) => float_of_int(playerCount));

let color = D3.Scale.(
  makeSequential(interpolateBrBG)
  |. sequentialDomain([|0., data |. Array.length |. float_of_int|])
);

let svg = D3.Helpers.makeContainer(".piechart", {width, height, margin})
|. S.attr("transform", "translate(" ++ fmtFloat(width /. 2.) ++ "," ++ fmtFloat(height /. 2.) ++ ")");

let path = D3.Arc.(make()
|. innerRadius(0.)
|. outerRadius(radius)
);

let label = D3.Arc.(make()
|. innerRadius(radius +. 25.)
|. outerRadius(radius +. 25.)
);

let group = svg
|. S.selectAll(".piearc")
|. S.data(pie(data))
|. S.enter
|. S.append("g")
|. S.classed("piearc", true);

group
|. S.append("path")
|. S.attr("d", path)
|. S.attrFn("fill", (_, idx, _) => {
  color |. D3.Scale.sequentialCall(float_of_int(idx))
});

group
|. S.append("text")
|. S.classed("teamText", true)
|. S.attr("dx", -15)
|. S.attrFn("transform", (d, _, _) => {
  let (x, y) = D3.Arc.centroid(label, d);
  "translate(" ++ fmtFloat(x) ++ "," ++ fmtFloat(y) ++ ")";
})
|. S.textFn((d: D3.Pie.wrapped(teamTuple), _, _) => {
  let (teamName, playerCount) = d##data;
  teamName ++ " (" ++ string_of_int(playerCount) ++ ")";
});
