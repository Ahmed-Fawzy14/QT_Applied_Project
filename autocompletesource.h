#ifndef AUTOCOMPLETEWIDGET_H
#define AUTOCOMPLETEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QStringList>
#include "directionspage.h"
#include "graph.h"

class directionsPage;


class AutoCompleteSource : public QWidget {
    Q_OBJECT

public:

    explicit AutoCompleteSource(QWidget *parent = nullptr);
    bool getSup();
    void setSup(bool y);
    void setData();
    void addToQStringList(const std::vector<std::string>& vec1,
                          const std::vector<std::string>& vec2,
                          const std::vector<std::string>& vec3);

    void addToQStringList(const std::vector<std::string>& vec1,
                          const std::vector<std::string>& vec2,
                          const std::vector<std::string>& vec3,
                          const std::vector<std::string>& vec4);

    QString start;
    QString end;

private slots:
    void onTextChanged(const QString &text);
    void onItemClicked(QListWidgetItem *item);

private:
    QString getBuilding() const;
    QString getBuildingFor() const;

    QString getRoom() const;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QStringList wordList;
    QString buildingSearch, roomSearch;
    QStringList roomList;
    void sortList(QStringList &list);
    void sendData();

    Graph g;

    bool sup = false;
    int x = 0;

    directionsPage *direction;

    void updateWidgetForNextStep();
    void prepareToShowResults();
};

#endif
