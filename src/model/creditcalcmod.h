#ifndef CPP_SMART_CALC_V2_SRC_MODEL_CREDITCALCMOD_H_
#define CPP_SMART_CALC_V2_SRC_MODEL_CREDITCALCMOD_H_

#include <cmath>

namespace calc {

class CreditModel {
 public:
  CreditModel() = default;
  CreditModel(const CreditModel&) = delete;
  CreditModel(CreditModel&&) = delete;
  ~CreditModel() = default;
  void SetDataModel(const double loan, const int date, const double percent);
  void AnnuityCredit();
  void DiffCredit();
  double GetPayment() { return payment_; };
  double GetFirstPayment() { return first_payment_; };
  double GetLastPayment() { return last_payment_; };
  double GetOverpayment() { return overpayment_; };
  double GetSum() { return sum_; };

 private:
  double loan_;
  int date_;
  double percent_;
  double payment_;
  double first_payment_;
  double last_payment_;
  double overpayment_;
  double sum_;
};

}  // namespace calc

#endif  // CPP_SMART_CALC_V2_SRC_MODEL_CREDITCALCMOD_H_
