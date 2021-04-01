import QtQuick 2.5
import StyleModule 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import ControlsModule 1.0
import an.qt.package 1.0

Rectangle {
    id: warningView

    opacity: 0.65
    color: Style.backgroundColor

    Text {
        id: name
        anchors.centerIn: parent
        text: qsTr("Warning View")
    }

    Component.onCompleted: {

    }
}
