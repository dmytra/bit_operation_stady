#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("chapyland");              // имя компании
    app.setOrganizationDomain("ua.chapyland");       // домен компании
    app.setApplicationName("Bitwize operation for study");     // имя приложения
    app.setApplicationVersion("2.0.0");             // версия приложения

    Widget w;
    w.show();
    return app.exec();
}
