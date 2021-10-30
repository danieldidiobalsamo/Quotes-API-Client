#include "Quote.hpp"

Quote::Quote(const QString author, const QString text)
{
	_author = author;
	_text = text;
}

Quote::Quote(const Quote& quote)
{
	_author = quote._author;
	_text = quote._text;
}

Quote& Quote::operator=(const Quote &quote)
{
	if(this == &quote)
		return *this;
	else
	{
		_author = quote._author;
		_text = quote._text;

		return *this;
	}
}

Quote::~Quote()
{

}

QString Quote::getAuthor() const
{
	return _author;
}
QString Quote::getText() const
{
	return _text;
}