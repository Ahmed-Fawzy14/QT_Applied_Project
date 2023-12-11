#ifndef STATEMAN_H
#define STATEMAN_H

#include <QString>

class StateManager {
public:
    static StateManager& getInstance() {
        static StateManager instance;
        return instance;
    }

    void setButtonText1(const QString& text) { buttonText1 = text; }
    void setButtonText2(const QString& text) { buttonText2 = text; }
    QString getButtonText1() const { return buttonText1; }
    QString getButtonText2() const { return buttonText2; }

private:
    StateManager() {

        buttonText1 = "Choose Source"; // Set initial text for button 1
        buttonText2 = "Choose Destinaiton"; // Set initial text for button 2
    }

    QString buttonText1;
    QString buttonText2;
};


#endif // STATEMAN_H
