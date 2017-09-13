/* ported (and simplified) Reason version of a basic d3 line chart
 * via https://bl.ocks.org/d3noob/402dd382a51a4f6eea487f9a35566de0 */
let sampleData = [|1, 5, 6, 9, 10, 1, 3|];
let margin = 20;
let width = 900;
let height = 500;

let x = D3.scaleLinear ()
    |> D3.domain (D3.extent sampleData ())
    |> D3.range [|0, width|];
let y = D3.scaleLinear ()
    |> D3.domain [|0., float_of_int (D3.max_ sampleData ())|]
    |> D3.range([|height, 0|]);

/* FIXME: invoke x() and y() in lineX() and lineY(), respectively */
let valueLine = D3.line ()
    |> D3.lineX (fun _ idx _ => float_of_int idx)
    |> D3.lineY (fun value _ _ => value);

let svg = D3.select "body"
    |> D3.append "svg"
    |> D3.attr "width" (width + 2 * margin)
    |> D3.attr "height" (height + 2 * margin)
    |> D3.append "g"
    |> D3.attr "transform" ("translate(" ^ (string_of_int margin) ^ "," ^ (string_of_int margin) ^ ")");

svg
    |> D3.append "path"
    |> D3.data [|sampleData|]
    |> D3.attr "class" "line"
    |> D3.attr "d" valueLine;

svg
    |> D3.append "g"
    |> D3.attr "transform" ("translate(0," ^ string_of_int (height - margin) ^ ")")
    |> D3.callAxis (D3.axisBottom x);

svg
    |> D3.append "g"
    |> D3.callAxis (D3.axisLeft y);
