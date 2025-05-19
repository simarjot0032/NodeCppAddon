cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_JS_INC} "addons")
add_definitions(-DNAP_VERSION=10)
file(GLOB SOURCE_FILES "addons/*")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
include_directories(
    ${CMAKE_JS_INC}  # from cmake-js, this includes node_api.h
    ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/node-addon-api  # for napi.h
    addons
)