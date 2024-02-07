//## Screenshot/screenshotter.h
#ifndef SCREENSHOTTER_H
#define SCREENSHOTTER_H

#include <QObject>
#include <QPixmap>

class Screenshotter : public QObject
{
    Q_OBJECT

public:
    explicit Screenshotter(QObject *parent = nullptr);
    ~Screenshotter();

    QPixmap takeScreenshot();

private:
    QScreen *screen;
};

#endif // SCREENSHOTTER_H
