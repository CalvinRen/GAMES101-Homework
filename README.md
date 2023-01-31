# GAMES101-Homework(Being Updated)

Homework of GAMES101: Introduction to Computer Graphics, instructed by Professor Linqi Yan. 

## Assignment0

Build up C++ Environment (OpenCV & Eigen)

## HW1-Rotation and Translation
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2001.36.20.png" width="400"/>
</div>

## HW2-Triangles and Z-buffering

### Normal Version
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-02%2022.00.23.png" width="400"/>
</div>


### MSAA Version

Implement MSAA by using supersampling to achieve anti-aliasing, and optimize the boundary, but there is a black edge at the intersection of triangles

<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2000.17.19.png" width="400"/>
</div>

### MSAA Version with no black-edge

Remove the black edge at the intersection of triangles  

<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2000.17.19.png" width="400"/>
</div>

### Comparison
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2001.55.25.png" width="400"/>
</div>

## HW3-Shading

### Normal Shader
<div align="center">
    <img src="./imgs/output_normal.png" width="400"/>
</div>

### Blinn-Phong Shader
<div align="center">
    <img src="./imgs/output_phong.png" width="400"/>
</div>

### Texture Shader
<div align="center">
    <img src="./imgs/output_texture.png" width="400"/>
</div>

### Bump Mapping Shader
<div align="center">
    <img src="./imgs/output_bump.png" width="400"/>
</div>

### Displacement Mapping Shader
<div align="center">
    <img src="./imgs/output_displacement.png" width="400"/>
</div>

## HW4-Bezier Curve
### Naive Bezier Curves
<div align="center">
    <img src="./imgs/naive_bezier.png" width="400"/>
</div>

### Anti-Aliasing Bezier Curves
<div align="center">
    <img src="./imgs/anti-aliasing_bezier.png" width="400"/>
</div>

### Comparison
<div align="center">
    <img src="./imgs/bezier_comp_glob.png" width="600"/>
</div>

<div align="center">
    <img src="./imgs/bezier_comp.png" width="600"/>
</div>

## HW5-Ray Tracing and Triangle Intersection
<div align="center">
    <img src="./imgs/hw5.png" width="400"/>
</div>

## HW6-Ray Bounding Box Intersection and BVH
<div align="center">
    <img src="./imgs/bunny.png" width="400"/>
</div>

## HW7-Path Tracing
### Original Framework
- SPP = 16  
- Render Time = 48min
<div align="center">
    <img src="./imgs/cornell_box.png" width="500"/>
</div>

### Optimized Framework

1. Multiple Thread (OpenMP)  
```c++
#pragma omp parallel for
```

2. Add SPP  
Set SPP = 1024.

3. Anti-Aliasing  
Sample randomly over a range of pixels.

4. Modify `get_random_float()`  
Due to the feature of `random_device` on Linux/Unix, the function uses the entropy pool provided by Operating System. When the entropy pool is exhausted, `random_device` blocks the call until there is enough entropy available, which therefore makes the function a time-consuming operation.  
In the given framework, `random_device` function was called frequently, resulting in an overall performance degradation.   
In order to optimize this function, we made the first three lines into static variables. 

5. Remove White Noise Point  
Since the *PDF* is sampled randomly, when the value of pdf closes to 0, the computed indirect light will be biased towards the limit value. Therefore, we only consider on computing the indirect light when $pdf > \epsilon$. 

#### Result
- SPP = 1024
- Render Time = 14min

<div align="center">
    <img src="./imgs/cornell_box_1024.png" width="500"/>
</div>