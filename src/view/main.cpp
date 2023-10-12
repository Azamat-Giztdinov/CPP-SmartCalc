#include <QApplication>

#include "smartcalc.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  calc::CalcModel model;
  calc::CalcController controller(&model);
  SmartCalc w(&controller);
  w.show();
  return a.exec();
}
