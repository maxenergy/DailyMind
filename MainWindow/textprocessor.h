//## MainWindow/textprocessor.h
#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <QObject>
#include <QString>

#include "liboai/liboai.h"

class TextProcessor : public QObject
{
    Q_OBJECT

public:
    explicit TextProcessor(QObject *parent = nullptr);
    ~TextProcessor();

    QString summarize(const QString &text);

private:
    Liboai *liboai;
};

#endif // TEXTPROCESSOR_H
