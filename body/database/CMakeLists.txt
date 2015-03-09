project(Server)

set(sources
    base.cpp
    bottom.cpp
    users.cpp
    interfaceusing.cpp
)

set(headers
    include_db.h
    base.h
    bottom.h
    users.h
    interfaceusing.h
)

include_directories(
    /usr/local/include
)

set(DB_WORLD_LIB_SRCS ${sources} ${headers})
add_library(database SHARED ${DB_WORLD_LIB_SRCS})
