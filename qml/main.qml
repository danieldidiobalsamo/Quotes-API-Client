import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Window 2.0

ApplicationWindow{
	id: mainWindow
	visible: true

	visibility: "FullScreen"

	color: "lightgray"

	Button{
		id: exitButton
		text: "Exit"

		anchors.right : parent.right
		anchors.top : parent.top

		anchors.margins: 20

		onClicked: Qt.quit()
	}

	Column{
		anchors.fill: parent

		Row{

			id: searchRow

			spacing : 20
			padding : 20

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

			width: parent.width*0.98
			height: parent.height

			anchors.horizontalCenter: parent.horizontalCenter

			model : quotesModel

			spacing: 20

			delegate: Text{

				text: character + ": " + quoteText

				width: parent.width
				font.pointSize : 15
				wrapMode: Text.Wrap
			}
		}
	}

}