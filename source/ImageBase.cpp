//
// Created by mattia on 21/11/19.
//

#include "ImageBase.h"

ImageBase::ImageBase()
: _width()
, _height()
{
}

ImageBase::ImageBase(int width, int height)
: _width(width)
, _height(height)
{}

int ImageBase::width() const {return _width;};
int ImageBase::height() const {return _height;};
