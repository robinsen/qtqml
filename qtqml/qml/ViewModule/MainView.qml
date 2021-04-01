import QtQuick 2.5
import StyleModule 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import ControlsModule 1.0
import an.qt.package 1.0

Rectangle {
    id: root

    property int curType: ToolItemType.ToolAll

    opacity: 0.65
    anchors.fill: parent
    color: Style.backgroundColor

    ColumnLayout {
        anchors.fill: parent
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        spacing: 0

        MainToolView {
            id: maintool
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
            Layout.preferredHeight: Style.titleItemLenth
        }

        StackView {
            id: stackView
            Layout.preferredHeight: root.height - maintool.height
            Layout.preferredWidth: root.width

            replaceEnter: Transition {
                PropertyAnimation{
                    property: "x"
                    from: -root.width
                    to: 0
                    duration: 300
                }
            }

            replaceExit: Transition {
                PropertyAnimation{
                    property: "x"
                    from: 0
                    to: root.width
                    duration: 300
                }
            }
            initialItem: AllView {}
        }
    }

    function showControlPage(type) {
        switch (type)
        {
            case ToolItemType.ToolAll:
                stackView.replace("qrc:/qml/ViewModule/AllView.qml")
                break;
            case ToolItemType.ToolSingle:
                stackView.replace("qrc:/qml/ViewModule/SingleView.qml")
                break;
            case ToolItemType.ToolStatus:
                stackView.replace("qrc:/qml/ViewModule/StatusView.qml")
                break;
            case ToolItemType.ToolData:
                stackView.replace("qrc:/qml/ViewModule/DataView.qml")
                break;
            case ToolItemType.ToolPower:
                stackView.replace("qrc:/qml/ViewModule/PowerView.qml")
                break;
            case ToolItemType.ToolRealTime:
                stackView.replace("qrc:/qml/ViewModule/RealTimeView.qml")
                break;
            case ToolItemType.ToolSetting:
                stackView.push("qrc:/qml/ViewModule/SettingView.qml")
                break;
            case ToolItemType.ToolMalfunction:
                stackView.push("qrc:/qml/ViewModule/MalfunctionView.qml")
                break;
            case ToolItemType.ToolManual:
                stackView.push("qrc:/qml/ViewModule/ManualView.qml")
                break;
            case ToolItemType.ToolWarning:
                stackView.push("qrc:/qml/ViewModule/WarningView.qml")
                break;
            case ToolItemType.ToolReport:
                stackView.push("qrc:/qml/ViewModule/ReportView.qml")
                break;
            default:
                mainLoader.source = "";
                break;
        }
    }

    Connections {
        target: maintool;
        onCurrentItemChanged: {
            if (curType != type)
            {
                curType = type
                showControlPage(type)
            }
        }
    }

    Component.onCompleted: {

    }
}
