import QtQuick 2.0
import StyleModule 1.0

Rectangle {
    id: root

    property int defaultRadius: 1

    anchors.fill: parent

    radius: defaultRadius / 2
    color: Style.primaryColor

}
