#include "BackEnd.hpp"
#include "QuotesAPI.hpp"

#include <QQmlContext>
#include <QString>
#include <QDebug>

BackEnd::BackEnd() : _quotesModel(), _engine(), _context(_engine.rootContext())
{
	_context->setContextProperty("quotesModel", &_quotesModel);
	_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
}

QQmlApplicationEngine& BackEnd::getEngine()
{
	return _engine;
}

void BackEnd::getQuote(QString character)
{
	QuotesAPI* QuotesAPI = QuotesAPI::getInstance();
	QList<Quote> quotes = QuotesAPI->searchByCharacter(character);

	_quotesModel.clear();
	_quotesModel.addQuoteList(quotes);
}