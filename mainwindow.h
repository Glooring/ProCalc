#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QColor>
#include <QMainWindow>
#include "utilities.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // New function to set text color
    //void setTextColor(const QString &objectName, const QString &colorHex);

private:
    Ui::MainWindow *ui;
    double_mp firstValue;
    double_mp secondValue;
    double_mp lastSecondValue;
    double_mp lastFirstValue;
    double_mp lastResult;  // Store the last result for subsequent operations
    QString sqrtArgument;
    QString sqrArgument;
    QString invArgument;
    QString currentOperator;
    bool isNewEntry;
    bool lastPressedOperator;
    bool lastPressedOperand;  // To track if the last pressed button was an operand (digit)
    bool lastPressedEqual;
    bool justPressedEqual;
    bool justPressedOperator;
    bool lastPressedDot;
    bool justPressedOperand;
    bool lastPressedBackspace;
    bool justPressedSqrt;
    bool lastPressedSqrt;
    bool justPressedSqr;
    bool lastPressedSqr;
    bool justPressedInv;
    bool lastPressedInv;
    bool lastPressedPM;
    bool resultNA;
    QString mainText;


    // New variables to store last operator and operand
    QString lastOperator;
    double_mp lastOperand;
    double_mp cachedValue;

    QString expression;  // Stores the full expressio

    double_mp calculateResult();  // Function to calculate the result
    void printExpressionAndResult();  // Function to print the expression and result
    void updateDisplays();  // Function to update the displays
    QString formatNumber(double_mp value);  // Add this declaration
    QString formatResult(double_mp value);  // Add this declaration

public slots:
    void onDigitButtonClicked();
    void onOperatorButtonClicked();
    void onEqualsButtonClicked();
    void onClearButtonClicked();
    void onBackspaceButtonClicked();
    void onDotButtonClicked();
    void onPMButtonClicked();  // Slot for handling +/- button click
    void onSqrtButtonClicked();
    void onSqrButtonClicked();
    void onInvButtonClicked();
};

#endif // MAINWINDOW_H
