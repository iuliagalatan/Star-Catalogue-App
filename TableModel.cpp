#include "TableModel.h"
#include "Service.h"
#include "qcolor.h"

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString("Name");
			case 1:
				return QString("Constelation");
			case 2:
				return QString("RA");
			case 3:
				return QString("DEC");
			case 4:
				return QString("Diameter");

			}
		}
	}
	return QVariant();
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant{};

	int row = index.row();
	int col = index.column();
	if (row < 0 || col < 0)
		return QVariant{};
	//std::vector<TElem> obj = service->GetObjects();
	std::vector<TElem> obj = service->getSorted();
	TElem object = obj[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(object.getName());
		case 1:
			return QString::fromStdString(object.getConstelation());
		case 2:
			return QString::fromStdString(object.getRA());
		case 3:
			return QString::fromStdString(object.getDEC());
		case 4:
			return QString::fromStdString(std::to_string(object.getDiameter()));
		default:
			break;
		}

	}
	/*if (role == Qt::BackgroundRole) {

		return QVariant(QColor(Qt::red));
	}*/
	return QVariant();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	return 5;
}

int TableModel::rowCount(const QModelIndex& parent) const
{
	//if (checked)
	//	return service->getFiltered().size();
	return service->GetObjects().size();
}

bool TableModel::insertRows(int row, int count, const QModelIndex& parent)
{
	Q_UNUSED(parent);
	beginInsertRows(QModelIndex(), row, row + count - 1);

	endInsertRows();
	return true;
}

bool TableModel::removeRows(int row, int count, const QModelIndex& parent)
{
	Q_UNUSED(parent);
	beginRemoveRows(QModelIndex(), row, row + count - 1);

	endRemoveRows();
	return true;
}


bool TableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	return false;

}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{

	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void TableModel::setChecked(bool ch)
{
	checked = ch;
}
