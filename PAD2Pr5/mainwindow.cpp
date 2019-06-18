#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include <string>
#include "linkedlist.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    travelagency = new TravelAgency();
}

MainWindow::~MainWindow()
{
    delete ui;
    travelagency->deleteObjects();
    delete travelagency;
}




//File einlesen, Tabelle füllen
/**
 * @brief MainWindow::on_actionFunktion_triggered
 */
void MainWindow::on_actionDatei_einlesen_triggered()
{

    QMessageBox::warning(this, "test" , "soll die Datei einlesen" , QMessageBox::Ok);

    correctRead = true;

    try{

    //readFile wird aufgerufen
    travelagency->readFile(); //readFile stürzt ab
    QMessageBox::information(this, "test", QString::number(travelagency->getListSize()), QMessageBox::Ok);


    }
    catch(std::invalid_argument) {
        QMessageBox::warning(this, "Error", "Fehler in Zeile " + QString::number(travelagency->getRowCount()) + "An Position " + QString::number(travelagency->getErrorPosition()), QMessageBox::Ok);
        correctRead = false;
        travelagency->deleteObjects();
    }

    //Wenn korrekt eingelesen wurde, dann:
    if(correctRead == true) {
    //Meldung als MessageBox
        QMessageBox::information(this,   "Einleseergebnis", "Es wurden " + QString::number(travelagency->getLAllBookingSize())
                                                         + " Buchungen " + QString::number(travelagency->getAllCustomerSize())
                                                         + " Kunden und " + QString::number(travelagency->getAllTravelsSize())
                                                         + " Reisen im Gesamtwert von " + QString::number(travelagency->getCompleteSum())
                                                         + " eingelesen ", QMessageBox::Ok);



    //Feld wird nach einmaligen triggern ausgegraut, erst wenn das fehlerfreie lesen passiert ist
        ui->actionDatei_einlesen->setEnabled(false);


    //Eigenschaften der Tabelle setzen
    ui->tableData->setRowCount(travelagency->getLAllBookingSize());
    ui->tableData->setColumnCount(4);

    //Tabelle soll nicht editierbar sein
    ui->tableData->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //========== Befüllen der Tabelle ==========




    for (unsigned int i {0}; i < travelagency->getLAllBookingSize(); i++) {

        //booking id
        ui->tableData->setItem(i, 0, new QTableWidgetItem(QString::number(travelagency->getBooking(i)->getID())));

        //preis
        ui->tableData->setItem(i, 1, new QTableWidgetItem(QString::number(travelagency->getBooking(i)->getPrice())));

        //Customer name
        ui->tableData->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(travelagency->findCustomerWIndex(travelagency, i))));

        //Reisenummer
        ui->tableData->setItem(i, 3, new QTableWidgetItem(QString::number(travelagency->getBooking(i)->getTravelId())));
    }


    }
}



/**
 * @brief MainWindow::on_actionProgramm_beenden_triggered
 */
void MainWindow::on_actionProgramm_beenden_triggered()
{
    //deleteTempV();
    exit(0);

}



/**
 * @brief MainWindow::on_tableData_doubleClicked
 * @param index
 */
