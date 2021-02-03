import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: starButton
    hoverEnabled: true
    scale: hovered ? settings.iconSizeHovered : settings.iconSizeDefault

    icon.source: {
        if (!model.Favourite)
            return "qrc:/resource/star.png"
        else
            return "qrc:/resource/star_starred.png"
    }
    icon.width: parent.height
    icon.height: parent.height
    icon.color: settings.appColor

    background: Rectangle {
        color: "transparent"
    }
    onClicked: {
        contactsModel.maskAsFavourite(model.Id,!model.Favourite)
    }
}
