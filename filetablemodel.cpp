#include "filetablemodel.h"

FileTableModel::FileTableModel()
{

}

int FileTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

int FileTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant FileTableModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    return modelData->value(index.row()).value(index.column());
}

QHash<int, QByteArray> FileTableModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}

QVariant FileTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation)

    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch (section)
    {
    case ID:
        return qtTrId("User ID");
        break;
    case NAME:
        return qtTrId("User Name");
        break;
    case PHONE:
        return qtTrId("User Phone");
        break;
    }
    return QVariant();
}

void FileTableModel::setModelData(QVector<QVector<QString> > *value)
{
    beginResetModel();
    modelData = value;
    endResetModel();
}
