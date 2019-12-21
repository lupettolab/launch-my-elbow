#pragma once
//
// Created by mattia on 21/11/19.
//

#ifndef LAUNCH_MY_ELBOW_IMAGEIMPL_H
#define LAUNCH_MY_ELBOW_IMAGEIMPL_H

#include "ImageBase.h"

template<typename T>
class ImageImpl: public ImageBase
{
public:
    /// default constructor
    ImageImpl(): ImageBase(), _data() {}

    ImageImpl(int width, int height): ImageBase(width, height), _data() {}

    ImageImpl(int width, int height, const T* data)
        : ImageBase(width, height), _data(width * height, T(0)) 
    {
        std::memcpy(_data.data(), data, static_cast<size_t>(width * height));
    }

    /// copy constructor
    ImageImpl(const ImageImpl& that) = delete;
    ImageImpl& operator=(const ImageImpl& that) = delete;

    /// move ctor
    ImageImpl(ImageImpl&& that) = default;
    ImageImpl& operator=(ImageImpl&& that) = default;

    /// destructor
    ~ImageImpl(){}

    /// random access operators
    T operator[](size_t idx) const {return _data[idx];}
    T& operator[](size_t idx) {return _data[idx];}

    T operator()(int x, int y) const {return _data[x * _width + y]; }
    T& operator()(int x, int y) {return _data[x * _width + y]; }

private:
    std::vector<T> _data;
};

#endif //LAUNCH_MY_ELBOW_IMAGEIMPL_H
