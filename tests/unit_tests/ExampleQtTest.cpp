#include <QtTest/QtTest>

class ExampleQtTest : public QObject {
Q_OBJECT
private slots:

    void FirstTest() const {
        QVERIFY(true);
    }
};

QTEST_MAIN(ExampleQtTest)

#include "ExampleQtTest.moc"