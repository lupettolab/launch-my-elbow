project("LaunchMyElbow")
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Configuration types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(DEFINED CMAKE_BUILD_TYPE AND CMAKE_VERSION VERSION_GREATER "2.8")
  SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS  ${CMAKE_CONFIGURATION_TYPES})
endif()

# Install
install(TARGETS ${PROJ_NAME}
    DESTINATION  "${${PROJ_NAME}_PATH_INSTALL}/bin/${CMAKE_BUILD_TYPE}/"
)

set(CMAKE_DEBUG_POSTFIX "d")

include_directories(${PROJECT_SOURCE_DIR}/include)

# build as library
add_library(ImageLib SHARED source/Image.cpp)

add_executable(LaunchMyElbow source/main.cpp)
target_link_libraries(LaunchMyElbow ImageLib)