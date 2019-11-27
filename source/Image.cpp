//
// Created by mattia on 21/11/19.
//

#include "Image.h"

Image::Image()
: _width()
, _heigth()
, _data()
{
}

Image::Image(int width, int height)
: _width(width)
, _heigth(height)
, _data()
{}

// TODO(Giulia)
Image::Image(const Image &that)
{}

// TODO(Giulia)
Image::Image(Image&& that)
{}

int Image::getWidth() const
{
    return _width;
}

int Image::getHeigth() const
{
    return 0;
}

Image &Image::operator=(const Image &that)
{
    // TODO: fill in
    return *this;
}

Image &Image::operator=(Image &&that)
{
    // TODO:: fill in
    return *this;
}

Image::~Image()
{
    //TODO: do we need to do anything here?
}

