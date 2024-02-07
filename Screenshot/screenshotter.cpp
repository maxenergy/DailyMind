//## Screenshot/screenshotter.cpp
#include "screenshotter.h"

#include <QGuiApplication>
#include <QPixmap>

Screenshotter::Screenshotter()
{
}

Screenshotter::~Screenshotter()
{
}

QPixmap Screenshotter::takeScreenshot()
{
    // Get the current screen
    QScreen *screen = QGuiApplication::primaryScreen();

    // Take a screenshot of the screen
    QPixmap screenshot = screen->grabWindow(0);

    // Return the screenshot
    return screenshot;
}
