//
// Created by mattia on 21/11/19.
//
#include "Image.h"

#include <iostream>

int main()
{
    std::cout << "Hello Giulia!!!" << std::endl;

    Image img(DType::FLOAT, 32, 32);
    std::cout << "img width: " << img.width() << ", height: " << img.height() << std::endl;

    std::vector<float> vals = {1., 2., 3.};
    Image img2(1, 3, vals.data());

    // std::cout << "img2 type: " << img2.dtype() << std::endl;
    std::cout << "img2 pretty type: " << img2.prettyType() << std::endl;

    Image img3(DType::UINT8, 1, 1);
    std::cout << "img3 pretty type: " << img3.prettyType() << std::endl;
    std::cout << typeid(float).name() << std::endl;

    return 0;
}