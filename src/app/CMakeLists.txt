cmake_minimum_required (VERSION 3.10)
project (live_to_ndi)

set (CMAKE_CXX_STANDARD 11)

add_definitions(-DBOOST_LOG_DYN_LINK)
INCLUDE (Bootstrap_Linux)

include_directories(..)
include_directories(${BOOST_INCLUDE_PATH})

message(Boost_LIBRARIES="${Boost_LIBRARIES}")

add_executable (live_to_ndi main_udp_to_ndi.cpp)


target_link_libraries(live_to_ndi
         common
         ${Boost_LIBRARIES})