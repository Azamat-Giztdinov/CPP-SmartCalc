#include "tests.h"

class TestCredit : public testing::Test {
 protected:
  calc::CreditModel data_;

  double loan = 3000000;
  double date = 50;
  double percent = 12;

  double DiffCreditFirstPayment = 90000;
  double DiffCreditLastPayment = 60600;
  double DiffCreditOverpayment = 765000;
  double DiffCreditSum = 3765000;

  double AnnuityCreditPayment = 76538.19;
  double AnnuityCreditOverpayment = 826909.5;
  double AnnuityCreditSum = 3826909.5;
};

TEST_F(TestCredit, AnnuityCredit) {
  data_.SetDataModel(loan, date, percent);
  data_.AnnuityCredit();
  EXPECT_LT(std::abs(data_.GetPayment() - AnnuityCreditPayment), 1);
  EXPECT_LT(std::abs(data_.GetOverpayment() - AnnuityCreditOverpayment), 1);
  EXPECT_LT(std::abs(data_.GetSum() - AnnuityCreditSum), 1);
}

TEST_F(TestCredit, DiffCredit) {
  data_.SetDataModel(loan, date, percent);
  data_.DiffCredit();
  EXPECT_LT(std::abs(data_.GetFirstPayment() - DiffCreditFirstPayment), 1);
  EXPECT_LT(std::abs(data_.GetLastPayment() - DiffCreditLastPayment), 1);
  EXPECT_LT(std::abs(data_.GetOverpayment() - DiffCreditOverpayment), 1);
  EXPECT_LT(std::abs(data_.GetSum() - DiffCreditSum), 1);
}