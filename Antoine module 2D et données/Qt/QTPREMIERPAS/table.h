#ifndef TABLE_H
#define TABLE_H

#include <QAbstractTableModel>

class Table : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Table(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
        QList<QString> datas;

};

#endif // TABLE_H
