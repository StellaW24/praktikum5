#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtTest/QTest>
#include <stdexcept>
#include <exception>

#include "travelagency.h"

class Test : public QObject {

    Q_OBJECT
public:
    explicit Test(QObject* parent = nullptr);


private slots:
    void testCompanyAvis();
    void testUnitedAirlines();
    void testBookingsWith1K();

    //eigene unit tests
    void testAllBookingSize();
    void testList();

};


#endif // TEST_H
