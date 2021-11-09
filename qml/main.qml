import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Window 2.0

ApplicationWindow{
	id: mainWindow
	visible: true

	width: Screen.desktopAvailableWidth *0.4
	height: Screen.desktopAvailableHeight *0.4

	color: "lightgray"

	Column{
		anchors.fill: parent

		Row{

			id: searchRow
			width: parent.width

			Text{
				text: "name : "
				font.pointSize : 20
			}

			ComboBox{
				id : characterName
				model: CharactersNameModel{}
			}

			Button{
				id: searchButton
				text: "Search"
				onClicked: {
					backend.getQuote(characterName.currentText)
				}
			}
		}

		ListView{

			id: searchResults

			width: parent.width
			height: parent.height

			model : quotesModel

			delegate:Text{

				font.pointSize : 15

				text: character + ": " + quoteText
			}
		}
	}

}