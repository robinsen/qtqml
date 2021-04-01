import QtQuick 2.0
import StyleModule 1.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root

    property int bubbleRadius: 1
    property string imageSource: ""

    width: bubbleRadius
    height: bubbleRadius

    radius: bubbleRadius / 2
    color: "transparent"

    border.color: Style.primaryColor
    border.width: 2

    Image {
        id: _image
        anchors.fill: root
        anchors.margins: Style.mediumOffset

        source: imageSource
        sourceSize.height: height
        sourceSize.width: width
    }

    ColorOverlay {
        anchors.fill: _image
        source: _image
        color: Style.themeInvertedColor
        antialiasing: true
    }
}
