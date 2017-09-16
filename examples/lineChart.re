/* ported (and simplified) Reason version of a basic d3 line chart
 * via https://bl.ocks.org/d3noob/402dd382a51a4f6eea487f9a35566de0 */
module S = D3.Selection;
module Scale = D3.Scale;

let sampleData = [|1, 5, 6, 9, 10, 1, 3|];
let margin = 20;
let width = 900;
let height = 500;

let x = Scale.makeLinear ()
    |> Scale.domain [|0., float_of_int ((Array.length sampleData) - 1) |]
    |> Scale.range [|0, width|];
let y = Scale.makeLinear ()
    |> Scale.domain [|0., float_of_int (D3.Arr.max_ sampleData ())|]
    |> Scale.range([|height, 0|]);

let valueLine = D3.Line.make ()
    |> D3.Line.x (fun _ idx _ => (x (float_of_int idx)))
    |> D3.Line.curve D3.Curve.bundle
    |> D3.Line.y (fun value _ _ => y value);

let svg = S.select "body"
    |> S.append "svg"
    |> S.attr "width" (width + 2 * margin)
    |> S.attr "height" (height + 2 * margin)
    |> S.append "g"
    |> S.attr "transform" ("translate(" ^ (string_of_int margin) ^ "," ^ (string_of_int margin) ^ ")");

svg
    |> S.append "path"
    |> S.data [|sampleData|]
    |> S.attr "fill" "none"
    |> S.attr "stroke" "#337"
    |> S.attr "class" "line"
    |> S.attr "d" valueLine;

svg
    |> S.append "g"
    |> S.attr "transform" ("translate(0," ^ string_of_int (height - margin) ^ ")")
    |> S.callAxis (D3.Axis.makeBottom x);

svg
    |> S.append "g"
    |> S.callAxis (D3.Axis.makeLeft y);
