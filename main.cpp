#include "QApplication"
#include "calculatormainwindow.h"

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication (lArgc, lArgv);
    CalculatorMainWindow Calculator;

    Calculator.show();

    return lApplication.exec();
}
