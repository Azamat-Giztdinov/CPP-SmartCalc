#include "smartcalc.h"

#include "ui_smartcalc.h"

SmartCalc::SmartCalc(calc::CalcController *controller, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartCalc), controller_(controller) {
  ui->setupUi(this);
  setFixedSize(size());
  Cw = new CreditCalc();
  connect(Cw, &CreditCalc::smartWindow, this, &SmartCalc::show);
  for (auto it : ui->buttonGroup->buttons()) {
    connect(it, SIGNAL(clicked()), this, SLOT(click_button()));
  }
}

SmartCalc::~SmartCalc() { delete ui; }

void SmartCalc::click_button() {
  if (ui->lineEdit->text() == "Error" || ui->lineEdit->text() == "inf" ||
      ui->lineEdit->text() == "-inf" || ui->lineEdit->text() == "nan") {
    ui->lineEdit->setText("");
  }
  QPushButton *button = (QPushButton *)sender();
  const QString dop = button->text();
  QString dop1 = ui->lineEdit->text();
  dop1.append(dop);
  if (strchr("sctal", (int)dop.toStdString().c_str()[0])) {
    dop1.append("(");
  }
  ui->lineEdit->setText(dop1);
}

void SmartCalc::on_pushButton_res_clicked() {
  double x = ui->lineEdit_2->text().toDouble();
  std::string str = ui->lineEdit->text().toStdString();
  controller_->SetExpression(str);
  if (controller_->CorrectExpression()) {
    ui->lineEdit->setText(QString::number(controller_->GetResult(x)));
  } else {
    ui->lineEdit->setText("Error");
  }
}

void SmartCalc::on_pushButton_delete_clicked() { ui->lineEdit->setText(""); }

void SmartCalc::on_pushButton_del_one_clicked() {
  if (ui->lineEdit->text() == "Error" || ui->lineEdit->text() == "inf" ||
      ui->lineEdit->text() == "-inf" || ui->lineEdit->text() == "nan") {
    ui->lineEdit->setText("");
  } else {
    QString str = ui->lineEdit->text();
    str.resize(str.size() - 1);
    ui->lineEdit->setText(str);
  }
}

void SmartCalc::on_pushButton_graph_clicked() {
  ui->widget->clearGraphs();
  controller_->SetExpression(ui->lineEdit->text().toStdString());
  if (controller_->CorrectExpression()) {
    x_.clear();
    y_.clear();
    double minX_ = ui->doubleSpinBox_x_min->value();
    double maxX_ = ui->doubleSpinBox_x_max->value();
    double interval = 0.1;
    while (minX_ <= maxX_) {
      x_.push_back(minX_);
      y_.push_back(controller_->GetResult(minX_));
      minX_ += interval;
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x_, y_);
    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->widget->xAxis->setRange(ui->doubleSpinBox_x_min->value(),
                                ui->doubleSpinBox_x_max->value());
    ui->widget->yAxis->setRange(ui->doubleSpinBox_y_min->value(),
                                ui->doubleSpinBox_y_max->value());
    ui->widget->replot();

  } else {
    ui->lineEdit->setText("Error");
  }
}

void SmartCalc::on_pushButton_del_one_2_clicked() {
  ui->lineEdit_2->setText("");
}

void SmartCalc::on_pushButton_calc2_clicked() {
  Cw->show();
  this->close();
}
