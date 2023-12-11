#ifndef AUTOCOMPLETEWIDGET_H
#define AUTOCOMPLETEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QStringList>
#include "directionspage.h"

class directionsPage;


class AutoCompleteDest : public QWidget {
    Q_OBJECT

public:
    explicit AutoCompleteDest(QWidget *parent = nullptr);

private slots:
    void onTextChanged(const QString &text);
    void onItemClicked(QListWidgetItem *item);


private:
    QString getBuilding() const;
    QString getRoom() const;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QStringList wordList;
    QString buildingSearch, roomSearch;
    QStringList roomList;

    int x = 0;

    directionsPage *direction;

    void updateWidgetForNextStep();
    void prepareToShowResults();
};

#endif
