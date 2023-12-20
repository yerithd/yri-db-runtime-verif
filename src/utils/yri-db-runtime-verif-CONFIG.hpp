/*
 * yri-db-runtime-verif-CONFIG.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_DB_RUNTIME_VERIF_CONFIG_HPP_
#define _YRI_DB_RUNTIME_VERIF_CONFIG_HPP_


#include <QtCore/QDate>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>



class YRDBRUNTIMEVERIF_Windows;

class YRI_DB_RUNTIME_VERIF_Database;


class YRI_DB_RUNTIME_VERIF_Config
{

public:

    inline static void SET_ALL_WINDOWS_instance(YRDBRUNTIMEVERIF_Windows *WINDOWS)
    {
    	ALL_WINDOWS = WINDOWS;
    }

    inline static YRDBRUNTIMEVERIF_Windows *GET_ALL_WINDOWS_instance()
    {
    	return ALL_WINDOWS;
    }



    inline static QString pathToPs2Pdf()
    {
        return QString("%1/ps2pdf").arg(pathToLatexSystemRootFolder);
    }

    inline static QString pathToDvips()
    {
        return QString("%1/dvips").arg(pathToLatexSystemRootFolder);
    }

    inline static QString pathToLatex()
    {
        return QString("%1/latex").arg(pathToLatexSystemRootFolder);
    }

    inline static QString pathToPdfLatex()
    {
        return QString("%1/pdflatex").arg(pathToLatexSystemRootFolder);
    }

    inline static QString pathToLualatex()
    {
        return QString("%1/lualatex").arg(pathToLatexSystemRootFolder);
    }



    static void init_YRI_DB_RUNTIME_VERIF_Config(QString initCfg);

    static void save_YRI_DB_RUNTIME_VERIF_Config();



    static QString _db_type;

    static QString _db_name;

    static QString _db_ip_address;

    static QString _db_user_name;

    static QString _db_user_pwd;

    static QString _db_connection_options;


    static QString temporaryFilesDir;


    static QString pathToLatexSystemRootFolder;


    static const QString __pathToPdfReader;

    static QString pathToPdfReader;


    static QString YRI_DB_RUNTIME_VERIF_CONFIGURATION_FILE_SEPARATION_OPERATOR;


    static QString YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE;

    static QString YRI_DB_RUNTIME_VERIF_TEMPORARY_FOLDER;

    static QString YRI_DB_RUNTIME_VERIF_SYSTEM_dbus_service_name;

    static QString YRI_DB_RUNTIME_VERIF_HOME_FOLDER;


    static YRI_DB_RUNTIME_VERIF_Database *_Database__SUT__for__verification_success_Notification;

    static YRDBRUNTIMEVERIF_Windows *ALL_WINDOWS;
};

#endif /* _YRI_DB_RUNTIME_VERIF_CONFIG_HPP_ */
