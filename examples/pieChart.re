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
let radius = min(width, height) /. 2.;


let svg = D3.Helpers.makeContainer(".piechart", {width, height, margin})
|. S.attr("transform", "translate(" ++ fmtFloat(width /. 2.) ++ "," ++ fmtFloat(height /. 2.) ++ ")");

let pie = D3.Pie.make()
|. D3.Pie.value(((_, playerCount)) => float_of_int(playerCount));

let path = D3.Arc.(make()
|. innerRadius(0.)
|. outerRadius(radius)
);

/*Js.log(path)*/
/*Js.log(pie(data))*/

let group = svg
|. S.selectAll(".piearc")
|. S.data(pie(data))
|. S.enter
|. S.append("g")
|. S.classed("piearc", true);

group
|. S.append("path")
|. S.attr("d", path)
