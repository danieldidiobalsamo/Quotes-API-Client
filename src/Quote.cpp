#include "Quote.hpp"

Quote::Quote(const QString character, const QString text)
{
	_character = character;
	_text = text;
}

Quote::Quote(const Quote& quote)
{
	_character = quote._character;
	_text = quote._text;
}

Quote& Quote::operator=(const Quote &quote)
{
	if(this == &quote)
		return *this;
	else
	{
		_character = quote._character;
		_text = quote._text;

		return *this;
	}
}

Quote::~Quote()
{

}

QString Quote::getAuthor() const
{
	return _character;
}
QString Quote::getText() const
{
	return _text;
}

QDebug operator<<(QDebug debug, const Quote &quote)
{
	debug << quote._character << " " << quote._text;
	return debug;
}