add_executable(${PROJECT_NAME} main.cpp tabletwatcher.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Core KF5::ConfigCore)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
