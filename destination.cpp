#include "destination.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QTimer>
#include <QString>
#include <string>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QDebug>
using namespace std;



destination::destination(QWidget *parent, QString start, QString end, QString room) : QWidget(parent), startNode(start), endNode(end), rooM(room) {
    setWindowState(Qt::WindowFullScreen);
    cout << "Constructor called" << endl;
    showFullScreen();
    // Create the image label
    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);
    //source//end after search

   string startS = startNode.toStdString();
   string endS = endNode.toStdString();

   if(startS == "Barlett Plaza")
   {
       startS= "BarlettPlaza";
   }

   if(endS == "Barlett Plaza")
   {
       endS= "BarlettPlaza";
   }

   if(startS == "Jameel Hall")
   {
      startS =  "Jameel";

   }
   if(endS == "Jameel Hall")
   {
      endS= "Jameel";
   }

    if(startS == "SSE")
   {
       startS =  "SSE";



   } if(startS == "Administration Building")
   {
     startS =  "Administration";

     if(endS == "Administration Building")
     {
         endS= "Administration";
     }


   } if(startS == "Hatem Mostafa Academic Center")
   {
       startS = "Hatem";
   }

   if(startS ==  "Sports Complex")
   {
       startS = "SportsComplex";
   }


   if(endS ==  "Sports Complex")
   {
       endS = "SportsComplex";
   }

   if(endS ==  "Hatem Mostafa Academic Center")
   {
       endS = "Hatem";
   }
   // start = "Hatem";
   // end = "SSE";
   string roomS = rooM.toStdString();
   string word = "";

    //cout<<start<<'\t'<<end<<endl;
    setData();
    // Set an example image, replace with your image path or logic
    QString photo = "C:/Users/Fawzy/OneDrive - YAT learning Solutions/Desktop/mid sector.jpg";
    imageLabel->setPixmap(QPixmap(photo).scaled(this->width(), this->height() / 2, Qt::KeepAspectRatio));
    // Create the text label
    const double walkingSpeedMetersPerMinute = 84.0; // Average walking speed in meters per minute
  //  g.searchClassroomInNode(startS, roomS, word, endS);
    g.dijkstra(g.intNodeIndex(startS),path, endS, totalDistance);
    double eta = totalDistance / walkingSpeedMetersPerMinute;
    string time = to_string(eta);
    string distance = to_string(totalDistance);
   // string distance = "100m";

   string display = "Estimated Distance" + distance + '\n' + "Estimated Time: " + time + " mins " + '\n' + "From: " + startS + " to " + endS;
    QString displayQ = QString::fromStdString(display);

    textLabel = new QLabel(displayQ, this);
    textLabel->setStyleSheet("border: 1px solid #cccccc; border-radius: 30px; padding: 5px 10px; font-size: 16px; background-color: white; text-align: center;");
    textLabel->setAlignment(Qt::AlignCenter);

    // Create the close button
    closeButton = new QPushButton("Close", this);
    closeButton->setStyleSheet("border: 1px solid #cccccc;   border-radius: 15px; padding: 5px 10px;   font-size: 16px; background-color: red; text-align: center;");
    connect(closeButton, &QPushButton::clicked, this, &destination::closeApplication);

    directions = new QPushButton("View Pth", this);
    connect(directions, &QPushButton::clicked, this, &destination::openPath);
    directions->setStyleSheet("border: 1px solid #cccccc;   border-radius: 15px; padding: 5px 10px;   font-size: 16px; background-color: blue; text-align: center;");

    // Create a horizontal layout for the close button
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(closeButton);
    hLayout->addStretch(1); // Add a stretch to push the button to the left
    hLayout->addWidget(directions);



    // Create a horizontal layout for the text label with spacers
    QHBoxLayout *textLabelLayout = new QHBoxLayout();
    // textLabelLayout->addSpacerItem(new QSpacerItem(5, 0, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Left spacer
    textLabelLayout->addWidget(textLabel);
    // textLabelLayout->addSpacerItem(new QSpacerItem(5, 0, QSizePolicy::Expanding, QSizePolicy::Minimum)); // Right spacer

    // Main vertical layout
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(imageLabel, 3); // 50% stretch factor for the image
    vLayout->addLayout(textLabelLayout, 1); // Add the horizontal layout for the text label with spacers
    vLayout->addLayout(hLayout); // Add the horizontal layout for the close button

    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vLayout->setContentsMargins(0, 0, 0, 0);
    vLayout->setSpacing(0);

    setLayout(vLayout);

    QTimer::singleShot(0, this, [this, photo]() { updateImage(photo); });
}


