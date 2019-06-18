#ifndef USERINPUT_H
#define USERINPUT_H

#include <QDialog>
#include "travelagency.h"

namespace Ui {
class UserInput;
}

class UserInput : public QDialog
{
    Q_OBJECT

public:
    explicit UserInput(QWidget *parent = nullptr, TravelAgency* travelagency = nullptr);
    ~UserInput();

    std::string getFileName() const {return fileName;}
    void setFileName(std::string fileName) {this->fileName = fileName;}

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserInput *ui;
    TravelAgency* travelagency;
    std::string fileName;
};

#endif // USERINPUT_H
