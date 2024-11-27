# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-src"
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-build"
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix"
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix/tmp"
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix/src/fetchtest-populate-stamp"
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix/src"
  "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix/src/fetchtest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix/src/fetchtest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/nhm/CLionProjects/P1/cmake-build-debug/_deps/fetchtest-subbuild/fetchtest-populate-prefix/src/fetchtest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
