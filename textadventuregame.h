#pragma once

#include <QWidget>

class QLineEdit;
class QTextEdit;

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

private slots:
    void onCommandTyped(const QString &command);
    void onCommandSubmitted();

};
