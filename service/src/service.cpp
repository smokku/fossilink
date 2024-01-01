#include "settings.h"

#include <signal.h>
#include <QCoreApplication>
#include <QLoggingCategory>

void signalhandler(int sig)
{
    if (sig == SIGINT) {
        qDebug() << "quit by SIGINT";
        qApp->quit();
    }
    else if (sig == SIGTERM) {
        qDebug() << "quit by SIGTERM";
        qApp->quit();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationName("fossilink"); // Use the same appname as the UI.
    app.setOrganizationName("");

    QLoggingCategory l("main");
    qCDebug(l) << argv[0] << APP_VERSION;

    Settings settings;

    QLoggingCategory::setFilterRules(settings.property("debug").toBool()
                                     ? "*.debug=true"
                                     : "*.debug=false");

//    Manager manager(&settings);
//    Q_UNUSED(manager);

    signal(SIGINT, signalhandler);
    signal(SIGTERM, signalhandler);

    return app.exec();
}
