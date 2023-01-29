# GAMES101-Homework(Being Updated)

Homework of GAMES101: Introduction to Computer Graphics, instructed by Professor Linqi Yan. 

## Assignment0

本地C++环境搭建(OpenCV & Eigen)

## Homework1 旋转与投影
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2001.36.20.png" width="400"/>
</div>

## Homework2 Triangles and Z-buffering

### Normal Version
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-02%2022.00.23.png" width="400"/>
</div>


### MSAA Version

使用超采样来实现反走样，对边界的处进行优化，但在三角形交界处存在黑边

<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2000.17.19.png" width="400"/>
</div>

### MSAA Version with no black-edge

去除交界处的黑边
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2000.17.19.png" width="400"/>
</div>

### 对比图
<div align="center">
    <img src="./imgs/%E6%88%AA%E5%B1%8F2022-09-03%2001.55.25.png" width="400"/>
</div

## Homework3 Shading

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

## Bezier Curve
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
