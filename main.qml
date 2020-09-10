
    import QtQuick 2.13
    import QtQuick.Controls 2.13


    ApplicationWindow {
        visible: true
        title: qsTr("Quantum Test")

        Component.onCompleted: {
//            showMaximized()
        }

        width: 640
        height: 480
        minimumHeight: 480
        minimumWidth: 640


        TableView {
            id: tableView
            clip: true
            anchors.fill: parent
            model: tableModel
            topMargin: columnsHeader.implicitHeight

            columnWidthProvider: function (column) {
                return tableView.model ? tableView.width/tableView.model.columnCount() : 0
            }

            onWidthChanged: tableView.forceLayout()

            delegate: Rectangle {
                implicitWidth: tableView.columnWidthProvider(column)
                implicitHeight: 40
                Text {
                    text: display
                    anchors.centerIn: parent
                }
            }

            Row {
                id: columnsHeader
                y: tableView.contentY
                z: 2
                Repeater {
                    model: tableView.columns > 0 ? tableView.columns : 1
                    Rectangle {
                        width: tableView.columnWidthProvider(modelData)
                        height: 60
                        clip: true

                        Label{
                            id: headerText
                            width: parent.width
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: tableView.model ? tableView.model.headerData(modelData, Qt.Horizontal): 0
                            elide: Text.ElideRight
                            clip: true
                        }
                    }
                }
            }
        }
    }
