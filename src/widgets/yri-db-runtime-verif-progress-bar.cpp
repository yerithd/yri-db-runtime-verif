/*
 * yri-db-runtime-verif-progress-bar.cpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#include "yri-db-runtime-verif-progress-bar.hpp"


#include "src/windows/yri-db-runtime-verif-COMMONS-window.hpp"


YRI_DB_RUNTIME_VERIF_ProgressBar::YRI_DB_RUNTIME_VERIF_ProgressBar(YRDBRUNTIMEVERIF_CommonsWindow *aYerothParentWindow)
:QProgressBar((QWidget *) aYerothParentWindow),
 _setup(false)
{
    setVisible(false);

    QString RGB_COLOR_TO_DISPLAY_AT_YEROTH_PROGRESS_BAR_BACKGROUND = "255, 48, 48";

    if (0 != aYerothParentWindow)
    {
        QToolBar &aYerothCommonWindowToolBar =
            aYerothParentWindow->get_tool_bar();

        const QColor &aQColor =
            aYerothCommonWindowToolBar.palette().color(QPalette::Button);

        RGB_COLOR_TO_DISPLAY_AT_YEROTH_PROGRESS_BAR_BACKGROUND =
            QString("%1, %2, %3")
                .arg(QString::number(aQColor.red()),
                     QString::number(aQColor.green()),
                     QString::number(aQColor.blue()));
    }

    setStyleSheet(QString("QProgressBar "
                          "{text-align: center; "
                          "border: 2px solid white; "
                          "border-radius: 1px; color: rgb(2, 160, 70);}"
                          "QProgressBar::chunk {"
                          "background-color: rgb(%1); "
                          "color: rgb(2, 160, 70); "
                          "width: 3px;}")
    				.arg(RGB_COLOR_TO_DISPLAY_AT_YEROTH_PROGRESS_BAR_BACKGROUND));

    int width = qCeil(((QMainWindow *) parent())->width() / 2.0);

    int X = qCeil(width / 2.0);

    int Y = qCeil(((QMainWindow *) parent())->height() / 2.0);

    setFixedWidth(width);

    move(X, Y);
}



