file(GLOB sandbox_SRC
     "include/*.h"
     "src/*.cpp"
)

add_executable(PrinceGE-Sandbox ${sandbox_SRC})

target_include_directories(PrinceGE-Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/pge-core/include/)
target_link_libraries(PrinceGE-Sandbox PRIVATE PrinceGE)