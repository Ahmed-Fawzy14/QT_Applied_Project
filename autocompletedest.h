#ifndef AUTOCOMPLETEWIDGET_H
#define AUTOCOMPLETEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QStringList>
#include <algorithm>
#include "results.h"
#include "graph.h"
#include "directionspage.h"

class resultsPage;


class AutoCompleteDest : public QWidget {
    Q_OBJECT

public:
    explicit AutoCompleteDest(QWidget *parent = nullptr);
    void setData();
    void addToQStringList(const std::vector<std::string>& vec1,
                          const std::vector<std::string>& vec2,
                          const std::vector<std::string>& vec3);

    void addToQStringList(const std::vector<std::string>& vec1,
                          const std::vector<std::string>& vec2,
                          const std::vector<std::string>& vec3,
                          const std::vector<std::string>& vec4);

private slots:
    void onTextChanged(const QString &text);
    void onItemClicked(QListWidgetItem *item);


public:
    QString getBuilding() const;
    QString getRoom() const;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QStringList wordList;
    QString buildingSearch, roomSearch;
    QStringList roomList;
    void sortList(QStringList &list);

    Graph g;

    int x = 0;

    results *result;
    directionsPage *direction;

    void updateWidgetForNextStep();
    void prepareToShowResults();
};

#endif
