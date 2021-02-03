import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0
import QtQuick.Controls.Material 2.15
import contacts 1.0

GridView {
    id: root_
    model: filterModel

    property int minCellWidth: 160;
    property int minCellHeight: 240;

    cellWidth: {
        var cellCount = Math.ceil(width/minCellWidth)
        return width/cellCount
    }

    cellHeight: {
        var celLCount = Math.ceil(height/minCellHeight)
        return height/celLCount
    }

    delegate: Rectangle {
        border.width: 1
        border.color: settings.appColor
        width: root_.cellWidth
        height: root_.cellHeight
        MouseArea {
            id: mouseKeeper
            propagateComposedEvents: true
            anchors.fill: parent
            hoverEnabled: true

            Column {
                anchors.fill: parent
                //spacing: height * 0.1 // everyone love magic numbers
                anchors.margins: parent.height * 0.1
                Image {
                    // make it rectangle to fit
                    anchors.horizontalCenter: parent.horizontalCenter
                    width: height
                    height: parent.height/2
                    id: contactImage
                    source: model.Photo
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
                    id: contactName
                    width: parent.width * 0.85 // a bit smaller for paddings
                    height: parent.height/4
                    text: model.Name
                    fontSizeMode: Text.Fit
                    horizontalAlignment: Text.Center
                    anchors.horizontalCenter: parent.horizontalCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                }
                Row {
                    id: buttons
                    height: parent.height/4
                    spacing: width/4
                    width: parent.width
                    StarButton {
                        anchors.verticalCenter: parent.verticalCenter
                        icon.height: parent.height * 0.75
                        icon.width: parent.width * 0.75
                    }
                    CallButton {
                        anchors.verticalCenter: parent.verticalCenter
                        icon.width: parent.width * 0.75
                        icon.height: parent.height * 0.75
                    }
                }
            }
        }
        Rectangle {
            anchors.fill: parent
            color: settings.appColor
            opacity: mouseKeeper.containsMouse ? settings.overlayOpacity : 0
        }
    }
}
