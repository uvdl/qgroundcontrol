import QtQuick          2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts  1.2
import QtQuick.Dialogs  1.2

import QGroundControl                   1.0
import QGroundControl.ScreenTools       1.0
import QGroundControl.Controls          1.0
import QGroundControl.FactControls      1.0
import QGroundControl.Palette           1.0

Row {
    id:                 indicatorRow
    anchors.top:        parent.top
    anchors.bottom:     parent.bottom
    spacing:            ScreenTools.defaultFontPixelWidth * 1.5

    Repeater {
        model: activeVehicle ? activeVehicle.toolBarIndicators : []
        Loader {
            id:                 indicatorLoader
            anchors.top:        parent.top
            anchors.bottom:     parent.bottom
            anchors.margins:    ScreenTools.defaultFontPixelHeight * 0.66
            source:             modelData
            visible:            item.showIndicator
            active:             QGroundControl.settingsManager.flyViewSettings.showCustomControls.value
        }
    }
}

