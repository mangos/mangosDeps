add_library(bzip2
    blocksort.c
    bzlib.c
    compress.c
    crctable.c
    decompress.c
    huffman.c
    randtable.c
    bzlib.h
    bzlib_private.h
)

add_library(BZip2::BZip2 ALIAS bzip2)

target_include_directories(bzip2
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(bzip2 PROPERTIES FOLDER "dep")
