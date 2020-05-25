cmake_minimum_required(VERSION 3.0)

project(watch_tablet_qt)

set(QT_MIN_VERSION "5.9.0")
set(KF5_MIN_VERSION "5.44.0")

find_package(ECM REQUIRED NO_MODULE)
find_package(ECM ${KF5_MIN_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_MODULE_PATH})

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED CONFIG COMPONENTS Widgets Core)
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS Config ConfigWidgets Notifications I18n)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

add_subdirectory(core)
add_subdirectory(kcm)

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
