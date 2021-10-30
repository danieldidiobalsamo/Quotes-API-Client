#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "QuoteListModel.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	QuoteListModel quotesModel;
	quotesModel.addQuote(Quote("author1", "text1"));
	quotesModel.addQuote(Quote("author2", "text2"));
	quotesModel.addQuote(Quote("author3", "text3"));
	quotesModel.addQuote(Quote("author4", "text4"));
	
	QQmlApplicationEngine engine;
	
	QQmlContext* context = engine.rootContext();
	context->setContextProperty("quotesModel", &quotesModel);

	engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

	return app.exec();
}