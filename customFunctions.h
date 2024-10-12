#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H

#include <QWidget>
#include <QString>
#include <QColor>
#include <QLineEdit>
#include <QDebug>
#include <QPushButton>
#include "PrecisionTypes.h"  // Include the centralized typedef

// Function to extract the part before "e" in scientific notation

// Inline function to ensure definition is available in all translation units
inline QString mpToQString(const double_mp& value)
{
    return QString::fromStdString(value.str());
}

inline QString extractBeforeE(const QString &numberStr) {
    int eIndex = numberStr.indexOf('e');
    if (eIndex != -1) {
        // Return the substring before 'e'
        return numberStr.left(eIndex+1);
    }
    return numberStr;  // If no 'e', return the original string
}

inline void setTextColor(QWidget *parentWidget, const QString &objectName, const QString &colorHex)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the widget by object name
    QWidget *widget = parentWidget->findChild<QWidget*>(objectName);
    if (!widget) {
        qDebug() << "Widget with object name" << objectName << "not found!";
        return;
    }

    // Create a QColor object from the hexadecimal color code
    QColor color(colorHex);

    // Check if the color is valid
    if (!color.isValid()) {
        qDebug() << "Invalid color code:" << colorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString colorString = color.name();
    // Apply stylesheet to set the text color
    widget->setStyleSheet(QString("color: %1;").arg(colorString));
}

inline void setButtonColors(QWidget *parentWidget, const QString &objectName, const QString &backgroundColorHex, const QString &textColorHex)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the QPushButton by object name
    QPushButton *button = parentWidget->findChild<QPushButton*>(objectName);
    if (!button) {
        qDebug() << "QPushButton with object name" << objectName << "not found!";
        return;
    }

    // Create QColor objects from the hexadecimal color codes
    QColor backgroundColor(backgroundColorHex);
    QColor textColor(textColorHex);

    // Check if the colors are valid
    if (!backgroundColor.isValid()) {
        qDebug() << "Invalid background color code:" << backgroundColorHex;
        return;
    }

    if (!textColor.isValid()) {
        qDebug() << "Invalid text color code:" << textColorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString backgroundColorString = backgroundColor.name();
    QString textColorString = textColor.name();

    // Apply stylesheet to set the background and text color
    button->setStyleSheet(QString("background-color: %1; color: %2;").arg(backgroundColorString, textColorString));
}

// Function to adjust color brightness by a percentage
inline QString adjustColorBrightness(const QString &colorHex, double percent)
{
    QColor color(colorHex);
    int r = color.red();
    int g = color.green();
    int b = color.blue();

    // Adjust the color components based on the percentage
    r = std::max(0, std::min(255, static_cast<int>(r + (r * (percent / 100.0)))));
    g = std::max(0, std::min(255, static_cast<int>(g + (g * (percent / 100.0)))));
    b = std::max(0, std::min(255, static_cast<int>(b + (b * (percent / 100.0)))));

    return QColor(r, g, b).name();
}

// Function to adjust color opacity (alpha channel) by a percentage
inline QString adjustColorOpacity(const QString &colorHex, double percent)
{
    QColor color(colorHex);
    int alpha = color.alpha();

    // Adjust the alpha component based on the percentage
    alpha = std::max(0, std::min(255, static_cast<int>(alpha + (alpha * (percent / 100.0)))));

    color.setAlpha(alpha);
    return color.name(QColor::HexArgb);  // Return the color with the alpha channel
}

