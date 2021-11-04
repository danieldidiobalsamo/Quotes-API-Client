#include "QuotesAPI.hpp"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QDebug>
#include <QEventLoop>

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
	// TODO : parse JSON reply

	QString urlStr = _rawAPIURL + QString("/all/personnage/") + character;
	QUrl url(urlStr);

	QNetworkRequest request(url);
	QNetworkReply *reply = _accessManager->get(request);
	QEventLoop loop;

	connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);	
	loop.exec();


	return reply->readAll();// for testing purpose only
}