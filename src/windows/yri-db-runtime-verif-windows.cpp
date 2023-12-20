/*
 * yri-db-runtime-verif-windows.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */


#include "src/windows/yri-db-runtime-verif-windows.hpp"


YRDBRUNTIMEVERIF_Windows::~YRDBRUNTIMEVERIF_Windows()
{
	delete _yrdbruntimeverif_setup_Window;
	delete _yrdbruntimeverif_main_Window;
}


void YRDBRUNTIMEVERIF_Windows::createAll_YRDBRUNTIMEVERIF_Windows()
{
	_yrdbruntimeverif_setup_Window = new YRDBRUNTIMEVERIF_SetupWindow;

	_yrdbruntimeverif_main_Window = new YRDBRUNTIMEVERIF_MainWindow;

	_yrdbruntimeverif_main_Window->show();
}


void YRDBRUNTIMEVERIF_Windows::CLOSE_allWindows()
{
	_yrdbruntimeverif_setup_Window->yri_close();
	_yrdbruntimeverif_main_Window->yri_close();
}


