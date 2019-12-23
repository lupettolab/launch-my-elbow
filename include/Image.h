#pragma once
//
// Created by mattia on 21/11/19.
//

#ifndef LAUNCH_MY_ELBOW_IMAGE_H
#define LAUNCH_MY_ELBOW_IMAGE_H

#include "ImageBase.h"
#include "ImageImpl.h"
#include "ImageTypes.h"

#include <memory>
#include <string>
#include <type_traits>

class Image
{
public:
    /// default constructor
    explicit Image(DType dtype = DType::UNSUPPORTED);

    Image(DType dtype, int width, int height);

    template<typename T>
    Image(int width, int height, const T* data)
    : _dtype(TypeCoverter<T>::dtype)
    , _img(std::make_unique<ImageImpl<T>>(width, height, data))
    {
        static_assert(TypeCoverter<T>::value, "Unsupported type");
    }

    /// copy constructor
    Image(const Image& that) = delete;
    Image& operator=(const Image& that) = delete;

    /// move ctor
    Image(Image&& that) = default;
    Image& operator=(Image&& that) = default;

    /// destructor
    ~Image();

    /// getters
    int width() const;
    int height() const;
    DType dtype() const;
    std::string prettyType() const;

    template<typename T>
    const ImageImpl<T>* get() const
    {
        if(TypeCoverter<T>::dtype != _dtype)
        {
            // log error
            return nullptr;
        }

        return dynamic_cast<T*>(_img.get());
    }

    template<typename T>
    ImageImpl<T>* release()
    {
        if(TypeCoverter<T>::dtype != _dtype)
        {
            // log error
            return nullptr;
        }
        
        return dynamic_cast<T*>(_img.release());
    }

private:
    DType _dtype;
    std::unique_ptr<ImageBase> _img;
};

#endif //LAUNCH_MY_ELBOW_IMAGE_H
