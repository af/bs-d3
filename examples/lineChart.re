/* ported (and simplified) Reason version of a basic d3 line chart
 * via https://bl.ocks.org/d3noob/402dd382a51a4f6eea487f9a35566de0 */
module S = D3.Selection;

let sampleData = [|1, 5, 6, 9, 10, 1, 3, 7, 6, 4, 5|];
let margin = 20;
let width = 900;
let height = 500;

let x = D3.Scale.(
    makeLinear ()
    |> domain [|0., float_of_int ((Array.length sampleData) - 1) |]
    |> range [|0, width|]
);
let y = D3.Scale.(
    makeLinear ()
    |> domain [|0., float_of_int (D3.Arr.max_ sampleData ())|]
    |> range([|height, 0|])
);

let curve = D3.Curve.catmullRom;
let valueLine = D3.Line.make ()
    |> D3.Line.x (fun _ idx _ => (x (float_of_int idx)))
    |> D3.Line.curve curve
    |> D3.Line.y (fun value _ _ => y value);
let area = D3.Area.make ()
    |> D3.Area.x (fun _ idx _ => (x (float_of_int idx)))
    |> D3.Area.curve curve
    |> D3.Area.y1 (fun value _ _ => y value)
    |> D3.Area.y0 (fun _ _ _ => (float_of_int (height - margin)));

let svg = S.select "body"
    |> S.append "svg"
    |> S.attr "width" (width + 2 * margin)
    |> S.attr "height" (height + 2 * margin)
    |> S.append "g"
    |> S.attr "transform" ("translate(" ^ (string_of_int margin) ^ "," ^ (string_of_int margin) ^ ")");

/* Draw a line with the data */
svg
    |> S.append "path"
    |> S.datum sampleData
    |> S.attr "fill" "none"
    |> S.attr "stroke-width" "3"
    |> S.attr "stroke" "#337"
    |> S.attr "class" "line"
    |> S.attr "d" valueLine;

/* Draw an area fill with the data */
svg
    |> S.append "path"
    |> S.datum sampleData
    |> S.attr "fill" "#ddf"
    |> S.attr "stroke" "none"
    |> S.attr "d" area;

/* Draw circles for each data point */
svg
    |> S.subSelectAll "circle"
    |> S.data sampleData
    |> S.enter
    |> S.append "circle"
        |> S.attr "fill" "337"
        |> S.attr "cx" (fun _ idx _ => x idx)
        |> S.attr "cy" (fun value _ _ => y value)
        |> S.attr "r" 3;

svg
    |> S.append "g"
    |> S.attr "transform" ("translate(0," ^ string_of_int (height - margin) ^ ")")
    |> S.callAxis (D3.Axis.makeBottom x);

svg
    |> S.append "g"
    |> S.callAxis (D3.Axis.makeLeft y);
