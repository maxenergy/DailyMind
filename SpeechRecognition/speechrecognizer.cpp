//## SpeechRecognition/speechrecognizer.cpp
#include "speechrecognizer.h"

#include <QAudioInput>
#include <QAudioOutput>
#include <QBuffer>
#include <QFile>
#include <QTemporaryFile>
#include <asr_qt5/asr_qt5.h>
#include <QAudioOutput>
#include <QBuffer>
#include <QFile>
#include <QTemporaryFile>
#include <asr_qt5/asr_qt5.h>

SpeechRecognizer::SpeechRecognizer(QObject *parent)
    : QObject(parent)
    , audioInput(nullptr)
    , audioOutput(nullptr)
    , asr(nullptr)
    , isRecording(false)
{
    // Initialize the ASR engine
    asr = new AsrQt5;
}

SpeechRecognizer::~SpeechRecognizer()
{
    // Stop recording if it is still ongoing
    if (isRecording) {
        stopRecording();
    }

    // Delete the ASR engine
    delete asr;
}

void SpeechRecognizer::startRecording()
{
    // Check if recording is already in progress
    if (isRecording) {
        return;
    }

    // Create a temporary file to store the recorded audio
    QTemporaryFile *tempFile = new QTemporaryFile;
    tempFile->open();

    // Create an audio input device
    audioInput = new QAudioInput;
    audioInput->setFormat(QAudioFormat::Format_PCM16);
    audioInput->setSampleRate(16000);
    audioInput->setChannelCount(1);

    // Connect the audio input to the temporary file
    audioInput->start(tempFile);

    // Create an audio output device to play the recorded audio
    audioOutput = new QAudioOutput;
    audioOutput->setFormat(QAudioFormat::Format_PCM16);
    audioOutput->setSampleRate(16000);
    audioOutput->setChannelCount(1);

    // Connect the temporary file to the audio output
    QBuffer *buffer = new QBuffer;
    buffer->open(QIODevice::ReadWrite);
    audioOutput->start(buffer);

    // Start recording
    isRecording = true;
}

void SpeechRecognizer::stopRecording()
{
    // Check if recording is not in progress
    if (!isRecording) {
        return;
    }

    // Stop recording
    audioInput->stop();
    audioOutput->stop();

    // Close the temporary file
    QTemporaryFile *tempFile = static_cast<QTemporaryFile *>(audioInput->device());
    tempFile->close();

    // Load the recorded audio from the temporary file
    QFile file(tempFile->fileName());
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    // Recognize the speech
    QString transcript = asr->recognize(data);

    // Emit the transcript signal
    emit transcriptReady(transcript);

    // Delete the temporary file
    tempFile->remove();

    // Reset the recording state
    isRecording = false;
}

QString SpeechRecognizer::getTranscript()
{
    // Return the transcript of the recorded audio
    return transcript;
}
