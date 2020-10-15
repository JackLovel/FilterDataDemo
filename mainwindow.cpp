#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    proxyModel = new QSortFilterProxyModel;

    ui->lineEdit->setPlaceholderText("输入...");

    ui->sourceView->setRootIsDecorated(false);
    ui->sourceView->setAlternatingRowColors(true);

    ui->treeView->setRootIsDecorated(false);
    ui->treeView->setAlternatingRowColors(true);
    ui->treeView->setModel(proxyModel);
    ui->treeView->setSortingEnabled(true);

    connect(ui->lineEdit, &QLineEdit::textChanged,
            this, &MainWindow::filterRegExpChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSourceModel(QAbstractItemModel *model)
{
    proxyModel->setSourceModel(model);
    ui->sourceView->setModel(model);
}

void MainWindow::filterRegExpChanged() {
    QRegExp::PatternSyntax syntax = QRegExp::FixedString;

    Qt::CaseSensitivity caseSen = Qt::CaseSensitivity(0);
    QString text = ui->lineEdit->text();

    QRegExp regExp(text, caseSen, syntax);
    proxyModel->setFilterRegExp(regExp);
}
