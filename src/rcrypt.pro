TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ResECB1024.cpp \
        ResECB1536.cpp \
        ResECB512.cpp \
        Sha256.cpp \
        main.cpp

HEADERS += \
    Hex.h \
    ResECB1024.h \
    ResECB1536.h \
    ResECB512.h \
    Sha256.h \
    _private/ResDeclarations.h \
    rcrypt.h
