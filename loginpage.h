#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include <QMessageBox>


class homePage;

QT_BEGIN_NAMESPACE
namespace Ui { class loginPage; }
QT_END_NAMESPACE

class loginPage : public QMainWindow
{
    Q_OBJECT

public:
    loginPage(QWidget *parent = nullptr);
    ~loginPage();
    QString getBuildingSearch();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_Cancel_clicked();

    void on_Login_clicked();

private:
    Ui::loginPage *ui;
    homePage *home;
    QMap<QString, QString> userCredentials;
    QString buildSearch;

};
#endif // LOGINPAGE_H
