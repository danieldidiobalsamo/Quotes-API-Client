#include "RequestWorker.hpp"

RequestWorker::RequestWorker(QString character, QString season)
    : _character(character)
    , _season(season)
{
}

RequestWorker::~RequestWorker()
{
}

void RequestWorker::process()
{
    QuotesAPI* QuotesAPI = QuotesAPI::getInstance();
    QList<Quote> quotes = QuotesAPI->search(_character, _season);

    emit finished(quotes);
}

void RequestWorker::updateWorker(QString character, QString season)
{
    _character = character;
    _season = season;
}