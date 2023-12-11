#ifndef DIRECTIONSPAGE_H
#define DIRECTIONSPAGE_H

#include "ui_directionspage.h"
#include <QMainWindow>
#include "stateMan.h"
#include "destination.h"
#include <QString>
#include <string>
#include <vector>

namespace Ui {
class directionsPage;
}





class directionsPage : public QMainWindow
{
    Q_OBJECT

private:
    Ui::directionsPage *ui;
    destination *dest;
    QPushButton *closeButton;





public:
    explicit directionsPage(QWidget *parent = nullptr);

    void updatePushButtonText(const QString& newText) {
        ui->pushButton->setText(newText);
    }

    void updatePushButtonText2(const QString& newText) {
        ui->pushButton_2->setText(newText);
    }

    void showEvent(QShowEvent *event) {
        QMainWindow::showEvent(event);
        // Update button texts when the window is shown
        updatePushButtonText(StateManager::getInstance().getButtonText1());
        updatePushButtonText2(StateManager::getInstance().getButtonText2());
    }

    QString startNode;
    QString endNode;
    QString room;
    std::vector<std::string> path;
    int totalDistance;
    void setStart();
    void setEnd();
    ~directionsPage();

private slots:
    void on_pushButton_clicked();


    void closeApplication();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();
};

#endif // DIRECTIONSPAGE_H
