#pragma once

#include <QString>
#include <QDebug>

class Quote
{
	private: 

		QString _character;
		QString _text;
		QString _season;

	public:

		Quote()=delete;
		Quote(const QString character, const QString text, const QString season);
		Quote(const Quote& quote);
		
		Quote& operator=(const Quote &quote);
		~Quote();

		QString getCharacter() const;
		QString getText() const;
		QString getSeason() const;

		void setCharacter(const QString& character);
		void setText(const QString& text);
		void setSeason(const QString& season);

		friend QDebug operator<<(QDebug debug, const Quote &quote);
};