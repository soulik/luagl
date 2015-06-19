cmake_minimum_required (VERSION 3.1.0)
project (luagl)

# Include glew

add_subdirectory(dependencies/glew/build/cmake)
include_directories(dependencies/glew/include)
set(BUILD_UTILS OFF CACHE BOOL "Build utils for GLEW")

set_target_properties(glew
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Include Lua 5.1

include(FindLua51)
include_directories(SYSTEM
	${LUA_INCLUDE_DIR}
	${LUA_INCLUDE_DIR}/lua5.1
)

include_directories(${CURRENT_DIR}/dependencies/lutok2/include)

add_subdirectory(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)
set_target_properties(luagl PROPERTIES PREFIX "")
