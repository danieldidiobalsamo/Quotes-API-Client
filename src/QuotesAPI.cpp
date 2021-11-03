#include "QuotesAPI.hpp"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QDebug>

QuotesAPI* QuotesAPI::_quotesAPI = nullptr;

QuotesAPI::QuotesAPI() // private
{
	_accessManager = new QNetworkAccessManager(this);
}

QuotesAPI* QuotesAPI::getInstance()
{
	if(_quotesAPI == nullptr)
	{
		_quotesAPI = new QuotesAPI();
	}

	return _quotesAPI;
}

QuotesAPI::~QuotesAPI()
{
	delete _quotesAPI;
}

QString QuotesAPI::searchByCharacter(QString character)
{	
	// TODO : use QThread

	QString urlStr = _rawAPIURL + QString("/all/personnage/") + character;
	QUrl url(urlStr);

	QNetworkRequest request(url);
	QNetworkReply *reply = _accessManager->get(request);

	connect(reply, &QNetworkReply::finished, [=](){

		if(reply->error() == QNetworkReply::NoError)
		{
			QByteArray response = reply->readAll();
			qDebug() << qPrintable(response);
		}
		else
		{
			qDebug() << reply->errorString();
		}
	});	

	return character;// for testing purpose only
}