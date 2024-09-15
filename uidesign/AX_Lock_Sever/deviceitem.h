#ifndef DEVICEITEM_H
#define DEVICEITEM_H

#include <QWidget> 
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTimer>

namespace Ui {
class DeviceItem;
}

class DeviceItem : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceItem(const QString &deviceId,QWidget *parent = nullptr);
    ~DeviceItem();

signals:
    void unlockRequested(const QString &deviceId);

private slots:
    void onUnlockButtonClicked();

private:
    Ui::DeviceItem *ui;
    QLabel *deviceIdLabel;
    QPushButton *unlockButton;
    QTimer *debounceTimer;
};

#endif // DEVICEITEM_H
