import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Dialogs 1.1

import contacts 1.0

Button {
    id: callButton

    hoverEnabled: true
    scale: hovered ? settings.iconSizeHovered : settings.iconSizeDefault

    icon.source: "qrc:/resource/phone.png"
    icon.width: parent.height
    icon.height: parent.height
    icon.color: Material.color(Material.Green)

    background: Rectangle {
        color: "transparent"
    }

    MessageDialog {
        id: messageDialog
        title: "Calling +" + model.Phone
    }

    onClicked: {
        messageDialog.text = contactsProvider.call(model.Id)
        messageDialog.open()
    }
}
