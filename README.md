# Project Name : FDF

# Info:
The goal of this project generate a 3D model from a set of vertex.
This project is about creating a simplified 3D graphic from 2D map.
![FDF](/fdf.png?raw=true "FDF PICTURE")

# Usage:
```
$> make
$> ./fdf maps/42.fdf
```

# Sample Map:
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

# Resources:
```
$> cd resources/maps
```

# Hot Keys:
The following key are used to move the camera:
  * `UP`, `DOWN` : Rotate along the X-axis
  * `LEFT`, `RIGHT` : Rotate along the Y-axis
  * `<`, `>` : Rotate along the Z-axis
  * `PgUp`, `PgDn` : Translate along the X-axis
  * `HOME`, `END` : Translate along the Y-axis
  * `X`, `Z` : increment z
  * `G` : Gradient
  * `D` : Diagonal
