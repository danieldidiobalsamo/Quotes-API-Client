#include "BackEnd.hpp"
#include "QuotesAPI.hpp"

#include <QQmlContext>
#include <QString>
#include <QDebug>

BackEnd::BackEnd() : _quotesModel(), _engine(), _context(_engine.rootContext())
{
	qRegisterMetaType<QList<Quote>>("QList<Quote>");

	_context->setContextProperty("quotesModel", &_quotesModel);
	_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	
	thread = new QThread();
	
	worker = new RequestWorker("", "");
	worker->moveToThread(thread);	

	QuotesAPI *api = QuotesAPI::getInstance();
	api->moveToThread(thread);
	
	connect(thread, SIGNAL(started()), worker, SLOT(process()));
	connect(worker, SIGNAL(finished(QList<Quote>)), this, SLOT(updateModel(QList<Quote>)));
	connect(worker, SIGNAL(finished(QList<Quote>)), thread, SLOT(quit()));
	connect(thread, SIGNAL(finished()), thread, SLOT(quit()));
}

QQmlApplicationEngine& BackEnd::getEngine()
{
	return _engine;
}

void BackEnd::getQuote(QString character, QString season)
{
	worker->updateWorker(character, season);
	thread->start();
}

void BackEnd::updateModel(QList<Quote> quotes)
{
	_quotesModel.clear();
	_quotesModel.addQuoteList(quotes);
}