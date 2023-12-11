#ifndef DESTINATION_H
#define DESTINATION_H

#include <QMainWindow>
#include "close.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <string>
#include "graph.h"
#include <vector>

namespace Ui {
class destination;
}

class destination : public QWidget {
    Q_OBJECT

public:
    Ui::destination *ui;

    explicit destination(QWidget *parent = nullptr, QString start = "", QString end = "", QString room = "");
    ~destination();

    Graph g;
    QString startNode;
    QString rooM;
    QString endNode;
    std::vector<std::string> path;
    int totalDistance;

    void setStart(QString x);

    void setEnd(QString x);

    void setData();

    std::string start;
    std::string end;
    QPushButton *directions;


    void openPath();

private slots:
    void closeApplication();
    void updateImage(QString photo);
    void resizeEvent(QResizeEvent *event,QString photo);

private:
    QLabel *imageLabel;
    QLabel *textLabel;
    QPushButton *closeButton;


};



#endif // DESTINATION_H
