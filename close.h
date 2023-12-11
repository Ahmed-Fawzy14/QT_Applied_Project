#ifndef CLOSE_H
#define CLOSE_H


#include <QPushButton>
#include <QCoreApplication>
#include <QBoxLayout>

class Close : public QWidget {
    Q_OBJECT

public:
    Close(QWidget *parent = nullptr) : QWidget(parent) {
        // Initialize the close button
        QPushButton *closeButton = new QPushButton("Close", this);

        // Your layout and other widgets
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(closeButton);  // Add the close button to the layout

        // Connect the button's clicked signal to the closeApplication slot
        connect(closeButton, &QPushButton::clicked, this, &Close::closeApplication);
    }
    void closeApplication() {
        QCoreApplication::quit();
    }
private slots:

};

#endif // CLOSE_H
