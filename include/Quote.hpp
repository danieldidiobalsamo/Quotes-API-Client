#pragma once

#include <QDebug>
#include <QString>

class Quote {
private:
    QString _character;
    QString _text;
    QString _season;

public:
    Quote() = delete;
    Quote(const QString character, const QString text, const QString season);
    Quote(const Quote& quote) = default;

    Quote& operator=(const Quote& quote) = default;
    ~Quote() = default;

    QString getCharacter() const;
    QString getText() const;
    QString getSeason() const;

    void setCharacter(const QString& character);
    void setText(const QString& text);
    void setSeason(const QString& season);

    friend QDebug operator<<(QDebug debug, const Quote& quote);
};