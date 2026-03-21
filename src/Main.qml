import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Config Browser")

    Column {
        anchors.fill: parent
        spacing: 10
        padding: 10

        Row {
            spacing: 10
            TextField {
                id: pathInput
                width: 450
                placeholderText: "The scan path"
            }
            Button {
                contentItem: Text {
                    id: scanButtonText
                    text: "Open"
                }
                onClicked: {
                    folderDialog.open()
                }
            }

            FolderDialog {
                id: folderDialog

                onAccepted: {
                    myFileModel.scanDirectory(selectedFolder)
                }
            }
        }

        ListView {
            width: parent.width
            height: parent.height
            clip: true

            model: myFileModel

            delegate: ItemDelegate {
                width: ListView.view.width
                padding: 20

                Column {
                    anchors.verticalCenter: parent.verticalCenter
                    Text {
                        text: (isDir ? "Dir " : "File ") + fileName
                        font.bold: true
                    }

                    Text {
                        text: filePath
                        font.pixelSize: 10
                        color: "gray"
                    }
                }
            }
        }
    }
}
