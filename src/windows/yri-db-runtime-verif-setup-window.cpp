/*
 * yri-db-runtime-verif-setup-window.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#include "src/windows/yri-db-runtime-verif-setup-window.hpp"


#include "src/utils/yri-db-runtime-verif-CONFIG.hpp"

#include "src/windows/yri-db-runtime-verif-windows.hpp"


#include <QtWidgets/QMainWindow>

#include <QtCore/QObject>



YRIDBRUNTIMEVERIF_SetupWindow::YRIDBRUNTIMEVERIF_SetupWindow()
{
	setupUi(this);

	setFixedSize(width(), height());


	toolBar_SetupWindow_YRI_DB_RUNTIME_VERIF
		->setStyleSheet(YRIDBRUNTIMEVERIF_MainWindow::QMESSAGE_BOX_STYLE_SHEET);



	lineEdit_pdf_reader_full_path
        ->setText(YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader);


    pushButton_STOP_LOGGING
        ->enable(this, SLOT(ON_STOP__logging__SUT_ACTIONS()));


    pushButton_START_LOGGING_from
        ->enable(this, SLOT(ON_START__logging__SUT_ACTIONS()));


    pushButton_choose_pdfReader
        ->enable(this, SLOT(ON_choose_path_pdfReader()));



    pushButton_RESET_parameters_change
        ->enable(this, SLOT(ON_pushButton_Reset_parameters_PRESSED()));

	pushButton_SAVE_parameters
        ->enable(this, SLOT(ON_pushButton_SAVE_parameters_PRESSED()));



    connect(actionExit,
    		SIGNAL(triggered()),
			this,
            SLOT(ACTION_EXIT_method()));


    connect(actionRETURN_TO_console,
    		SIGNAL(triggered()),
			this,
            SLOT(ON_actionRETURN_TO_console_trigerred()));
}


void YRIDBRUNTIMEVERIF_SetupWindow::yri_show()
{
    YRI_DB_RUNTIME_VERIF_Config::init_YRI_DB_RUNTIME_VERIF_Config
        (YRI_DB_RUNTIME_VERIF_Config::YRI_DB_RUNTIME_VERIF_FILE_ABSOLUTEPATH_CONFIGURATION_PROPERTY_FILE);



    lineEdit_pdf_reader_full_path
        ->setText(YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader);



    YRIDBRUNTIMEVERIF_CommonsWindow::yri_show();
}


void YRIDBRUNTIMEVERIF_SetupWindow::ON_STOP__logging__SUT_ACTIONS()
{
    YRIDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
    		YRI_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

    if (0 != ALL_WINDOWS_INSTANCE)
    {
        if (0 != ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_main_Window)
        {
            QString SUT_string_ID = comboBox_SUT_identification->currentText();

            if (!SUT_string_ID.isEmpty())
            {
                ALL_WINDOWS_INSTANCE
                    ->_yrdbruntimeverif_main_Window
                        ->Set___SUT__Logging(SUT_string_ID,
                                             false);
            }
        }
    }
}


void YRIDBRUNTIMEVERIF_SetupWindow::ON_START__logging__SUT_ACTIONS()
{
    YRIDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
    		YRI_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

    if (0 != ALL_WINDOWS_INSTANCE)
    {
        if (0 != ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_main_Window)
        {
            QString SUT_string_ID = comboBox_SUT_identification->currentText();

            if (!SUT_string_ID.isEmpty())
            {
                qDebug() << "|> strart logging of SYSTEM UDER TEST: "
                         << SUT_string_ID;

                ALL_WINDOWS_INSTANCE
                    ->_yrdbruntimeverif_main_Window
                        ->Set___SUT__Logging(SUT_string_ID,
                                             true);
            }
        }
    }
}


void YRIDBRUNTIMEVERIF_SetupWindow::
		set_connection_DBUS_status(QString  message_STATUS,
								   bool 	error_not_connected /* = false */)
{

}


void YRIDBRUNTIMEVERIF_SetupWindow::ON_choose_path_pdfReader()
{
    QString pdfReaderFilePath =
    		QFileDialog::getOpenFileName(this,
    									 QObject::tr("select a full path to a Pdf reader"),
										 QString::null,
										 QString::null);

    if (!pdfReaderFilePath.isEmpty())
    {
        YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader = pdfReaderFilePath;

        lineEdit_pdf_reader_full_path->setText(pdfReaderFilePath);
    }
}


void YRIDBRUNTIMEVERIF_SetupWindow::ON_actionRETURN_TO_console_trigerred()
{
    YRIDBRUNTIMEVERIF_Windows *ALL_WINDOWS_INSTANCE =
    		YRI_DB_RUNTIME_VERIF_Config::GET_ALL_WINDOWS_instance();

    if (0 != ALL_WINDOWS_INSTANCE)
    {
    	ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_main_Window->yri_show();
    	ALL_WINDOWS_INSTANCE->_yrdbruntimeverif_setup_Window->yri_close();
    }
}


void YRIDBRUNTIMEVERIF_SetupWindow::ON_pushButton_Reset_parameters_PRESSED()
{
    QString msgEnregistrer = QObject::tr("RESET current settings ?");

    if (QMessageBox::Ok ==
            QMessageBox::question(toolBar_SetupWindow_YRI_DB_RUNTIME_VERIF,
                                  QObject::tr("RESET current YRI-DB-RUNTIME-VERIF APPLICATIONS parameters"),
                                  msgEnregistrer,
                                  QMessageBox::Cancel,
                                  QMessageBox::Ok))
    {
        YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader =
            YRI_DB_RUNTIME_VERIF_Config::__pathToPdfReader;


        lineEdit_pdf_reader_full_path
            ->setText(YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader);


        YRI_DB_RUNTIME_VERIF_Config::save_YRI_DB_RUNTIME_VERIF_Config();
    }
}


void YRIDBRUNTIMEVERIF_SetupWindow::ON_pushButton_SAVE_parameters_PRESSED()
{
    QString msgEnregistrer = QObject::tr("Save current settings ?");

    if (QMessageBox::Ok ==
            QMessageBox::question(toolBar_SetupWindow_YRI_DB_RUNTIME_VERIF,
                                  QObject::tr("save current YRI-DB-RUNTIME-VERIF GUI settings"),
                                  msgEnregistrer,
                                  QMessageBox::Cancel,
                                  QMessageBox::Ok))
    {
        YRI_DB_RUNTIME_VERIF_Config::pathToPdfReader = lineEdit_pdf_reader_full_path->text();

        YRI_DB_RUNTIME_VERIF_Config::save_YRI_DB_RUNTIME_VERIF_Config();
    }
}