/*inline void setButtonColorStates(QWidget *parentWidget, const QString &objectName, const QString &backgroundColorHex, double hoverPercent = 20.0, double pressedPercent = -20.0, const QString &textColorHex = "#FFFFFF", double hoverTextPercent = 0.0, double pressedTextPercent = -2.0)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the QPushButton by object name
    QPushButton *button = parentWidget->findChild<QPushButton*>(objectName);
    if (!button) {
        qDebug() << "QPushButton with object name" << objectName << "not found!";
        return;
    }

    // Create QColor objects from the hexadecimal color codes
    QColor backgroundColor(backgroundColorHex);
    QColor textColor(textColorHex);

    // Check if the colors are valid
    if (!backgroundColor.isValid()) {
        qDebug() << "Invalid background color code:" << backgroundColorHex;
        return;
    }

    if (!textColor.isValid()) {
        qDebug() << "Invalid text color code:" << textColorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString backgroundColorString = backgroundColor.name();
    QString textColorString = textColor.name();

    // Calculate hover and pressed colors for background
    QString hoverColor = adjustColorBrightness(backgroundColorHex, hoverPercent);
    QString pressedColor = adjustColorBrightness(backgroundColorHex, pressedPercent);

    // Calculate hover and pressed colors for text
    QString hoverTextColor = adjustColorBrightness(textColorHex, hoverTextPercent);
    QString pressedTextColor = adjustColorBrightness(textColorHex, pressedTextPercent);

    // Apply stylesheet to set the background, text, hover, and pressed colors using the multi-arg version of QString::arg()
    button->setStyleSheet(QString("QPushButton#%1 { background-color: %2; color: %3; } QPushButton#%1:hover { background-color: %4; color: %5; } QPushButton#%1:pressed { background-color: %6; color: %7; }")
                              .arg(objectName, backgroundColorString, textColorString, hoverColor, hoverTextColor, pressedColor, pressedTextColor));
}
*/

// Function to set button color states with text color and border color adjustments or opacity adjustments
inline void setButtonColorStatesV2(QWidget *parentWidget, const QString &objectName, const QString &backgroundColorHex, double hoverPercent = 20.0, double pressedPercent = -20.0, const QString &textColorHex = "#FFFFFF", double hoverTextPercent = 0.0, double pressedTextPercent = -2.0, const QString &borderColorHex = "#000000", double hoverBorderPercent = 20.0, double pressedBorderPercent = -20.0, bool adjustOpacity = false)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the QPushButton by object name
    QPushButton *button = parentWidget->findChild<QPushButton*>(objectName);
    if (!button) {
        qDebug() << "QPushButton with object name" << objectName << "not found!";
        return;
    }

    // Create QColor objects from the hexadecimal color codes
    QColor backgroundColor(backgroundColorHex);
    QColor textColor(textColorHex);
    QColor borderColor(borderColorHex);

    // Check if the colors are valid
    if (!backgroundColor.isValid()) {
        qDebug() << "Invalid background color code:" << backgroundColorHex;
        return;
    }

    if (!textColor.isValid()) {
        qDebug() << "Invalid text color code:" << textColorHex;
        return;
    }

    if (!borderColor.isValid()) {
        qDebug() << "Invalid border color code:" << borderColorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString backgroundColorString = backgroundColor.name();
    QString textColorString = textColor.name();
    QString borderColorString = borderColor.name();

    // Calculate hover and pressed colors for background
    QString hoverColor = adjustColorBrightness(backgroundColorHex, hoverPercent);
    QString pressedColor = adjustColorBrightness(backgroundColorHex, pressedPercent);

    // Calculate hover and pressed colors for border
    QString hoverBorderColor = adjustColorBrightness(borderColorHex, hoverBorderPercent);
    QString pressedBorderColor = adjustColorBrightness(borderColorHex, pressedBorderPercent);

    // Calculate hover and pressed colors or opacity for text
    QString hoverTextColor, pressedTextColor;

    if (adjustOpacity) {
        hoverTextColor = adjustColorOpacity(textColorHex, hoverTextPercent);
        pressedTextColor = adjustColorOpacity(textColorHex, pressedTextPercent);
    } else {
        hoverTextColor = adjustColorBrightness(textColorHex, hoverTextPercent);
        pressedTextColor = adjustColorBrightness(textColorHex, pressedTextPercent);
    }

    // Apply stylesheet to set the background, text, hover, pressed, and border colors
    button->setStyleSheet(QString(
                              "QPushButton#%1 { background-color: %2; color: %3; border: 2px solid %8; border-radius: 10px; }"
                              "QPushButton#%1:hover { background-color: %4; color: %5; border: 2px solid %9; }"
                              "QPushButton#%1:pressed { background-color: %6; color: %7; border: 2px solid %10; }"
                              ).arg(objectName)
                              .arg(backgroundColorString)
                              .arg(textColorString)
                              .arg(hoverColor)
                              .arg(hoverTextColor)
                              .arg(pressedColor)
                              .arg(pressedTextColor)
                              .arg(borderColorString)
                              .arg(hoverBorderColor)
                              .arg(pressedBorderColor));
}

