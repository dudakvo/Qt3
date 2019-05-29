#include "calculatormainwindow.h"

#include "QLineEdit"
#include "QPushButton"
#include "QLabel"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

CalculatorMainWindow::CalculatorMainWindow(QWidget *parent) : QWidget(parent)
{
    QLabel *lLableFirsArgument = new QLabel("first argument");
    QLabel *lLableSecondArgument= new QLabel("second argument");
    QLabel *lLableResult = new QLabel("result");

    mLineFirstArgument = new QLineEdit();
    mLineSecondArgument = new QLineEdit();
    mLineResult = new QLineEdit();
    mLineResult->setReadOnly(true);

    mPushButtonPlus = new QPushButton("+");
    mPushButtonMinus = new QPushButton("-");
    mPushButtonMultiply = new QPushButton("*");
    mPushButtonDivisions = new QPushButton("/");

    QHBoxLayout *lHBoxLayoutFirstArgument = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutSecondArgument = new QHBoxLayout;
    QHBoxLayout *lHBoxLayoutResult = new QHBoxLayout;
    QVBoxLayout *lVBoxLayout = new QVBoxLayout;
    QHBoxLayout *lHBoxLayoutOperations = new QHBoxLayout;

    lHBoxLayoutFirstArgument->addWidget(lLableFirsArgument);
    lHBoxLayoutSecondArgument->addWidget(lLableSecondArgument);
    lHBoxLayoutResult->addWidget(lLableResult);

    lHBoxLayoutFirstArgument->addWidget(mLineFirstArgument);
    lHBoxLayoutSecondArgument->addWidget(mLineSecondArgument);
    lHBoxLayoutResult->addWidget(mLineResult);

    lHBoxLayoutOperations->addWidget(mPushButtonPlus);
    lHBoxLayoutOperations->addWidget(mPushButtonMinus);
    lHBoxLayoutOperations->addWidget(mPushButtonMultiply);
    lHBoxLayoutOperations->addWidget(mPushButtonDivisions);

    lVBoxLayout->addLayout(lHBoxLayoutFirstArgument);
    lVBoxLayout->addLayout(lHBoxLayoutSecondArgument);
    lVBoxLayout->addLayout(lHBoxLayoutResult);
    lVBoxLayout->addLayout(lHBoxLayoutOperations);

    setLayout(lVBoxLayout);
    setWindowTitle("My Calculator Widget");

    connect(mPushButtonPlus, SIGNAL(clicked()), this, SLOT(argumentsPlus()));
    connect(mPushButtonMinus, SIGNAL(clicked()), this, SLOT(argumentsMinus()));
    connect(mPushButtonMultiply, SIGNAL(clicked()), this, SLOT(argumentsMultiply()));
    connect(mPushButtonDivisions, SIGNAL(clicked()), this, SLOT(argumentsDivisions()));
}

void CalculatorMainWindow::argumentsPlus()
{
   QString firstArgument, secondArgument;

   firstArgument=mLineFirstArgument->displayText();
   secondArgument=mLineSecondArgument->text();
   int firstInt= firstArgument.toInt(), secondInt=secondArgument.toInt();

   mLineResult->setText(QString::number(firstInt+secondInt));
}

void CalculatorMainWindow::argumentsMinus()
{
    QString firstArgument, secondArgument;

    firstArgument=mLineFirstArgument->displayText();
    secondArgument=mLineSecondArgument->text();
    int firstInt= firstArgument.toInt(), secondInt=secondArgument.toInt();

    mLineResult->setText(QString::number(firstInt-secondInt));

}

void CalculatorMainWindow::argumentsMultiply()
{
    QString firstArgument, secondArgument;

    firstArgument=mLineFirstArgument->displayText();
    secondArgument=mLineSecondArgument->text();
    int firstInt= firstArgument.toInt(), secondInt=secondArgument.toInt();

    mLineResult->setText(QString::number(firstInt*secondInt));

}

void CalculatorMainWindow::argumentsDivisions()
{
    QString firstArgument, secondArgument;

    firstArgument=mLineFirstArgument->displayText();
    secondArgument=mLineSecondArgument->text();
    int firstInt= firstArgument.toInt(), secondInt=secondArgument.toInt();
    if(secondInt!=0)
        mLineResult->setText(QString::number(firstInt/secondInt));
    else
        mLineResult->setText("division by zero");
}
