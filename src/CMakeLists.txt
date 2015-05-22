set(luagl_src
	a.cpp
	b.cpp
	c.cpp
	d.cpp
	e.cpp
	f.cpp
	g.cpp
	glew.cpp
	h.cpp
	i.cpp
	j.cpp
	k.cpp
	l.cpp
	m.cpp
	main.cpp
	n.cpp
	o.cpp
	p.cpp
	q.cpp
	r.cpp
	s.cpp
	t.cpp
	u.cpp
	utils.cpp
	v.cpp
	w.cpp	
)

set(luagl_sources
	${luagl_src}
)

include_directories(./)

set(luagl_version_script luagl.version)

IF(UNIX)
    IF(CMAKE_COMPILER_IS_GNUCC)
         SET(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_CXX_COMPILE_OPTIONS_VISIBILITY}hidden -Wl,--version-script=${luagl_version_script}")
    ENDIF(CMAKE_COMPILER_IS_GNUCC)

    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-declarations")
ENDIF(UNIX)

add_library(luagl SHARED
	${luagl_sources}
)

set_property(TARGET luagl PROPERTY CXX_STANDARD 11)
set_property(TARGET luagl PROPERTY CXX_STANDARD_REQUIRED ON)

set_target_properties(luagl
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries (luagl
	glew
	${LUA_LIBRARY}
)
