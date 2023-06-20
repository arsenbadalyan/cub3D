#include "cub3D.h"

// map validation rules
// in first is symbol valid
// every time save length of previous line (init value 0)
// allowed flags must be not first line, not last, not first column, not last
// allowed flags place must be smaller than line above, and line bottom
// above or bottom of allowed flags cannot be WHITE_SPACE
// left and right part of door must be wall