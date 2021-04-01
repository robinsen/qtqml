import QtQuick 2.5
import StyleModule 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import ControlsModule 1.0
import an.qt.package 1.0
import QtCharts 2.1

Rectangle {
    id: dataView

    opacity: 0.65
    color: Style.backgroundColor

    Text {
        id: name
        anchors.centerIn: parent
        text: qsTr("Data View")
    }

//    ChartView {
//        id: chart
//        title: "Top-5 car brand shares in Finland"
//        anchors.fill: parent
////        legend.alignment: Qt.AlignBottom
//        antialiasing: true

//        PieSeries {
//            id: pieSeries
//            PieSlice { label: "Volkswagen"; value: 13.5 }
//            PieSlice { label: "Toyota"; value: 10.9 }
//            PieSlice { label: "Ford"; value: 8.6 }
//            PieSlice { label: "Skoda"; value: 8.2 }
//            PieSlice { label: "Volvo"; value: 6.8 }
//        }
//    }

    Component.onCompleted: {
        // You can also manipulate slices dynamically
        othersSlice = pieSeries.append("Others", 52.0);
        pieSeries.find("Volkswagen").exploded = true;
    }

}
