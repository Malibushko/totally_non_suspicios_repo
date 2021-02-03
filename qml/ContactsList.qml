import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0
import QtQuick.Controls.Material 2.15

import contacts 1.0


ListView {
        id: root_
        width: parent.width
        model: filterModel
        clip: true

        delegate: Rectangle {
            height: settings.rowHeight
            width: settings.rowWidth
            Image {
                // make it rectangle to fit
                id: contactImage
                anchors.left: parent.left
                anchors.leftMargin: settings.rowHorizontalMargin / 2
                anchors.verticalCenter: parent.verticalCenter

                height: parent.height * 0.85
                width: height
                source: model.Photo
                fillMode: Image.PreserveAspectCrop
                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: mask
                }
            }
            Rectangle {
                id: mask
                width: contactImage.width
                height: contactImage.height
                radius: width/2
                visible: false
            }
            // contact's name
            Label {
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: settings.rowHorizontalMargin
                anchors.leftMargin: settings.rowHorizontalMargin
                anchors.left: contactImage.right
                anchors.right: parent.right

                text: model.Name
                font.pointSize: 16
                fontSizeMode: Text.Fit
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            }
            Rectangle {
                anchors.bottom: parent.bottom
                width: parent.width
                height: 1
                color: settings.appColor
            }
            MouseArea {
                id: mouseKeeper
                anchors.fill: parent
                hoverEnabled: true
            }
            Rectangle {
                anchors.fill: parent
                color: settings.appColor
                opacity: mouseKeeper.containsMouse ? settings.overlayOpacity : 0
            }
            Row {
                id: buttons
                height: parent.height/2
                width: parent.width * 0.33
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                spacing: width/4

                StarButton {
                    anchors.verticalCenter: parent.verticalCenter
                }
                CallButton {
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
    }
}

