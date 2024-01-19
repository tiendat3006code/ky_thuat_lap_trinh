import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

ApplicationWindow {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Control")
    id: root

    property bool isConnect: false

    Rectangle{
        anchors.fill: parent
        Image {
            id: backGround_1
            source: "qrc:/1.gif"
            anchors.fill: parent

        }
        AnimatedImage {
                    anchors.fill: parent
                    source: "qrc:/1.gif"
                    fillMode: Image.PreserveAspectCrop
                    smooth: true
                    // loops: Animation.Infinite
                }
    }

    Rectangle {
        visible: isConnect
        y: 300
        width: 500
        height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        color: "transparent"

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            z: 5
            text: "FORWARD"
            onClicked: {
                Car.control(1)
                console.log("forward clicked")
            }
        }

        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            z: 5
            text: "BACKWARD"
            onClicked: {
                Car.control(-1)
                console.log("backward clicked")
            }
        }

        Button {
            anchors.centerIn: parent
            z: 5
            text: "STOP"
            onClicked: {
                Car.control(0)
                console.log("stop clicked")
            }
        }

        Button {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            z: 5
            text: "RIGHT"
            onClicked: {
                Car.control(2)
                console.log("right clicked")
            }
        }

        Button {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            z: 5
            text: "LEFT"
            onClicked: {
                Car.control(3)
                console.log("left clicked")
            }
        }
    }

    Text {
        id: comboBoxText
        text: qsTr("Choose COM port")// This is available in all editors.
        anchors.horizontalCenter: parent.horizontalCenter
        y: 30
        font.pointSize: 20
        color: "white"
    }

    Text {
        id: stateText
        text: qsTr("State: disconnected")
        anchors.horizontalCenter: parent.horizontalCenter
        y: 125
        font.pointSize: 20
        color: "white"
    }

    Rectangle{
        anchors.horizontalCenter: parent.horizontalCenter
        y: 80
        width: 100
        height: 40
        ComboBox{
            id: comboBox
            anchors.fill: parent
            model: ListModel{
                ListElement{text: "COM1"}
                ListElement{text: "COM2"}
                ListElement{text: "COM3"}
                ListElement{text: "COM4"}
                ListElement{text: "COM5"}
                ListElement{text: "COM6"}
                ListElement{text: "COM7"}
                ListElement{text: "COM8"}
                ListElement{text: "COM9"}
            }
            textRole: "text"
            onActivated: {
                console.log("Selected:", model.get(index).text);
            }
        }
    }

    Button{
        id: connectButton
        x: 800
        y: 80
        text: "Connect"
        onClicked: {
            console.log("Connect ", comboBox.currentText)
            isConnect = true
            Car.connectPort(comboBox.currentIndex)
            stateText.text = "State: connected"
        }
    }

    Button{
        id: disconnectButton
        y: 80
        x: 950
        text: "Disconnect"
        onClicked: {
            console.log("Disconnect ", comboBox.currentText)
            isConnect = false
            Car.disconnect()
            stateText.text = "State: disconnected"
        }
    }

    Rectangle{
        x: 30
        y: 20
        Text {
            id: member_1
            text: qsTr("Nguyễn Bá Long Quân 20195143")
            color: "white"
            font.pixelSize: 25
        }
        Text {
            id: member_2
            anchors.top: member_1.bottom
            text: qsTr("Nguyễn Thế Đức 20194962")
            color: "white"
            font.pixelSize: 25
        }
        Text {
            id: member_3
            anchors.top: member_2.bottom
            text: qsTr("Trần Đăng Trung Thành 20195186")
            color: "white"
            font.pixelSize: 25
        }
    }


}
