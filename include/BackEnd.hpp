#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include "QuoteListModel.hpp"

class QuotesAPI;
class QuoteListModel;
class QQmlContext;
class QString;

class BackEnd : public QObject
{
	Q_OBJECT

	private: 
		QuoteListModel _quotesModel;

		QQmlApplicationEngine _engine;
		QQmlContext* _context;

	public: 
		BackEnd();
		BackEnd(const BackEnd& backend)=delete;
		BackEnd& operator=(const BackEnd& backend)=delete;

		void initModel();

		Q_INVOKABLE QString getQuote(QString author);

		QQmlApplicationEngine& getEngine();		

};