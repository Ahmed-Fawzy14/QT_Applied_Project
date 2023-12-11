#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H
#include <QLabel>
#include <QResizeEvent>

class CustomLabel : public QLabel {
public:
    // Constructor
    CustomLabel(const QString &text, QWidget *parent = nullptr)
        : QLabel(text, parent) {}

protected:
    void resizeEvent(QResizeEvent *event) override {
        // Calculate new width as 95% of the parent widget's width
        int newWidth = this->parentWidget()->width() * 0.95;
        this->setFixedWidth(newWidth);
        QLabel::resizeEvent(event);
    }
};
#endif // CUSTOMLABEL_H
