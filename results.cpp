#include "results.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QTimer>
#include <string>
#include <iostream>
using namespace std;

results::results(QWidget *parent, string word) : QWidget(parent) {
    setWindowState(Qt::WindowFullScreen);
    showFullScreen();

    // Create the image label
    imageLabel = new QLabel(this);
    imageLabel->setAlignment(Qt::AlignCenter);

    // Set an example image, replace with your image path or logic
    QString photo = "C:/Users/Fawzy/OneDrive - YAT learning Solutions/Desktop/big test.jpg";
    imageLabel->setPixmap(QPixmap(photo).scaled(this->width(), this->height() / 2, Qt::KeepAspectRatio));

    QString wordQ = QString::fromStdString(word);
    // Create the text label
    textLabel = new QLabel(wordQ, this);
    textLabel->setStyleSheet("border: 1px solid #cccccc; border-radius: 30px; padding: 5px 10px; font-size: 16px; background-color: white; text-align: center;");
    textLabel->setAlignment(Qt::AlignCenter);

    // Create the close button
    closeButton = new QPushButton("Close", this);
    connect(closeButton, &QPushButton::clicked, this, &results::closeApplication);
    closeButton->setStyleSheet("border: 1px solid #cccccc;   border-radius: 15px; padding: 5px 10px;   font-size: 16px; background-color: red; text-align: center;");

    directions = new QPushButton("Navigate", this);
    connect(directions, &QPushButton::clicked, this, &results::openDir);
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

void results::updateImage(QString photo) {
    QPixmap pixmap(photo);
    if (!pixmap.isNull()) {
        imageLabel->setPixmap(pixmap.scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio));
    }
}

void results::resizeEvent(QResizeEvent *event, QString photo) {
    QWidget::resizeEvent(event);
    updateImage(photo);
}

void results::closeApplication() {
    QCoreApplication::quit();
}

void results::openDir()
{

    hide();
    pageDir = new directionsPage(this);
    pageDir->show();

}

results::~results() {

}
