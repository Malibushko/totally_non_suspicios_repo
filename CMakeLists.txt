cmake_minimum_required(VERSION 3.14)

project(Testovoye LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set (SOURCES_ROOT ${CMAKE_SOURCE_DIR}/src)
set (PROJECT_HEADERS ${SOURCES_ROOT}/utility.h
                     ${SOURCES_ROOT}/contactlistmodel.h
                     ${SOURCES_ROOT}/contactlistprovider.h
                     ${SOURCES_ROOT}/filterproxymodel.h)
set(PROJECT_SOURCES
        ${SOURCES_ROOT}/contactlistmodel.cpp
        ${SOURCES_ROOT}/contactlistprovider.cpp
        ${SOURCES_ROOT}/filterproxymodel.cpp
        ${SOURCES_ROOT}/main.cpp
        qml.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Testovoye
        ${PROJECT_HEADERS} ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Testovoye SHARED
           ${PROJECT_HEADERS} ${PROJECT_SOURCES}
        )
    else()
        add_executable(Testovoye
          ${PROJECT_HEADERS} ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(Testovoye
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Testovoye
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)
