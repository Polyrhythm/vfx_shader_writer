file(GLOB_RECURSE SOURCES  ./*.cpp ./*.h)

add_executable(vfx_shader ${SOURCES})

target_link_libraries(vfx_shader nodes)