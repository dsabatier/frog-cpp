cmake_minimum_required(VERSION 3.0)
project(FROG C CXX)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME} src/main.cpp src/Scenes/Scene.h src/Scenes/GameScene.cpp src/Scenes/GameScene.h src/Scenes/MainMenuScene.cpp src/Scenes/MainMenuScene.h src/Scenes/GameOverScene.cpp src/Scenes/GameOverScene.h src/Sprites/Frog.cpp src/Sprites/Frog.h src/Sprites/Sprite.h src/Sprites/Car.cpp src/Sprites/Car.h src/UI/Menu.cpp src/UI/Menu.h src/UI/MenuItem.h src/GameState.cpp src/GameState.h)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="./assets/") # Set the asset path macro in release more
