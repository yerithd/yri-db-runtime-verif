/*
 * yri-db-runtime-verif-PROCESS-info.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YRI_DB_RUNTIME_VERIF_UTILS_YEROTH_PROCESS_INFO_HPP_
#define _YRI_DB_RUNTIME_VERIF_UTILS_YEROTH_PROCESS_INFO_HPP_


#include "src/process/yri-db-runtime-verif-PROCESS.hpp"


#include <QtCore/QString>


class YRI_DB_RUNTIME_VERIF_Utils;
class YRI_DB_RUNTIME_VERIF_Logger;

class YRDBRUNTIMEVERIF_ProcessInfo
{
public:


    inline YRDBRUNTIMEVERIF_ProcessInfo()
    {
    }

    inline ~YRDBRUNTIMEVERIF_ProcessInfo()
    {
    }

    static bool CHECK_WHETHER_DAEMON_PROCESS_IS_RUNNING(QString a_daemon_process_ID_STR,
    													QString executable_full_path,
    													YRI_DB_RUNTIME_VERIF_Logger *logger = 0);
};


#endif /* _YRI_DB_RUNTIME_VERIF_UTILS_YEROTH_PROCESS_INFO_HPP_ */
