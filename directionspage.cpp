#include "directionspage.h"
#include "ui_directionspage.h"
#include "autocompletesource.h"
#include "zoomablegraphicsview.h"
#include <QBoxLayout>

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QStringList>

bool pressed = false;
bool pressed2 = false;
bool pressed3 = false;

bool x = false;

class directionsPage;




directionsPage::directionsPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::directionsPage)
{
    ui->setupUi(this);

    // Set the size of the QGroupBox  //x,y
    ui->groupBox->setFixedSize(1400, 800);  // Set the desired width and height

    // Create an instance of ZoomableGraphicsView
    ZoomableGraphicsView *zoomableView = new ZoomableGraphicsView(ui->groupBox);

    // Set the layout directly for the groupBox
    ui->groupBox->setLayout(new QVBoxLayout(ui->groupBox));  // QVBoxLayout is created directly here
    ui->groupBox->layout()->addWidget(zoomableView);

    // Create the close button


    // Create a horizontal layout for the close button
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch(1); // Add a stretch to push the button to the left



    showFullScreen();


}

void directionsPage::closeApplication() {
    QCoreApplication::quit();
}


directionsPage::~directionsPage()
{
    delete ui;
}

void directionsPage::on_pushButton_clicked()
{
    pressed = true;
    hide();
    AutoCompleteSource *autoCompleteWidget = new AutoCompleteSource();
    autoCompleteWidget->setAttribute(Qt::WA_DeleteOnClose);
    autoCompleteWidget->show();
    //need to update here



}


void directionsPage::on_pushButton_2_clicked()
{
    pressed3 = true;

    if(pressed == true){
        hide();
        AutoCompleteSource *autoCompleteWidget = new AutoCompleteSource();
        autoCompleteWidget->setSup(pressed3);
        autoCompleteWidget->setAttribute(Qt::WA_DeleteOnClose);
        autoCompleteWidget->show();
    }

    //  pressed = true;
//    startNode = this->start;
//    endNode = autoCompleteWidget->end;
    pressed2 = true;

}


void directionsPage::on_pushButton_3_clicked()
{
    if(pressed && pressed2)
    {
        this->hide();
        dest = new destination(nullptr, startNode, endNode, room);
        //dest->setStart(startNode);
        //dest->setEnd(endNode);
        dest->setAttribute(Qt::WA_DeleteOnClose); // Set the attribute
        dest->showFullScreen();

    }
}

