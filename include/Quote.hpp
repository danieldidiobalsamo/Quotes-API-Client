#pragma once

#include <QString>

class Quote
{
	private: 

		QString _author;
		QString _text;

	public:

		Quote()=delete;
		Quote(const QString author, const QString text);
		Quote(const Quote& quote);
		
		Quote& operator=(const Quote &quote);
		~Quote();

		QString getAuthor() const;
		QString getText() const;
};