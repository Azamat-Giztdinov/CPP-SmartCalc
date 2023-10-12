#include "creditcalcmod.h"

namespace calc {

void CreditModel::SetDataModel(const double loan, const int date,
                               const double percent) {
  loan_ = loan;
  date_ = date;
  percent_ = percent;
}

void CreditModel::AnnuityCredit() {
  double perc = percent_ / 1200;
  double dop = pow((1 + perc), date_);
  payment_ = loan_ * perc * dop / (dop - 1);
  sum_ = payment_ * date_;
  overpayment_ = sum_ - loan_;
}

void CreditModel::DiffCredit() {
  double remainder = 0;
  double dop = 0;
  sum_ = loan_;
  double sum_pay = loan_ / date_;
  for (int i = 0; i < date_; i++) {
    remainder = loan_ - sum_pay * i;
    dop = remainder * percent_ / 1200;
    sum_ += dop;
    if (i == 0) {
      first_payment_ = dop + sum_pay;
    }
  }
  last_payment_ = dop + sum_pay;
  overpayment_ = sum_ - loan_;
}

}  // namespace calc
