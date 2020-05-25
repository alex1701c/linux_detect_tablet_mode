cmake_minimum_required(VERSION 3.0)

project(watch_tablet_qt)

set(QT_MIN_VERSION "5.2")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(ECM REQUIRED NO_MODULE)
find_package(Qt5Core)
find_package(KF5Config)

add_subdirectory(core)

# CPack configuration
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Test package")
set(CPACK_PACKAGE_NAME ${CMAKE_PROJECT_NAME})
set(CPACK_PACKAGE_VERSION "0.0.1")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "%{AUTHOR}")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt5core5a (>= 5.2)")

set(CPACK_RPM_PACKAGE_ARCHITECTURE "x86_64")
set(CPACK_RPM_PACKAGE_REQUIRES "qt5-qtbase >= 5.2")

INCLUDE(CPack)
