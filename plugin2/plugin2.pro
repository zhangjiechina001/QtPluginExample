#! [0]
TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../echowindow
HEADERS         = plugin2.h
SOURCES         = plugin2.cpp
TARGET          = $$qtLibraryTarget(plugin2)
DESTDIR         = ../plugins
#! [0]

EXAMPLE_FILES = echoplugin.json

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tools/echoplugin/plugins
INSTALLS += target

CONFIG += install_ok  # Do not cargo-cult this!
