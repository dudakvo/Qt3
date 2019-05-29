#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QWidget>

class QPushButton;
class QLineEdit;

class CalculatorMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CalculatorMainWindow(QWidget *parent = nullptr);

signals:


private slots:

    void argumentsPlus ();
    void argumentsMinus();
    void argumentsMultiply ();
    void argumentsDivisions ();


public slots:


private:
    QPushButton *mPushButtonPlus;
    QPushButton *mPushButtonMinus;
    QPushButton *mPushButtonMultiply;
    QPushButton *mPushButtonDivisions;

    QLineEdit *mLineFirstArgument;
    QLineEdit *mLineSecondArgument;
    QLineEdit *mLineResult;
};

#endif // CALCULATORMAINWINDOW_H
