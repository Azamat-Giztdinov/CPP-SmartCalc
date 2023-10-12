#include "creditcontroller.h"

namespace calc {

void CreditController::SetDate(const double loan, const int date,
                               const double percent) {
  data_.SetDataModel(loan, date, percent);
}

}  // namespace calc
