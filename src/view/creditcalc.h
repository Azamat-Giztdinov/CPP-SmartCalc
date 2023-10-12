#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QDialog>

#include "../controller/creditcontroller.h"

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 signals:
  void smartWindow();

 private slots:
  void on_pushButton_calc1_clicked();

  void on_pushButton_clicked();

 private:
  Ui::CreditCalc *ui;
  calc::CreditController credit_controller_;
};

#endif  // CREDITCALC_H
