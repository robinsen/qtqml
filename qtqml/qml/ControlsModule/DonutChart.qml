import QtQuick 2.5
import QtGraphicalEffects 1.0
import StyleModule 1.0
import QtQuick.Controls 2.0
import QtCharts 2.0
import QtQml 2.2

ChartView {
    id: donutView
    margins {
        top: 10
        left: 10
        right: 10
        bottom: 20
    }
    antialiasing: true
    backgroundColor: "#0e1218"
    theme:ChartView.ChartThemeDark
    legend.visible: false
    PieSeries {
        id:pieOuter
        PieSlice {

        }
    }
    PieSeries {
        id:pieInner
        PieSlice {

        }
    }
}
