import QtQuick 2.5
import QtGraphicalEffects 1.0
import StyleModule 1.0

Rectangle {
    id: itemdelegate

    color: "#663300"
    width: Style.titleItemLenth
    property string sourceimg: normalimg
    property int itemtype: type

    signal clickItem(int type, string text)

    Image {
        id: img
        anchors.topMargin: 5
        anchors.top: parent.top
        anchors.horizontalCenter: itemdelegate.horizontalCenter
        sourceSize.height: height
        sourceSize.width: width
        source: sourceimg
    }

    Text {
        id: tooltext
        anchors.topMargin: 5
        anchors.top: img.bottom
        anchors.horizontalCenter: itemdelegate.horizontalCenter
        font.pointSize: 13
        color: Style.primaryColor
        text: itemtext
    }

    MouseArea {
        id: _delegateArea
        anchors.fill: itemdelegate
        acceptedButtons: Qt.LeftButton | Qt.RightButton;
        onClicked: {
            if(mouse.button == Qt.LeftButton){
                itemdelegate.clickItem(itemdelegate.itemtype, tooltext.text);
                console.log(selectimg,normalimg)
            }
        }
    }

    Connections {
        target: toolview;
        onCurrentItemChanged: {
            if (type == itemdelegate.itemtype)
                itemdelegate.sourceimg = selectimg;
            else
                itemdelegate.sourceimg = normalimg;
        }
    }

    Component.onCompleted: {
        itemdelegate.clickItem.connect(toolview.onClickItem);
    }
}
