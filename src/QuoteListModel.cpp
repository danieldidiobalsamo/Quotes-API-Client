#include "QuoteListModel.hpp"

#include <QAbstractItemModel>

QuoteListModel::QuoteListModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

QuoteListModel::~QuoteListModel()
{
}

int QuoteListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return _quotes.count();
}

QHash<int, QByteArray> QuoteListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CharacterRole] = "character";
    roles[TextRole] = "quoteText";
    roles[SeasonRole] = "season";

    return roles;
}

QVariant QuoteListModel::data(const QModelIndex& index, int role) const
{
    Q_UNUSED(role);

    if (!index.isValid())
        return QVariant();

    Quote quote = _quotes[index.row()];

    switch (role) {
    case CharacterRole:
        return quote.getCharacter();
    case TextRole:
        return quote.getText();
    case SeasonRole:
        return quote.getSeason();
    default:
        return QVariant();
    }
}

bool QuoteListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    int row = index.row();

    if (row >= 0 && row < _quotes.length()) {
        switch (role) {
        case CharacterRole:
            _quotes[row].setCharacter(value.toString());
            break;
        case TextRole:
            _quotes[row].setText(value.toString());
            break;
        case SeasonRole:
            _quotes[row].setSeason(value.toString());
            break;
        }

        emit dataChanged(QModelIndex(), QModelIndex());
    }

    return true;
}

bool QuoteListModel::insertRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0 || count < 0)
        return false;

    if (count == 0)
        return true;

    if (row > rowCount(parent))
        row = rowCount(parent);

    beginInsertRows(QModelIndex(), row, row + count - 1);
    endInsertRows();

    emit dataChanged(QModelIndex(), QModelIndex());

    return true;
}

bool QuoteListModel::removeRows(int row, int count, const QModelIndex& parent)
{

    if (row < 0 || count < 0 || rowCount(parent) <= 0)
        return false;

    if (count == 0)
        return true;

    if (row >= rowCount(parent))
        row = rowCount(parent) - 1;

    beginRemoveRows(QModelIndex(), row, row + count - 1);
    endRemoveRows();

    emit dataChanged(QModelIndex(), QModelIndex());

    return true;
}

void QuoteListModel::addQuote(const Quote& quote)
{
    beginInsertRows(QModelIndex(), _quotes.size(), _quotes.size());
    _quotes.append(quote);
    endInsertRows();
}

void QuoteListModel::addQuoteList(const QList<Quote>& list)
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