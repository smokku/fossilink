#pragma once

#include <MDConfGroup>

class Settings : public MDConfGroup
{
    Q_OBJECT

    Q_PROPERTY(bool debug MEMBER debug NOTIFY debugChanged)
    Q_PROPERTY(bool incomingCallNotification MEMBER incomingCallNotification NOTIFY incomingCallNotificationChanged)

    bool debug;
    bool incomingCallNotification;

public:
    explicit Settings(QObject *parent = nullptr) :
        MDConfGroup("/org/" APP_NAME "/settings", parent, BindProperties),
        debug(false),
        incomingCallNotification(true)
    {
        resolveMetaObject();
        QMetaObject::invokeMethod(this, "propertyChanged", Qt::DirectConnection);
        sync();
    }

signals:
    void debugChanged();
    void incomingCallNotificationChanged();
};
