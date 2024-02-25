#pragma once

#include "commandparser.h"
#include <QWidget>

class QStringListModel;

QT_BEGIN_NAMESPACE
namespace Ui { class TextAdventureGame; }
QT_END_NAMESPACE

class TextAdventureGame : public QWidget
{
    Q_OBJECT

public:
    TextAdventureGame(QWidget *parent = nullptr);
    ~TextAdventureGame();

private:
    Ui::TextAdventureGame *ui;
    QStringListModel *m_roomsVisited{nullptr};
    CommandParser m_commandParser;
    QList<QString> m_roomData;
    int m_currentRoom{0};

    void initialiseRoomData();
    void displayTextForRoom(int room);
    void visitRoom(int room);

private slots:
    void onCommandTyped(const QString &command);
    void onCommandSubmitted();

};
