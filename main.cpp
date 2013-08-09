
#include "stables.h"
#include "MainFrame.h"

int main(int argc, char** argv=NULL)
{
    QApplication app(argc, argv);

    MainFrame mainWindow;
    mainWindow.show();
    return app.exec();
}
