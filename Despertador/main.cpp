#include "jnlprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{   

    QApplication a(argc, argv);
    jnlPrincipal w;
    w.show();

    return a.exec();
}
