#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    proxyModel = new QSortFilterProxyModel;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSourceModel(QAbstractItemModel *model)
{
    proxyModel->setSourceModel(model);
//     ->setModel(model);
    ui->treeView->setModel(model);
}
