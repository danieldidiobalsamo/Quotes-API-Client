#pragma once

#include <QString>
#include <QDebug>

class Quote
{
	private: 

		QString _character;
		QString _text;

	public:

		Quote()=delete;
		Quote(const QString character, const QString text);
		Quote(const Quote& quote);
		
		Quote& operator=(const Quote &quote);
		~Quote();

		QString getCharacter() const;
		QString getText() const;

		void setCharacter(const QString& character);
		void setText(const QString& text);

		friend QDebug operator<<(QDebug debug, const Quote &quote);
};