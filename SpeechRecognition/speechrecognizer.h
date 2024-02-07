//## SpeechRecognition/speechrecognizer.h
#ifndef SPEECHRECOGNIZER_H
#define SPEECHRECOGNIZER_H

#include <QObject>
#include <QString>

class SpeechRecognizer : public QObject
{
    Q_OBJECT

public:
    explicit SpeechRecognizer(QObject *parent = nullptr);
    ~SpeechRecognizer();

    void startRecording();
    void stopRecording();
    QString getTranscript();

signals:
    void transcriptReady(const QString &transcript);

private:
    QAudioInput *audioInput;
    QAudioOutput *audioOutput;
    #include <asr_qt5/asr_qt5.h>

    AsrQt5 *asr;
    QString transcript;
    bool isRecording;
};

#endif // SPEECHRECOGNIZER_H
