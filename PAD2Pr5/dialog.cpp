#include "dialog.h"
#include "ui_dialog.h"
#include "travelagency.h"
#include <string>
#include <QMessageBox>

using namespace std;



/**
 * @brief Dialog::Dialog
 * @param parent
 * @param travelagency
 */
Dialog::Dialog(QWidget* parent, TravelAgency* travelagency) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->travelagency = travelagency;

    //Namen der Felder

    ui->lineEdit->setText("0.0");
    ui->lineEdit_2->setText(QString::number(0));
    ui->lineEdit_3->setText("startdatum");
    ui->lineEdit_4->setText("enddatum");

    ui->lineEdit_5->setText("Startflughafen");
    ui->lineEdit_6->setText("individuell 1");
    ui->lineEdit_7->setText("individuell 2");
    ui->lineEdit_8->setText("individuell 3");
    ui->lineEdit_9->setText("Zielflughafen");
    ui->lineEdit_10->setText("Fluglinie");
    ui->lineEdit_11->setText("Sitzpraeferenz");
    ui->lineEdit_12->setText("individuell 4");

    ui->comboBox->insertItem(0,QString("Flightbooking"));
    ui->comboBox->insertItem(1,QString("Hotelbooking"));
    ui->comboBox->insertItem(2,QString("Rentalcarreservation"));
}



/**
 * @brief Dialog::~Dialog
 */
Dialog::~Dialog()
{
    delete ui;
}



/**
 * @brief Dialog::on_pushButton_clicked
 */
void Dialog::on_pushButton_clicked()
{
    //bool ok1, ok2, ok3;
    std::vector<std::string> bookingDetails;
    QString text = ui->comboBox->currentText();

    //Variablen für die übergabe
    double p = ui->lineEdit->text().toDouble();
    long tId = ui->lineEdit_2->text().toLong();
    std::string start = ui->lineEdit_3->text().toStdString();
    std::string end = ui->lineEdit_4->text().toStdString();

    //Variablen für die 3 individuellen felder
    std::string indiv1 = ui->lineEdit_6->text().toStdString();
    std::string indiv2 = ui->lineEdit_7->text().toStdString();
    std::string indiv3 = ui->lineEdit_8->text().toStdString();

    //neues individuelles Attribut
    std::string indiv4 = ui->lineEdit_12->text().toStdString();


    //booking id die später zurückgegeben wird
    int bookId {0};

    //Typermittlung:
    char type = 'F';

    //Travel Id testen ob es sie schon gibt
    if(travelagency->checkTravelId(tId) == 1) {
        //wenn ja wird das Fenster geschlossen?
        QMessageBox::information(this, "Fehlerhafte Eingabe!", "Achtung, es wurde eine fehlerhafte Eingabe gemacht", QMessageBox::Ok);
        this->close();
    }
    //Je nach typ wird entschieden was in den Vektor kommt
    else {

    if(text == "Flightbooking") {
        type = 'F';

        //Individuellen Felder werden dem Vektor übergeben
        bookingDetails.push_back(indiv1);
        bookingDetails.push_back(indiv2);
        bookingDetails.push_back(indiv3);
        bookingDetails.push_back(indiv4);
    }
    else if (text == "Hotelbooking") {
        type = 'H';

        //Individuellen Felder werden dem Vektor übergeben
        bookingDetails.push_back(indiv1);
        bookingDetails.push_back(indiv2);
        bookingDetails.push_back(indiv4);

    }
    else if (text == "Rentalcarreservation") {
        type = 'R';

        //Individuellen Felder werden dem Vektor übergeben
        bookingDetails.push_back(indiv1);
        bookingDetails.push_back(indiv2);
        bookingDetails.push_back(indiv3);
        bookingDetails.push_back(indiv4);
    }


    try {
        //Aufruf der Funktion createBooking
        bookId = travelagency->createBooking(type, p, start, end, tId, bookingDetails);
    }
    catch(std::out_of_range) {
        std::cout << "Fehler in dialog" << std::endl;
    }
    catch(int ) {
        std::cout << "Fehler mit int?" << std::endl;
    }

    QMessageBox::information(this, "Buchungs ID", "Die Id der neuen Buchung lautet " + QString::number(bookId));
    }
    this->close();

}

/**
 * @brief Dialog::on_comboBox_activated
 * @param arg1
 */
void Dialog::on_comboBox_activated(const QString &arg1)
{
    QString text = ui->comboBox->currentText();

    //Änderung der Namen, abhängig vom inhalt der combobox
    if(text == "Flightbooking") {
        ui->lineEdit_5->setText(QString("Startflughafen"));
        ui->lineEdit_9->setText(QString("Zielflughafen"));
        ui->lineEdit_10->setText(QString("Fluglinie"));
        ui->lineEdit_11->setText(QString("Sitzpraeferenz"));
        ui->lineEdit_10->setVisible(true);
        ui->lineEdit_8->setVisible(true);

    }
    else if (text == "Hotelbooking") {
        ui->lineEdit_5->setText(QString("Hotel"));
        ui->lineEdit_9->setText(QString("Stadt"));
        ui->lineEdit_11->setText(QString("Rauchen erlaubt oder nicht 1 oder 0"));
        ui->lineEdit_10->setVisible(false);
        ui->lineEdit_8->setVisible(false);
    }
    else if (text == "Rentalcarreservation") {
        ui->lineEdit_5->setText(QString("Abhol Ort"));
        ui->lineEdit_9->setText(QString("Rückgabe Ort"));
        ui->lineEdit_10->setText(QString("Firma"));
        ui->lineEdit_11->setText(QString("Versicherung"));
        ui->lineEdit_10->setVisible(true);
        ui->lineEdit_8->setVisible(true);
    }


}


/**
 * @brief Dialog::on_pushButton_2_clicked
 */
void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
