#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <QThread>

#include "QuoteListModel.hpp"
#include "RequestWorker.hpp"

class QuotesAPI;
class QuoteListModel;
class QQmlContext;
class QString;

class BackEnd : public QObject {
    Q_OBJECT

private:
    QuoteListModel _quotesModel;

    QQmlApplicationEngine _engine;
    QQmlContext* _context;

    QThread* _requestThread;
    RequestWorker* _requestWorker;

public:
    BackEnd();
    BackEnd(const BackEnd& backend) = delete;
    BackEnd& operator=(const BackEnd& backend) = delete;

    Q_INVOKABLE void getQuote(QString character, QString season);

    QQmlApplicationEngine& getEngine();

public slots:
    void updateModel(QList<Quote>);
};