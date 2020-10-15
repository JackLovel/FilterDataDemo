#include "mainwindow.h"

#include <QApplication>

#include <QStandardItemModel>
#include <QTime>

void addMail(QAbstractItemModel *model, const QString &name)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), name);
}

QAbstractItemModel *createMailModel(QObject *parent)
{
    QStandardItemModel *model = new QStandardItemModel(0, 1, parent);

    model->setHeaderData(0, Qt::Horizontal, "姓名");

    addMail(model, "li hong");
    addMail(model, "wang gang");

    return model;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setSourceModel(createMailModel(&w));
    w.show();
    w.setWindowTitle("信息过滤");
    return a.exec();
}
