#include "QuoteListModel.hpp"

QuoteListModel::QuoteListModel(QObject *parent) : QAbstractListModel(parent)
{

}

QuoteListModel::~QuoteListModel()
{

}

int QuoteListModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return _quotes.count();
}

QHash<int, QByteArray> QuoteListModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[AuthorRole] = "author";
	roles[TextRole] = "quoteText";

	return roles;
}

QVariant QuoteListModel::data(const QModelIndex &index, int role) const
{
	Q_UNUSED(role);

	if(!index.isValid())
		return QVariant();

	Quote quote = _quotes[index.row()];

	switch(role)
	{
		case AuthorRole:
			return quote.getAuthor();
		case TextRole:
			return quote.getText();
		default:
			return QVariant();
	}
}

void QuoteListModel::addQuote(const Quote &quote)
{
	_quotes.append(quote);
}

void QuoteListModel::addQuoteList(const QList<Quote> &list)
{
	_quotes.append(list);
}