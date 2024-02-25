#include "textadventuregame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextAdventureGame window;
    window.setWindowTitle("Text Adventure Glitch");
    window.show();
    return a.exec();
}
