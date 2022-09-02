#include<cmath>
#include<Eigen/Core>
#include<Eigen/Dense>
#include<iostream>

#define PI 3.14
#define DEG2RAD (PI/180.0f)

int main(){
    // homework1
    Eigen::Vector3f x(2.0f, 1.0f, 1.0f);
    Eigen::Matrix3f T;
    Eigen::Matrix3f R;

    float rd = 45.0f * DEG2RAD;
    T << 1, 0, 1,
         0, 1, 2,
         0, 0, 1;
    R << std::cos(rd), -std::sin(rd), 0,
         std::sin(rd), std::cos(rd), 0,
         0, 0, 1;
    
    Eigen::Vector3f result = T * R * x;

    std::cout << result << std::endl;

    return 0;
}