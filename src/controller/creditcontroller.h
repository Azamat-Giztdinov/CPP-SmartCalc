#ifndef CPP_SMART_CALC_V2_SRC_CONTROLLER_CREDITCONTROLLER_H_
#define CPP_SMART_CALC_V2_SRC_CONTROLLER_CREDITCONTROLLER_H_

#include <iostream>

#include "../model/creditcalcmod.h"

namespace calc {
class CreditController {
 public:
  CreditController() = default;
  CreditController(const CreditController &) = delete;
  CreditController(CreditController &&) = delete;
  ~CreditController() = default;

  void SetDate(const double loan, const int date, const double percent);
  void AnnuityCredit() { data_.AnnuityCredit(); };
  void DiffCredit() { data_.DiffCredit(); };
  double GetPayment() { return data_.GetPayment(); };
  double GetFirstPayment() { return data_.GetFirstPayment(); };
  double GetLastPayment() { return data_.GetLastPayment(); };
  double GetOverpayment() { return data_.GetOverpayment(); };
  double GetSum() { return data_.GetSum(); };

 private:
  CreditModel data_;
};
}  // namespace calc

#endif  // CPP_SMART_CALC_V2_SRC_CONTROLLER_CREDITCONTROLLER_H_