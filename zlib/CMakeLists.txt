#
# Copyright (C) 1995-2011 Mark Adler
# For conditions of distribution and use, see copyright notice in zlib.h
#

add_library(zlib
    adler32.c
    compress.c
    crc32.c
    deflate.c
    gzclose.c
    gzlib.c
    gzread.c
    gzwrite.c
    infback.c
    inffast.c
    inflate.c
    inftrees.c
    trees.c
    uncompr.c
    zutil.c
    crc32.h
    deflate.h
    gzguts.h
    inffast.h
    inffixed.h
    inflate.h
    inftrees.h
    trees.h
    zconf.h
    zlib.h
    zutil.h
)

add_library(ZLIB::ZLIB ALIAS zlib)

target_include_directories(zlib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(zlib PROPERTIES FOLDER "dep")
