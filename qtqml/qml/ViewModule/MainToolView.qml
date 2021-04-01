import QtQuick 2.5
import QtQml 2.2
import QtQuick.Layouts 1.1
import an.qt.package 1.0
import StyleModule 1.0

Rectangle {
    id: toolview

    objectName: "mainToolView"
    signal itemWidthChanged(var w)
    signal currentItemChanged(var type)

    height: Style.titleItemLenth
    color: Style.backgroundColor2

    RowLayout {
        id: mainLayout
        spacing: 0
        anchors.fill: parent
        Layout.preferredHeight: Style.titleItemLenth

        Repeater {
            id:rowRepeat
            model: mainModel
            ToolItem {
                itemtype: type
                strtext: strText
                normalimg: normal
                selectimg: select
                Layout.preferredWidth: parent.width/mainModel.size();
                Layout.preferredHeight: Style.titleItemLenth
            }
        }
    }

    function onClickItem(type, text) {
        currentItemChanged(type);
        console.log(type)
    }
}
