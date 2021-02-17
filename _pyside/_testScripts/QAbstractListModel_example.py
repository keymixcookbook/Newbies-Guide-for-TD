'''
http://www.yasinuludag.com/PyQt/Tutorial03/Tutorial03_TableModel.py
'''

from PyQt5 import QtWidgets, QtGui, QtCore
import sys


class PaletteTableModel(QtCore.QAbstractTableModel):

    def __init__(self, colors = [[]], headers = [], parent = None):
        QtCore.QAbstractTableModel.__init__(self, parent)
        self.__data = colors
        self.__headers = headers



    def rowCount(self, parent):
        return len(self.__data)


    def columnCount(self, parent):
        return len(self.__data[0])


    def flags(self, index):
        return QtCore.Qt.ItemIsEditable | QtCore.Qt.ItemIsEnabled | QtCore.Qt.ItemIsSelectable


    def data(self, index, role):


        if role == QtCore.Qt.EditRole:
            row = index.row()
            column = index.column()
            return self.__data[row][column].name()


        if role == QtCore.Qt.ToolTipRole:
            row = index.row()
            column = index.column()
            return "Hex code: " + self.__data[row][column].name()


        if role == QtCore.Qt.DecorationRole:

            row = index.row()
            column = index.column()
            value = self.__data[row][column]

            pixmap = QtGui.QPixmap(26, 26)
            pixmap.fill(value)

            icon = QtGui.QIcon(pixmap)

            return icon


        if role == QtCore.Qt.DisplayRole:

            row = index.row()
            column = index.column()
            value = self.__data[row][column]

            return value.name()


    def setData(self, index, value, role = QtCore.Qt.EditRole):
        if role == QtCore.Qt.EditRole:

            row = index.row()
            column = index.column()

            color = QtGui.QColor(value)

            if color.isValid():
                self.__data[row][column] = color
                self.dataChanged.emit(index, index)
                return True
        return False




    def headerData(self, section, orientation, role):

        if role == QtCore.Qt.DisplayRole:

            if orientation == QtCore.Qt.Horizontal:

                if section < len(self.__headers):
                    return self.__headers[section]
                else:
                    return "not implemented"
            else:
                return "Color %s" % section



    #=====================================================#
    #INSERTING & REMOVING
    #=====================================================#
    def insertRows(self, row, count, parent = QtCore.QModelIndex()):
        self.beginInsertRows(parent, row, row + count - 1)

        for i in range(count):

            defaultValues = [QtGui.QColor("#000000") for i in range(self.columnCount(None))]
            self.__data.insert(row, defaultValues)

        self.endInsertRows()

        return True


    def insertColumns(self, column, count, parent = QtCore.QModelIndex()):
        self.beginInsertColumns(parent, column, column + count - 1)

        rowCount = len(self.__data)

        for i in range(count):
            for j in range(rowCount):
                self.__data[j].insert(column, QtGui.QColor("#000000"))

        self.endInsertColumns()

        return True







if __name__ == '__main__':

    app = QtWidgets.QApplication(sys.argv)
    app.setStyle("plastique")


    #ALL OF OUR VIEWS
    listView = QtWidgets.QListView()
    listView.show()

    comboBox = QtWidgets.QComboBox()
    comboBox.show()

    tableView = QtWidgets.QTableView()
    tableView.show()



    red   = QtGui.QColor(255,0,0)
    green = QtGui.QColor(0,255,0)
    blue  = QtGui.QColor(0,0,255)



    rowCount = 4
    columnCount = 6

    headers = ["Pallete0", "Colors", "Brushes", "Omg", "Technical", "Artist"]
    tableData0 = [ [ QtGui.QColor("#FFFF00") for i in range(columnCount)] for j in range(rowCount)]

    model = PaletteTableModel(tableData0, headers)
    model.insertColumns(0, 5)

    listView.setModel(model)
    comboBox.setModel(model)
    tableView.setModel(model)


    sys.exit(app.exec_())
