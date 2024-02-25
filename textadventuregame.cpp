#include "textadventuregame.h"
#include "./ui_textadventuregame.h"

#include <QTextBrowser>
#include <QLineEdit>
#include <QVBoxLayout>

TextAdventureGame::TextAdventureGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextAdventureGame)
{
    ui->setupUi(this);
    ui->consoleOutput->setWindowTitle("Console output");

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
    qDebug() << "onCommandSubmitted() with m_command "
             << ui->commandLine->text();

    ui->commandHistory->appendPlainText(ui->commandLine->text());
    ui->commandLine->clear();
}

