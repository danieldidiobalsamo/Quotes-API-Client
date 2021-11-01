#pragma once

#include <QObject>

class QNetworkAccessManager;


// singleton
class NetworkManager : public QObject
{
	Q_OBJECT

	private: 

		static NetworkManager *_networkManager;
		QNetworkAccessManager *_accessManager;

		NetworkManager();

	public : 
		~NetworkManager();
		NetworkManager(const NetworkManager& manager)=delete;
		NetworkManager& operator=(const NetworkManager& manager)=delete;

		static NetworkManager* getInstance();
};