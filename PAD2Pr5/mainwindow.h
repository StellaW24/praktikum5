#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "userinput.h"
#include <QMessageBox>
#include <travelagency.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool getCorrectRead() const {return correctRead;}
    void setCorrectRead(bool correctRead) {this->correctRead = correctRead;}

private slots:


    void on_actionDatei_einlesen_triggered();

    void on_actionProgramm_beenden_triggered();

    void on_tableData_doubleClicked(const QModelIndex &index);

    void on_calendarWidget_activated(const QDate &date);

    void on_actionNeue_Buchung_triggered();

    void on_stackedWidget_currentChanged(int arg1);


    void on_actionDaten_speichern_triggered();

    void on_pushButton_clicked();

signals:
    void sendTravelagency(TravelAgency*);

private:
    Ui::MainWindow *ui;
    TravelAgency* travelagency;
    Dialog* dialog;
    UserInput* userinput;
    bool correctRead;
};

#endif // MAINWINDOW_H
