import QtQuick 2.5
import QtGraphicalEffects 1.0
import StyleModule 1.0
import an.qt.package 1.0
import QtQuick.Controls 2.0

Rectangle {
    id: listitem

    property int itemtype: 0
    property string strtext: ""
    property string normalimg: ""
    property string selectimg: ""
    property string sourceimg: normalimg
    property color backColor: Style.backgroundColor2

    signal clickItem(int type, string text)

    anchors.top: parent.top
    color: backColor

    Image {
        id: img
        anchors.topMargin: 8
        anchors.top: parent.top
        sourceSize.height: height
        sourceSize.width: width
        source: sourceimg
        anchors.horizontalCenter: listitem.horizontalCenter
    }

    Text {
        id: tooltext
        anchors.topMargin: 8
        anchors.top: img.bottom
        font.pixelSize: 12
        color: Style.primaryColor
        text: strtext
        anchors.horizontalCenter: listitem.horizontalCenter
    }

    Rectangle {
        id: bottomBorder

        property color borderColor: Style.backgroundColor2

        height: 2
        color: borderColor
        width: parent.width
        anchors.bottom: parent.bottom
    }

    MouseArea {
        id: _delegateArea
        anchors.fill: listitem
        acceptedButtons: Qt.LeftButton | Qt.RightButton;
        onClicked: {
            if(mouse.button == Qt.LeftButton){
                listitem.clickItem(listitem.itemtype, tooltext.text);
                console.log(selectimg,normalimg)
            }
        }
    }

    Connections {
        target: toolview;
        onCurrentItemChanged: {
            if (type == listitem.itemtype)
            {
                listitem.sourceimg = selectimg;
                bottomBorder.borderColor = Style.borderColor
            }
            else
            {
                listitem.sourceimg = normalimg;
                bottomBorder.borderColor = Style.backgroundColor2
            }
        }
    }

    Component.onCompleted: {
        listitem.clickItem.connect(toolview.onClickItem);
        if (itemtype == ToolItemType.ToolAll)
        {
            listitem.sourceimg = selectimg;
            bottomBorder.borderColor = Style.borderColor
        }
    }
}
