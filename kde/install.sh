#!/bin/bash

# Exit if something fails
set -e

if [[ $PWD != *"/linux_detect_tablet_mode/kde" ]];then
    git clone https://github.com/alex1701c/linux_detect_tablet_mode
    cd linux_detect_tablet_mode/kde
fi

mkdir -p build
cd build

cmake -DKDE_INSTALL_QTPLUGINDIR=`kf5-config --qt-plugins` -DCMAKE_BUILD_TYPE=Release  ..
make -j$(nproc)

sudo make install

ln -s /usr/local/bin/watch_tablet_qt ~/.config/autostart-scripts/

echo "Installation finished !";