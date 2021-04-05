#include "table.h"

Table::Table(QObject *parent)
    : QAbstractTableModel(parent)
{
    for( int i = 0 ; i < 2 ; i ++) datas.push_back();
}

QVariant Table::headerData(int section, Qt::Orientation orientation, int role) const
{
    static QList<QString> headers = {"x","y"};

    if(role == Qt::DisplayRole)
    {
        return headers[section];
    }

    return QVariant();
}

int Table::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int Table::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 2;
}

QVariant Table::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
