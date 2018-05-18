open Jest;
module S = D3.Selection;

describe("D3", () => {
  open Expect;

  test("should be attached to the JsDom body", () => {
    let d3 = JsDom.make("<!DOCTYPE html><p>Hello!!</p>") |. JsDom.attachD3;
    expect(d3 |> S.subSelect("p") |> S.text) |> toBe("Hello!!")
  })
});
