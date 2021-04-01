import QtQuick 2.5
import QtQml 2.2
import QtQuick.Window 2.2
import ViewModule 1.0
import StyleModule 1.0
import an.qt.package 1.0

Window {
    visible: true
    width: 580
    height: 380
    minimumWidth: 580
    minimumHeight: 380
    title: qsTr("QmlC++Mixed")

    MainView {
        id: mainView
        anchors.fill: parent
    }

    Component.onCompleted: {
        console.log(ToolItemType.ToolData)
    }
}
