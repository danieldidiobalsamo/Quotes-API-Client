#pragma once

#include <QObject>

class QNetworkAccessManager;


// singleton
class QuotesAPI : public QObject
{
	Q_OBJECT

	private: 

		static QuotesAPI *_quotesAPI;
		QNetworkAccessManager *_accessManager;

		QuotesAPI();

	public : 
		~QuotesAPI();
		QuotesAPI(const QuotesAPI& manager)=delete;
		QuotesAPI& operator=(const QuotesAPI& manager)=delete;

		static QuotesAPI* getInstance();
		QString searchByAuthor(QString author);
};