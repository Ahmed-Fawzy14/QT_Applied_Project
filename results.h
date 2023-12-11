#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "directionspage.h"
using namespace std;

class CustomLabel;

class results : public QWidget {
    Q_OBJECT

public:
    explicit results(QWidget *parent = nullptr,  string word = "");
    ~results();

private slots:
    void closeApplication();
    void updateImage(QString photo);
    void resizeEvent(QResizeEvent *event,QString photo);
    void openDir();

private:
    QLabel *imageLabel;
    QLabel *textLabel;
    QPushButton *closeButton;
    QPushButton *directions;
    directionsPage *pageDir;

};

#endif // RESULTS_H
