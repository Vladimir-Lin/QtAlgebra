NAME         = QtAlgebra
TARGET       = $${NAME}

QT           = core
QT          -= gui
CONFIG(static,static|shared) {
# static version does not support Qt Script now
QT          -= script
} else {
QT          += script
}
QT          += network
QT          += sql
QT          += Essentials
QT          += QtGMP
QT          += QtGSL

load(qt_module)

INCLUDEPATH += $${PWD}/../../include/$${NAME}

HEADERS     += $${PWD}/../../include/$${NAME}/qtalgebra.h

SOURCES     += $${PWD}/nAlgebraElement.cpp
SOURCES     += $${PWD}/nAlgebraVariable.cpp

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)

TRNAME       = $${NAME}
include ($${PWD}/../../Translations.pri)
