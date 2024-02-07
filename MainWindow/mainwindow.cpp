//## MainWindow/mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QWebEnginePage>
#include <QWebEngineView>

#include "textprocessor.h"
#include "screenshotter.h"
#include "historytracker.h"
#include "speechrecognizer.h"
#include "datastore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize components
    textProcessor = new TextProcessor;
    screenshotter = new Screenshotter;
    historyTracker = new HistoryTracker;
    speechRecognizer = new SpeechRecognizer;
    dataStore = new DataStore;

    // Connect signals and slots
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::on_actionNew_triggered);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::on_actionOpen_triggered);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::on_actionSave_triggered);
    connect(ui->actionSaveAs, &QAction::triggered, this, &MainWindow::on_actionSaveAs_triggered);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit_triggered);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::on_actionAbout_triggered);
    connect(ui->pushButtonScreenshot, &QPushButton::clicked, this, &MainWindow::on_pushButtonScreenshot_clicked);
    connect(ui->pushButtonStartRecording, &QPushButton::clicked, this, &MainWindow::on_pushButtonStartRecording_clicked);
    connect(ui->pushButtonStopRecording, &QPushButton::clicked, this, &MainWindow::on_pushButtonStopRecording_clicked);
    connect(ui->pushButtonSummarize, &QPushButton::clicked, this, &MainWindow::on_pushButtonSummarize_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete textProcessor;
    delete screenshotter;
    delete historyTracker;
    delete speechRecognizer;
    delete dataStore;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Save data before closing the application
    dataStore->save(getData());

    // Accept the close event
    event->accept();
}

void MainWindow::on_actionNew_triggered()
{
    // Clear the current web page
    ui->webView->setUrl(QUrl());
}

void MainWindow::on_actionOpen_triggered()
{
    // Open a file dialog to select a web page
    QString filePath = QFileDialog::getOpenFileName(this, "Open Web Page", QDir::homePath(), "Web Page (*.html *.htm)");

    // Load the web page if a file was selected
    if (!filePath.isEmpty()) {
        ui->webView->setUrl(QUrl::fromLocalFile(filePath));
    }
}

void MainWindow::on_actionSave_triggered()
{
    // Save the current web page
    QString filePath = QFileDialog::getSaveFileName(this, "Save Web Page", QDir::homePath(), "Web Page (*.html *.htm)");

    // Save the web page if a file was selected
    if (!filePath.isEmpty()) {
        ui->webView->page()->save(filePath);
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
    // Save the current web page as a different file
    QString filePath = QFileDialog::getSaveFileName(this, "Save Web Page As", QDir::homePath(), "Web Page (*.html *.htm)");

    // Save the web page if a file was selected
    if (!filePath.isEmpty()) {
        ui->webView->page()->save(filePath);
    }
}

void MainWindow::on_actionExit_triggered()
{
    // Close the application
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    // Show an about dialog
    QMessageBox::about(this, "About Web Browser", "This is a simple web browser built with Qt.");
}

void MainWindow::on_pushButtonScreenshot_clicked()
{
    // Take a screenshot of the current web page
    QPixmap screenshot = screenshotter->takeScreenshot();

    // Save the screenshot to a file
    QString filePath = QFileDialog::getSaveFileName(this, "Save Screenshot", QDir::homePath(), "Image (*.png *.jpg)");

    // Save the screenshot if a file was selected
    if (!filePath.isEmpty()) {
        screenshot.save(filePath);
    }
}

void MainWindow::on_pushButtonStartRecording_clicked()
{
    // Start recording audio
    speechRecognizer->startRecording();
}

void MainWindow::on_pushButtonStopRecording_clicked()
{
    // Stop recording audio
    speechRecognizer->stopRecording();

    // Get the transcript of the recorded audio
    QString transcript = speechRecognizer->getTranscript();

    // Display the transcript in the web view
    ui->webView->setHtml(transcript);
}

void MainWindow::on_pushButtonSummarize_clicked()
{
    // Get the current web page content
    QString content = ui->webView->page()->toHtml();

    // Summarize the content
    QString summary = textProcessor->summarize(content);

    // Display the summary in the web view
    ui->webView->setHtml(summary);
}

QVariantMap MainWindow::getData()
{
    // Get the current web page URL
    QUrl url = ui->webView->url();

    // Get the browsing history
    QStringList history = historyTracker->getHistory();

    // Get the saved data
    QVariantMap data = dataStore->load();

    // Add the current web page URL and browsing history to the data
    data["url"] = url.toString();
    data["history"] = history;

    // Return the data
    return data;
}
