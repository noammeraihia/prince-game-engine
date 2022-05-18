file(GLOB pge_SRC
     "include/*.h"
     "src/*.cpp"
)

add_library(PrinceGE ${pge_SRC})

target_include_directories(PrinceGE PRIVATE include/ PRIVATE ${CMAKE_SOURCE_DIR}/third-party/SDL2/include/)
target_link_libraries(PrinceGE PRIVATE mingw32 SDL2main SDL2)