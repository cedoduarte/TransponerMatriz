#include "Widget.h"
#include "ui_Widget.h"
#include "DoubleSpinBoxDelegate.h"
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    mModelT = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    ui->tableViewT->setModel(mModelT);
    ui->tableView->setItemDelegate(new DoubleSpinBoxDelegate(this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_numeroDeFilasSpinBox_valueChanged(int arg1)
{
    mModel->setRowCount(arg1);
    mModelT->setColumnCount(arg1);
}

void Widget::on_numeroDeColumnasSpinBox_valueChanged(int arg1)
{
    mModel->setColumnCount(arg1);
    mModelT->setRowCount(arg1);
}

void Widget::on_transponerPushButton_clicked()
{
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    const int tRowCount = mModelT->rowCount();
    const int tColCount = mModelT->columnCount();
    mModelT->clear();
    mModelT->setRowCount(tRowCount);
    mModelT->setColumnCount(tColCount);
    for (int jx = 0; jx < colCount; ++jx) {
        for (int ix = 0; ix < rowCount; ++ix) {
            appendTo(mModelT, getValueAt(mModel, ix, jx));
        }
    }
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

double Widget::getValueAt(QStandardItemModel *model, int ix, int jx) const
{
    if (!model->item(ix, jx)) {
        return 0.0;
    }
    return model->item(ix, jx)->text().toDouble();
}

void Widget::appendTo(QStandardItemModel *model, double value) const
{
    const int rowCount = model->rowCount();
    const int colCount = model->columnCount();
    for (int ix = 0; ix < rowCount; ++ix) {
        for (int jx = 0; jx < colCount; ++jx) {
            if (!model->item(ix, jx)) {
                model->setItem(ix, jx,
                    new QStandardItem(QString::number(value)));
                return;
            }
        }
    }
}
