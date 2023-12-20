
TEMPLATE = lib

CONFIG += static
CONFIG += precompile_header 
CONFIG += qt
CONFIG += moc

CONFIG(debug, debug|release){
        DESTDIR = $$OUT_PWD/lib.debug
}
else{
        DESTDIR = $$OUT_PWD/lib
}

TARGET = yri-db-runtime-verif_FOR_YERITH_ERP

QT += core
QT += gui
QT += widgets
QT += sql
QT += dbus
QT += network

MOC_DIR  = moc

OBJECTS_DIR = obj

PRECOMPILED_HEADER  = src/include/yri-db-runtime-verif-precompiled-header.hpp
 
HEADERS = src/include/yri-db-runtime-verif-definition-format-date-time.hpp \
			src/DBUS/yri-db-runtime-verif-DBUS-CLIENT-ADAPTOR.h \
			src/yri-db-runtime-verif-interface.h \
			src/utils/yri-db-runtime-verif-logger.hpp \
			src/utils/yri-db-runtime-verif-sqltable-model.hpp \
		  src/utils/yri-db-runtime-verif-utils.hpp \
			src/utils/yri-db-runtime-verif-database-table-column.hpp

SOURCES = src/include/yri-db-runtime-verif-definition-format-date-time.hpp \
			src/DBUS/yri-db-runtime-verif-DBUS-CLIENT-ADAPTOR.cpp \
			src/yri-db-runtime-verif-interface.cpp \
			src/utils/yri-db-runtime-verif-logger.cpp \
			src/utils/yri-db-runtime-verif-sqltable-model.cpp \
		  src/utils/yri-db-runtime-verif-utils.cpp \
			src/utils/yri-db-runtime-verif-database-table-column.cpp

