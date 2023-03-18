# Linus-PE-2022
* Assignment
* Algorithm
  * UML shematic
* Instructions

# Assignment
This program should create a printable bitmap graphic that looks like this.
Before rendering the picture the program will ask how many rectangles should be generated.
![Example](./img/GruneMaylis.JPG)

# Algorithm
This program can be executed with recursion, while n is the number of execution cycles.
The functions passes the edges of every rectangle and the function calculates the
vectors out of the positions

pseudo-code
```c
#Edge 1. 0/0 2.0/1000 3.1000/1000 4.1000/0
 
drawRecangle([0,0], [0,1000], [1000,1000], [1000,0])

#Edges 1.
```

# Instruction

Requirements:
* build-essentials
* gcc

This program was tested on Ubuntu 22.04 with ggc version 11.3.0
## Compile
```bash
gcc PE-2022 main.c include/file_handler.c include/graphics_handler.c
```
## Execute
```bash
./PE-2022
```