#include "Quote.hpp"

Quote::Quote(const QString character, const QString text, const QString season)
    : _character(character)
    , _text(text)
    , _season(season)
{
}

QString Quote::getCharacter() const
{
    return _character;
}
QString Quote::getText() const
{
    return _text;
}

QString Quote::getSeason() const
{
    return _season;
}

void Quote::setCharacter(const QString& character)
{
    _character = character;
}
void Quote::setText(const QString& text)
{
    _text = text;
}

void Quote::setSeason(const QString& season)
{
    _season = season;
}

QDebug operator<<(QDebug debug, const Quote& quote)
{
    debug << quote._character << " " << quote._text << " " << quote._season;
    return debug;
}