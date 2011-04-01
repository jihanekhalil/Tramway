project(tramway) # the name of your project

cmake_minimum_required(VERSION 2.4.0)

find_package(Qt4 REQUIRED) 

include(${QT_USE_FILE})

set(project_SRCS
    ligne.cpp
    main.cpp
    mainwindow.cpp
    pointsynchronisation.cpp
    rame.cpp
    station.cpp
    thread.cpp
    feux.cpp
    obstacle.cpp
    passager.cpp
    porte.cpp
    element.cpp
    signals.cpp
    gestionsignal.cpp
    params.h
)

SET(project_MOC_HDRS    
    mainwindow.h    
)

QT4_WRAP_CPP(project_MOC_SRCS ${project_MOC_HDRS})

SET(project_UIS

    mainwindow.ui

)

QT4_WRAP_UI(project_UIS_H ${project_UIS})

include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

qt4_automoc(${project_SRCS})

add_executable(tramway ${project_SRCS} ${project_MOC_SRCS} ${project_UIS_H} )

target_link_libraries(tramway ${QT_LIBRARIES})
