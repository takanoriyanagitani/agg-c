cmake_minimum_required(VERSION 3.0)

project(agg_c)

if(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
endif()

SET(CMAKE_C_FLAGS         "-Wall -Werror -mavx -mavx2 -mfma -msse -msse2 -msse3 -msse4 -msse4.1 -msse4.2 -msse2avx -mtune=native -march=native")
SET(CMAKE_C_FLAGS_RELEASE "-O3")
SET(CMAKE_C_FLAGS_DEBUG   "-O0 -g -coverage")

add_executable(compute_agg_f64_test compute_agg_f64_test.c)

enable_testing()

add_test(NAME t1_run COMMAND compute_agg_f64_test)