// Function to set button color states with text color adjustments or opacity adjustments
inline void setButtonColorStates(QWidget *parentWidget, const QString &objectName, const QString &backgroundColorHex, double hoverPercent = 20.0, double pressedPercent = -20.0, const QString &textColorHex = "#FFFFFF", double hoverTextPercent = 0.0, double pressedTextPercent = -2.0, bool adjustOpacity = false)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the QPushButton by object name
    QPushButton *button = parentWidget->findChild<QPushButton*>(objectName);
    if (!button) {
        qDebug() << "QPushButton with object name" << objectName << "not found!";
        return;
    }

    // Create QColor objects from the hexadecimal color codes
    QColor backgroundColor(backgroundColorHex);
    QColor textColor(textColorHex);

    // Check if the colors are valid
    if (!backgroundColor.isValid()) {
        qDebug() << "Invalid background color code:" << backgroundColorHex;
        return;
    }

    if (!textColor.isValid()) {
        qDebug() << "Invalid text color code:" << textColorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString backgroundColorString = backgroundColor.name();
    QString textColorString = textColor.name();

    // Calculate hover and pressed colors for background
    QString hoverColor = adjustColorBrightness(backgroundColorHex, hoverPercent);
    QString pressedColor = adjustColorBrightness(backgroundColorHex, pressedPercent);

    // Calculate hover and pressed colors or opacity for text
    QString hoverTextColor, pressedTextColor;

    if (adjustOpacity) {
        hoverTextColor = adjustColorOpacity(textColorHex, hoverTextPercent);
        pressedTextColor = adjustColorOpacity(textColorHex, pressedTextPercent);
    } else {
        hoverTextColor = adjustColorBrightness(textColorHex, hoverTextPercent);
        pressedTextColor = adjustColorBrightness(textColorHex, pressedTextPercent);
    }

    // Apply stylesheet to set the background, text, hover, and pressed colors
    button->setStyleSheet(QString(
                              "QPushButton#%1 { background-color: %2; color: %3; }"
                              "QPushButton#%1:hover { background-color: %4; color: %5; }"
                              "QPushButton#%1:pressed { background-color: %6; color: %7; }"
                              ).arg(objectName)
                              .arg(backgroundColorString)
                              .arg(textColorString)
                              .arg(hoverColor)
                              .arg(hoverTextColor)
                              .arg(pressedColor)
                              .arg(pressedTextColor));
}




// Function to adjust the RGB values of a color
inline QColor adjustColor(QColor color, int rAdjust, int gAdjust, int bAdjust)
{
    int r = std::max(0, std::min(255, color.red() + rAdjust));
    int g = std::max(0, std::min(255, color.green() + gAdjust));
    int b = std::max(0, std::min(255, color.blue() + bAdjust));
    return QColor(r, g, b);
}

// Function to set the button colors with hover and clicked states
inline void setButtonColorsWithStates(QWidget *parentWidget, const QString &objectName, const QString &normalColorHex, int rHoverAdjust, int gHoverAdjust, int bHoverAdjust, int rClickAdjust, int gClickAdjust, int bClickAdjust, const QString &textColorHex)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    QPushButton *button = parentWidget->findChild<QPushButton*>(objectName);
    if (!button) {
        qDebug() << "QPushButton with object name" << objectName << "not found!";
        return;
    }

    QColor normalColor(normalColorHex);
    QColor textColor(textColorHex);

    if (!normalColor.isValid() || !textColor.isValid()) {
        qDebug() << "Invalid color code(s):" << normalColorHex << "or" << textColorHex;
        return;
    }

    QColor hoverColor = adjustColor(normalColor, rHoverAdjust, gHoverAdjust, bHoverAdjust);
    QColor clickedColor = adjustColor(hoverColor, rClickAdjust, gClickAdjust, bClickAdjust);

    button->setStyleSheet(QString(
                              "QPushButton { background-color: %1; color: %2; }"
                              "QPushButton:hover { background-color: %3; }"
                              "QPushButton:pressed { background-color: %4; }"
                              ).arg(normalColor.name(), textColor.name(), hoverColor.name(), clickedColor.name()));
}

