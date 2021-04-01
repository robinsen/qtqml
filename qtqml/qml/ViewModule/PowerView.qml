import QtQuick 2.5
import StyleModule 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import ControlsModule 1.0
import an.qt.package 1.0
import QtCharts 2.0
import QtQml 2.2

Rectangle {
    id: powerView

    property var pieChart
    property real itime: 0.0
    property real itime1: 0.0

    opacity: 0.65
    color: Style.backgroundColor

    Row {
        spacing: 0
        ChartView {
            id:lineChart

            margins {
                top: 10
                left: 10
                right: 10
                bottom: 20
            }
            title: qsTr("功率曲线")
            antialiasing: true
            backgroundColor: "#0e1218"
            width: powerView.width/2
            height: powerView.height;
            theme:ChartView.ChartThemeDark
            legend.visible: false
            animationOptions:ChartView.SeriesAnimations

            ValueAxis {
                id: myAxisX
                min: 0
                max: 6
                tickCount: 6
                labelsColor: "#ff0000"
                labelsFont.pointSize: 10
                labelsFont.bold: false
            }
            ValueAxis{
                id:myAxisY
                min:0
                max:10
                tickCount: 5
                labelsColor: "#00ff00"
                labelsFont.pointSize: 10
                labelsFont.bold: false
            }

            LineSeries {
                id:lineSeries
                name:qsTr("分时段功率曲线")
                axisX: myAxisX
                axisY:myAxisY
                color: "#00ffff"
                width: 3
            }

            LineSeries {
                id:lineSeries1
                name:qsTr("标准曲线")
                axisX: myAxisX
                axisY:myAxisY
                color: "#662299"
                width: 3
            }

            Timer{
                interval: 1000
                running: true
                repeat: true
                onTriggered: {
                    lineSeries.append(itime, itime+Math.random()*5)
                    itime = itime+0.05

                    lineSeries1.append(itime1, itime1+Math.random()*0.3)
                    itime1 = itime1+0.3
                }
            }
        }

        Column {
            id:pieColumn
            spacing: 0
            width: powerView.width/2

            Text {
                id: text
                height: 40
                font.pixelSize: 12
                color: "#ffffff"
                text: qsTr("风向统计(正北朝上)")
                width: powerView.width/2
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            function getPieChart() {
                return pieView
            }

            function onHoveredPie(pie, state) {
                if (state === true)
                    pie.color = "#ff2222"
                else
                    pie.color = "#0e639c"
            }

            ChartView {
                id: pieView
                margins {
                    top: 10
                    left: 10
                    right: 10
                    bottom: 20
                }
                width: powerView.width/2
                height: powerView.height - text.height;
                antialiasing: true
                backgroundColor: "#0e1218"
                theme:ChartView.ChartThemeDark
                legend.visible: false
            }

            Component.onCompleted: {
                for (var i=0; i<18; i++)
                {
                    var pieSeries = pieView.createSeries(ChartView.SeriesTypePie);
                    pieSeries.size = 0.7
                    pieSeries.startAngle = i*20
                    pieSeries.endAngle = (i+1)*20
                    if (i == 6)
                        pieSeries.size = 0.9
                    var pie = pieSeries.append("pie"+i, 20)
                    pie.color = "#0e639c"
                    pie.labelVisible = true
                    pie.borderColor = "#ffffff"
                    pie.borderWidth = 1
                    if (i == 6)
                        pie.color = "#ff0000"
                    pieSeries.onHovered.connect(onHoveredPie)
                }
                pieChart = getPieChart();
            }
        }
    }

    Component.onCompleted: {
        if (pieChart)
        {
            var pie = pieChart.list(2);
            pie.size = 0.8
        }
    }
}
