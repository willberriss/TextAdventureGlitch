#include "commandparser.h"
#include <QDebug>
#include <QString>

CommandParser::CommandParser()
{
    m_commands
        << "help"
        << "h"
        << "north"
        << "n"
        << "east"
        << "e"
        << "south"
        << "s"
        << "west"
        << "w"
        << "quit"
        << "q";
}

void CommandParser::parse(const QString &command,
                          std::function<void(const QString &, const int)> process,
                          std::function<void()> help)
{
    if ( ! m_commands.contains(command) )
    {
        help();
        return;
    }

    int delta{0};

    if (command == "north" || command == "n") delta = 1;
    else if (command == "east" || command == "e") delta = 2;
    else if (command == "south" || command == "s") delta = 3;
    else if (command == "west" || command == "w") delta = 4;
    else if (command == "quit" || command == "q")
    {
        exit(0); // terminate now
    }
    else
    {
        help();
        return;
    }

    if (delta > 0)
    {
        process(command, delta);
    }

    return;
}
