#include "autocompletedest.h"
#include <QVBoxLayout>
#include "directionspage.h"
#include "destination.h"

// Constructor
AutoCompleteDest::AutoCompleteDest(QWidget *parent)
    : QWidget(parent, Qt::Window), x(0) {
    lineEdit = new QLineEdit(this);
    listWidget = new QListWidget(this);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(listWidget);

    wordList = {"jameel", "sse", "admin", "quick", "AUC Portal"};
    listWidget->addItems(wordList); // Populate the list

    connect(lineEdit, &QLineEdit::textChanged, this, &AutoCompleteDest::onTextChanged);
    connect(listWidget, &QListWidget::itemClicked, this, &AutoCompleteDest::onItemClicked);

    showFullScreen();

}

// onTextChanged
void AutoCompleteDest::onTextChanged(const QString &text) {
    listWidget->clear();

    // Determine the list to be used based on the step
    QStringList currentList = x == 0 ? wordList : roomList;

    for (const QString &word : currentList) {
        if (word.contains(text, Qt::CaseInsensitive)) {
            listWidget->addItem(word);
        }
    }

    listWidget->show();
}
// onItemClicked
void AutoCompleteDest::onItemClicked(QListWidgetItem *item) {
    if (x == 0) {
        buildingSearch = item->text();
        qDebug() << "Building Selected: " << buildingSearch;

        updateWidgetForNextStep(); // Update the widget for room selection
    } else if (x == 1) {
        roomSearch = item->text();
        qDebug() << "Room Selected: " << roomSearch;

        prepareToShowResults(); // Prepare to show results
    }

    x++; // Increment the counter

    if (x >= 2) {
        disconnect(listWidget, &QListWidget::itemClicked, this, &AutoCompleteDest::onItemClicked);
    }

    //    listWidget->hide();
    lineEdit->clear();
}

// Additional methods for updating the widget and showing results
void AutoCompleteDest::updateWidgetForNextStep() {
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

void AutoCompleteDest::prepareToShowResults() {
    this->hide();
    direction = new directionsPage(this);
    direction->show();
    direction->updatePushButtonText2(buildingSearch+" "+roomSearch); // Update the button text here
    StateManager::getInstance().setButtonText2(buildingSearch + " " + roomSearch);

}

// Getters for building and room if needed
QString AutoCompleteDest::getBuilding() const {
    return buildingSearch;
}

QString AutoCompleteDest::getRoom() const {
    return roomSearch;
}
