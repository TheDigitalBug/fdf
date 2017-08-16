# Project Name : FDF

# Info
The goal of this project generate a 3D model from a set of vertex.
This project is about creating a simplified 3D graphic from 2D map.
![FDF](/fdf.png?raw=true "FDF PICTURE")

# The rules of the game:
 - the winner is player who gets biggest board space.
 - the game is over for player if he cant makes an move.
 - piece sent by the Virtual Machine.
 - piece can have any shape and size.

# Usage!
```
$> make
$> ./fdf map
```

# SAMPLE MAP
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

# Resources
```
$> cd resources/maps
$> cd resources/players
```

# Hot Keys
The following key are used to move the camera:
  * `I`, `K` : Rotate along the X-axis
  * `J`, `L` : Rotate along the Y-axis
  * `O`, `P` : Rotate along the Z-axis
  * `A`, `D` : Translate along the X-axis
  * `W`, `S` : Translate along the Y-axis
  * `+`, `-` : Translate along the Z-axis (Numerical Pad)

# Usage!
  - $> make
  - $> ./fdf map
