#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GUI w;
    w.show();

    return app.exec();
}

