# Linus-PE-2022

# Assignment
This program should create a printable bitmap graphic that looks like the picture below.
Before rendering the picture the program will ask how many rectangles should be generated.
![Example](./img/GruneMaylis.JPG)

# Algorithm
Using recursion the program will generate a rectangles, while n is the number of execution cycles.
The function passes the edges of every rectangle and after every iteration cycle the new point will be 
the middle of the two points. The algoritmen defines these points as the rectangle: 

![Rectangle](./img/recangle.svg)

pseudo-code
```c
main{
    #Edge A(0/0) B(0/1000) C(1000/1000) D(1000/0)
    drawStructure(3, A, B, C, D)   
}

drawStructure(n, A, B, C, D){
  if n == 0: return;
  
  drawRecangle(A, B, C, C)
  
  A = middleOfVectors(A, B)
  B = middleOfVectors(B, C)
  C = middleOfVectors(C, D)
  D = middleOfVectors(D, A)
  
  #Edges A(0/500) B(500/1000) C(1000/500)
  drawStructure(n-1, A, B, C, D)
          
}
```
UML Diagram:

![UML Diagram](./img/algorithm.svg)
# Instruction

Requirements:
* build-essentials
* gcc

This program was tested on Ubuntu 22.04 with ggc version 11.3.0

The size of the image can be adjusted inside of graphics_handler.h
## Compile
```bash
gcc main.c include/file_handler.c include/graphics_handler.c
```
## Execute
```bash
./a.out
```

When executing the file with CLion the generated file will appear inside the folder cmake-build-debug

# GitHub Repository
[Repository](https://github.com/Maytastico/Linus-PE-2022)