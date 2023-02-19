//#ifdef NDEBUG
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) //release, 关闭cmd
//#endif

#include "qDetectMarked.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDetectMarked w;
    w.show();

    return a.exec();
}
