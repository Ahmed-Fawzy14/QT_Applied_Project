#ifndef RESULTSPAGE_H
#define RESULTSPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class resultsPage : public QWidget {
    Q_OBJECT

public:
    explicit resultsPage(QWidget *parent = nullptr);

private slots:
    void closeApplication();

private:
    QLabel *imageLabel;
    QLabel *textLabel;
    QPushButton *closeButton;
};

#endif // RESULTSPAGE_H
