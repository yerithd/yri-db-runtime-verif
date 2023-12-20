/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a src/YRIruntimeverification_adaptor yri.db-runtime.verif.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "src/YRIruntimeverification_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class IYRIruntimeverificationAdaptor
 */

IYRIruntimeverificationAdaptor::IYRIruntimeverificationAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

IYRIruntimeverificationAdaptor::~IYRIruntimeverificationAdaptor()
{
    // destructor
}

bool IYRIruntimeverificationAdaptor::YRI_slot_refresh_DELETE_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRIruntimeverification.YRI_slot_refresh_DELETE_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YRI_slot_refresh_DELETE_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

bool IYRIruntimeverificationAdaptor::YRI_slot_refresh_INSERT_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRIruntimeverification.YRI_slot_refresh_INSERT_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YRI_slot_refresh_INSERT_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

bool IYRIruntimeverificationAdaptor::YRI_slot_refresh_SELECT_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRIruntimeverification.YRI_slot_refresh_SELECT_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YRI_slot_refresh_SELECT_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

bool IYRIruntimeverificationAdaptor::YRI_slot_refresh_UPDATE_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRIruntimeverification.YRI_slot_refresh_UPDATE_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YRI_slot_refresh_UPDATE_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

