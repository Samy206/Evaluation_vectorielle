cmake_minimum_required(VERSION 3.20)
project(test)

find_package(PythonInterp 3.8 EXACT)
find_package(PythonLibs 3.8 EXACT)
find_package(Python 3.8 COMPONENTS Interpreter Development EXACT)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(Affichage/Headers ${PYTHON_INCLUDE_DIRS})

find_package(Threads REQUIRED)


set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)


add_executable(${PROJECT_NAME} main.c 
      appel_API.h
      appel_API.c
      )

target_link_libraries(${PROJECT_NAME}
        PRIVATE 
        ${CMAKE_DL_LIBS}
        Threads::Threads
        ${SOURCE_FILES}
        ${PYTHON_LIBRARIES}
        rt)
