#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "zoomablegraphicsview.h"
#include "directionspage.h"
#include <string>
using namespace std;

class directionsPage;

namespace Ui {
class homePage;
}

class homePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit homePage(QWidget *parent = nullptr);
    ~homePage();
    QString getBuildingSearch();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void closeApplication();


    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::homePage *ui;
    ZoomableGraphicsView *zoomableView;  // Add this line
    directionsPage *pageDir;
    QPushButton *closeButton;
    QString buildSearch;


};

#endif // HOMEPAGE_H
