import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import contacts 1.0

ApplicationWindow {
    id: root
    width: Screen.desktopAvailableWidth/2
    height: Screen.desktopAvailableHeight * 0.75
    visible: true
    title: qsTr("Testovoe dlya luxoft")

    property var generatedContactsNum: 125

    AppSettings {
        id: settings
    }
    ContactListProvider {
        id: contactsProvider
    }
    ContactListModel {
                id: contactsModel
                Component.onCompleted: {
                    // just random number
                    setModel(contactsProvider.generateContacts(generatedContactsNum));
                }
    }
    FilterProxyModel {
        id: filterModel
        sourceModel: contactsModel
        showOnlyFavourites: false
        filterCaseSensitivity: Qt.CaseInsensitive
    }
    header: Header {
        id: appHeader
    }
    // following the 'kostyl' pattern in order
    // to prevent items from creating by making them properties
    // so that they would not overlap each other
    property ContactsList list: ContactsList {
        id: contactsList
    }
    property ContactsGrid grid: ContactsGrid {
        id: contactsGrid
    }

    TextField {
        id: searchField
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.leftMargin: settings.rowHorizontalMargin
        anchors.rightMargin: settings.rowHorizontalMargin
        height: settings.rowHeight

        placeholderText: qsTr("Enter name")

        onTextChanged: {
            filterModel.filterRole = ContactListModel.Name
            filterModel.setFilterString(text)
        }
    }
    StackView {
        id: appMainView
        anchors.fill: parent
        anchors.topMargin: searchField.height
        initialItem: contactsList
    }
}
