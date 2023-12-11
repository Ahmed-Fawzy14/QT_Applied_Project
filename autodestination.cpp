#include "autodestination.h"
#include "directionspage.h"
#include <QVBoxLayout>

// Constructor
autoDestination::autoDestination(QWidget *parent)
    : QWidget(parent, Qt::Window) {
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

    connect(lineEdit, &QLineEdit::textChanged, this, &autoDestination::onTextChanged);
    connect(listWidget, &QListWidget::itemClicked, this, &autoDestination::onItemClicked);

    showFullScreen();

}

void autoDestination::sortList(QStringList &list) {
    std::sort(list.begin(), list.end());
}


// onTextChanged
void autoDestination::onTextChanged(const QString &text) {
    listWidget->clear();
    for (const QString &word : wordList) {
        if (word.contains(text, Qt::CaseInsensitive)) {
            listWidget->addItem(word);
        }
    }
}
// onItemClicked
void autoDestination::onItemClicked(QListWidgetItem *item) {
    buildingSearch = item->text();
    qDebug() << "Building Selected: " << buildingSearch;
    prepareToShowResults();
}

// Additional methods for updating the widget and showing results
void autoDestination::updateWidgetForNextStep() {
    // Clear the current list
    listWidget->clear();

    // Depending on the selected building, update the list with rooms
    // This is a placeholder logic. Replace it with your actual logic for fetching rooms.
    if (buildingSearch == "jameel") {
        roomList = {"Room 101", "Room 102", "Room 103"};
    } else if (buildingSearch == "sse") {
        roomList = {"Lab A", "Lab B", "Lab C"};
    } else {
        roomList = {"General Room 1", "General Room 2"};
    }

    // Add the rooms to the list widget
    listWidget->addItems(roomList);

    // Show the updated list
    listWidget->show();
}

void autoDestination::prepareToShowResults() {
    this->hide();
    direction = new directionsPage(this);
    direction->show();
    direction->updatePushButtonText(buildingSearch); // Update the button text here
    StateManager::getInstance().setButtonText1(buildingSearch);

}

// Getters for building and room if needed
QString autoDestination::getBuilding() const {
    return buildingSearch;
}

QString autoDestination::getRoom() const {
    return roomSearch;
}
