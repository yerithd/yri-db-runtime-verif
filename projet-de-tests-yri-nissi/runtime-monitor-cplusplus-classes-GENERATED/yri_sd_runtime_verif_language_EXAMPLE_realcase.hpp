/*
* yri_sd_runtime_verif_language_EXAMPLE_realcase.hpp
*
*/

#ifndef _YRI_DB_VERIF_RUNTIME_MONITOR_yri_sd_runtime_verif_language_EXAMPLE_realcase_HPP_
#define _YRI_DB_VERIF_RUNTIME_MONITOR_yri_sd_runtime_verif_language_EXAMPLE_realcase_HPP_

#include "include/yri-db-runtime-verif-MONITOR.hpp"

#include "yri_sd_runtime_verif/utils/YRI_CPP_UTILS.hpp"

#include "yri_sd_runtime_verif/YRI_CPP_MONITOR_object.hpp"


#include <QtCore/QDebug>


class YRI_CPP_MONITOR_EDGE;
class YRI_CPP_MONITOR;


class yri_sd_runtime_verif_language_EXAMPLE_realcase : public YRI_DB_RUNTIME_VERIF_Monitor
{
    Q_OBJECT

public:

    static void YRI_CALL_BACK_final_state(YRI_CPP_MONITOR 			*a_runtime_monitor,
                                          YRI_CPP_MONITOR_EDGE 	*an_EDGE_leading_TO_error_FINAL_state);

    yri_sd_runtime_verif_language_EXAMPLE_realcase();

    yri_sd_runtime_verif_language_EXAMPLE_realcase(YRI_DB_RUNTIME_VERIF_Logger *logger);

    inline virtual ~yri_sd_runtime_verif_language_EXAMPLE_realcase()
    {
    }

public slots:

    /**
    * THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
    * LOGIC CHECK AFTER A STATE EVENT (or system event)
    * could be achieved by the runtime monitor system !
    *
    * A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
    * METHOD !
    */
    virtual bool DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(
        QString sql_table_ADDED_with_file_AND_line_number,
        uint	sql_record_qty_MODIFIED,
        YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER cur_SQL_command =
            YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UNDEFINED_SQL_COMMAND);


    bool YRI_SQL_SELECT_departements_produits();

};


#endif /* _YRI_DB_VERIF_RUNTIME_MONITOR_yri_sd_runtime_verif_language_EXAMPLE_realcase_HPP_ */

