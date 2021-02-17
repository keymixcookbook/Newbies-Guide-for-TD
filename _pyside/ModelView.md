# Model View

Python model/view is one of the most powerful features to display data, it allows the most efficient way of displaying and editing data


## Overview

![modelviewgraph](https://doc.qt.io/qtforpython/_images/modelview-overview.png)

There are 3 types of data you can display:
- List based (1 Dimensional)
- Table based (2 Dimensional)
- Tree based (Hierarchical)


Every model are inherited from 3 main class:
- `QAbstractItemModel`
	- `QAbstractTableModel`
	- `QAbstractListModel`


and views
- `QListView`
- `QTableView`
- `QTreeView`

*All Abstract models have be subclassed*

## Basic Components

Everymodel has a few basic methods we shall define when subclassing. Of which to identify the **row**, **column** and **data**.


For each unit of the data it calls the following **methods**:
- `rowCount(self)`
- `columnCount(self)`
- `data(self, index, role)`
- `headerData(self, section, orientation, role)`: top and side header display
- `flags(self, index)`: to set the property of each data
- `setData(self, index, value, role)`: edit and submit the data in the model
	- `self.dataChanged.emit(index,index)`: must call to update other views that has same model
- `insertRows(self, row, count, parent)`/`removeRows(self, row, count, parent)`: insert/remove rows
	- operations need to be sandwiched between `self.beginInsertRows()` and `self.endInsertRows()`
	- more detail in example below
- `: remove row


As you can see there are a few consistent **arguments**:
- `index`: current index: return integer or object
	- `index.row()`
	- `index.column()`
	- `index.parent()`: returns object for Hierarchical data
- `section`: current row or section
- `orientation`:
	- `QtCore.Qt.Horizontal`
	- `QtCore.Qt.Vertical`
- `role`: role to display data - `QtCore.Qt.`ItemDataRole
	- `Qt.DisplayRole`: data to be displayed as text
	- `Qt.DecorationRole`: rendered as an icon
	- `Qt.EditRole`: data in form suitable for editing (ie. double click to change text)
	- `Qt.ToolTipRole`: data display as tooltip
	- [..full list](https://doc.qt.io/qtforpython/PySide6/QtCore/Qt.html)
- `value`: the value given when user edits
- `row`: index of the row
- `count`: number of integer


list of flags - `QtCore.Qt.`ItemFlag:
- `Qt.ItemIsSelecable`
- `Qt.ItemIsEditable`
- `Qt.ItemIsEnabled`
- [..full list](https://doc.qt.io/qtforpython/PySide6/QtCore/Qt.html)


Example of using of methods:
```python
class MyModel(QtCore.QAbstractTableModel):
	def __init__(self, data = []):
		super(MyModel, self).__init__()

		self.data = data

	# Number of rows based on length of the data
	def rowCount(self):
		'''set the number of rows'''
		return len(data)

	# Number of column based on length of the 1st item
	def columnCount(self):
		'''set the number of columns'''
		return len(data[0])

	def data(self, index, role):
		'''set the data of the view from model'''
		row = index.row()
		value = self.data[row]

		# Display Icon
		if role == QtCore.Qt.DecorationRole:
			pixmap = QtGui.QPixmap(50,50)
			pixmap.fill(QColor(QtCore.Qt.red))
			icon = QtGui.QIcon(pixmap)
			return icon

		# Display Text
		if role = QtCore.Qt.DisplayRole:
			return value

		# Pass in the existing value when editing or it would be empty
		if role == QtCore.Qt.EditRole:
			return value

		# Tooltip when hover
		if role == QtCore.Qt.ToolTipRole:
			return "tooltip is" + value

	def headerData(self, section, orientation, role):
		'''set the header of this model'''
		if role == QtCore.Qt.DisplayRole:
			if orientation == QtCore.Qt.Horizontal:
				#returns the section number of this row
				return "row %s" % section

	def flags(self, index):
		'''set the property of the view'''
		return QtCore.Qt.ItemIsEnabled | QtCore.Qt.ItemisEditable | QtCore.Qt.ItemIsSelectable

	def setData(self, index, value, role = QtCore.Qt.EditRole):
		'''set the submit in the model with edit'''
		if role == QtCore.Qt.EditRole:
			row = index.row()
			color = QtGui.QColor(value) # the value given when editing
			self.data[row] = color
			self.dataChanged.emit(index,index) # update other views
			return True # must return true to set the data

		return False

	def insertRows(self, row, count, value, parent = QtCore.Qt.QModelIndex()):
		'''insert rows
		parent = QModelIndex() default to root
		'''
		# begin insert, from which row to row+count-1
		self.beginInsertRows(parent, row, row+count-1)

		for i in range(rows):
			self.data.insert(row, value)

		self.endInsertRows()

		return True

	def removeRows(self, row, count,
					parent = QtCore.Qt.QModelIndex()):
		'''remove rows, same as above'''

		self.beginRemoveRows(parent, row, row+count-1)

		for i in range(rows):
			value = self.data[row]
			self.data.remove(value)

		self.endRemoveRows()

		return True

	def insertColumns(self, column, count, value,
						parent = QtCore.QModelIndex()):
		self.beginInsertColumns(parent,column, column+count-1)

		rowCount = len(self.data)

		for i in range(counts):
			for j in range(rowCount):
				self.data[j].insert(column, value)

		self.endInsertColumns()

```


Working Examples
- [QAbstractTableModel](./_testScripts/Example_QAbstractTableModel.py)


## TreeView

TreeView has a hierarchical list data structure, much like a node based structures

[Node Based Class Example](./_testScripts/node.py)
