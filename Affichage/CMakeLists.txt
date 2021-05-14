cmake_minimum_required(VERSION 3.19)
project(Evalutation_vectorielle)


find_package(Qt5 5.0.1 REQUIRED COMPONENTS
            Core Gui Widgets
            )

set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


include_directories(Affichage/Headers)

add_executable(Evalutation_vectorielle
        src/addfunctwindow.ui
        src/addvectwindow.ui
        src/datawindow.ui
        src/display_4d.ui
        src/displaywindow.ui
        src/executewindow.ui
        src/loadwindow.ui
        src/mainwindow.ui
        src/savewindow.ui
        Headers/addfunctwindow.h
        Headers/addvectwindow.h
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
        src/addfunctwindow.cpp
        src/addvectwindow.cpp
        src/datawindow.cpp
        src/display_4d.cpp
        src/displaywindow.cpp
        src/executewindow.cpp
        src/gestion_ES.c
        src/liste_vecteurs.c
        src/loadwindow.cpp
        src/main.cpp
        src/mainwindow.cpp
        src/savewindow.cpp
        src/statistiques.c
        src/tinyexpr.c
        src/vecteurs.c)

target_link_libraries(${PROJECT_NAME}

        Qt5::Core Qt5::Gui Qt5::Widgets

        )