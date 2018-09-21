/*
 * Manually namespace sub-modules
 * Bucklescript has its own namespacing support, but with it turned on, we were getting strange build
 * failures on the first few builds. So we namespace manually for now.
 *
 * See https://blog.janestreet.com/better-namespaces-through-module-aliases/
 */
include D3_RootSelection;

module Area = D3_Area;
module Array = D3_Array;
module Axis = D3_Axis;
module Curve = D3_Curve;
module Line = D3_Line;
module Scale = D3_Scale;
module Selection = D3_Selection;

/* Assorted utils that come from this bindings library */
module Helpers = D3_Helpers;
