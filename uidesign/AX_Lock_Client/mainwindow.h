#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QStyleOption>
#include <QThread>
#include <QPushButton>
#include <QTimer>
#include <QMouseEvent>
#include "lockthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void FaceRecognition();
    void GreenLight();
    void YellowLight();
    ~MainWindow();

public slots:
    void handleMessage(const QString& message);

private slots:
    void on_Button_Clicked(int number);
    void onBackButtonClicked();

private:
    Ui::MainWindow *ui;
    void connectButtons();
    QTimer *longPressTimer;
    bool longPressDetected;
};
#endif // MAINWINDOW_H
