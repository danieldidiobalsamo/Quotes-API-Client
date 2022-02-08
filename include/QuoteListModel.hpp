#pragma once

#include <QAbstractListModel>
#include <QByteArray>
#include <QHash>
#include <QList>
#include <QObject>

#include "Quote.hpp"

class QuoteListModel : public QAbstractListModel {
    Q_OBJECT
    Q_DISABLE_COPY(QuoteListModel)

private:
    QList<Quote> _quotes;

public:
    enum QuoteRoles {
        CharacterRole = Qt::UserRole + 1,
        TextRole,
        SeasonRole
    };

    QuoteListModel(QObject* parent = 0);
    ~QuoteListModel();

    virtual int rowCount(const QModelIndex& parent) const;
    QHash<int, QByteArray> roleNames() const;
    virtual QVariant data(const QModelIndex& index, int role) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex());

    void clear();

    void addQuote(const Quote& quote);
    void addQuoteList(const QList<Quote>& list);
};