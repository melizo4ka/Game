cmake_minimum_required(VERSION 3.13)
project(Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game src/main.cpp src/Engine.cpp headers/Engine.h src/Player.cpp headers/Player.h src/Plant.cpp headers/Plant.h src/Farm.cpp headers/Farm.h src/Fish.cpp headers/Fish.h src/Shop.cpp headers/Shop.h src/Pond.cpp headers/Pond.h src/House.cpp headers/House.h src/Object.cpp headers/Object.h src/TileMap.cpp headers/TileMap.h src/PlayerState.cpp headers/PlayerState.h src/StandingState.cpp headers/StandingState.h src/WalkingState.cpp headers/WalkingState.h src/FishingState.cpp headers/FishingState.h src/ShoppingState.cpp headers/ShoppingState.h src/Menu.cpp headers/Menu.h src/SleepingState.cpp headers/SleepingState.h headers/testCollision.cpp src/PlantingState.cpp headers/PlantingState.h src/ShopMenu.cpp headers/ShopMenu.h src/HarvestingState.cpp headers/HarvestingState.h)

include_directories(headers /usr/include c:/SFML/include)

add_subdirectory(headers)
add_subdirectory(src)
add_subdirectory(Google_tests)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
