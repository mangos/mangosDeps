# SPDX-License-Identifier: Unlicense
#
# LibTomMath, a free open source portable number theoretic multiple-precision
# integer (MPI) library written entirely in C.
#

cmake_minimum_required(VERSION 3.10)

project(libtommath
    VERSION 1.2.0
    DESCRIPTION "A free open source portable number theoretic multiple-precision integer (MPI) library written entirely in C."
    HOMEPAGE_URL "https://www.libtom.net/LibTomMath"
    LANGUAGES C)

include(sources.cmake)

#-----------------------------------------------------------------------------
# Compose CFLAGS
#-----------------------------------------------------------------------------

# Some information ported from makefile_include.mk


if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified.")
  set(CMAKE_BUILD_TYPE "Release")
endif()

# We only differentiate between MSVC and GCC-compatible compilers
if(MSVC)
    set(LTM_C_FLAGS -W3)
elseif(WATCOM)
    set(LTM_C_FLAGS -fo=.obj -oaxt -3r -w3)
else()
    set(LTM_C_FLAGS -Wall -Wsign-compare -Wextra -Wshadow
                    -Wdeclaration-after-statement -Wbad-function-cast -Wcast-align
                    -Wstrict-prototypes -Wpointer-arith -Wsystem-headers)
    set(CMAKE_C_FLAGS_DEBUG "-g3")
    set(CMAKE_C_FLAGS_RELEASE "-O3 -funroll-loops -fomit-frame-pointer")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g3 -O2")
    set(CMAKE_C_FLAGS_MINSIZEREL "-Os")
endif()

# What compiler do we have and what are their...uhm... peculiarities
if(CMAKE_C_COMPILER_ID MATCHES "(C|c?)lang")
    list(APPEND LTM_C_FLAGS -Wno-typedef-redefinition -Wno-tautological-compare -Wno-builtin-requires-header)
    # Clang requires at least '-O1' for dead code elimination
    set(CMAKE_C_FLAGS_DEBUG "-O1 ${CMAKE_C_FLAGS_DEBUG}")
endif()
if(CMAKE_C_COMPILER MATCHES "mingw")
    list(APPEND LTM_C_FLAGS -Wno-shadow -Wno-expansion-to-defined -Wno-declaration-after-statement -Wno-bad-function-cast)
endif()
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    list(APPEND LTM_C_FLAGS -Wno-nullability-completeness)
endif()
if(CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
    list(APPEND LTM_C_FLAGS -no-undefined)
endif()

# TODO: coverage (lgcov)

# If the user set the environment variables at generate-time, append them
# in order to allow overriding our defaults.
# ${LTM_CFLAGS} means the user passed it via sth like:
# $ cmake -DLTM_CFLAGS="foo"
list(APPEND LTM_C_FLAGS ${LTM_CFLAGS})
list(APPEND LTM_LD_FLAGS ${LTM_LDFLAGS})

#-----------------------------------------------------------------------------
# library target
#-----------------------------------------------------------------------------
add_library(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)

target_compile_options(${PROJECT_NAME} BEFORE PRIVATE
    ${LTM_C_FLAGS}
)
target_link_options(${PROJECT_NAME} BEFORE PRIVATE
    ${LTM_LD_FLAGS}
)

set(PUBLIC_HEADERS tommath.h)
set(C89 False CACHE BOOL "(Usually maintained automatically) Enable when the library is in c89 mode to package the correct header files on install")
if(C89)
    list(APPEND PUBLIC_HEADERS tommath_c89.h)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME tommath
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
)
