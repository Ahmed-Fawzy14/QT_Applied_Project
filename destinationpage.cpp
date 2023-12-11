//#include "destinationpage.h"
#include "ui_destinationpage.h"
#include <QMainWindow>

namespace Ui {
class destinationPage;
}

class destinationPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit destinationPage(QWidget *parent = nullptr);
    ~destinationPage();

private:
    Ui::destinationPage *ui;
};


destinationPage::destinationPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::destinationPage)
{
    ui->setupUi(this);
}

destinationPage::~destinationPage()
{
    delete ui;
}
