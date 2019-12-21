#pragma once
//
// Created by mattia on 21/11/19.
//

#ifndef LAUNCH_MY_ELBOW_IMAGETYPES_H
#define LAUNCH_MY_ELBOW_IMAGETYPES_H

#include <type_traits>
#include <functional>

namespace ltype
{
    using uint8 = unsigned char;
    using uint16 = unsigned short;
    using uint32 = unsigned int;
    using uint64 = std::size_t;
    using int8 =  char;
    using int16 =  short;
    using int32 =  int;
    using int64 = long long;
    using float32 = float;
    using float64 = double;
}

enum class DType
{
    UNSUPPORTED = -1,
    UINT8 = 0,
    UINT16 = 1,
    UINT32 = 2,
    INT8 = 3,
    INT16 = 4,
    INT32 = 5,
    FLOAT = 6,
    DOUBLE = 7
};

/// generic type
template<typename T>
struct TypeCoverter: public std::false_type { 
static const constexpr DType dtype = DType::UNSUPPORTED;
};

/// struct specialization
#define LUPETTOLAB_DEFINE_IMAGE_TYPE(t, enumtype)\
template<> struct TypeCoverter<t>: public std::true_type { \
static const constexpr DType dtype = enumtype;\
}

LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::uint8, DType::UINT8);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::uint16, DType::UINT16);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::uint32, DType::UINT32);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::int8, DType::INT8);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::int16, DType::INT16);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::int32, DType::INT32);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::float32, DType::FLOAT);
LUPETTOLAB_DEFINE_IMAGE_TYPE(ltype::float64, DType::DOUBLE);


template<typename WrappedType>
struct TypeWrapper
{
  using T = WrappedType;
};


template<typename F>
void typeSwitcher(DType type, F func)
{
  switch (type)
  {
  case DType::UINT8:
  {
    func(TypeWrapper<ltype::uint8>());
    break;
  }
  case DType::UINT16:
  {
    func(TypeWrapper<ltype::uint16>());
    break;
  }
  case DType::UINT32:
  {
    func(TypeWrapper<ltype::uint32>());
    break;
  }
//   case DType::UINT64:
//   {
//     func(TypeWrapper<ltype::uint64>());
//     break;
//   }
  case DType::INT8:
  {
    func(TypeWrapper<ltype::int8>());
    break;
  }
  case DType::INT16:
  {
    func(TypeWrapper<ltype::int16>());
    break;
  }
  case DType::INT32:
  {
    func(TypeWrapper<ltype::int32>());
    break;
  }
//   case DType::INT64:
//   {
//     func(TypeWrapper<ltype::int64>());
//     break;
//   }
  case DType::FLOAT:
  {
    func(TypeWrapper<ltype::float32>());
    break;
  }
  case DType::DOUBLE:
  {
    func(TypeWrapper<ltype::float64>());
    break;
  }
  default:
  {
    assert(false);
    break;
  }
  }
}



#endif //LAUNCH_MY_ELBOW_IMAGETYPES_H
