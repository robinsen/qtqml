#ifndef MAINTOOLMODEL_H
#define MAINTOOLMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include "globaldefine.h"
#include "resourcemanager.h"

//![0]
class MainToolItem
{
public:
    MainToolItem(const int &type, const QString &text, const QString &img, const QString &img1);
//![0]

    int type() const;
    QString text() const;
    QString normal() const;
    QString select() const;

private:
    int m_type;
    QString m_text;
    QString m_normalImg = GetResPath("collect_4.png");
    QString m_selectImg = GetResPath("collect_6.png");
//![1]
};


class MainToolModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ToolRoles {
        TypeRole = Qt::UserRole + 1,
        TextRole,
        NormalRole,
        SelectRole
    };

    MainToolModel(QObject *parent = 0);

    Q_INVOKABLE int size();
//![1]

    void addItem(const MainToolItem &item);
    void deleteItem(const int &row);
    void insertItem(const int &row, const MainToolItem &item);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<MainToolItem> m_items;
//![2]
};
//![2]



#endif
