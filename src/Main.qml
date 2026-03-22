import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Controls.Material

Window {
    id: window
    visible: true
    visibility: "Maximized"
    title: qsTr("Config Browser")

    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        anchors.margins: 20

        Row {
            spacing: 10
            Layout.preferredHeight: 60
            TextField {
                id: pathInput
                width: 450
                placeholderText: "The scan path"
            }
            Button {
                contentItem: Text {
                    id: scanButtonText
                    text: "Open"
                    color: "#000000"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
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

            Item {
                width: 20
            }

            ComboBox {
                id: extensiosBox
            }
        }

        Rectangle {
            id: listWrapper

            Layout.fillWidth: true
            Layout.fillHeight: true
            width: parent.width

            color: "transparent"
            border.color: "#000000"
            border.width: 2
            radius: 8

            ListView {
                width: parent.width
                height: parent.height
                clip: true
                model: myFileModel
                anchors.horizontalCenter: parent.horizontalCenter

                delegate: ItemDelegate {
                    width: parent.width

                    Column {
                        anchors.left: parent.left
                        anchors.leftMargin: 20
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
}
