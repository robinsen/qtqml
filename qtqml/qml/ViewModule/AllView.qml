import QtQuick 2.5
import StyleModule 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import ControlsModule 1.0
import an.qt.package 1.0
import QtCharts 2.0

Rectangle {
    id: allView

    opacity: 0.65
    color: "#55996f"/*Style.backgroundColor*/

    CAllView {
        id: callView
    }


    Component {
        id:powerChart
        Rectangle {
            color: "green"
            width: ListView.width
        }
    }

    //全场数据
    Component {
        id:leftBoard
        Rectangle {
            color: "red"/*Style.backgroundColor2*/
            width: 150
            ListView {
                id:chatlist
                model: 3
                delegate: powerChart
            }
        }
    }

    //设备状态列表
    Component {
        id:rightBoard
        Column {
            id:equimemntColumn
            GridLayout {
                id:equimemntlist
            }
//            RowLayout {

//            }
        }
    }

    ColumnLayout {
        Loader {
            anchors.left: parent.left
            sourceComponent: leftBoard;
        }
        Loader {
            anchors.right: parent.right
            sourceComponent: rightBoard;
        }
    }

    Component.onCompleted: {

    }
}
