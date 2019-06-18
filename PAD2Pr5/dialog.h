#ifndef DIALOG_H
#define DIALOG_H

#include "travelagency.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{

    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, TravelAgency* travelagency = nullptr);   //funzt für normale anzeige/standartfall
    //Dialog(QWidget* parent,TravelAgency* travelagency);


    ~Dialog();
    TravelAgency* travelagency;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Dialog *ui;
    TravelAgency* travelagnecy;
};

#endif // DIALOG_H
