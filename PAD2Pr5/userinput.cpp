#include "userinput.h"
#include "ui_userinput.h"

UserInput::UserInput(QWidget *parent, TravelAgency* travelagency) :
    QDialog(parent),
    ui(new Ui::UserInput)
{
    ui->setupUi(this);
    this->travelagency = travelagency;
    ui->lineEdit->setText(".txt");



}

UserInput::~UserInput()
{
    delete ui;
}

void UserInput::on_pushButton_clicked()
{
   fileName = ui->lineEdit->text().toStdString();
   this->close();
}
