#include "homepage.h"
#include "ui_directionspage.h"
#include "ui_homepage.h"
#include "autocomplete.h"
#include "zoomablegraphicsview.h"
#include <QBoxLayout>
#include <QMessageBox>

homePage::homePage(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::homePage)
{
    ui->setupUi(this);
    showFullScreen();
    // Set the size of the QGroupBox  //x,y
    ui->groupBox->setFixedSize(1400, 800);  // Set the desired width and height

    // Create an instance of ZoomableGraphicsView
    ZoomableGraphicsView *zoomableView = new ZoomableGraphicsView(ui->groupBox);

    // Create the close button
    closeButton = new QPushButton("Close", this);
    connect(closeButton, &QPushButton::clicked, this, &homePage::closeApplication);
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(closeButton);
    hLayout->addStretch(1); // Add a stretch to push the button to the left


    // Set the layout directly for the groupBox
    ui->groupBox->setLayout(new QVBoxLayout(ui->groupBox));  // QVBoxLayout is created directly here
    ui->groupBox->layout()->addWidget(zoomableView);         // Add the zoomableView to the layout
}

homePage::~homePage()
{
    delete ui;
}

void homePage::on_pushButton_4_clicked()
{
    closeApplication();
}


void homePage::closeApplication() {
    QCoreApplication::quit();
}


void homePage::on_pushButton_clicked()
{
    hide();
    AutoCompleteWidget *autoCompleteWidget = new AutoCompleteWidget();
    buildSearch = autoCompleteWidget->getBuilding();
    autoCompleteWidget->setAttribute(Qt::WA_DeleteOnClose);
    autoCompleteWidget->show();
}

void homePage::on_pushButton_2_clicked()
{
    hide();
    pageDir = new directionsPage(this);
    pageDir->show();

}

QString homePage ::getBuildingSearch()
{

    return buildSearch;

}






void homePage::on_pushButton_3_clicked()
{

    QMessageBox::about(this,"Help", "Displayed is an integrative map to help with navigation. \n  To search for a classroom or location on campus click on the Search AUCMaps bar. \n Choose the classroom or location you would like to search for from the list or type in the name and choose from the available choices \n Displayed is a map of the campus with waypoints for ease of navigation, and details about your search. \n To navigate click on the Navigate button in the bottom left corner. \nTo close the application click the Close button in the bottom right corner. \n To navigate to a classroom or location on campus click on the Directions button or access after searching. \n Displayed is an integrative map to help with navigation.\n Click on the Source bar. \n Choose the location you would like to start from in the list or type in the name and choose from the available choices. \n Choose the classroom or location you would like to navigate to from the list or type in the name and choose from the available choices. \n Click on the Directions button to get the path, distance, estimated time, and location. \n Displayed is a zoomed in map of the location for ease of navigation."
);

}

