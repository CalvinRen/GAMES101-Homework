# GAMES101-Homework(Being Updated)

Homework of GAMES101: Introduction to Computer Graphics, instructed by Professor Linqi Yan. 

## Assignment0

本地C++环境搭建(OpenCV & Eigen)

## Homework1 旋转与投影

![截屏2022-09-03 01.36.20](https:cdn.jsdelivr.net/gh/Calvin-Ren/image-host/blog-img/202209030144076.png)

## Homework2 Triangles and Z-buffering

#### Normal Version

 ![截屏2022-09-02 22.00.23](https:cdn.jsdelivr.net/gh/Calvin-Ren/image-host/blog-img/202209030148578.png)

#### MSAA Version

使用超采样来实现反走样，对边界的处进行优化，但在三角形交界处存在黑边

![截屏2022-09-03 00.17.19](https:cdn.jsdelivr.net/gh/Calvin-Ren/image-host/blog-img/202209030152886.png)

#### MSAA Version with no black-edge

去除交界处的黑边

![截屏2022-09-03 00.56.50](https:cdn.jsdelivr.net/gh/Calvin-Ren/image-host/blog-img/202209030153355.png)

#### 对比图

![截屏2022-09-03 01.55.25](https:cdn.jsdelivr.net/gh/Calvin-Ren/image-host/blog-img/202209030156050.png)