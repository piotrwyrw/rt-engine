project(RTEngine C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)

set(SOURCE_FILES src/main.c src/vec.c src/sph.c)

add_executable(RTEngine ${SOURCE_FILES})
target_link_libraries(RTEngine m)