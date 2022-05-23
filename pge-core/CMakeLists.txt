file(GLOB pge_SRC
     "include/*.h"
     "include/*/*.h"
     "include/*/*/*.h"
     "src/*.cpp"
     "src/*/*.cpp"
     "src/*/*/*.cpp"
)

add_library(PrinceGE ${pge_SRC})

target_include_directories(PrinceGE PRIVATE include/)
target_link_libraries(PrinceGE PRIVATE mingw32 SDL2main SDL2)