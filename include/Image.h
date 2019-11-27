#pragma once
//
// Created by mattia on 21/11/19.
//

#ifndef LAUNCH_MY_ELBOW_IMAGE_H
#define LAUNCH_MY_ELBOW_IMAGE_H

#include <vector>

class Image
{
public:
    /// default constructor
    Image();

    /// one possibile constructor
    Image(int width, int height);

    /* put some useful ctors here */

    /// copy constructor
    Image(const Image& that);

    /// copy assignement
    Image& operator=(const Image& that);

    /// move ctor
    Image(Image&& that);

    /// move assignment
    Image& operator=(Image&& that);

    /// destructor
    ~Image();

    /// getters

    int getWidth() const;
    int getHeigth() const;

private:
    int _width;
    int _heigth;
    std::vector<float> _data;
};

#endif //LAUNCH_MY_ELBOW_IMAGE_H
