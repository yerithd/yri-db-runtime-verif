/*
 * yri-db-runtime-verif-CONFIG.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#include "yri-db-runtime-verif-CONFIG.hpp"


//##################### QMAINWINDOW RELATED IMPORTS #####################

#include "src/windows/yri-db-runtime-verif-windows.hpp"

//#######################################################################


#include "src/utils/yri-db-runtime-verif-database.hpp"

#include "src/utils/yri-db-runtime-verif-utils.hpp"


#include <QtCore/QDebug>



QString YRI_DB_RUNTIME_VERIF_Config::_db_type("");

QString YRI_DB_RUNTIME_VERIF_Config::_db_name("");

QString YRI_DB_RUNTIME_VERIF_Config::_db_ip_address("");

QString YRI_DB_RUNTIME_VERIF_Config::_db_user_name("");

QString YRI_DB_RUNTIME_VERIF_Config::_db_user_pwd("");

QString YRI_DB_RUNTIME_VERIF_Config::_db_connection_options("");


QString YRI_DB_RUNTIME_VERIF_Config::temporaryFilesDir("/tmp");


QString YRI_DB_RUNTIME_VERIF_Config::pathToLatexSystemRootFolder("/usr/bin");


const QString YRI_DB_RUNTIME_VERIF_Config::__pathToPdfReader("/usr/bin/evince");

QString YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader("/usr/bin/evince");


QString YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_CONFIGURATION_FILE_SEPARATION_OPERATOR("=");


QString YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE("");

QString YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_TEMPORARY_FOLDER("/tmp");

QString YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_SYSTEM_dbus_service_name("yri.db-runtime.verif");

QString YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER("/tmp");


YRIDBRUNTIMEVERIF_Windows *YRI_DB_RUNTIME_VERIF_Config::ALL_WINDOWS(0);



void YRI_DB_RUNTIME_VERIF_Config::init_YRI_DB_RUNTIME_VERIF_Config(QString initCfg)
{
    QFile file(initCfg);

    if (!file.open(QFile::ReadOnly))
    {
        return;
    }

    QTextStream init_cfg(&file);
    QString line;
    QStringList list;

    do
    {
        line = init_cfg.readLine();

        list = line.split(YRI_DB_RUNTIME_VERIF_CONFIGURATION_FILE_SEPARATION_OPERATOR);
        //qDebug() << "++ line: " << line << "\n";

        if ("db_type" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::_db_type = list.at(1).trimmed();
            // qDebug() << "++ db_type = " << db_type << "\n";
        }
        if ("db_name" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::_db_name = list.at(1).trimmed();

            //qDebug() << "++ db_name = " << db_name << "\n";
        }
        else if ("db_ip_address" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::_db_ip_address = list.at(1).trimmed();
            //qDebug() << "++ db_ip_address = " << db_ip_address << "\n";
        }
        else if ("db_user_name" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::_db_user_name = list.at(1).trimmed();
            //qDebug() << "++ db_user_name = " << db_user_name << "\n";
        }
        else if ("db_user_pwd" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::_db_user_pwd = list.at(1).trimmed();
            //qDebug() << "++ db_user_pwd = " << db_user_pwd << "\n";
        }
        else if ("db_connection_options" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::_db_connection_options = list.at(1).trimmed();
            //qDebug() << "++ db_connection_options = " << db_connection_options << "\n";
        }
        else if ("parameter_full_path_pdf_reader" == list.at(0))
        {
            YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader = list.at(1).trimmed();
            //qDebug() << "++ parameter_full_path_pdf_reader = "
            //         <<  YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader << "\n";
        }
    }
    while (!line.isNull());
}


void YRI_DB_RUNTIME_VERIF_Config::save_YRI_DB_RUNTIME_VERIF_Config()
{
    QFile file (YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);

    QDEBUG_STRINGS_OUTPUT_2("YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE",
                            YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);

    if (!file.open(QFile::WriteOnly))
    {
        return;
    }

    QTextStream textStream(&file);

    textStream << QString("parameter_full_path_pdf_reader=%1\n")
                    .arg(YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader);

    file.close();
}
