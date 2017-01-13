QT += core
QT -= gui

CONFIG += c++11

TARGET = Date_Class
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    date.cpp

HEADERS += \
    date.h
