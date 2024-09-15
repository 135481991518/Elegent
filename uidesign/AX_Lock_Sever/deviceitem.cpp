#include "deviceitem.h"
#include "ui_deviceitem.h"

DeviceItem::DeviceItem(const QString &deviceId, QWidget *parent) : QWidget(parent) {
    debounceTimer = new QTimer(this);
    debounceTimer->setSingleShot(true); // 设置为单次触发
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 0, 10, 0); // 增大左右边距

    deviceIdLabel = new QLabel(deviceId, this);
    deviceIdLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    unlockButton = new QPushButton("开锁", this);
    connect(unlockButton, &QPushButton::clicked, this, &DeviceItem::onUnlockButtonClicked);

    layout->addWidget(deviceIdLabel);
    layout->addWidget(unlockButton);
    setLayout(layout);
}

DeviceItem::~DeviceItem()
{

}

void DeviceItem::onUnlockButtonClicked() {
    if (debounceTimer->isActive()) {
       return;
    }
    debounceTimer->start(500); // 设置500毫秒的超时时间
    emit unlockRequested(deviceIdLabel->text());
}
