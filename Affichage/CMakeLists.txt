cmake_minimum_required(VERSION 3.0)
project(Evalutation_vectorielle)


find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts
            )
find_package(Threads REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include_directories(Affichage/Headers)

add_executable(Evalutation_vectorielle
        Sources/addfunctwindow.ui
        Sources/addvectwindow.ui
        Sources/datawindow.ui
        Sources/display_4d.ui
        Sources/displaywindow.ui
        Sources/executewindow.ui
        Sources/loadwindow.ui
        Sources/mainwindow.ui
        Sources/savewindow.ui
        Headers/addfunctwindow.h
        Headers/addvectwindow.h
        Headers/chartview.h
        Headers/datawindow.h
        Headers/display_4d.h
        Headers/displaywindow.h
        Headers/executewindow.h
        Headers/gestion_ES.h
        Headers/liste_vecteurs.h
        Headers/loadwindow.h
        Headers/mainwindow.h
        Headers/savewindow.h
        Headers/statistiques.h
        Headers/tinyexpr.h
        Headers/vecteurs.h
        Sources/addfunctwindow.cpp
        Sources/addvectwindow.cpp
        Sources/chartview.cpp
        Sources/datawindow.cpp
        Sources/display_4d.cpp
        Sources/displaywindow.cpp
        Sources/executewindow.cpp
        Sources/gestion_ES.c
        Sources/liste_vecteurs.c
        Sources/loadwindow.cpp
        Sources/main.cpp
        Sources/mainwindow.cpp
        Sources/savewindow.cpp
        Sources/statistiques.c
        Sources/tinyexpr.c
        Sources/vecteurs.c)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Charts
        PRIVATE Threads::Threads)
