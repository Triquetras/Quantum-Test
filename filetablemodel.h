#ifndef FILETABLEMODEL_H
#define FILETABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <qqml.h>

class FileTableModel : public QAbstractTableModel
{
    Q_OBJECT

    enum COLUMNS
    {
        ID,
        NAME,
        PHONE
    };


public:
    FileTableModel();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;


    void setModelData(QVector<QVector<QString> > *value);

private:
    QVector<QVector<QString> > *modelData;
};

#endif // FILETABLEMODEL_H
