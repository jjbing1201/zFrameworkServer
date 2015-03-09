project(Server)

set(sources
    Logic.cpp
)

set(header
    Logic.h
    Master.h
    body_include.h
)

add_subdirectory(world)
add_subdirectory(m_user)
add_subdirectory(m_shop)
add_subdirectory(base)
add_subdirectory(database)

set(BODY_G_LIB_SRCS ${sources} ${header})
add_library(body SHARED ${BODY_G_LIB_SRCS}) 
target_link_libraries(body world m_user m_shop base database)
