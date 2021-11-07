#include "QuotesAPI.hpp"
#include "Quote.hpp"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QDebug>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

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

QList<Quote> QuotesAPI::searchByCharacter(QString character)
{	
	// TODO : use QThread

	QList<Quote> quotesList;

	QString urlStr = _rawAPIURL + QString("/all/personnage/") + character;
	QUrl url(urlStr);

	QNetworkRequest request(url);
	QNetworkReply *reply = _accessManager->get(request);
	QEventLoop loop;

	connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);	
	loop.exec();

	QByteArray rawReply = reply->readAll();
	QJsonDocument jsonReply = QJsonDocument::fromJson(rawReply);
	QJsonObject json = jsonReply.object();

	if(json.empty())
	{
		quotesList.append(Quote("No results", ""));
		return quotesList;
	}
	
	const QJsonArray quotes = json["citation"].toArray();

	for(const QJsonValue &quoteVal : quotes)
	{
		QJsonObject quoteObj = quoteVal.toObject();

		const QString author = quoteObj["infos"].toObject()["personnage"].toString();
		const QString text = quoteObj["citation"].toString();

		Quote quote(author, text);
		quotesList.append(quote);
	}


	return quotesList;
}