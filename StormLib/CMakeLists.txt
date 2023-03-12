#
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
#

project(StormLib VERSION 9.22)
set(LIBRARY_NAME stormlib)

set(SRC_FILES
           src/adpcm/adpcm.cpp
           src/huffman/huff.cpp
           src/jenkins/lookup3.c
           src/lzma/C/LzFind.c
           src/lzma/C/LzmaDec.c
           src/lzma/C/LzmaEnc.c
           src/pklib/explode.c
           src/pklib/implode.c
           src/sparse/sparse.cpp
           src/FileStream.cpp
           src/SBaseCommon.cpp
           src/SBaseDumpData.cpp
           src/SBaseFileTable.cpp
           src/SBaseSubTypes.cpp
           src/SCompression.cpp
           src/SFileAddFile.cpp
           src/SFileAttributes.cpp
           src/SFileCompactArchive.cpp
           src/SFileCreateArchive.cpp
           src/SFileExtractFile.cpp
           src/SFileFindFile.cpp
           src/SFileGetFileInfo.cpp
           src/SFileListFile.cpp
           src/SFileOpenArchive.cpp
           src/SFileOpenFileEx.cpp
           src/SFilePatchArchives.cpp
           src/SFileReadFile.cpp
           src/SFileVerify.cpp
           src/rsa/rsa_verify_simple.c
           src/misc/crypt_libc.c
)

add_definitions(-D_7ZIP_ST -DBZ_STRICT_ANSI -D__SYS_ZLIB -D__SYS_BZLIB)

if(${CMAKE_SYSTEM_NAME} STREQUAL FreeBSD)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DO_LARGEFILE=0 -Dstat64=stat -Dlstat64=lstat -Dlseek64=lseek -Doff64_t=off_t -Dfstat64=fstat -Dftruncate64=ftruncate")
endif()

add_library(
      ${LIBRARY_NAME}
      STATIC
      ${SRC_FILES}
      )

set(LINK_LIBS ${LINK_LIBS} ZLIB::ZLIB BZip2::BZip2 libtommath libtomcrypt)

if(WIN32)
    set(LINK_LIBS ${LINK_LIBS} wininet)
endif()

target_link_libraries(${LIBRARY_NAME} PRIVATE ${LINK_LIBS})
target_compile_definitions(${LIBRARY_NAME} INTERFACE STORMLIB_NO_AUTO_LINK)
target_include_directories(${LIBRARY_NAME} PUBLIC src/)
set_target_properties(${LIBRARY_NAME} PROPERTIES PUBLIC_HEADER "src/StormLib.h;src/StormPort.h")
