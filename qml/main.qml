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

			TextField{
				id: authorName
				text: ""
			}

			Button{
				id: searchButton
				text: "Search"
				onClicked: {
					var quote = backend.getQuote(authorName.text)
					console.log(quote)
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

				text: "author: " + author + "| " + quoteText
			}
		}
	}

}