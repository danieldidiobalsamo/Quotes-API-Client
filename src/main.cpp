#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "QuoteListModel.hpp"
#include "BackEnd.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	BackEnd backend;
	backend.getEngine().rootContext()->setContextProperty("backend", &backend);

	return app.exec();
}