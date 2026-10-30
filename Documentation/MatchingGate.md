# Matching Gate

## Rules
- A matching-C gate MUST reject authored sources whose body is the original machine code retyped as instruction words in a .text array; byte counts alone MUST NOT count as C coverage.
- A lane reporting a jump in a coverage metric MUST have its written source opened and checked for shape before the metric is believed.
