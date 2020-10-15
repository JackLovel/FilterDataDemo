#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>

#include <QLineEdit>
#include <QSortFilterProxyModel>
#include <QTreeView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSourceModel(QAbstractItemModel *model);

public slots:
    void filterRegExpChanged();

private:
    Ui::MainWindow *ui;

    QSortFilterProxyModel *proxyModel;
};
#endif // MAINWINDOW_H
