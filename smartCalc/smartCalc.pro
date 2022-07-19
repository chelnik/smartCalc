QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
#    ../C7_SmartCalc_v1.0-0/math/remove_circle.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_abs.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_acos.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_asin.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_atan.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_ceil.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_cos.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_exp.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_fabs.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_floor.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_fmod.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_log.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_pow.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_sin.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_sqrt.c \
#    ../C7_SmartCalc_v1.0-0/math/s21_tan.c \
#    ../C7_SmartCalc_v1.0-0/src/forFunc.c \
#    ../C7_SmartCalc_v1.0-0/src/listFunction.c \
#    ../C7_SmartCalc_v1.0-0/src/parser.c \
#    ../C7_SmartCalc_v1.0-0/src/printers.c \
#    ../C7_SmartCalc_v1.0-0/src/priorityFunction.c \
#    ../C7_SmartCalc_v1.0-0/src/supportFunction.c \
#    ../C7_SmartCalc_v1.0-0/src/validator.c \
../src/forFunc.c \
../src/listFunction.c \
../src/parser.c \
../src/printers.c \
../src/priorityFunction.c \
../src/supportFunction.c \
../src/validator.c \
    credit.cpp \
    deposit.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp


HEADERS += \
#    ../C7_SmartCalc_v1.0-0/math/math.h \
#    ../C7_SmartCalc_v1.0-0/math/s21_math.h \
#    ../C7_SmartCalc_v1.0-0/src/underfile.h \
../math/math.h \
../math/s21_math.h \
../src/underfile.h \
    credit.h \
    deposit.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    deposit.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
#    ../C7_SmartCalc_v1.0-0/src/Makefile \
#    ../C7_SmartCalc_v1.0-0/src/s21_math.a \
    ../src/Makefile \
    ../src/s21_math.a \


SUBDIRS += \

