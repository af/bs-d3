open Jest;
module S = D3.Selection;

describe("D3", () => {
  open Expect;

  test("should be attached to the JsDom body", () => {
    let d3 = JsDom.make("<!DOCTYPE html><p>Hello!!</p>") |. JsDom.attachD3;
    expect(d3 |. S.select("p") |. S.text) |> toBe("Hello!!")
  });

  test("should select all nodes", () => {
    let d3 = JsDom.make("<!DOCTYPE html><p>1</p><p>2</p><div>3</div><p>4</p>") |. JsDom.attachD3;
    expect(d3 |. S.selectAll("p") |. S.size) |> toBe(3)
  });

  test("should filter by function (with this)", () => {
    let d3 = JsDom.make("<!DOCTYPE html><body><p id='nok'>foo</p><p id='ok'>bar</p></body>") |. JsDom.attachD3;
    expect(d3 |. S.selectAll("p") |. S.filterFn([@bs.this] this => this##id == "ok") |. S.text) |> toBe("bar")
  });

  test("should filter by function and index (with this)", () => {
    let d3 = JsDom.make("<!DOCTYPE html><body><p id='nok'>foo</p><p id='ok'>bar</p></body>") |. JsDom.attachD3;
    expect(d3 |. S.selectAll("p") |. S.filterFnWithIndex([@bs.this] (_this, _d, index) => index == 1) |. S.text) |> toBe("bar")
  });

  test("should detect empty nodes", () => {
    let d3 = JsDom.make("<!DOCTYPE html><body/>") |. JsDom.attachD3;
    expect(d3 |. S.selectAll("p") |. S.empty()) |> toBe(true)
  })
});
