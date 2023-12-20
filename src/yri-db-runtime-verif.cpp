/*
 * yri-db-runtime-verif.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */


#include "YRIruntimeverification_adaptor.h"


//############ USER'S RUNTIME MONITOR HEADER RELATED IMPORTS ############

#include "src/include/yri-db-runtime-verif-MONITOR.hpp"


//#######################################################################

#include "src/utils/yri-db-runtime-verif-CONFIG.hpp"

#include "src/utils/yri-db-runtime-verif-database.hpp"

#include "src/utils/yri-db-runtime-verif-utils.hpp"


#include <QtCore/QVector>
#include <QtCore/QList>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QCryptographicHash>

#include <QtDBus/QDBusServiceWatcher>

#include <QtNetwork/QNetworkInterface>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>

#include <unistd.h>



//##################### QMAINWINDOW RELATED IMPORTS #####################

#include "src/windows/yri-db-runtime-verif-windows.hpp"

//#######################################################################



#include "utils/yri-db-runtime-verif-logger.hpp"


const QString MYSQL("MySQL");


class YRI_DB_RUNTIME_VERIF_ALERT_PERIOD_TIME;

QString text_init_cfg("");


int main(int argc, char *argv[])
{
    qDebug() << "yri-db-runtime-verif | yri-db-runtime-verif.cpp | main. started"
             << "\n";


    QApplication app(argc, argv);


    //########################### GRAPHICAL USER INTERFACE SETUP CODE ###########################
    QApplication::setWindowIcon(QIcon(":yri-db-runtime-verif-images/LOGO-icon.png"));

    QApplication::setStyle(QStyleFactory::create("cde"));


    YRDBRUNTIMEVERIF_Windows all_windows(app.desktop());

    all_windows.createAll_YRDBRUNTIMEVERIF_Windows();

    YRI_DB_RUNTIME_VERIF_Config::SET_ALL_WINDOWS_instance(&all_windows);

    QToolBar &atoolBar = all_windows._yrdbruntimeverif_main_Window->get_tool_bar();
    //############################################################################################



    YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE =
        QString(std::getenv("YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE")).trimmed();


    YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER =
        QString(std::getenv("YRI_DB_RUNTIME_VERIF_HOME_FOLDER")).trimmed();




    qDebug() << "yri-db-runtime-verif.cpp | main | YRI-DB-RUNTIME-VERIF HOME FOLDER: "
             << YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER;


    if (YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER.isEmpty())
    {
        QString errMsg
        	("Environment variable YRI_DB_RUNTIME_VERIF_HOME_FOLDER isn't set ! \n\n");

        errMsg.append("PLEASE TRY logging out AND THEN logging in. \n\n"
        			  "In case yri-db-runtime-verif is still not functional,\n"
        			  "please contact DR.-ING. DIPL.-INF. XAVIER NOUNDOU: "
                      "'yerith.d@gmail.com'.");

        QMessageBox::critical(&atoolBar,
        					  "yri-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg),
							  QMessageBox::Cancel);
    }


    QString logFileName(YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER);

    logFileName.append("/yri-db-runtime-verif.log");

    qDebug() << "yri-db-runtime-verif.cpp | main | yri-db-runtime-verif home folder: "
    		 << YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER;



    YRI_DB_RUNTIME_VERIF_Utils::setLogFileName(logFileName);

    qDebug() << "yri-db-runtime-verif.cpp | main | log file name: "
             << logFileName;

    YRI_DB_RUNTIME_VERIF_Logger logger(YRI_DB_RUNTIME_VERIF_Utils::getLogFileName());



    qDebug() << "yri-db-runtime-verif.cpp | main | PROPERTY FILE YRI-DB-RUNTIME-VERIF.properties absolute file path: "
             << YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE
             << "\n";

    YRI_DB_RUNTIME_VERIF_Config::init_YRI_DB_RUNTIME_VERIF_Config
            (YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);



    QString initCfg(QString("%1/%2")
    				.arg(YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_HOME_FOLDER,
    					 "yri-db-runtime-verif-database-connection.properties"));

    qDebug() << "yri-db-runtime-verif.cpp | main | yri-db-runtime-verif-database-connection.properties absolute file path: "
             << initCfg
             << "\n";



    YRI_DB_RUNTIME_VERIF_Config::init_YRI_DB_RUNTIME_VERIF_Config(initCfg);

    YRI_DB_RUNTIME_VERIF_Database database(YRI_DB_RUNTIME_VERIF_Config::_db_type);


    //qDebug() << "++ database.toString(): " << database.toString();

    text_init_cfg.append(database.db_type());

    if (!database.open())
    {
        QString errMsg(QObject::tr("yri-db-runtime-verif couldn't connect to database!\n\n"));

        errMsg.append(QObject::tr("DATABASE SERVER: %1.\n\n"
                              	  "Last error message (%2).\n\n"
                              	  "Please contact PROF. DR.-ING. DIPL.-INF. XAVIER NOUNDOU\n"
                              	  "\t(yerith.d@gmail.com)\n")
        				.arg(database.db_ip_address(),
        					 database.lastError().text()));

        logger.log("main",
                   QString("last database (host: %1) error: %2")
				   	   .arg(database.db_ip_address(),
				   			database.lastError().text()));

        QMessageBox::critical(&atoolBar,
                              "yri-db-runtime-verif",
                              FROM_UTF8_STRING(errMsg),
							  QMessageBox::Cancel);
    }

    //qDebug() << "yri-db-runtime-verif.cpp | main | Database connection could be opened successfully";
    //logger << "[yri-db-runtime-verif.cpp][main] Database connection could be opened successfully"
    //         << "\n";



    QFile file_EN_template_EVENT_LOG_TEX(YRI_DB_RUNTIME_VERIF_Utils::FILE_YRI_DB_RUNTIME_VERIF_EVENT_LOG_PDF_TEMPLATE_EN);

    YRI_DB_RUNTIME_VERIF_Utils::YEROTH_READ_FILE_CONTENT(file_EN_template_EVENT_LOG_TEX,
                                                        YRI_DB_RUNTIME_VERIF_Utils::EN_template_EVENT_LOG_TEX_document);




    //##################### RUNTIME MONITOR DECLARATION INSTANTIATION #####################

    QVector<YRI_DB_RUNTIME_VERIF_Monitor *> user_defined_Runtime_Monitors;

    
    //######################################################################################



    QDBusConnection connection = QDBusConnection::systemBus();

    QString systemYerothService =
        YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_SYSTEM_dbus_service_name;



    QString current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus;

    YRI_DB_RUNTIME_VERIF_Monitor *A_USER_DEFINED_RT_MONITOR = 0;


    bool couldRegisterService = false;

    bool couldRegisterObject = false;


    int rt_monitor_Vector_SIZE = user_defined_Runtime_Monitors.size();


    for (uint k = 0; k < rt_monitor_Vector_SIZE; ++k)
    {
        A_USER_DEFINED_RT_MONITOR = user_defined_Runtime_Monitors.at(k);

        if (0 != A_USER_DEFINED_RT_MONITOR)
        {
            current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus =
                QString("/%1")
                 .arg(A_USER_DEFINED_RT_MONITOR->get_RUNTIME_MONITOR_NAME());

            if (!connection.registerObject(current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus,
                                           A_USER_DEFINED_RT_MONITOR))
            {
                QDEBUG_STRINGS_OUTPUT_1(QString("Could not register '%1' object")
                                        .arg(current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus));

                QDEBUG_STRINGS_OUTPUT_1(QString("Last error: %1")
                                        .arg(QDBusError::errorString(connection.lastError().type())));

                                        couldRegisterObject = false;
            }
            else
            {
                all_windows._yrdbruntimeverif_main_Window
                    ->user_defined_Runtime_Monitors_NAME__TO__RUNTIME_INSTANCES
                        .insert(A_USER_DEFINED_RT_MONITOR->get_RUNTIME_MONITOR_NAME(),
                                 A_USER_DEFINED_RT_MONITOR);


                QDEBUG_STRINGS_OUTPUT_1(QString("Could register '%1' object")
                                        .arg(current_RT_Monitor_OBJECT_ID_for_query_RPC_Dbus));

                couldRegisterObject = true;
            }
        }
    }


    // REGISTERING DBUS SERVICE ON system bus !

    if (!connection.registerService(systemYerothService))
    {
        QDEBUG_STRINGS_OUTPUT_1(QString("Could not Register '%1' SERVICE")
                                .arg(systemYerothService));

        QDEBUG_STRINGS_OUTPUT_1(QString("Last error: %1")
                                .arg(connection.lastError().message()));

        couldRegisterService = false;
    }
    else
    {
        QDEBUG_STRINGS_OUTPUT_1(QString("Could register '%1' SERVICE")
                                .arg(systemYerothService));

        couldRegisterService = true;
    }



    //########################### GRAPHICAL USER INTERFACE STATUS CODE ###########################
    if (couldRegisterService && couldRegisterObject)
    {
    	all_windows._yrdbruntimeverif_main_Window
			->set_connection_DBUS_status
				(QString("YRI-DB-RUNTIME-VERIF: this console is registered to the system d-bus as service: '%1'.")
					.arg(systemYerothService));

        qDebug() << "STARTING YRI-DB-RUNTIME-VERIF !";
    }
    else
    {
    	all_windows._yrdbruntimeverif_main_Window
			->set_connection_DBUS_status
				(QObject::tr("YRI-DB-RUNTIME-VERIF: this console IS NOT REGISTERED TO SYSTEM D-BUS."),
				 true);
    }
    //############################################################################################



    return app.exec();
}
