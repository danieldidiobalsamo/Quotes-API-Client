#pragma once

#include <QObject>
#include <QString>

class QNetworkAccessManager;
class Quote;


// singleton
class QuotesAPI : public QObject
{
	Q_OBJECT

	private: 

		static QuotesAPI *_quotesAPI;
		QNetworkAccessManager *_accessManager;

		const QString _rawAPIURL = QString("https://kaamelott.chaudie.re/api");

		QuotesAPI();

	public : 
		~QuotesAPI();
		QuotesAPI(const QuotesAPI& manager)=delete;
		QuotesAPI& operator=(const QuotesAPI& manager)=delete;

		static QuotesAPI* getInstance();
		QList<Quote> search(QString character, QString season);
};