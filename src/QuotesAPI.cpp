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

QList<Quote> QuotesAPI::search(QString character, QString season)
{	
	QNetworkAccessManager *accessManager = new QNetworkAccessManager();

	QList<Quote> quotesList;
	QString urlStr = _rawAPIURL + "/all";

	if(season != "All")
		urlStr += QString("/livre/") + season;

	urlStr += QString("/personnage/") + character;

	QUrl url(urlStr);

	QNetworkRequest request(url);
	QNetworkReply *reply = accessManager->get(request);
	QEventLoop loop;

	connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);	
	loop.exec();

	QByteArray rawReply = reply->readAll();
	QJsonDocument jsonReply = QJsonDocument::fromJson(rawReply);
	QJsonObject json = jsonReply.object();

	if(json.empty())
	{
		quotesList.append(Quote("No results", "", ""));
		return quotesList;
	}
	
	const QJsonArray quotes = json["citation"].toArray();

	for(const QJsonValue &quoteVal : quotes)
	{
		QJsonObject quoteObj = quoteVal.toObject();

		const QString author = quoteObj["infos"].toObject()["personnage"].toString();
		const QString season = quoteObj["infos"].toObject()["saison"].toString();
		const QString text = quoteObj["citation"].toString();

		Quote quote(author, text, season);
		quotesList.append(quote);
	}


	return quotesList;
}