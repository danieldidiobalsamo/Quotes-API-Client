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
			}
		}

		Text{
			id: quote

			width: parent.width
			height: parent.height

			wrapMode: Text.Wrap
			font.pointSize : 20
			textFormat: Text.AutoText

			text: "test"
		}
	}

}