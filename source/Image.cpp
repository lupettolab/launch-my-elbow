//
// Created by mattia on 21/11/19.
//

#include "Image.h"

Image::Image(DType dtype)
: _dtype(dtype)
, _img(nullptr)
{
}

Image::Image(DType dtype, int width, int height)
: _dtype(dtype)
{
    auto imgCreator = [&](auto type_wrapper){
        using deduced_type = typename decltype(type_wrapper)::T;
        _img = std::make_unique<ImageImpl<deduced_type>>(width, height);
    };
    typeSwitcher(_dtype, imgCreator);
}

int Image::width() const
{
    return _img->width();
}

int Image::height() const
{
    return _img->height();
}

DType Image::dtype() const {return _dtype;}


std::string Image::prettyType() const {
    std::string repr;
    auto getRepr = [this, &repr](auto dtype){
        const auto& idd = typeid(typename decltype(dtype)::T);
        repr = std::string(idd.name());
    };
    typeSwitcher(_dtype, getRepr);
    return repr;
;
}


Image::~Image()
{
}

