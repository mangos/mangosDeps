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

if (NOT TARGET "ZLIB::ZLIB")
    add_subdirectory(zlib)
endif()

if (NOT TARGET "BZip2::BZip2")
    add_subdirectory(bzip2)
endif()

add_subdirectory(acelite)
add_subdirectory(utf8cpp)

if(BUILD_MANGOSD)
    if(SCRIPT_LIB_ELUNA)
        add_subdirectory(lualib)
    endif()
    if(SOAP)
        add_subdirectory(gsoap)
    endif()
endif()

if(BUILD_MANGOSD OR BUILD_TOOLS)
    add_subdirectory(recastnavigation)
    add_subdirectory(g3dlite)
endif()

if(BUILD_TOOLS)
    add_subdirectory(StormLib)
    add_subdirectory(loadlib)
endif()
