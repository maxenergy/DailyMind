//## MainWindow/textprocessor.cpp
#include "textprocessor.h"
#include <liboai/liboai.h>

TextProcessor::TextProcessor()
{
    liboai = new Liboai;
}

TextProcessor::~TextProcessor()
{
    delete liboai;
}

QString TextProcessor::summarize(const QString &text)
{
    // Summarize the text using Liboai
    QString summary = liboai->summarize(text);

    // Return the summary
    return summary;
}
