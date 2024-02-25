#pragma once

#include <QStringList>
#include <QString>

class CommandParser
{
public:
    CommandParser();

    void parse(const QString &command,
               std::function<void(const QString &, const int)> process,
               std::function<void()> help);

private:
    QStringList m_commands;
};

