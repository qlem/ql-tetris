#!/bin/bash

INSTALL_DIR=/opt/ql-tetris
DESKTOP_ENTRY_DIR=$HOME/.local/share/applications
DESKTOP_ENTRY=./ql-tetris.desktop

# output color
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

# uninstall files
sudo rm -r $INSTALL_DIR
if [ ! $? -eq 0 ]; then
    echo -e $RED'Cannot uninstall files'$NC
    exit 1
fi

# uninstall destop entry
sudo rm $DESKTOP_ENTRY_DIR/$DESKTOP_ENTRY
if [ ! $? -eq 0 ]; then
    echo -e $RED'Cannot uninstall desktop entry'$NC
    exit 1
fi

echo -e $BLUE'Uninstall done'$NC
