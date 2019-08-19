#!/bin/bash

INSTALL_DIR=/opt/ql-tetris
ICON=./icon.png
LIB_DIR=./lib
SOUND_DIR=./sounds
SHAPE_DIR=./tetrimino
BIN=./bin/tetris
RUN=./bin/run.sh
DESKTOP_ENTRY_DIR=$HOME/.local/share/applications
DESKTOP_ENTRY=./ql-tetris.desktop

# output color
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

# create install dir
if [ ! -d "$INSTALL_DIR" ]; then
    sudo mkdir $INSTALL_DIR
    if [ ! $? -eq 0 ]; then
        echo -e $RED'Cannot create install directory'$NC
        exit 1
    fi
fi

# install files / dirs
sudo cp -r $ICON $LIB_DIR $SOUND_DIR $SHAPE_DIR $BIN $RUN $INSTALL_DIR
if [ ! $? -eq 0 ]; then
    echo -e $RED'Cannot install files and directories'$NC
    exit 1
fi

# install desktop entry
cp -r $DESKTOP_ENTRY $DESKTOP_ENTRY_DIR
if [ ! $? -eq 0 ]; then
    echo -e $RED'Cannot install desktop entry'$NC
    exit 1
fi

echo -e $BLUE'Install done'$NC
