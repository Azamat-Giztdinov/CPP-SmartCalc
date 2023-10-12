#include "creditcalc.h"

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
  setFixedSize(size());
  ui->radioButton->setChecked(true);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_calc1_clicked() {
  this->close();
  emit smartWindow();
}

void CreditCalc::on_pushButton_clicked() {
  QString str;
  int type = ui->radioButton->isChecked() ? 1 : 0;
  credit_controller_.SetDate(ui->doubleSpinBox_start->value(),
                             ui->doubleSpinBox_date->value(),
                             ui->doubleSpinBox_percent->value());
  if (type) {
    credit_controller_.AnnuityCredit();
    str = QString::number(credit_controller_.GetPayment());

  } else {
    credit_controller_.DiffCredit();
    str = QString::number(credit_controller_.GetFirstPayment());
    str.append(" - ");
    str.append(QString::number(credit_controller_.GetLastPayment()));
  }
  ui->label_month->setText(str);
  ui->label_add->setText(QString::number(credit_controller_.GetOverpayment()));
  ui->label_endsum->setText(QString::number(credit_controller_.GetSum()));
}
