add_library(kcm_watch_tablet MODULE kcm.cpp)
target_link_libraries(kcm_watch_tablet
        Qt5::Core
        Qt5::Gui
        KF5::CoreAddons
        KF5::ConfigCore
        KF5::ConfigWidgets
        )

# Todo choose better paths
install(TARGETS kcm_watch_tablet DESTINATION /usr/lib/x86_64-linux-gnu/qt5/plugins)
install(FILES watch_tablet.desktop DESTINATION ~/.local/share/kservices5/)
