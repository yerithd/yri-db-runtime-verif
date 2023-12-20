/*
* yri_sd_runtime_verif_language_EXAMPLE_realcase.cpp
*
*/

#include "yri_sd_runtime_verif_language_EXAMPLE_realcase.hpp"


#include <QtSql/QSqlRecord>

#include <QtSql/QSqlQuery>

#include <QtSql/QSqlError>


#include "utils/yri-db-runtime-verif-logger.hpp"

#include "yri_sd_runtime_verif/YRI_CPP_MONITOR.hpp"
#include "yri_sd_runtime_verif/YRI_CPP_MONITOR_STATE.hpp"
#include "yri_sd_runtime_verif/YRI_CPP_MONITOR_EDGE.hpp"


void yri_sd_runtime_verif_language_EXAMPLE_realcase::YRI_CALL_BACK_final_state(YRI_CPP_MONITOR 			*a_runtime_monitor,
        YRI_CPP_MONITOR_EDGE 	*an_EDGE_leading_TO_error_FINAL_state)
{
    if (0 != a_runtime_monitor)
    {
        ( (YRI_DB_RUNTIME_VERIF_Monitor *) a_runtime_monitor)
        ->YRI_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION(an_EDGE_leading_TO_error_FINAL_state);
    }
}



yri_sd_runtime_verif_language_EXAMPLE_realcase::yri_sd_runtime_verif_language_EXAMPLE_realcase()
    :YRI_DB_RUNTIME_VERIF_Monitor()
{
    set_RUNTIME_MONITOR_NAME("yri_sd_runtime_verif_language_EXAMPLE_realcase");


    YRI_CPP_MONITOR_EDGE *a_last_edge_1 = create_yri_monitor_edge ("d", "e");
    a_last_edge_1->get_SOURCE_STATE()->set_START_STATE(*this, true);
    a_last_edge_1->get_TARGET_STATE()->set_ERROR_STATE(true);
    a_last_edge_1->get_SOURCE_STATE()->set_PRE_CONDITION_notIN("YRI_ASSET", "departements_produits.nom_departement_produit");
    a_last_edge_1->get_TARGET_STATE()->set_POST_CONDITION_IN("YRI_ASSET", "stocks.nom_departement_produit");


    YRI_CPP_notinset_inset_TRACE_expression *a_last_edge_1_GUARDED_CONDITION
        = new YRI_CPP_notinset_inset_TRACE_expression(true,
                "'DELETE.departements_produits.YRI_ASSET'",
                "d");

    a_last_edge_1->set_GUARDED_CONDITION(a_last_edge_1_GUARDED_CONDITION);


    YRI_CPP_MONITOR_EVENT *a_last_edge_event_1 = a_last_edge_1->set_EDGE_EVENT("'SELECT.departements_produits'");

    //print_TO_dot_FILE();

    YRI_register_set_final_state_CALLBACK_FUNCTION(&YRI_CALL_BACK_final_state);
}


yri_sd_runtime_verif_language_EXAMPLE_realcase::yri_sd_runtime_verif_language_EXAMPLE_realcase(YRI_DB_RUNTIME_VERIF_Logger *logger)
    :YRI_DB_RUNTIME_VERIF_Monitor(logger)
{
    set_RUNTIME_MONITOR_NAME("yri_sd_runtime_verif_language_EXAMPLE_realcase");


    YRI_CPP_MONITOR_EDGE *a_last_edge_1 = create_yri_monitor_edge ("d", "e");
    a_last_edge_1->get_SOURCE_STATE()->set_START_STATE(*this, true);
    a_last_edge_1->get_TARGET_STATE()->set_ERROR_STATE(true);
    a_last_edge_1->get_SOURCE_STATE()->set_PRE_CONDITION_notIN("YRI_ASSET", "departements_produits.nom_departement_produit");
    a_last_edge_1->get_TARGET_STATE()->set_POST_CONDITION_IN("YRI_ASSET", "stocks.nom_departement_produit");


    YRI_CPP_notinset_inset_TRACE_expression *a_last_edge_1_GUARDED_CONDITION
        = new YRI_CPP_notinset_inset_TRACE_expression(true,
                "'DELETE.departements_produits.YRI_ASSET'",
                "d");

    a_last_edge_1->set_GUARDED_CONDITION(a_last_edge_1_GUARDED_CONDITION);


    YRI_CPP_MONITOR_EVENT *a_last_edge_event_1 = a_last_edge_1->set_EDGE_EVENT("'SELECT.departements_produits'");

    //print_TO_dot_FILE();

    YRI_register_set_final_state_CALLBACK_FUNCTION(&YRI_CALL_BACK_final_state);
}


/**
* THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
* LOGIC CHECK AFTER A STATE EVENT (or system event)
* could be achieved by the runtime monitor system !
*
* A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
* METHOD !
*/
bool yri_sd_runtime_verif_language_EXAMPLE_realcase::DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(
    QString sql_table_ADDED_with_file_AND_line_number,
    uint	sql_record_qty_MODIFIED,
    YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER cur_SQL_command
    /* = YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UNDEFINED_SQL_COMMAND */)
{
    QStringList sql_table_ADDED_with_file_AND_line_number_LIST =
        sql_table_ADDED_with_file_AND_line_number.split(";", Qt::KeepEmptyParts);

    QString sql_table_name = sql_table_ADDED_with_file_AND_line_number_LIST.at(0);

    QString CPP_FILE_NAME = sql_table_ADDED_with_file_AND_line_number_LIST.at(1);

    QString cpp_line_number = sql_table_ADDED_with_file_AND_line_number_LIST.at(2);


    qDebug() << "\t "
             << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]").
             arg(YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
                 value(cur_SQL_command), sql_table_name,
                 QString::number(cur_SQL_command),
                 QString::number(sql_record_qty_MODIFIED), CPP_FILE_NAME,
                 cpp_line_number);


    switch(cur_SQL_command)
    {
    case YRI_CPP_UTILS::INSERT:
        break;

    case YRI_CPP_UTILS::SELECT:

        if (YRI_DB_RUNTIME_VERIF_Utils::isEqualsCaseInsensitive(sql_table_name, "departements_produits"))
        {
            return YRI_SQL_SELECT_departements_produits();
        }

        break;

    case YRI_CPP_UTILS::UPDATE:
        break;

    case YRI_CPP_UTILS::DELETE:
        break;

    default:

        break;
    }

    return false;
}


bool yri_sd_runtime_verif_language_EXAMPLE_realcase::YRI_SQL_SELECT_departements_produits()
{
    return YRI_trigger_an_edge_event("'SELECT.departements_produits'");
}

