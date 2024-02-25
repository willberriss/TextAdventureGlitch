#include "textadventuregame.h"
#include "./ui_textadventuregame.h"

#include <QStringListModel>

TextAdventureGame::TextAdventureGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextAdventureGame)
    , m_roomsVisited{new QStringListModel(this)}
{
    ui->setupUi(this);
    initialiseRoomData();
    displayTextForRoom(0);

    connect(ui->commandLine,
            &QLineEdit::textEdited,
            this,
            &TextAdventureGame::onCommandTyped);

    connect(ui->commandLine,
            &QLineEdit::returnPressed,
            this,
            &TextAdventureGame::onCommandSubmitted);
}

TextAdventureGame::~TextAdventureGame()
{
    delete ui;
}

void TextAdventureGame::onCommandTyped(const QString &command)
{
    qDebug() << "onCommandTyped() with command " << command;
}

void TextAdventureGame::onCommandSubmitted()
{
    const QString command{ui->commandLine->text()};
    qDebug() << "onCommandSubmitted() with m_command " << command;

    ui->commandLine->clear();

    auto process = [this](const QString &command, int delta)
    {
        ui->commandHistory->appendPlainText(command);
        visitRoom(m_currentRoom + delta);
    };

    auto help = [this]()
    {
        ui->roomTextSummary->clear();
        ui->roomTextSummary->insertPlainText("Help: See list of valid commands below.");
    };

    m_commandParser.parse(command, process, help);
}

void TextAdventureGame::initialiseRoomData()
{
    if (m_roomsVisited->insertRow(m_roomsVisited->rowCount()))
    {
        const QModelIndex index{m_roomsVisited->index(m_roomsVisited->rowCount() - 1, 0)};
        m_roomsVisited->setData(index, "Start");
    }
    ui->roomsView->setModel(m_roomsVisited);

    m_roomData
        << "Dear player, welcome to Text Adventure Glitch. You are at the start. "
        << "You have reached the spooky room. Here we go..."
        << "This is the happy room, take a look around and help yourself..."
        << "What are you doing in here. Run for your life!"
        << "It's very cold in here, head south!"
        << "Welcome to the room of death.";
}

void TextAdventureGame::displayTextForRoom(int room)
{
    ui->roomName->setText("Room " + QString::number(room));
    ui->roomTextSummary->clear();
    ui->roomTextSummary->insertPlainText(m_roomData[room]);
}

void TextAdventureGame::visitRoom(int room)
{
    // Ensure room is a valid index
    const long long numRooms{m_roomData.length()};
    room %= numRooms;

    displayTextForRoom(room);
    m_currentRoom = room;
    if (m_roomsVisited->insertRow(m_roomsVisited->rowCount()))
    {
        const QModelIndex index{m_roomsVisited->index(m_roomsVisited->rowCount() - 1, 0)};
        m_roomsVisited->setData(index, QString::number(room));
    }
}
