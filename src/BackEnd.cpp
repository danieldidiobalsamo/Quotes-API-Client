#include "BackEnd.hpp"
#include "NetworkManager.hpp"

#include <QQmlContext>
#include <QString>

BackEnd::BackEnd() : _quotesModel(), _engine(), _context(_engine.rootContext())
{
	initModel();
	_engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
}

void BackEnd::initModel()
{
	_quotesModel.addQuote(Quote("author1", "text1"));
	_quotesModel.addQuote(Quote("author2", "text2"));
	_quotesModel.addQuote(Quote("author3", "text3"));
	_quotesModel.addQuote(Quote("author4", "text4"));

	_context->setContextProperty("quotesModel", &_quotesModel);
}

QQmlApplicationEngine& BackEnd::getEngine()
{
	return _engine;
}

QString BackEnd::getQuote(QString author)
{
	NetworkManager* networkManager = NetworkManager::getInstance();
	return networkManager->searchByAuthor(author);
}