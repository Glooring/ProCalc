#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "utilities.h"  // Include the header file for custom functions
#include <QDebug>  // Include for debug output
#include <QLineEdit>
#include <QLabel>
#include <QTimer>
#include <cmath>  // Required for std::isnan
#include <QRegularExpression>  // Include QRegularExpression

// Include standard library namespaces
using namespace std;

namespace mp = boost::multiprecision;
namespace bm = boost::math;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(300, 440);  // Replace with your desired width and height
    // Set size policies for buttons to make them expand and shrink with the window
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach(QPushButton* button, buttons) {
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }


    // Adjust grid layout margins and spacing
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);  // Set margins to 0
    ui->gridLayout->setSpacing(0);  // Set spacing between widgets to 0

    // this->setMinimumSize(382, 430);  // Optionally set a minimum size to avoid shrinking too much

    setButtonColorStates(this, "buttonEquals", "#DB9EE5", -13.0, -26.0, "#000000", 0, -47, true);
    //setButtonColorStates(this, "button3", "#3C3C3C", -15.0, -30.0, "#FFFFFF", 0.0, -10.0);
    // Iterate over all QPushButton objects and apply the color states except for buttonEquals
    QList<QPushButton*> pushButtons = this->findChildren<QPushButton*>();

    foreach(QPushButton* button, pushButtons) {
        if (button->objectName() != "buttonEquals") {
            setButtonColorStates(this, button->objectName(), "#3C3C3C", -14.0, -28.0, "#FFFFFF", 0.0, -10.0, false);
        }
    }

    // Initialize variables
    firstValue = 0.0;
    secondValue = 0.0;
    currentOperator = "";
    lastOperator = "";
    lastResult = 0.0;  // Initialize lastResult
    sqrtArgument = "";
    sqrArgument = "";
    invArgument = "";
    isNewEntry = true;
    lastPressedOperator = false;
    lastPressedOperand = false;  // Initialize lastPressedOperand
    lastPressedEqual = false;
    justPressedEqual = false;
    justPressedOperator = false;
    justPressedOperand = false;
    lastPressedDot = false;
    lastPressedBackspace = false;
    justPressedSqrt = false;
    lastPressedSqrt = false;
    justPressedSqr = false;
    lastPressedSqr = false;
    justPressedInv = false;
    lastPressedInv = false;
    lastPressedPM = false;
    resultNA = false;
    QString mainText;

    // Set the mainDisplay to "0" when the app starts
    mainText = "0";  // Initially empty
    firstValue = 0;
    secondValue = 0;
    lastSecondValue = 0;
    lastFirstValue = 0;
    // Hide the mainDisplay when the app starts


    // Connect digit buttons to slots
    connect(ui->button0, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button5, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button6, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button7, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button8, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);
    connect(ui->button9, &QPushButton::clicked, this, &MainWindow::onDigitButtonClicked);

    // Connect operator buttons to slots
    connect(ui->buttonPlus, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->buttonMinus, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->buttonMultiply, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->buttonDivide, &QPushButton::clicked, this, &MainWindow::onOperatorButtonClicked);
    connect(ui->buttonPM, &QPushButton::clicked, this, &MainWindow::onPMButtonClicked);
    connect(ui->buttonSqrt, &QPushButton::clicked, this, &MainWindow::onSqrtButtonClicked);
    connect(ui->buttonSqr, &QPushButton::clicked, this, &MainWindow::onSqrButtonClicked);
    connect(ui->buttonInv, &QPushButton::clicked, this, &MainWindow::onInvButtonClicked);


    // Connect equals button to slot
    connect(ui->buttonEquals, &QPushButton::clicked, this, &MainWindow::onEqualsButtonClicked);

    // Connect backspace button to slot
    connect(ui->buttonBackspace, &QPushButton::clicked, this, &MainWindow::onBackspaceButtonClicked);

    // Connect clear button to slot
    connect(ui->buttonClear, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);

    // Connect dot button to slot
    connect(ui->buttonDot, &QPushButton::clicked, this, &MainWindow::onDotButtonClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


// Function to calculate and return the result
double_mp MainWindow::calculateResult()
{
    double_mp result = 0.0;


    //qDebug() << lastOperator + "->" + mpToQString(secondValue);
    //qDebug() << justPressedOperand;
    //qDebug() << "lastFirstValue: " << mpToQString(lastFirstValue);
    //qDebug() << "lastSecondValue: " << mpToQString(lastSecondValue);

    if ((lastOperator == "/" || lastOperator == "÷") && !justPressedOperand && !lastPressedEqual && formatNumber(secondValue) == "0" && formatNumber(lastSecondValue) == "0" )
    {
        resultNA = true;
        mainText = "Error";
    }
    else
    {
        //qDebug() << "SecondValue: " << secondValue << "|" << "LastOperator: " << lastOperator;
        //qDebug() << "lastPressedEqual: " << justPressedEqual;
        /*if ((lastOperator == "/" || lastOperator == "÷") && secondValue == 0.0 && !lastPressedEqual && !justPressedOperand)
        {
            resultNA = true;
            mainText = "Error";
        }*/
        if (currentOperator == "+") {
            result = firstValue + secondValue;
        } else if (currentOperator == "-") {
            result = firstValue - secondValue;
        } else if (currentOperator == "*" || currentOperator == "×") {
            result = firstValue * secondValue;
        } else if (currentOperator == "/" || currentOperator == "÷") {
            if (secondValue != 0.0) {
                result = firstValue / secondValue;
            } else {
                if (justPressedEqual)
                {
                    mainText = "Error";
                    //ui->exDisplay->setText("");  // No operator, exDisplay should be empty
                    //ui->mainDisplay->setText("ERROR");
                }
                else if (!((mainText.contains(".") && !mainText.contains((" ")))))
                {
                    //resultNA = true;
                    //mainText = "Error";
                }
                else
                {

                }
                //qDebug() << "Error: Division by zero";
                return 0.0;
            }
        } else {
            //qDebug() << "KKKKK";
            // If no operator is selected, return the firstValue
            result = firstValue;
        }
    }
    return result;
}

QString MainWindow::formatNumber(double_mp value)
{
    QString result;
    int decimals = 12;  // Start with up to 12 decimal places

    // Convert double_mp to a string representation with specified decimals
    std::string valueStr = value.str(decimals, std::ios_base::fixed);  // Fixed-point notation
    result = QString::fromStdString(valueStr);  // Convert the string to a QString

    // Remove trailing zeros
    static const QRegularExpression trailingZerosPattern("0+$");
    result = result.remove(trailingZerosPattern);

    // Remove the decimal point if it's a whole number
    if (result.endsWith('.')) {
        result.chop(1);
    }

    int maxLength = 12;  // Maximum allowed length for the result
    int signLength = result.startsWith('-') ? 1 : 0;  // Length of the sign if negative

    // Check the length of the result excluding the sign
    int resultLength = result.length() - signLength;

    // If the total length exceeds maxLength, attempt to reduce decimals
    if (resultLength > maxLength) {
        int decimalIndex = result.indexOf('.');
        if (decimalIndex != -1) {
            // We have a decimal point; try reducing decimal places
            while (resultLength > maxLength && result.endsWith('0')) {
                result.chop(1);  // Remove trailing zero
                resultLength = result.length() - signLength;
            }
            // If the last character is a '.', remove it
            if (result.endsWith('.')) {
                result.chop(1);
                resultLength = result.length() - signLength;
            }
            // If still too long, remove decimal digits
            while (resultLength > maxLength && result.contains('.')) {
                int lastCharIndex = result.length() - 1;
                if (result[lastCharIndex] != '.') {
                    result.chop(1);  // Remove last character
                } else {
                    break;  // Stop if we reach the decimal point
                }
                resultLength = result.length() - signLength;
            }
            // If still too long, switch to scientific notation
            if (resultLength > maxLength) {
                result = QString::fromStdString(value.str(6, std::ios_base::scientific));
            }
        } else {
            // No decimal point and length exceeds maxLength; use scientific notation
            result = QString::fromStdString(value.str(6, std::ios_base::scientific));
        }
    }

    // Final check if result still exceeds maxLength after adjustments
    resultLength = result.length() - signLength;
    if (resultLength > maxLength) {
        result = QString::fromStdString(value.str(6, std::ios_base::scientific));
        resultLength = result.length() - signLength;
        // If still too long, set an error or overflow message
        if (resultLength > maxLength) {
            result = "Error";  // Or set mainText to "OVF" as per your application logic
        }
    }

    return result;
}








/*QString MainWindow::formatResult(double value)
{
    // Step 1: Round the value to 8 decimal places to avoid floating-point precision issues
    value = std::round(value * 1e8) / 1e8;

    // Step 2: Convert the value to a QString with a fixed number of decimal places (e.g., 8)
    QString result = QString::number(value, 'f', 8);

    // Step 3: Remove trailing zeros after the decimal point
    result = result.remove(QRegularExpression("0+$"));

    // Step 4: Remove the decimal point if there are no digits after it
    if (result.endsWith('.')) {
        result.chop(1);
    }

    return result;
}*/






// Function to print expression and result
void MainWindow::printExpressionAndResult()
{
    double_mp result = calculateResult();
    QString expressionStr;

    if (currentOperator.isEmpty()) {
        expressionStr = formatNumber(firstValue);
    } else {
        expressionStr = formatNumber(firstValue) + " " + currentOperator + " " + formatNumber(secondValue);
    }



    //qDebug() << "Expression: " << expressionStr;
    //qDebug() << "Result: " << mpToQString(result);
    //qDebug() << "mainText: " << mainText;
    double_mp penFirstValue = lastFirstValue;
    //qDebug() << "lastFirstValue: " << mpToQString(lastFirstValue) << "lastSecondValue: " << mpToQString(lastSecondValue);
    lastResult = result;
    lastFirstValue = firstValue;
    lastSecondValue = secondValue;
    //qDebug() << "lastFirstValue: " << mpToQString(lastFirstValue) << "lastSecondValue: " << mpToQString(lastSecondValue);


    // Extract the operator and operands from the expressionStr
    QStringList expressionParts = expressionStr.split(" ");
    QString leftOperand = expressionParts[0];
    QString operatorSymbol = (expressionParts.size() > 1) ? expressionParts[1] : "";
    QString rightOperand = (expressionParts.size() > 2) ? expressionParts[2] : "";


    //qDebug() << "leftOperand: " << expressionParts[0] << " | " << "operatorSymbol: " << operatorSymbol << " | " << "rightOperand: " << rightOperand;
    // Update exDisplay based on the expression
    if (mainText == "Error")
    {
        if (justPressedSqrt)
        {
            // Convert sqrtArgument to double_mp
            double_mp sqrtArgValue = double_mp(sqrtArgument.toStdString());
            double_mp sqrtResult = boost::multiprecision::sqrt(sqrtArgValue);
            QString equalsSymbol;

            if (sqrtResult != sqrtResult)  // Check for NaN
            {
                equalsSymbol = "";  // Don't show any symbol for NaN
                ui->exDisplay->setText("√(" + sqrtArgument + ")");
                ui->mainDisplay->setText("N/A");
            }
        }
        else if (justPressedInv)
        {
            // Convert sqrtArgument to double_mp
            double_mp invArgValue = double_mp(invArgument.toStdString());
            double_mp invResult = 1/invArgValue;
            QString equalsSymbol;


            equalsSymbol = "";  // Don't show any symbol for NaN
            ui->exDisplay->setText("1/" + invArgument);
            ui->mainDisplay->setText("N/A");
        }
        // New block to check for overflow or too-large results
        else if (penFirstValue.str().length() > 12 || lastSecondValue.str().length() > 12)
        {
            // Handle large numbers or overflow
            //ui->exDisplay->setText(formatNumber(penFirstValue) + " × " + formatNumber(lastSecondValue));
            ui->exDisplay->setText("");
            ui->mainDisplay->setText("OVF");  // Display Overflow or Error
        }
        else
        {
            // Default case for other errors
            //ui->exDisplay->setText(formatNumber(penFirstValue) + " ÷ " + formatNumber(lastSecondValue));
            ui->exDisplay->setText("");
            ui->mainDisplay->setText("N/A");
        }
    }
    else if (mainText == "OVF")
    {
        ui->exDisplay->setText("");
        ui->mainDisplay->setText("OVF");
    }
    else
    {
        //qDebug() << "operatorSymbol: " << operatorSymbol;
        if (justPressedSqrt)
        {
            // Convert sqrtArgument to double_mp
            double_mp sqrtArgValue = double_mp(sqrtArgument.toStdString());
            double_mp sqrtResult = boost::multiprecision::sqrt(sqrtArgValue);
            QString equalsSymbol;

            // Check if sqrtResult is an integer
            double_mp fractionalPart = sqrtResult - boost::multiprecision::floor(sqrtResult);

            if (abs(fractionalPart) < double_mp("1e-12") && operatorSymbol.isEmpty())
            {
                equalsSymbol = " =";
                ui->exDisplay->setText("√" + sqrtArgument + equalsSymbol);
            }
            else if (operatorSymbol.isEmpty())
            {
                equalsSymbol = " ≈";
                ui->exDisplay->setText("√" + sqrtArgument + equalsSymbol);
            }
        }
        else if (justPressedInv)
        {
            if (operatorSymbol.isEmpty())
            {
                // Convert sqrtArgument to double_mp
                double_mp invArgValue = double_mp(invArgument.toStdString());
                double_mp invResult = 1/invArgValue;

                if (invArgValue < 0)
                {
                    ui->exDisplay->setText("1/(" + invArgument + ") =");
                }
                else
                {
                    ui->exDisplay->setText("1/" + invArgument + " =");
                }
            }

        }
        else if (justPressedSqr)
        {
            if (operatorSymbol.isEmpty())
            {
                if (sqrArgument.contains("-"))
                {
                    ui->exDisplay->setText("(" + sqrArgument + ")²" + " =");  // Display sqrtArgument (string)
                }
                else
                {
                    // Convert sqrtArgument (string) to double for sqrtResult calculation
                    ui->exDisplay->setText(sqrArgument + "²" + " =");  // Display sqrtArgument (string)
                }
            }
            // Update exDisplay with the appropriate symbol
        }
        else if (operatorSymbol.isEmpty()) {

            if (justPressedEqual)
            {
                ui->exDisplay->setText(leftOperand + " =");  // No operator, exDisplay should be empty
                ui->mainDisplay->setText(leftOperand);
            }
            else
            {
                if (lastPressedSqrt)
                {
                    ui->exDisplay->setText("");  // No operator, exDisplay should be empty
                }
                if (lastPressedSqr)
                {
                    ui->exDisplay->setText("");
                }
                if (lastPressedInv)
                {
                    ui->exDisplay->setText("");
                }
                ui->exDisplay->setText("");  // No operator, exDisplay should be empty
                if (mainText.contains(".") && !mainText.contains((" ")))
                {
                    ui->mainDisplay->setText(mainText);
                }
                else
                {
                    ui->mainDisplay->setText(leftOperand);
                }
            }

        } else if (!justPressedEqual) {
            ui->exDisplay->setText(leftOperand + " " + operatorSymbol);  // Show left operand and operator
            if (mainText.contains(".") && !mainText.contains((" ")))
            {
                ui->mainDisplay->setText(mainText);
            }
            else
            {
                ui->mainDisplay->setText(rightOperand);
            }
        }
        else
        {
            double_mp rightOperandValue = double_mp(rightOperand.toStdString());

            if (rightOperandValue < 0)
            {
                QString sanitizedExpression = formatNumber(firstValue) + " " + currentOperator + " (" + formatNumber(secondValue) + ")";
                ui->exDisplay->setText(sanitizedExpression + " =");
            }
            else
            {
                ui->exDisplay->setText(expressionStr + " =");
            }
            ui->mainDisplay->setText(formatNumber(result));
        }
    }
}

void MainWindow::onDigitButtonClicked()
{
    if ((ui->mainDisplay->text() == "N/A") || (ui->mainDisplay->text() == "OVF") || (ui->mainDisplay->text() == "Error") || (lastPressedSqrt && currentOperator == "") || (lastPressedSqr && currentOperator == "") || (lastPressedInv && currentOperator == ""))
    {
        onClearButtonClicked();
    }
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString digit = button->text();
    justPressedOperand = true;


    // If the last action was pressing '=', reset the expression
    if ((!lastPressedOperator && !lastPressedOperand && !lastPressedBackspace && !lastPressedPM)) {
        //qDebug() << lastPressedOperator << " | " << lastPressedOperand;
        firstValue = digit.toDouble();  // Set firstValue to the new digit
        secondValue = 0.0;  // Reset secondValue
        currentOperator = "";  // Clear the operator
        mainText = digit;  // mainDisplay the new digit
        isNewEntry = true;  // Mark as new entry
        lastPressedBackspace = false;
    } else {
        // //qDebug() << lastPressedOperator << " | " << lastPressedOperand;
        // If the last pressed button was an operator, start a new entry
        if (lastPressedBackspace && (mainText != "0"))
        {
            // Check if the current number already has more than 10 decimal places

            // Calculate the length of the number, ignoring the '-' sign
            int lengthWithoutMinus = mainText.length() - (mainText.startsWith('-') ? 1 : 0);

            // If the length exceeds 12 characters, do nothing
            if (lengthWithoutMinus >= 11) {
                return;  // Do nothing if the number is already 12 characters long or more
            }


            mainText = mainText + digit;
        }
        else if (lastPressedOperator || lastPressedSqrt || lastPressedSqr || lastPressedInv) {
            mainText = digit;
            lastPressedOperator = false;
            lastPressedBackspace = false;
            isNewEntry = false;
        }
        /*else if (mainText != "0"){

            // Append the new digit to the existing number
            mainText = mainText + digit;
        }*/
        else
        {
            if (mainText == "0" || (lastPressedBackspace && !lastPressedPM))
            {
                mainText = digit;
            }
            else
            {
                // Check if the current number already has more than 10 decimal places

                int lengthWithoutMinus = mainText.length() - (mainText.startsWith('-') ? 1 : 0);

                // If the length exceeds 12 characters, do nothing
                if (lengthWithoutMinus >= 11) {
                    return;  // Do nothing if the number is already 12 characters long or more
                }


                mainText = mainText + digit;
            }
            lastPressedBackspace = false;
            //mainText = digit;
        }

        //qDebug() << mainText;
    }


    // Update the current value based on the mainDisplay
    if (currentOperator.isEmpty()) {
        firstValue = double_mp(mainText.toStdString());
    } else {
        secondValue = double_mp(mainText.toStdString());
    }


    justPressedEqual = false;
    justPressedSqr = false;
    justPressedSqrt = false;
    justPressedInv = false;
    // Print the expression and result to the console
    printExpressionAndResult();
    lastPressedPM = false;
    lastPressedDot = false;
    lastPressedSqrt = false;
    lastPressedSqr = false;
    lastPressedInv = false;
    lastPressedOperand = true;  // Mark as operand pressed
    lastPressedEqual = false;
}

void MainWindow::onPMButtonClicked()
{
    if (ui->mainDisplay->text() == "N/A") {
        return;
    }

    // Handle the case where lastPressedEqual was true
    if (lastPressedEqual || lastPressedSqrt || lastPressedSqr || lastPressedInv) {
        // Clear the current expression and start with the negated value
        currentOperator = "";
        secondValue = 0.0;
        lastPressedEqual = false;

        // Negate the mainText value
        double_mp value = double_mp(mainText.toStdString());
        value = -value;
        mainText = formatNumber(value);

        // Update the main display
        ui->mainDisplay->setText(mainText);

        // Set firstValue to the new negated value
        firstValue = value;
        justPressedEqual = false;
    }
    else {
        // Negate the current mainText value
        double_mp value = double_mp(mainText.toStdString());
        value = -value;
        mainText = formatNumber(value);

        // Update the main display
        ui->mainDisplay->setText(mainText);

        // Update the firstValue or secondValue depending on the current operator
        if (currentOperator.isEmpty()) {
            firstValue = value;
        } else {
            secondValue = value;
        }
    }

    justPressedEqual = false;
    justPressedSqrt = false;
    justPressedSqr = false;
    justPressedInv = false;

    printExpressionAndResult();

    lastPressedSqr = false;
    lastPressedInv = false;
    lastPressedSqrt = false;
    lastPressedPM = true;
}

void MainWindow::onInvButtonClicked()
{
    justPressedInv = true;
    justPressedSqrt = false;
    justPressedSqr = false;

    if (ui->mainDisplay->text() == "N/A") {
        return;
    }

    if (mainText.isEmpty())
    {
        mainText = "0";
    }

    // Store the current value of mainText before calculating the square root
    invArgument = mainText;

    // Handle the case where lastPressedEqual was true
    if (lastPressedEqual) {
        // Clear the current expression and start with the square root of the current value
        currentOperator = "";
        secondValue = 0.0;
        lastPressedEqual = false;

        // Convert mainText to double_mp
        double_mp value = lastResult;//double_mp(mainText.toStdString());

        if (value == 0) {
            // Square root of negative number
            firstValue = 0.0;
            mainText = "Error";
            //qDebug() << "Zero numitor input.";
        } else {
            // Calculate the square root using boost::multiprecision::sqrt
            value = 1/value;

            // Set mainText to the formatted value
            mainText = formatNumber(value);
            ui->mainDisplay->setText(mainText);

            // Set firstValue to the new square root value
            firstValue = value;
        }
        justPressedEqual = false;
    }
    else {
        //qDebug() << "Calculating inv.";

        // Convert mainText to double_mp
        double_mp value; //double_mp(mainText.toStdString());

        if (currentOperator.isEmpty())
        {
            if (lastResult == 0)
            {
                firstValue = 0.0;
                mainText = "Error";
                //qDebug() << "Zero numitor input.";
            }
            else
            {
                value = 1/lastResult;
                firstValue = value;
                // Set mainText to the formatted value
                mainText = formatNumber(value);
                ui->mainDisplay->setText(mainText);
            }
        }
        else
        {
            if (secondValue == 0)
            {
                mainText = "Error";
                //qDebug() << "Zero numitor input.";
            }
            else
            {
                value = 1/secondValue;
                secondValue = value;
                //qDebug() << "secondValue: " << mpToQString(secondValue);
                mainText = formatNumber(secondValue);
                ui->mainDisplay->setText(mainText);
            }
        }
    }
    // Print the expression and result to the console
    printExpressionAndResult();
    lastPressedSqrt = false;
    lastPressedSqr = false;
    lastPressedInv = true;
}



void MainWindow::onSqrButtonClicked()
{
    justPressedSqr = true;
    justPressedInv = false;
    justPressedSqrt = false;

    if (ui->mainDisplay->text() == "N/A") {
        return;
    }

    if (mainText.isEmpty())
    {
        mainText = "0";
    }

    // Store the current value of mainText before calculating the square root
    sqrArgument = mainText;

    // Handle the case where lastPressedEqual was true
    if (lastPressedEqual) {
        // Clear the current expression and start with the square root of the current value
        currentOperator = "";
        secondValue = 0.0;
        lastPressedEqual = false;

        // Convert mainText to double_mp
        double_mp value = lastResult;//double_mp(mainText.toStdString());


        value = value * value;

        // Set mainText to the formatted value
        mainText = formatNumber(value);
        ui->mainDisplay->setText(mainText);

        // Set firstValue to the new square root value
        firstValue = value;

        justPressedEqual = false;
    }
    else {
        //qDebug() << "Calculating square root.";

        // Convert mainText to double_mp
        double_mp value; //double_mp(mainText.toStdString());

        if (currentOperator.isEmpty())
        {

            value = lastResult * lastResult;
            firstValue = value;
            // Set mainText to the formatted value
            mainText = formatNumber(value);
            ui->mainDisplay->setText(mainText);

        }
        else
        {
            value = secondValue * secondValue;
            secondValue = value;
            //qDebug() << "secondValue: " << mpToQString(secondValue);
            mainText = formatNumber(secondValue);
            ui->mainDisplay->setText(mainText);
        }
    }

    // Print the expression and result to the console
    printExpressionAndResult();
    lastPressedSqr = true;
    lastPressedSqrt = false;
    lastPressedInv = false;
}


void MainWindow::onSqrtButtonClicked()
{
    justPressedSqrt = true;
    justPressedSqr = false;
    justPressedInv = false;
    if (ui->mainDisplay->text() == "N/A") {
        return;
    }

    if (mainText.isEmpty())
    {
        mainText = "0";
    }

    // Store the current value of mainText before calculating the square root
    sqrtArgument = mainText;

    // Handle the case where lastPressedEqual was true
    if (lastPressedEqual) {
        // Clear the current expression and start with the square root of the current value
        currentOperator = "";
        secondValue = 0.0;
        lastPressedEqual = false;

        // Convert mainText to double_mp
        double_mp value = lastResult; //double_mp(mainText.toStdString());

        if (value < 0) {
            // Square root of negative number
            firstValue = 0.0;
            mainText = "Error";
            //qDebug() << "Negative input for square root.";
        } else {
            // Calculate the square root using boost::multiprecision::sqrt
            value = boost::multiprecision::sqrt(value);

            // Set mainText to the formatted value
            mainText = formatNumber(value);
            ui->mainDisplay->setText(mainText);

            // Set firstValue to the new square root value
            firstValue = value;
        }
        justPressedEqual = false;
    }
    else {
        //qDebug() << "Calculating square root.";

        // Convert mainText to double_mp
        double_mp value; //double_mp(mainText.toStdString());

        if (currentOperator.isEmpty())
        {
            if (lastResult < 0)
            {
                firstValue = 0.0;
                mainText = "Error";
                //qDebug() << "Negative input for square root.";
            }
            else
            {
                value = boost::multiprecision::sqrt(lastResult);
                firstValue = value;
                // Set mainText to the formatted value
                mainText = formatNumber(value);
                ui->mainDisplay->setText(mainText);
            }
        }
        else
        {
            if (secondValue < 0)
            {
                mainText = "Error";
                //qDebug() << "Negative input for square root.";
            }
            else
            {
                value = boost::multiprecision::sqrt(secondValue);
                secondValue = value;
                //qDebug() << "secondValue: " << mpToQString(secondValue);
                mainText = formatNumber(secondValue);
                ui->mainDisplay->setText(mainText);
            }
        }
    }
    // Print the expression and result to the console
    printExpressionAndResult();
    lastPressedSqrt = true;
    lastPressedSqr = false;
    lastPressedInv = false;
}




void MainWindow::onOperatorButtonClicked()
{
    if ((ui->mainDisplay->text() == "N/A"))
    {
        return;
    }
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString newOperator = button->text();
    justPressedOperator = true;
    justPressedOperand = false;
    if (!currentOperator.isEmpty() && (lastPressedOperator == false || lastPressedBackspace)) {
        // After '=', use the last result for the next operation
        firstValue = lastResult;
        secondValue = firstValue;
    }
    else if (!currentOperator.isEmpty() && lastPressedOperator == false) {
        // Calculate the result if there's already an operator and the last button pressed wasn't an operator
        firstValue = calculateResult();
    }

    // If the last action was not '=', reset the second operand to match the first operand
    else if (!currentOperator.isEmpty() && lastPressedOperator) {
        secondValue = firstValue;
    }     // Check if the last action was '=', and update the operands accordingly
    /*else if (!currentOperator.isEmpty() && lastPressedOperand & lastPressedOperator) {
        firstValue = lastResult;
        secondValue = firstValue;
    }*/

    else {
        secondValue = firstValue;
    }


    lastOperator = currentOperator;
    // Update the operator
    currentOperator = newOperator;

    // mainDisplay the expression as "firstValue operator firstValue"
    //mainText = QString::number(firstValue) + " " + currentOperator + " " + QString::number(secondValue);
    mainText = formatNumber(secondValue);


    //
    justPressedEqual = false;
    justPressedSqrt = false;
    justPressedSqr = false;
    justPressedInv = false;
    // Print the expression and result to the console
    printExpressionAndResult();
    lastPressedOperator = true;
    lastPressedEqual = false;
    lastPressedSqrt = false;
    lastPressedSqr = false;
    lastPressedInv = false;
    lastPressedPM = false;
    lastPressedDot = false;
    lastPressedBackspace = false;
    lastPressedOperand = false;


}



void MainWindow::onEqualsButtonClicked()
{
    justPressedEqual = true;
    justPressedSqrt = false;
    justPressedSqr = false;
    justPressedInv = false;

    if (mainText == "Error")
    {
        onClearButtonClicked();
    }
    // Check if the last character of mainDisplay is a dot
    QString currentText = ui->mainDisplay->text();
    if (currentText.endsWith(".")) {
        // Remove the trailing dot
        currentText.chop(1);
        ui->mainDisplay->setText(currentText);
        //mainText = currentText;  // Update mainText as well
    }

    //if (!currentOperator.isEmpty()) {
    // Perform the calculation
    double_mp result = calculateResult();
    //qDebug() << "Result is: " << mpToQString(result);


    // Update the mainDisplay to show the full expression, not just the result
    mainText = formatNumber(result);
    //qDebug() << "mainText: " << mainText;
    // Print the expression and result to the console
    printExpressionAndResult();

    // After showing the result, continue with the last operator and operand for next calculations
    firstValue = result;
    // Keep secondValue as is, so it can be reused with the same operator
    //}



    lastPressedOperand = false;
    lastPressedOperator = false;  // Set this to false as the last action is now pressing '='
    lastPressedEqual = true;
    lastPressedDot = false;
    lastPressedBackspace = false;
}


void MainWindow::onClearButtonClicked()
{
    firstValue = 0.0;
    secondValue = 0.0;
    currentOperator = "";
    mainText = "0";
    isNewEntry = true;

    justPressedEqual = false;
    justPressedSqrt = false;
    justPressedSqr = false;
    justPressedInv = false;
    justPressedOperator = false;
    justPressedOperand = false;
    lastOperator = "";
    //qDebug() <<"justPressedSqrt: " << justPressedSqrt;
    printExpressionAndResult();

    lastPressedOperator = false;
    lastPressedSqrt = false;
    lastPressedSqr = false;
    lastPressedInv = false;
    lastPressedPM = false;
    lastPressedEqual = false;
    lastPressedBackspace = false;

    // Print the cleared state to the console
    //qDebug() << "Expression cleared.";
}

void MainWindow::onBackspaceButtonClicked()
{
    if (mainText.contains("e") || mainText.contains("inf") || mainText.contains("N/A") || mainText.contains("ovf"))
    {
        return;
    }
    //qDebug() << "firstVaalue: " << lastResult << " | " << "secondValue: " << secondValue;
    if (lastPressedEqual || (lastPressedSqrt && currentOperator == "") || (lastPressedSqr && currentOperator == "") || (lastPressedInv && currentOperator == ""))
    {
        double_mp newValue = firstValue;
        //qDebug() << newValue;
        onClearButtonClicked();
        // Convert newValue to string and extract the part before "e"
        mainText = formatNumber(newValue);
        //mainText = QString::number(newValue);
    }
    /*
    else if (lastPressedOperator)
    {
        double newValue = firstValue;
        mainText = formatNumber(newValue);
    }*/
    if (mainText.length() > 1 && (!lastPressedEqual)) {
        // Remove the last character from mainText
        mainText.chop(1);
    } else {
        // If only one character left, reset to 0
        mainText = "0";
    }

    // Update the display
    ui->mainDisplay->setText(mainText);

    // Update the firstValue or secondValue depending on the context
    if (currentOperator.isEmpty()) {
        firstValue = double_mp(mainText.toStdString());
    } else if  (!lastPressedEqual){
        secondValue = double_mp(mainText.toStdString());
    }

    lastPressedBackspace = true;
    lastPressedSqrt = false;
    lastPressedPM = false;
    lastPressedOperator = false;
    // Recalculate the result and update the displays
    printExpressionAndResult();
}


void MainWindow::onDotButtonClicked()
{
    justPressedEqual = false;
    justPressedSqrt = false;
    justPressedSqr = false;
    justPressedInv = false;
    if ((lastPressedEqual) && !lastPressedBackspace)
    {
        lastOperator = "";
        firstValue = 0.0;
        secondValue = 0.0;
        currentOperator = "";
        isNewEntry = true;
        // Reset displays and mainText
        mainText = "0.";  // Set mainText to "0."
        ui->mainDisplay->setText("0.");  // Reset mainDisplay to "0."
        ui->exDisplay->setText("");  // Clear exDisplay if needed

        // Reset flags
        lastPressedEqual = false;
    }
    else if (lastPressedOperator || lastPressedSqrt || lastPressedSqr || lastPressedInv)
    {
        mainText = "0.";  // Set mainText to "0."
        secondValue = 0.0;
        lastPressedOperator = false;
    }
    else if (!mainText.contains(".")) {
        int lengthWithoutMinus = mainText.length() - (mainText.startsWith('-') ? 1 : 0);

        // If the length exceeds 12 characters, do nothing
        if (lengthWithoutMinus >= 10) {
            return;  // Do nothing if the number is already 12 characters long or more
        }
        mainText = mainText + ".";
        // Make the dot visible in mainDisplay
        ui->mainDisplay->setText(ui->mainDisplay->text() + ".");
    }

    printExpressionAndResult();

    lastPressedOperand = true;  // Mark as operand pressed
    lastPressedDot = true;
    lastPressedBackspace = false;
    lastPressedSqrt = false;
    lastPressedInv = false;
    lastPressedPM = false;

}
