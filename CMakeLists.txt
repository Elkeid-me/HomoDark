# Copyright (C) 2022-2024 Elkeid-me
#
# This file is part of HomoDark.
#
# HomoDark is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# HomoDark is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with HomoDark.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.16)
set(CMAKE_BUILD_TYPE "Release")
project(HomoDark VERSION 2.0 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Path/To/Qt") # You should use your own Qt PATH.

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(PROJECT_SOURCES
    src/doc_state.cpp

    src/main_window.h
    src/main_window.cpp
    src/file_handler.cpp

    src/main.cpp

    src/rcs.qrc
)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::WebEngineWidgets)