void MainWindow::on_tableData_doubleClicked(const QModelIndex &index)
{

    //Einstellen, dass der Nutzer keine eigenen Daten mehr auswählen kann
    ui->calendarWidget->setSelectionMode(QCalendarWidget::NoSelection);
    ui->calendarWidget_2->setSelectionMode(QCalendarWidget::NoSelection);

    //angeklickte row bestimmen
    int bookingIndex = ui->tableData->currentRow();

    //buchung nach bookingIndex auswählen und den String des Datums rausholen
    std::string datumN = travelagency->getBooking(bookingIndex)->getToDate();
    std::string datumV = travelagency->getBooking(bookingIndex)->getFromDate();

    //mit substring teile des Strings holen und in ints casten; aufeilung nach JJJJ,MM,TT
    std::string jV = datumV.substr(0,4);
    std::string mV = datumV.substr(4,2);
    std::string dV = datumV.substr(6,2);

    std::string jN = datumN.substr(0,4);
    std::string mN = datumN.substr(4,2);
    std::string dN = datumN.substr(6,2);

    //in ints umwandeln
    int iJV = std::stoi(jV);
    int iMV = std::stoi(mV);
    int iDV = std::stoi(dV);

    int iJN = std::stoi(jN);
    int iMN = std::stoi(mN);
    int iDM = std::stoi(dN);

    //Aufgeteilte ints als Datum nutzen
    ui->calendarWidget->setSelectedDate(QDate(iJV, iMV, iDV));
    ui->calendarWidget_2->setSelectedDate(QDate(iJN, iMN, iDM));

    //Buchungsnummer nochmal extra ausgeben
    ui->lineEdit_4->setText(QString::number(travelagency->getBooking(bookingIndex)->getID()));
    //Buchungsnummer ändert sich

    //Preis ausgabe
    ui->lineEdit_2->setText(QString::number(travelagency->getBooking(bookingIndex)->getPrice()));
    //preis ändert sich

    //Reise
    ui->lineEdit_3->setText(QString::number(travelagency->getBooking(bookingIndex)->getTravelId()));
    //Reise ändert sich

    //Kunde
    ui->lineEdit_5->setText(QString::fromStdString(travelagency->findCustomerWTravel(travelagency, travelagency->findTravel(travelagency->getBooking(bookingIndex)->getTravelId()))));
    //Kunde ändert  sich


    //hier die individuellen Felder hin. Dazu muss eine prüfung existieren zu welchen genauen typ die Buchung gehört

    //funktioniert, man kann testen ob es der typ ist oder ein nullp
    if(dynamic_cast<FlightBooking*>(travelagency->getBooking(bookingIndex)) != nullptr) {

        //sichtbarkeiten
        ui->lineEdit_11->setVisible(true);
        ui->lineEdit_7->setVisible(true);

        //Kategorien //13, 9, 10, 11, 12
        ui->lineEdit_13->setText("Flightbooking");
        ui->lineEdit_9->setText("Start Datum");
        ui->lineEdit_10->setText("End Datum");
        ui->lineEdit_11->setText("Airline");
        ui->lineEdit_12->setText("Seat Preference");

        //inhalt //1, 6, 7, 8
        ui->lineEdit->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency->getBooking(bookingIndex))->getToDate()));
        ui->lineEdit_6->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency->getBooking(bookingIndex))->getFromDate()));
        ui->lineEdit_7->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency->getBooking(bookingIndex))->getAirline()));
        ui->lineEdit_8->setText(QString::fromStdString(dynamic_cast<FlightBooking*>(travelagency->getBooking(bookingIndex))->showDetails()));

    }
    else if (dynamic_cast<HotelBooking*>(travelagency->getBooking(bookingIndex)) != nullptr) {

        //sichtbarkeiten
        ui->lineEdit_11->setVisible(false);
        ui->lineEdit_7->setVisible(false);

        //Kategorien // 13, 9, 10, 11, 12
        ui->lineEdit_13->setText("Hotelbooking");
        ui->lineEdit_9->setText("Hotel");
        ui->lineEdit_10->setText("Town");
        ui->lineEdit_12->setText("Smoke");

        //inhalt // 1, 6, 7, 8
        ui->lineEdit->setText(QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency->getBooking(bookingIndex))->getHotel()));
        ui->lineEdit_6->setText(QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency->getBooking(bookingIndex))->getTown()));
        ui->lineEdit_8->setText(QString::fromStdString(dynamic_cast<HotelBooking*>(travelagency->getBooking(bookingIndex))->showDetails()));

    }
    else if (dynamic_cast<RentalCarReservation*>(travelagency->getBooking(bookingIndex)) != nullptr) {

        //sichtbarkeiten
        ui->lineEdit_11->setVisible(true);
        ui->lineEdit_7->setVisible(true);

        //Kategorien //13, 9, 10, 11, 12
        ui->lineEdit_13->setText("RentalCarReservation");
        ui->lineEdit_9->setText("Pickuplocation");
        ui->lineEdit_10->setText("Returnlocation");
        ui->lineEdit_11->setText("Company");
        ui->lineEdit_12->setText("Insurance typ");

        //inhalt //1, 6, 7, 8
        ui->lineEdit->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency->getBooking(bookingIndex))->getPickupLocation()));
        ui->lineEdit_6->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency->getBooking(bookingIndex))->getReturnLocation()));
        ui->lineEdit_7->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency->getBooking(bookingIndex))->getCompany()));
        ui->lineEdit_8->setText(QString::fromStdString(dynamic_cast<RentalCarReservation*>(travelagency->getBooking(bookingIndex))->showDetails()));

    }
}




//Tabelle wird beim erstelle einer neuen Buchung aktualisiert um die neue Buchung anzeigen zu können
/**
 * @brief MainWindow::on_actionNeue_Buchung_triggered
 */
void MainWindow::on_actionNeue_Buchung_triggered()
{
    ui->tableData->clear();


    //neues Dialogfenster
    Dialog* dialog = new Dialog(this, travelagency);

    dialog->exec();

    //eingenschaften der Tabelle
    ui->tableData->setColumnCount(4);
    ui->tableData->setRowCount(travelagency->getLAllBookingSize());

    //Tabelle soll nicht editierbar sein
    ui->tableData->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //aktualisierte ausgabe
    QMessageBox::information(this,   "Einleseergebnis", "Es wurden " + QString::number(travelagency->getLAllBookingSize())
                                                         + " Buchungen " + QString::number(travelagency->getAllCustomerSize())
                                                         + " Kunden und " + QString::number(travelagency->getAllTravelsSize())
                                                         + " Reisen im Gesamtwert von " + QString::number(travelagency->getCompleteSum())
                                                         + " eingelesen ", QMessageBox::Ok);

    //Befüllen der Tabelle
    //schleife um die Tabelle mit den einzelnen Items befüllen
    for (unsigned int i {0}; i < travelagency->getLAllBookingSize(); i++) {

        //booking id
        ui->tableData->setItem(i, 0, new QTableWidgetItem(QString::number(travelagency->getBooking(i)->getID())));

        //Preis
        ui->tableData->setItem(i, 1, new QTableWidgetItem(QString::number(travelagency->getBooking(i)->getPrice())));

        //customer name
        ui->tableData->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(travelagency->findCustomerWIndex(travelagency, i))));

        //Reisenummer
        ui->tableData->setItem(i, 3, new QTableWidgetItem(QString::number(travelagency->getBooking(i)->getTravelId())));
    }
}





/**
 * @brief MainWindow::on_calendarWidget_activated
 * @param date
 */
void MainWindow::on_calendarWidget_activated(const QDate &date)
{

}





void MainWindow::on_actionDaten_speichern_triggered()
{

    UserInput* userinput = new UserInput(this, travelagency);

    userinput->exec();

    //über dialog den Dateinamen bekommen
    std::string newFileName = userinput->getFileName();

    travelagency->writeNewFile(newFileName);

    QMessageBox::information(this, "Info", "Daten gespeichert", QMessageBox::Ok);

}

void MainWindow::on_pushButton_clicked()
{

}
