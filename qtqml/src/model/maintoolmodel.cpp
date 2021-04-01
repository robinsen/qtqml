#include "maintoolmodel.h"

MainToolItem::MainToolItem(const int &type, const QString &text, const QString &img, const QString &img1)
    : m_type(type),
      m_text(text),
      m_normalImg(img),
      m_selectImg(img1)
{
}

int MainToolItem::type() const
{
    return m_type;
}

QString MainToolItem::text() const
{
    return m_text;
}

QString MainToolItem::select() const
{
    return m_selectImg;
}

QString MainToolItem::normal() const
{
    return m_normalImg;
}

MainToolModel::MainToolModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int MainToolModel::size()
{
    return m_items.size();
}

void MainToolModel::addItem(const MainToolItem &item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_items.append(item);
    endInsertRows();
}

void MainToolModel::deleteItem(const int &row)
{
    beginRemoveRows(QModelIndex(), row, row);
    m_items.removeAt(row);
    endRemoveRows();
}

void MainToolModel::insertItem(const int &row, const MainToolItem &item)
{
    beginInsertRows(QModelIndex(), row, row);
    m_items.insert(row, item);
    endInsertRows();
}

int MainToolModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_items.count();
}

QVariant MainToolModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_items.count())
        return QVariant();

    const MainToolItem &item = m_items[index.row()];
    if (role == TypeRole)
        return item.type();
    else if (role == TextRole)
        return item.text();
    else if (role == NormalRole)
        return item.normal();
    else if (role == SelectRole)
        return item.select();
    return QVariant();
}

//![0]
QHash<int, QByteArray> MainToolModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[TextRole] = "strText";
    roles[NormalRole] = "normal";
    roles[SelectRole] = "select";
    return roles;
}
//![0]
