TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ball.cpp \
        game.cpp \
        main.cpp \
        menue.cpp \
        paddle.cpp \
        play.cpp

unix:!macx: LIBS += -L$$PWD/../../../usr/local/lib/SFML-2.5.1/lib/ -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio

INCLUDEPATH += $$PWD/../../../usr/local/lib/SFML-2.5.1/include
DEPENDPATH += $$PWD/../../../usr/local/lib/SFML-2.5.1/include

HEADERS += \
    ball.h \
    game.h \
    gamestate.h \
    menue.h \
    paddle.h \
    play.h
