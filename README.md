[![Build Status](https://travis-ci.org/af/bs-d3.svg?branch=master)](https://travis-ci.org/af/bs-d3)

# bs-d3

WIP [d3](https://github.com/d3/d3) 5.x bindings for [Bucklescript](https://github.com/bucklescript/bucklescript/).

Extremely incomplete and experimental; contributions welcome!


## Setting up a dev environment

```
# Install dependencies
yarn

# Start bucklescript in watch mode
yarn start

# In a separate terminal window, run webpack
yarn webpack

# Then open `./examples/index.html` and you should the line chart from `./examples/lineChart.re`
```

## Current status

d3 has a large [API surface](https://github.com/d3/d3/blob/master/API.md#paths-d3-path), so there's still a lot to do! However, the pieces are already in place to [draw line and area charts](https://github.com/af/bs-d3/blob/master/examples/lineChart.re)

Currently some of the typings are still quite loose/permissive, if you have any suggestions to tighten them up in an idiomatic OCaml way, please file an issue or PR.

- [x] Axes
- [x] Arrays (about 50%)
- [ ] Brushes
- [ ] Chords
- [ ] Brushes
- [ ] Collections
- [ ] Colors
- [ ] Dispatches
- [ ] Dragging
- [ ] Easings
- [ ] Forces
- [ ] Number formatting
- [ ] Geo
- [ ] Hierarchies
- [ ] Interpolators
- [ ] Paths
- [ ] Polygons
- [ ] Quadtrees
- [x] Scales (partially)
- [x] Selections (mostly)
- [x] Shapes (lines & areas only at the moment)
- [ ] Time Intervals
- [ ] Timers
- [ ] Transitions
- [ ] Voronoi
- [ ] Zooming
