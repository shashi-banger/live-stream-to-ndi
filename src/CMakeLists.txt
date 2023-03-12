cmake_minimum_required (VERSION 3.10)

project ("live_to_ndi")

# Add custom cmake modules path
LIST (APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

INCLUDE (Bootstrap_Linux)

# Output build settings
IF (SUPPORTED_PLATFORM)
    MESSAGE (STATUS "Supported target platform: ${SUPPORTED_PLATFORM}")
ELSE ()
    MESSAGE (STATUS "Unsupported target platform, will still attempt build!")
ENDIF ()
MESSAGE (STATUS "Target platform: ${CONFIG_PLATFORM}")
MESSAGE (STATUS "Target architecture: ${CONFIG_ARCH}")
MESSAGE (STATUS "CPU Count: ${CONFIG_CPU_COUNT}")
MESSAGE (STATUS "Target build type: ${CMAKE_BUILD_TYPE}")


ADD_SUBDIRECTORY (common)
ADD_SUBDIRECTORY (app)
