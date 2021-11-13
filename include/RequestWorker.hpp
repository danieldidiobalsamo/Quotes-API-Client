#pragma once

#include <QObject>
#include <QString>

#include "Quote.hpp"
#include "QuotesAPI.hpp"

class RequestWorker : public QObject
{
	Q_OBJECT

	private: 
		QString _character;
		QString _season;

	public :
		RequestWorker()=delete;
		RequestWorker(QString character, QString season);

		void updateWorker(QString character, QString season);

		~RequestWorker();

	public slots: 
		void process();

	signals: 
		void finished(QList<Quote> quotes);
};