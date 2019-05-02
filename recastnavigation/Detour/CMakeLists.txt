file(GLOB SOURCES Source/*.cpp)
file(GLOB INCLUDES Include/*.h)

add_library(Detour STATIC ${SOURCES} ${INCLUDES})
add_library(RecastNavigation::Detour ALIAS Detour)

target_include_directories(Detour
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_compile_definitions(Detour
    PUBLIC
        DT_POLYREF64
)

set_target_properties(Detour
    PROPERTIES
        VERSION 1.0.0
)