void destination::setData()
{
    int i = 0;


    g.createGraph(g.BruceLLudwigFamilySquare);
    g.createGraph(g.DrHamzaAlKohliInformationCentre);
    g.createGraph(g.Gate1);
    g.createGraph(g.AllamAmphitheatre);
    g.createGraph(g.SchoolOfContinuingEducation);
    g.createGraph(g.Jameel);
    g.createGraph(g.JameelFirstFloor);
    g.createGraph(g.JameelSecondFloor);
    g.createGraph(g.BusGate);
    g.createGraph(g.SSE);
    g.createGraph(g.SSEFirstFloor);
    g.createGraph(g.SSESecondFloor);
    g.createGraph(g.SSERoof);
    g.createGraph(g.SSEPlaza);
    g.createGraph(g.Hatem);
    g.createGraph(g.HatemFirstFloor);
    g.createGraph(g.HatemSecondFloor);
    g.createGraph(g.HatemThird);
    g.createGraph(g.HatemRoof);
    g.createGraph(g.Quick);
    g.createGraph(g.OmarMohsen);
    g.createGraph(g.Waleed);
    g.createGraph(g.WaleedFirstFloor);
    g.createGraph(g.WaleedSecondFloor);
    g.createGraph(g.AUCCenterForArts);
    g.createGraph(g.ArtFF);
    g.createGraph(g.TabaliPlaza);
    g.createGraph(g.ArtsGate);
    g.createGraph(g.Gate5);
    g.createGraph(g.SocialResearchCenter);
    g.createGraph(g.AUCPortal);
    g.createGraph(g.WatsonHouse);
    g.createGraph(g.LinkPlaza);
    g.createGraph(g.Administration);
    g.createGraph(g.AdministrationGarden);
    g.createGraph(g.AdministrationFirstFloor);
    g.createGraph(g.AdministrationSecondFloor);
    g.createGraph(g.WestGarden);
    g.createGraph(g.BarlettPlaza);
    g.createGraph(g.Library);
    g.createGraph(g.LibraryGarden);
    g.createGraph(g.LibraryFirstFloor);
    g.createGraph(g.LibrarySecondFloor);
    g.createGraph(g.LibraryThirdFloor);
    g.createGraph(g.CVC);
    g.createGraph(g.CampusCenter);
    g.createGraph(g.EastGarden);
    g.createGraph(g.NorthGarden);
    g.createGraph(g.GardensGate);
    g.createGraph(g.Gate2);
    g.createGraph(g.AUCResid);
    g.createGraph(g.AUCResidFF);
    g.createGraph(g.AUCResidSS);
    g.createGraph(g.SportsPlaza);
    g.createGraph(g.EastEntrance);
    g.createGraph(g.SportsComplex);
    g.createGraph(g.PepsiGate);
    g.createGraph(g.Gate4);
    g.createGraph(g.ArnoldPavillion);
    g.createGraph(g.SportGate);
    g.createGraph(g.IndoorSports);
    g.createGraph(g.SportsFF);
    g.createGraph(g.ComplexPool);
    g.createGraph(g.ComplexOutdoor);
    g.createGraph(g.Gate3);

    // g.test = g.getAdjlist();


    g.buildNodeToIndexMap();

    //g.print();

    //   Graph p(100); // Assuming 7 nodes in the graph
    //   g.createGraph(Graph::SSE); // Customize with your starting node

    //  Graph::Buildings startNode1 = Graph::BruceLLudwigFamilySquare;
    //   Graph::Buildings endNode = Graph::SocialResearchCenter;   // Customize with your ending node

    // int shortestDistance = g.findShortestDistance(startNode, endNode, g);
    //working but small but when using start as HatemRoof it acts as if OmarMohsen
    //if you subtract 2 it acts as HatemRoof normally check whats up
    //same thing with OmarMohes as start it goes to +2 Omar
    //at some point a +2 must be happening becuase this does not happen for bruce
    //Gate3 not showing up, probably same error





    //   g.dijkstra(startNode1);

    //    cout<<g.findNodeIndex("Jameel");

    // vector<string> typeJamS={"classroom", "classroom", "classroom", "classroom", "classroom"};


    //JAMEEL

    //Ground
    g.classGround;
    for (int i = 1; i <= 32; ++i) {

        if(i == 1)
        {
            string build = "Go to Building";
            g.classGround.push_back(build);
            string cp = "CP" + to_string(i);
            g.classGround.push_back(cp);
            //cout << classGround[i - 1] << "  " << endl;
        }
        else
        {
            string cp = "CP" + to_string(i);
            g.classGround.push_back(cp);
            //cout << classGround[i - 1] << "  " << endl;
        }

    }


    g.typeJamG={"Building","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                  "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                  "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                  "Classroom", "Office", "Office", "Office", "Office", "Office"};


    //FF
    g.classFirst;
    for (int i = 1; i <= 30; ++i) {

        if(i<=15)
        {
            string cp = "10" + to_string(i);
            g.classFirst.push_back(cp);
            // cout << classFirst.back() << "  " << endl;
        }
        else
        {
            string cp = "P0" + to_string(i);
            g.classFirst.push_back(cp);
            //  cout << classFirst.back() << "  " << endl;

        }

    }

    g.typeJamF={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                  "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                  "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                  "Classroom", "Office", "Office", "Office", "Office", "Office"};

    //SS
    g.classSecond;

    for (int i = 1; i <= 31; ++i) {
        string cp = "20" + to_string(i);
        g.classSecond.push_back(cp);
        //cout << classSecond.back() << "  " << endl;
    }


    g.typeJamS={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                  "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                  "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                  "Classroom", "Office", "Office", "Office", "Office", "Office"};



    ///////////////////////////////////////////////////
    //SSE

    string cp = "";




    ////////////////////////////////////////////////
    //  g.startNode="Waleed";
    // g.endNode= "AUCPortal";
    g.insertInNode("Jameel",g.classGround, g.typeJamG);
    g.insertInNode("JameelFirstFloor",g.classFirst,g.typeJamF);
    g.insertInNode("JameelSecondFloor",g.classSecond,g.typeJamS);




    g.AdminGround = g.classGround;
    g.AdminFF = g.classFirst;
    g.AdminSF = g.classSecond;

    g.SSEG = g.classGround;
    g.SSESF = g.classSecond;
    g.SSEFF = g.classFirst;

    g.SSEType = g.typeJamG;




    //First Floor
    for (int i = 1; i <= 5; ++i) {
        string kj = "Physics Lab " + to_string(i);
        g.SSEFF.push_back(kj);
        //   cout << classFirst.back() << "  " << endl;
    }



    //Second Floor
    for (int i = 1; i <= 5; ++i) {
        string cp = "Computer Lab " + to_string(i);
        g.SSESF.push_back(cp);
        // cout << classSecond.back() << "  " << endl;
    }



    g.SSEType={"Classroom","Classroom", "Classroom", "Classroom", "Classroom", "Classroom",
                 "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Men's Bathroom", "Women's Bathroom",
                 "Classroom", "Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom","Classroom",
                 "Classroom", "Office", "Office", "Office", "Office","Office", "Lab", "Lab", "Lab", "Lab", "Lab"};


    g.insertInNode("SSE",g.SSEG, g.SSEType);
    g.insertInNode("SSEFirstFloor", g.SSEFF,g.SSEType);
    g.insertInNode("SSESecondFloor",g.SSESF,g.SSEType);
    //g.searchClassroomInNode(nodeName,"Go to Building");
    //g.searchClassroomInNode(nodeName,"Computer Lab 4");




    //////ADMIN


    g.AdminG;
    g.AdminGType ={"Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                    "Office","Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                    "Office", "Office", "Office", "Office", "Office","Office", "Office", "Office", "Office"};



    g.AdminType ={"Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                   "Office","Office","Office","Office","Office","Office","Office","Office","Office","Office","Office",
                   "Office", "Office", "Office", "Office", "Office","Office", "Office", "Office", "Office"};



    for (int i = 1; i <= 30; ++i) {

        string cp = "G" + to_string(i);
        g.AdminG.push_back(cp);


        //  cout << classSecond.back() << "  " << endl;
    }




    g.insertInNode("Administration",g.AdminGround, g.AdminGType);
    g.insertInNode("AdministrationGarden",g.AdminG,g.AdminType);
    g.insertInNode("AdministrationFirstFloor",g.AdminFF,g.AdminType);
    g.insertInNode("AdministrationSecondFloor",g.AdminSF,g.AdminType);

    //    nodeName = "Administration";
    //   g.searchClassroomInNode(nodeName,"Go to Building");
    //   g.searchClassroomInNode(nodeName,"G1");


    std::string classroomToSearch = "your_classroom";
    // vector<string> l;
    // int y=0;



    // g.dijkstra(g.intNodeIndex(startNode),l, endNode, y );




}

void destination::updateImage(QString photo) {
    cout << "Updating image with path: " << photo.toStdString() << endl;
    QPixmap pixmap(photo);
    if (!pixmap.isNull()) {
        cout << "Image loaded successfully" << endl;
        imageLabel->setPixmap(pixmap.scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio));
    } else {
        cout << "Failed to load image" << endl;
    }
}

void  destination::openPath()
{
    string c = "";
    QString temp = "";
    int i = 0;

    for (const auto& item : path) {
        if(i==0)
            c = c + item;
        else
            c = c + "  " + item;
    }

    temp = QString::fromStdString(c);

    QMessageBox::about(this,"Path", temp);

}

void destination::resizeEvent(QResizeEvent *event, QString photo) {
    cout << "Resize event triggered" << endl;
    QWidget::resizeEvent(event);
    updateImage(photo); // Make sure 'photo' is accessible here, or pass it some other way
}

void destination::setStart(QString x)
{
    startNode = x;
    cout<<"Set start"<<endl;
}

void destination::setEnd(QString x)
{
    endNode = x;
    cout<<"Set end"<<endl;

}

void destination::closeApplication() {
    cout << "Closing application" << endl;
    QCoreApplication::quit();
}

destination::~destination() {
    cout << "Destructor called" << endl;
}