// Function to set QLineEdit color states with text color adjustments or opacity adjustments
inline void setLineEditColorStates(QWidget *parentWidget, const QString &objectName, const QString &backgroundColorHex, double hoverPercent = 20.0, double focusPercent = -20.0, const QString &textColorHex = "#000000", double hoverTextPercent = 0.0, double focusTextPercent = -2.0, bool adjustOpacity = false)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the QLineEdit by object name
    QLineEdit *lineEdit = parentWidget->findChild<QLineEdit*>(objectName);
    if (!lineEdit) {
        qDebug() << "QLineEdit with object name" << objectName << "not found!";
        return;
    }

    // Create QColor objects from the hexadecimal color codes
    QColor backgroundColor(backgroundColorHex);
    QColor textColor(textColorHex);

    // Check if the colors are valid
    if (!backgroundColor.isValid()) {
        qDebug() << "Invalid background color code:" << backgroundColorHex;
        return;
    }

    if (!textColor.isValid()) {
        qDebug() << "Invalid text color code:" << textColorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString backgroundColorString = backgroundColor.name();
    QString textColorString = textColor.name();

    // Calculate hover and focus colors for background
    QString hoverColor = adjustColorBrightness(backgroundColorHex, hoverPercent);
    QString focusColor = adjustColorBrightness(backgroundColorHex, focusPercent);

    // Calculate hover and focus colors or opacity for text
    QString hoverTextColor, focusTextColor;

    if (adjustOpacity) {
        hoverTextColor = adjustColorOpacity(textColorHex, hoverTextPercent);
        focusTextColor = adjustColorOpacity(textColorHex, focusTextPercent);
    } else {
        hoverTextColor = adjustColorBrightness(textColorHex, hoverTextPercent);
        focusTextColor = adjustColorBrightness(textColorHex, focusTextPercent);
    }

    // Apply stylesheet to set the background, text, hover, and focus colors
    lineEdit->setStyleSheet(QString(
                                "QLineEdit#%1 { background-color: %2; color: %3; }"
                                "QLineEdit#%1:hover { background-color: %4; color: %5; }"
                                "QLineEdit#%1:focus { background-color: %6; color: %7; }"
                                ).arg(objectName)
                                .arg(backgroundColorString)
                                .arg(textColorString)
                                .arg(hoverColor)
                                .arg(hoverTextColor)
                                .arg(focusColor)
                                .arg(focusTextColor));
}

// Function to set the background color for any QWidget with hover and focus adjustments
inline void setWidgetBackgroundColorStates(QWidget *parentWidget, const QString &objectName, const QString &backgroundColorHex, double hoverPercent = 20.0, double focusPercent = -20.0)
{
    if (!parentWidget) {
        qDebug() << "Parent widget pointer is null!";
        return;
    }

    // Find the QWidget by object name
    QWidget *widget = parentWidget->findChild<QWidget*>(objectName);
    if (!widget) {
        qDebug() << "QWidget with object name" << objectName << "not found!";
        return;
    }

    // Create QColor objects from the hexadecimal color code
    QColor backgroundColor(backgroundColorHex);

    // Check if the color is valid
    if (!backgroundColor.isValid()) {
        qDebug() << "Invalid background color code:" << backgroundColorHex;
        return;
    }

    // Convert QColor to #RRGGBB string
    QString backgroundColorString = backgroundColor.name();

    // Calculate hover and focus colors for background
    QString hoverColor = adjustColorBrightness(backgroundColorHex, hoverPercent);
    QString focusColor = adjustColorBrightness(backgroundColorHex, focusPercent);

    // Apply stylesheet to set the background, hover, and focus colors
    widget->setStyleSheet(QString(
                              "QWidget#%1 { background-color: %2; }"
                              "QWidget#%1:hover { background-color: %3; }"
                              "QWidget#%1:focus { background-color: %4; }"
                              ).arg(objectName)
                              .arg(backgroundColorString)
                              .arg(hoverColor)
                              .arg(focusColor));
}






#endif // CUSTOMFUNCTIONS_H
