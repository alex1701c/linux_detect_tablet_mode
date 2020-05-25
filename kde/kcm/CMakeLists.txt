set(kcm_SRCS kcm.cpp)
ki18n_wrap_ui(kcm_SRCS kcm.ui)
add_library(kcm_watch_tablet MODULE ${kcm_SRCS})
target_link_libraries(kcm_watch_tablet
        Qt5::Core
        Qt5::Gui
        KF5::CoreAddons
        KF5::ConfigCore
        KF5::ConfigWidgets
        KF5::I18n
        KF5::WidgetsAddons
        )

install(TARGETS kcm_watch_tablet DESTINATION ${KDE_INSTALL_QTPLUGINDIR})
install(FILES kcm_watch_tablet.desktop DESTINATION ${KDE_INSTALL_KSERVICES5DIR})
