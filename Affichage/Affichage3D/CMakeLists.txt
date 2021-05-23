cmake_minimum_required(VERSION 3.0)
project(Affichage3D)

find_package(PythonInterp 3.8 REQUIRED)
find_package(PythonLibs 3.8 REQUIRED)
find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(Affichage/Headers ${PYTHON_INCLUDE_DIRS})

find_package(Threads REQUIRED)



set(CMAKE_CXX_STANDARD 14)
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
        )
