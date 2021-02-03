import QtQuick 2.15
import QtQuick.Controls.Material 2.15

Item {
    property real rowWidth: root.width
    property real rowHeight: root.height * 0.1
    property real rowHorizontalMargin: rowWidth * 0.05
    property real rowVerticalMargin: rowHeight * 0.1
    property real rowSpacing: rowHeight * 0.25
    property real overlayOpacity: 0.04

    property color appColor: Material.color(Material.LightBlue)

    property real iconSizeDefault: 1
    property real iconSizeHovered: 1.15
}
