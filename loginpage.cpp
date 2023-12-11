#include "loginpage.h"
#include "ui_loginpage.h"
#include "homepage.h"
#include <QMessageBox>
#include <iostream>
using namespace std;



loginPage::loginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginPage)
{
    ui->setupUi(this);
    showFullScreen();
    userCredentials["QT"] = "QT@1234";
    userCredentials["Joudy"] = "ADT";
    userCredentials["CS"] = "CE";
    userCredentials["ahmed-fawzy"] = "900222633";

  //  cout<<"contr"<<endl;

}


void loginPage::on_pushButton_clicked()
{

    QString UserName = ui->lineEdit_User_Name->text();
    QString Password = ui->lineEdit_Password->text();

    // Check if the entered credentials match any in the userCredentials map
    if (userCredentials.contains(UserName) && userCredentials[UserName] == Password)
    {
        QMessageBox::information(this, "Login Successful", "Welcome to AUCMaps!");
        hide();
        home = new homePage(this);
        buildSearch = home ->getBuildingSearch();
        home->show();

    }
    else
    {
        QMessageBox::warning(this, "Error!", "Please Enter Valid Username or Password!");
    }

}


QString loginPage::getBuildingSearch()
{
    return buildSearch;

}

loginPage::~loginPage()
{
    delete ui;
}









