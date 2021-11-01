#include "QuotesAPI.hpp"

#include <QNetworkAccessManager>

QuotesAPI* QuotesAPI::_quotesAPI = nullptr;

QuotesAPI::QuotesAPI() // private
{
	_accessManager = new QNetworkAccessManager(this);
}

QuotesAPI* QuotesAPI::getInstance()
{
	if(_quotesAPI == nullptr)
	{
		_quotesAPI = new QuotesAPI();
	}

	return _quotesAPI;
}

QuotesAPI::~QuotesAPI()
{
	delete _quotesAPI;
}

QString QuotesAPI::searchByAuthor(QString author)
{
	return author;
}