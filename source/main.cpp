//
// Created by mattia on 21/11/19.
//
#include "Image.h"

#include <iostream>

int main()
{
    std::cout << "Hello Giulia!!!" << std::endl;

    Image img(32, 32);
    std::cout << "img width: " << img.getWidth() << ", height: " << img.getHeigth() << std::endl;

    return 0;
}