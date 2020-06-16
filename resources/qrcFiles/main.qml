import QtQuick 2.3
import QtQuick.Window 2.2

// main window
Item {

	width: 600
	height: 600

	Component.onCompleted: {
		myListView.model.append({ myColor: 'red', myText: 'A' });
		myListView.model.append({ myColor: 'blue', myText: 'B' });
		myListView.model.append({ myColor: 'green', myText: 'C' });
		myListView.model.append({ myColor: 'yellow', myText: 'D' });
		myListView.model.append({ myColor: 'black', myText: 'E' });
		myListView.model.append({ myColor: 'white', myText: 'F' });
		myListView.model.append({ myColor: 'orange', myText: 'G' });
		myListView.model.append({ myColor: 'teal', myText: 'H' });
	}

	ListView {
		id: myListView
		anchors.fill: parent
		model: ListModel {}
		delegate: Rectangle {
			width: parent.width
			height: 50
			color: myColor
			Text {
				text: myText
			}
		}
	}

    // MouseArea {
    //     anchors.fill: parent
    //     onClicked: {
    //         	Qt.quit();
    //     }
    // }

	// Rectangle {
	// 	anchors.fill: parent
	// 	Text {
	// 		anchors.centerIn: parent
	// 		text: "Hello World"
	// 	}
	// }

}