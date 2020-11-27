# CMakeList.txt: проект CMake для 20201127; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

find_package(Curses)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (20201127 "20201127.cpp")
include_directories(20201127 "${CURSES_INCLUDE_DIRS}")
target_link_libraries(20201127 $"{CURSES_LIBRARIES}")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
