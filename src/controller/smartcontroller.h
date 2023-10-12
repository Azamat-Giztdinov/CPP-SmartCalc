#ifndef CPP_SMART_CALC_V2_SRC_CONTROLLER_SMARTCONTROLLER_H_
#define CPP_SMART_CALC_V2_SRC_CONTROLLER_SMARTCONTROLLER_H_

#include "../model/smartcalcmod.h"

namespace calc {

class CalcController {
 public:
  CalcController() = default;
  CalcController(const CalcController &) = delete;
  CalcController(CalcController &&) = delete;
  CalcController(CalcModel *expression) : expression_(expression){};
  ~CalcController() = default;

  void SetExpression(const std::string &infix);
  bool CorrectExpression();
  double GetResult(double x = 0);

 private:
  CalcModel *expression_;
};

}  // namespace calc

#endif  // CPP_SMART_CALC_V2_SRC_CONTROLLER_SMARTCONTROLLER_H_