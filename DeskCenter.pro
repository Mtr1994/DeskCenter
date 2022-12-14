QT       += core gui webenginewidgets webchannel

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

lessThan(QT_MAJOR_VERSION, 6): win32: QMAKE_CXXFLAGS += -execution-charset:utf-8

# make the application have authority of running on Ubuntu, and I do not know why it works
unix: QMAKE_LFLAGS += -no-pie

# Qt 5.14 VERSION can only contains numbers, no any others type of character please
# please do not put 0 before any version number, because this will cause a warnning on Qt 5.14
win32:  VERSION = 22.9.28.1140                # major.minor.patch.build
else:   VERSION = 22.9.28                    # major.minor.patch

QMAKE_TARGET_COPYRIGHT = Mtr1994 create at 1004

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# 禁用 QDebug 输出调试i信息
#DEFINES += QT_NO_DEBUG_OUTPUT


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = ../bin

SOURCES += \
    Channel/jscontext.cpp \
    Control/FlatToolButton/flattoolbutton.cpp \
    Public/appsignal.cpp \
    Widget/Base/animationwidgetbase.cpp \
    Widget/Contents/widgethomepage.cpp \
    Widget/widgetappmenu.cpp \
    Widget/widgetcontentpages.cpp \
    Widget/Contents/widgetstatistics.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Channel/jscontext.h \
    Control/FlatToolButton/flattoolbutton.h \
    Public/appsignal.h \
    Public/tableitemdelegate.h \
    Public/treeitemdelegate.h \
    Widget/Base/animationwidgetbase.h \
    Widget/Contents/widgethomepage.h \
    Widget/widgetappmenu.h \
    Widget/widgetcontentpages.h \
    Widget/Contents/widgetstatistics.h \
    mainwindow.h

FORMS += \
    Widget/Contents/widgethomepage.ui \
    Widget/widgetappmenu.ui \
    Widget/widgetcontentpages.ui \
    Widget/Contents/widgetstatistics.ui \
    mainwindow.ui

TRANSLATIONS += \
    Translate_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = ./Resource/icon/icon.ico

RESOURCES += \
    res.qrc

#0x0800代表和系统当前语言一致
RC_LANG = 0x0800
