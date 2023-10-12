#include "smartcontroller.h"

namespace calc {

void CalcController::SetExpression(const std::string &infix) {
  expression_->SetExpression(infix);
}

bool CalcController::CorrectExpression() { return expression_->Correct(); }

double CalcController::GetResult(double x) { return expression_->GetResult(x); }

}  // namespace calc
