# This code is part of MaNGOS. Contributor & Copyright details are in AUTHORS/THANKS.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

project(GSOAP)

add_library(gsoap STATIC
    soapC.cpp
    soapServer.cpp
    stdsoap2.cpp
    soapH.h
    soapStub.h
    stdsoap2.h
)

target_include_directories(gsoap
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
