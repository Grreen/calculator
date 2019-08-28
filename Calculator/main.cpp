#include "mainwindow.h"
#include <QApplication>
#include "st.h"

ST first_class;
ST second_class;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
