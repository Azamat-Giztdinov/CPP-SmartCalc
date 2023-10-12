QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/creditcontroller.cc \
    ../controller/smartcontroller.cc \
    ../model/creditcalcmod.cc \
    ../model/smartcalcmod.cc \
    creditcalc.cpp \
    main.cpp \
    qcustomplot.cpp \
    smartcalc.cpp

HEADERS += \
    ../controller/creditcontroller.h \
    ../controller/smartcontroller.h \
    ../model/creditcalcmod.h \
    ../model/smartcalcmod.h \
    creditcalc.h \
    qcustomplot.h \
    smartcalc.h

FORMS += \
    creditcalc.ui \
    smartcalc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
