#include "QuoteListModel.hpp"

#include <QAbstractItemModel>

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

bool QuoteListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	int row = index.row();

	if(row >= 0 && row < _quotes.length())
	{
		switch(role)
		{
			case AuthorRole:
				_quotes[row].setAuthor(value.toString());
				break;
			case TextRole:
				_quotes[row].setText(value.toString());
				break;
		}

		emit dataChanged(QModelIndex(),QModelIndex());
	}

	return true;
}

bool QuoteListModel::insertRows(int row, int count, const QModelIndex &parent)
{
	if(row < 0 || count < 0)
		return false;

	if(count == 0)
		return true;

	if(row > rowCount(parent))
		row = rowCount(parent);

	beginInsertRows(QModelIndex(), row, row+count-1);
	endInsertRows();
	
	emit dataChanged(QModelIndex(),QModelIndex());

    return true;
}

bool QuoteListModel::removeRows(int row, int count, const QModelIndex &parent) 
{

    if(row < 0 || count < 0 || rowCount(parent) <= 0)
		return false;

    if(count == 0)
		return true;

    if(row >= rowCount(parent))
		row = rowCount(parent) - 1;

	beginRemoveRows(QModelIndex(), row, row+count-1);
	endRemoveRows();

	emit dataChanged(QModelIndex(),QModelIndex());

    return true;
}

void QuoteListModel::addQuote(const Quote &quote)
{
	beginInsertRows(QModelIndex(), _quotes.size(), _quotes.size());
	_quotes.append(quote);
	endInsertRows();
}

void QuoteListModel::addQuoteList(const QList<Quote> &list)
{
	beginInsertRows(QModelIndex(), _quotes.size(), _quotes.size() + list.size() - 1);
	_quotes.append(list);
	endInsertRows();
}

void QuoteListModel::clear()
{
	beginRemoveRows(QModelIndex(), 0, _quotes.size());
	_quotes.clear();
	endRemoveRows();
}