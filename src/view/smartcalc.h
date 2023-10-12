#ifndef SMARTCALC_H
#define SMARTCALC_H
#include <QMainWindow>
#include <cstring>

#include "../controller/smartcontroller.h"
#include "creditcalc.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class SmartCalc;
}
QT_END_NAMESPACE

class SmartCalc : public QMainWindow {
  Q_OBJECT

 public:
  SmartCalc(calc::CalcController *controller, QWidget *parent = nullptr);
  ~SmartCalc();

 private:
  Ui::SmartCalc *ui;
  CreditCalc *Cw;
  calc::CalcController *controller_;
  QVector<double> x_, y_;

 private slots:
  void click_button();
  void on_pushButton_res_clicked();
  void on_pushButton_delete_clicked();
  void on_pushButton_del_one_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_del_one_2_clicked();
  void on_pushButton_calc2_clicked();
};
#endif  // SMARTCALC_H
