# GAMES101-Homework(Being Updated)

Homework of GAMES101: Introduction to Computer Graphics, instructed by Professor Linqi Yan. 

## Assignment0

本地C++环境搭建(OpenCV & Eigen)

## Homework1 旋转与投影

![截屏2022-09-03 01.36.20](/imgs/%E6%88%AA%E5%B1%8F2022-09-03%2001.36.20.png)

## Homework2 Triangles and Z-buffering

### Normal Version

 ![截屏2022-09-02 22.00.23](/imgs/%E6%88%AA%E5%B1%8F2022-09-02%2022.00.23.png)

### MSAA Version

使用超采样来实现反走样，对边界的处进行优化，但在三角形交界处存在黑边

![截屏2022-09-03 00.17.19](/imgs/%E6%88%AA%E5%B1%8F2022-09-03%2000.17.19.png)

### MSAA Version with no black-edge

去除交界处的黑边

![截屏2022-09-03 00.56.50](/imgs/%E6%88%AA%E5%B1%8F2022-09-03%2000.56.50.png)

### 对比图

![截屏2022-09-03 01.55.25](/imgs/%E6%88%AA%E5%B1%8F2022-09-03%2001.55.25.png)

## Homework3 Shading

### Normal Shader
![normal_shader](/imgs/output_normal.png)

### Blinn-Phong Shader
![blinn_phong_shader](/imgs/output_phong.png)

### Texture Shader
![texture_shader](/imgs/output_texture.png)

### Bump Mapping Shader
![bump_mapping_shader](/imgs/output_bump.png)

### Displacement Mapping Shader
![displacement_mapping_shader](/imgs/output_displacement.png)