#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_numeroDeFilasSpinBox_valueChanged(int arg1);
    void on_numeroDeColumnasSpinBox_valueChanged(int arg1);
    void on_transponerPushButton_clicked();
    void on_quitarAplicacionPushButton_clicked();
private:
    double getValueAt(QStandardItemModel *model, int ix, int jx) const;
    void appendTo(QStandardItemModel *model, double value) const;

    Ui::Widget *ui;
    QStandardItemModel *mModel;
    QStandardItemModel *mModelT;
};

#endif // WIDGET_H
