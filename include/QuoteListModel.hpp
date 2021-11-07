#pragma once

#include <QAbstractListModel>
#include <QObject>
#include <QList>
#include <QByteArray>
#include <QHash>

#include "Quote.hpp"

class QuoteListModel : public QAbstractListModel
{
	Q_OBJECT
	Q_DISABLE_COPY(QuoteListModel)

	private :
		QList<Quote> _quotes;

	public:

	enum QuoteRoles{
		AuthorRole = Qt::UserRole + 1,
		TextRole
	};


	QuoteListModel(QObject *parent = 0);
	~QuoteListModel();

	virtual int rowCount(const QModelIndex &parent) const;
	QHash<int, QByteArray> roleNames() const;
	virtual QVariant data(const QModelIndex &index, int role) const;


	void addQuote(const Quote &quote);
	void addQuoteList(const QList<Quote> &list);

};