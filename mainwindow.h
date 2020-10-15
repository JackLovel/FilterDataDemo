#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAbstractItemModel;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
#include <QSortFilterProxyModel>
class QTreeView;

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

private:
    Ui::MainWindow *ui;

    QSortFilterProxyModel *proxyModel;
};
#endif // MAINWINDOW_H
