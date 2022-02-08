#include "BackEnd.hpp"
#include "QuotesAPI.hpp"

#include <QDebug>
#include <QQmlContext>
#include <QString>

BackEnd::BackEnd()
    : _quotesModel()
    , _engine()
    , _context(_engine.rootContext())
{
    qRegisterMetaType<QList<Quote>>("QList<Quote>");

    _context->setContextProperty("quotesModel", &_quotesModel);
    _engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    _requestThread = new QThread();

    _requestWorker = new RequestWorker("", "");
    _requestWorker->moveToThread(_requestThread);

    QuotesAPI* api = QuotesAPI::getInstance();
    api->moveToThread(_requestThread);

    connect(_requestThread, &QThread::started, _requestWorker, &RequestWorker::process);
    connect(_requestWorker, &RequestWorker::finished, this, &BackEnd::updateModel);
    connect(_requestWorker, &RequestWorker::finished, _requestThread, &QThread::quit);
    connect(_requestThread, &QThread::finished, _requestThread, &QThread::quit);
}

QQmlApplicationEngine& BackEnd::getEngine()
{
    return _engine;
}

void BackEnd::getQuote(QString character, QString season)
{
    _requestWorker->updateWorker(character, season);
    _requestThread->start();
}

void BackEnd::updateModel(QList<Quote> quotes)
{
    _quotesModel.clear();
    _quotesModel.addQuoteList(quotes);
}