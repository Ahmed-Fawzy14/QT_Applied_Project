#include "autocomplete.h"
#include <QVBoxLayout>
#include <QString>
#include <algorithm>

// Constructor
AutoCompleteWidget::AutoCompleteWidget(QWidget *parent)
    : QWidget(parent, Qt::Window), x(0) {
    lineEdit = new QLineEdit(this);
    listWidget = new QListWidget(this);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(listWidget);

    wordList = {"Gate 1", "Bruce L. Ludwig Family Square", "Allam Ampitheatre",
        "Dr. Hamaza Al Kholi Informaiton Center", "AUC Portal", "School of Continuing Eduction",
        "AUC Center for the Arts", "Social Research Center", "Watson House", "Prince Al Waleed Hall",
        "Link Plaza", "Quick 24", "Arts Gate", "Gate 5", "Administration Building", "Hatem Mostafa Academic Center",
        "SSE", "Barlett Plaza", "Library", "Bus Gate", "Jameel Hall", "Campus Center", "Arnold Pavillion",
        "Pepsi Gate", "AUC CVC", "East Garden", "North Garden", "Garden's Gate", "Gate 2", "West Garden",
        "Gate 4", "AUC Residences", "East Entrance", "Sports Complex", "Sports Gate", "Complex Pool", "Gate 3"


                                                                                };

    sortList(wordList);

    listWidget->addItems(wordList); // Populate the list

    connect(lineEdit, &QLineEdit::textChanged, this, &AutoCompleteWidget::onTextChanged);
    connect(listWidget, &QListWidget::itemClicked, this, &AutoCompleteWidget::onItemClicked);

    setData();

    showFullScreen();

}

void AutoCompleteWidget::setData()
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

void AutoCompleteWidget::sortList(QStringList &list) {
    std::sort(list.begin(), list.end());
}


// onTextChanged
void AutoCompleteWidget::onTextChanged(const QString &text) {
    listWidget->clear();

    // Determine the list to be used based on the step
    QStringList currentList = x == 0 ? wordList : roomList;
    sortList(currentList); // Sort the current list

    for (const QString &word : currentList) {
        if (word.contains(text, Qt::CaseInsensitive)) {
            listWidget->addItem(word);
        }
    }

    listWidget->show();
}

// onItemClicked
void AutoCompleteWidget::onItemClicked(QListWidgetItem *item) {
    if (x == 0) {
        buildingSearch = item->text();
        qDebug() << "Building Selected: " << buildingSearch;
        g.nodeName = buildingSearch.toStdString();


        updateWidgetForNextStep(); // Update the widget for room selection
    } else if (x == 1) {
        roomSearch = item->text();
        qDebug() << "Room Selected: " << roomSearch;
        g.room = roomSearch.toStdString();

        prepareToShowResults(); // Prepare to show results
    }

    x++; // Increment the counter

    if (x >= 2) {
        disconnect(listWidget, &QListWidget::itemClicked, this, &AutoCompleteWidget::onItemClicked);
    }

//    listWidget->hide();
    lineEdit->clear();
}


void AutoCompleteWidget::addToQStringList(const std::vector<std::string>& vec1,
                             const std::vector<std::string>& vec2,
                             const std::vector<std::string>& vec3) {

    // Helper lambda to add contents of a vector to the QStringList
    // Adding elements from the first vector
    for (const auto& item : vec1) {
        this->roomList.append(QString::fromStdString(item));
    }

    // Adding elements from the second vector
    for (const auto& item : vec2) {
        this->roomList.append(QString::fromStdString(item));
    }

    // Adding elements from the third vector
    for (const auto& item : vec3) {
        this->roomList.append(QString::fromStdString(item));
    }


}

void AutoCompleteWidget::addToQStringList(const std::vector<std::string>& vec1,
                                        const std::vector<std::string>& vec2,
                                        const std::vector<std::string>& vec3,
                                         const std::vector<std::string>& vec4) {

    // Helper lambda to add contents of a vector to the QStringList
    // Adding elements from the first vector
    for (const auto& item : vec1) {
        this->roomList.append(QString::fromStdString(item));
    }

    // Adding elements from the second vector
    for (const auto& item : vec2) {
        this->roomList.append(QString::fromStdString(item));
    }

    // Adding elements from the third vector
    for (const auto& item : vec3) {
        this->roomList.append(QString::fromStdString(item));
    }

    // Adding elements from the third vector
    for (const auto& item : vec4) {
        this->roomList.append(QString::fromStdString(item));
    }

}
// Additional methods for updating the widget and showing results
void AutoCompleteWidget::updateWidgetForNextStep() {
    // Clear the current list
    listWidget->clear();



   // addToQStringList(g.classGround, g.classFirst, g.classSecond);
    // Depending on the selected building, update the list with rooms
    // This is a placeholder logic. Replace it with your actual logic for fetching rooms.

    if (buildingSearch == "Jameel Hall") {
        addToQStringList(g.classGround, g.classFirst, g.classSecond);
    } else if (buildingSearch == "SSE") {
        addToQStringList(g.SSEG, g.SSEFF, g.SSESF);
    } else if(buildingSearch == "Administration Building")
    {
        addToQStringList(g.AdminG, g.AdminGround, g.AdminFF, g.AdminSF);
    }
    else if (buildingSearch == "Hatem Mostafa Academic Center")
    {
        addToQStringList(g.classGround, g.classFirst, g.classSecond);
    }
    else
    {
        roomList = {"Go to Location"};
    }

    // Sort the roomList
    sortList(roomList);

    // Add the rooms to the list widget
    listWidget->addItems(roomList);

    // Show the updated list
    listWidget->show();
}

void AutoCompleteWidget::prepareToShowResults() {
    // Hide this widget
    this->hide();
    string word;
    string o;

    //cout<<g.nodeName<<'\t'<<g.room<<endl;
    if(g.nodeName == "Jameel Hall")
    {
        g.nodeName = "Jameel";
        g.searchClassroomInNode(g.nodeName,g.room, word, o);

    }
    else if(g.nodeName == "SSE")
    {
        g.nodeName = "SSE";
        g.searchClassroomInNode(g.nodeName,g.room, word, o);


    }else if(g.nodeName == "Administration Building")
    {
        g.nodeName = "Administration";
        g.searchClassroomInNode(g.nodeName,g.room, word, o);

    }else if(g.nodeName == "Hatem Mostafa Academic Center")
    {
        g.nodeName = "Jameel";
        g.searchClassroomInNode(g.nodeName,g.room, word, o);


    }
    else
    {
        word = "This is " + g.nodeName;
    }
    // Create and show an instance of FullScreenPage without setting this as its parent
    results *Result = new results(nullptr, word);
    Result->setAttribute(Qt::WA_DeleteOnClose); // Ensure it's deleted once closed
    Result->show();
}


// Getters for building and room if needed
QString AutoCompleteWidget::getBuilding() const {
    return buildingSearch;
}

QString AutoCompleteWidget::getRoom() const {
    return roomSearch;
}
