project(engine C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)

set(SOURCE_FILES src/main.c src/vec.c src/sph.c src/sdl.c src/engine.c src/clr.c)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(engine ${SOURCE_FILES})
target_link_libraries(engine m ${SDL2_LIBRARIES})