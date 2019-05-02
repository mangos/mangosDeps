file(GLOB SOURCES Source/*.cpp)
file(GLOB INCLUDES Include/*.h)

add_library(Recast STATIC ${SOURCES} ${INCLUDES})
add_library(RecastNavigation::Recast ALIAS Recast)

target_include_directories(Recast
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

set_target_properties(Recast
    PROPERTIES
        VERSION 1.0.0
)
