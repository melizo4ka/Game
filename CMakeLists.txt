cmake_minimum_required(VERSION 3.13)
project(Game)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Test/googletest-master)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} SFML/include headers src)

add_executable(Game
        src/main.cpp
        src/Engine.cpp
        src/Player.cpp
        src/Plant.cpp
        src/Fish.cpp
        src/Shop.cpp
        src/Pond.cpp
        src/House.cpp
        src/Object.cpp
        src/TileMap.cpp
        src/PlayerState.cpp
        src/StandingState.cpp
        src/WalkingState.cpp
        src/FishingState.cpp
        src/ShoppingState.cpp
        src/Menu.cpp
        src/SleepingState.cpp
        src/PlantingState.cpp
        src/ShopMenu.cpp
        src/HarvestingState.cpp)

add_executable(Test
        Test/PlayerTest.cpp
        Test/runAllTests.cpp
        Test/PlayerFixture.cpp
        src/Engine.cpp
        src/Player.cpp
        src/Plant.cpp
        src/Fish.cpp
        src/Shop.cpp
        src/Pond.cpp
        src/House.cpp
        src/Object.cpp
        src/TileMap.cpp
        src/PlayerState.cpp
        src/StandingState.cpp
        src/WalkingState.cpp
        src/FishingState.cpp
        src/ShoppingState.cpp
        src/Menu.cpp
        src/SleepingState.cpp
        src/PlantingState.cpp
        src/ShopMenu.cpp
        src/HarvestingState.cpp)

target_link_libraries(Test gtest gtest_main)

include_directories(headers SFML/include)

#set SFML files
set(SFML_ROOT SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(Test ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
