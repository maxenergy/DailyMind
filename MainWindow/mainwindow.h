//## MainWindow/mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "textprocessor.h"
#include "screenshotter.h"
#include "historytracker.h"
#include "speechrecognizer.h"
#include "datastore.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_pushButtonScreenshot_clicked();
    void on_pushButtonStartRecording_clicked();
    void on_pushButtonStopRecording_clicked();
    void on_pushButtonSummarize_clicked();

private:
    Ui::MainWindow *ui;

    TextProcessor *textProcessor;
    Screenshotter *screenshotter;
    HistoryTracker *historyTracker;
    SpeechRecognizer *speechRecognizer;
    DataStore *dataStore;

    QVariantMap getData();
};

#endif // MAINWINDOW_H
