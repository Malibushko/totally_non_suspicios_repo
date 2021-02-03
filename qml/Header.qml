import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ToolBar {
    Menu {
        id: contextMenu
        MenuItem {
            text: qsTr("Switch to ") + (contactsList.visible ? qsTr("Grid") : qsTr("List"))
            onClicked: {
                if (appMainView.currentItem == contactsGrid) {
                    appMainView.pop()
                }
                else {
                    appMainView.push(contactsGrid)
                }
            }
        }
        MenuItem {
            CheckBox {
                    checked: false
                    text: qsTr("Show only favourites")
                    onCheckedChanged: {
                        filterModel.showOnlyFavourites = checked
                    }
             }
        }
        MenuItem {
            text: qsTr("Exit")
            onClicked: {
                Qt.quit()
            }
        }
    }
    RowLayout {
        anchors.fill: parent
        Label {
            text: qsTr("Contacts")
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
        }
        ToolButton {
            text: qsTr("⋮")
            onClicked: contextMenu.popup()
        }
   }
}
