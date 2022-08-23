cmake_minimum_required(VERSION 3.16)

project(MinimalDOCK VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(KDDockWidgets-qt6 CONFIG)

qt_add_executable(${PROJECT_NAME}
    main.cpp
)

qt_add_qml_module(${PROJECT_NAME}
    URI untitled
    VERSION 1.0
    QML_FILES main.qml Another.qml Guest.qml Guest1.qml Guest2.qml Guest3.qml
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Quick KDAB::kddockwidgets)
