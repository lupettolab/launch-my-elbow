#pragma once
//
// Created by mattia on 21/11/19.
//

#ifndef LAUNCH_MY_ELBOW_IMAGEBASE_H
#define LAUNCH_MY_ELBOW_IMAGEBASE_H

#include <vector>

class ImageBase
{
public:
    /// default constructor
    ImageBase();

    /// one possibile constructor
    ImageBase(int width, int height);

    virtual ~ImageBase(){}

    /// getters
    virtual int width() const;
    virtual int height() const;

protected:
    int _width;
    int _height;
};

#endif //LAUNCH_MY_ELBOW_IMAGEBASE_H
