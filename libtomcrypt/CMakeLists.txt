# SPDX-License-Identifier: Unlicense
#
# LibTomCrypt, modular cryptographic library -- Tom St Denis
#

cmake_minimum_required(VERSION 3.10)

project(libtomcrypt
    VERSION 1.18.2
    DESCRIPTION "A modular cryptographic library."
    HOMEPAGE_URL "https://www.libtom.net/LibTomCrypt"
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

# We differentiate between MSVC, WATCOM and GCC-compatible compilers
if(MSVC)
    set(LTC_C_FLAGS -W3)
elseif(WATCOM)
    set(LTC_C_FLAGS -fo=.obj -oaxt -3r -w3)
else()
    set(LTC_C_FLAGS -Wall -Wsign-compare -Wextra -Wshadow
                    -Wdeclaration-after-statement -Wbad-function-cast -Wcast-align
                    -Wstrict-prototypes -Wpointer-arith -Wsystem-headers)
    set(CMAKE_C_FLAGS_DEBUG "-g3")
    set(CMAKE_C_FLAGS_RELEASE "-O3 -funroll-loops -fomit-frame-pointer")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "-g3 -O2")
    set(CMAKE_C_FLAGS_MINSIZEREL "-Os")
endif()

# What compiler do we have and what are their...uhm... peculiarities
if(CMAKE_C_COMPILER_ID MATCHES "(C|c?)lang")
    list(APPEND LTC_C_FLAGS -Wno-typedef-redefinition -Wno-tautological-compare -Wno-builtin-requires-header)
    # Clang requires at least '-O1' for dead code eliminiation
    set(CMAKE_C_FLAGS_DEBUG "-O1 ${CMAKE_C_FLAGS_DEBUG}")
endif()
if(CMAKE_C_COMPILER MATCHES "mingw")
    list(APPEND LTC_C_FLAGS -Wno-shadow -Wno-expansion-to-defined -Wno-declaration-after-statement -Wno-bad-function-cast)
endif()
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    list(APPEND LTC_C_FLAGS -Wno-nullability-completeness)
endif()
if(CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
    list(APPEND LTC_C_FLAGS -no-undefined)
endif()

# If the user set the environment variables at generate-time, append them
# in order to allow overriding our defaults.
# ${LTC_CFLAGS} means the user passed it via sth like:
# $ cmake -DLTC_CFLAGS="foo"
list(APPEND LTC_C_FLAGS ${LTC_CFLAGS})
list(APPEND LTC_LD_FLAGS ${LTC_LDFLAGS})

#-----------------------------------------------------------------------------
# Library targets
#-----------------------------------------------------------------------------
add_library(${PROJECT_NAME}
    ${SOURCES}
    ${PUBLIC_HEADERS}
    ${PRIVATE_HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/headers>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
)

target_compile_options(${PROJECT_NAME} BEFORE PRIVATE
    ${LTC_C_FLAGS}
)
target_link_options(${PROJECT_NAME} BEFORE PRIVATE
    ${LTC_LD_FLAGS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME tomcrypt
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${PUBLIC_HEADERS}"
)

target_compile_definitions(${PROJECT_NAME} PUBLIC LTM_DESC)
target_compile_definitions(${PROJECT_NAME} PUBLIC USE_LTM)
target_compile_definitions(${PROJECT_NAME} PUBLIC LTC_NO_PROTOTYPES)

target_link_libraries(${PROJECT_NAME} PUBLIC libtommath)
