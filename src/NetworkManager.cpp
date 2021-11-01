#include "NetworkManager.hpp"

#include <QNetworkAccessManager>

NetworkManager* NetworkManager::_networkManager = nullptr;

NetworkManager::NetworkManager() // private
{
	_accessManager = new QNetworkAccessManager(this);
}

NetworkManager* NetworkManager::getInstance()
{
	if(_networkManager == nullptr)
	{
		_networkManager = new NetworkManager();
	}

	return _networkManager;
}

NetworkManager::~NetworkManager()
{
	delete _networkManager;
}