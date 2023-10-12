#ifndef CPP_SMART_CALC_V2_SRC_MODEL_SMARTCALCMOD_H_
#define CPP_SMART_CALC_V2_SRC_MODEL_SMARTCALCMOD_H_

#include <cmath>
#include <cstring>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace calc {

enum Operation {
  OPENBRACKET,
  CLOSEBRACKET,
  NUMBER,
  X,

  MINUS,
  PLUS,
  MOD,
  MUL,
  DIV,
  EXP,

  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  SQRT,
  LN,
  LOG
};

class CalcModel {
 public:
  CalcModel() = default;
  CalcModel(const CalcModel &) = delete;
  CalcModel(CalcModel &&) = delete;
  ~CalcModel() = default;
  void SetExpression(const std::string &str);
  bool Correct() { return correct_; };
  double GetResult(double x = 0) { return Result(x); };

 private:
  class Lexeme {
   public:
    Lexeme() = delete;
    Lexeme(Operation operation) : operation_(operation) { SetPriority(); };
    Lexeme(Operation operation, double value)
        : operation_(operation), value_(value){};
    Operation GetOperation() { return operation_; };
    int GetPriority() { return priority_; };
    double GetValue() { return value_; };
    void SetValue(double x) {
      if (operation_ == X) value_ = x;
    };

   private:
    Operation operation_;
    double value_ = 0;
    int priority_ = 0;

    void SetPriority();
  };

  std::string str_;
  std::string::iterator it_;
  std::list<Lexeme> infix_;
  std::list<Lexeme> postfix_;
  std::stack<double> numbers_;
  std::stack<Lexeme> operations_;
  bool correct_;
  double x_;
  int countBracket_;

  double Result(double x);
  void Clear();
  void StringToLexeme();
  void GetPostfix();
  void OperatorSearch();
  double StrToDouble();
  void AddUnarOper();
  bool SearchFunctions();
  bool SearchOperation();
  void PushOperation(std::list<Lexeme>::iterator it);
  void CalcOperation(std::list<Lexeme>::iterator it);
  void CalcFuntion(std::list<Lexeme>::iterator it);
  static const std::map<std::string, Operation> mapFunctions;
  static const std::map<std::string, Operation> mapOperators;
};

}  // namespace calc

#endif  // CPP_SMART_CALC_V2_SRC_MODEL_SMARTCALCMOD_H_
