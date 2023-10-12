#include "smartcalcmod.h"

namespace calc {

void CalcModel::Lexeme::SetPriority() {
  if (operation_ == PLUS || operation_ == MINUS) {
    priority_ = 1;
  } else if (operation_ == MUL || operation_ == DIV || operation_ == MOD) {
    priority_ = 2;
  } else if (operation_ == EXP) {
    priority_ = 3;
  } else if (operation_ >= COS || operation_ == OPENBRACKET) {
    priority_ = 4;
  } else if (operation_ == CLOSEBRACKET) {
    priority_ = 5;
  }
}

void CalcModel::SetExpression(const std::string &str) {
  Clear();
  str_ = str;
  x_ = 0;
  it_ = str_.begin();
  StringToLexeme();
  AddUnarOper();
  GetPostfix();
  Result(x_);
}

void CalcModel::Clear() {
  correct_ = true;
  countBracket_ = 0;
  infix_.clear();
  postfix_.clear();
  while (operations_.size()) {
    operations_.pop();
  }
  while (numbers_.size()) {
    numbers_.pop();
  }
}

double CalcModel::Result(double x) {
  for (auto i = postfix_.begin(); i != postfix_.end() && correct_; ++i) {
    if ((*i).GetPriority() == 0) {
      if ((*i).GetOperation() == X) (*i).SetValue(x);
      numbers_.push((*i).GetValue());
    } else if ((*i).GetPriority() < 4) {
      CalcOperation(i);
    } else {
      CalcFuntion(i);
    }
  }
  if (numbers_.size() == 1) {
    x_ = numbers_.top();
    numbers_.pop();
  } else {
    correct_ = false;
  }
  return x_;
}

void CalcModel::CalcOperation(std::list<Lexeme>::iterator it) {
  if (numbers_.size() > 1) {
    double x2 = numbers_.top();
    numbers_.pop();
    double x1 = numbers_.top();
    numbers_.pop();
    auto i = (*it).GetOperation();
    if (i == PLUS)
      numbers_.push(x1 + x2);
    else if (i == MINUS)
      numbers_.push(x1 - x2);
    else if (i == MUL)
      numbers_.push(x1 * x2);
    else if (i == DIV)
      numbers_.push(x1 / x2);
    else if (i == MOD)
      numbers_.push(fmod(x1, x2));
    else if (i == EXP)
      numbers_.push(pow(x1, x2));
  } else {
    correct_ = false;
  }
}

void CalcModel::CalcFuntion(std::list<Lexeme>::iterator it) {
  if (numbers_.size() > 0) {
    double x = numbers_.top();
    numbers_.pop();
    auto i = (*it).GetOperation();
    if (i == COS)
      numbers_.push(cos(x));
    else if (i == ACOS)
      numbers_.push(acos(x));
    else if (i == SIN)
      numbers_.push(sin(x));
    else if (i == ASIN)
      numbers_.push(asin(x));
    else if (i == TAN)
      numbers_.push(tan(x));
    else if (i == ATAN)
      numbers_.push(atan(x));
    else if (i == LN)
      numbers_.push(log(x));
    else if (i == LOG)
      numbers_.push(log10(x));
    else if (i == SQRT)
      numbers_.push(sqrt(x));
  } else {
    correct_ = false;
  }
}

void CalcModel::StringToLexeme() {
  char ch = 0;
  for (; it_ != str_.end() && correct_ && countBracket_ >= 0; ++it_) {
    ch = (*it_);
    if (ch == ' ') {
      continue;
    } else if (isdigit(ch)) {
      infix_.push_back(Lexeme(NUMBER, StrToDouble()));
    } else if (ch == '(') {
      infix_.push_back(OPENBRACKET);
      countBracket_++;
    } else if (ch == ')') {
      infix_.push_back(CLOSEBRACKET);
      countBracket_--;
    } else if (ch == 'x') {
      infix_.push_back(Lexeme(X, x_));
    } else {
      OperatorSearch();
    }
  }
  if (countBracket_) correct_ = false;
}

double CalcModel::StrToDouble() {
  double res = 0;
  int i = 0;
  sscanf(&it_[0], "%le%n", &res, &i);
  it_ += (i - 1);
  return res;
}

void CalcModel::GetPostfix() {
  if (!correct_) return;
  for (auto i = infix_.begin(); i != infix_.end(); i++) {
    if ((*i).GetPriority() == 0) {
      postfix_.push_back(*i);
    } else {
      PushOperation(i);
    }
  }
  while (operations_.size()) {
    postfix_.push_back(operations_.top());
    operations_.pop();
  }
}

void CalcModel::PushOperation(std::list<Lexeme>::iterator it) {
  if (operations_.size() == 0) {
    operations_.push(*it);
  } else {
    if ((*it).GetPriority() == 5) {
      while (operations_.size() && operations_.top().GetPriority() != 4) {
        postfix_.push_back(operations_.top());
        operations_.pop();
      }
      if (operations_.size() &&
          operations_.top().GetOperation() != OPENBRACKET) {
        postfix_.push_back(operations_.top());
      }
      operations_.pop();
    } else if (((*it).GetPriority() == 3 && operations_.size() &&
                operations_.top().GetPriority() == 3) ||
               (*it).GetPriority() > operations_.top().GetPriority()) {
      operations_.push(*it);
    } else if (operations_.size() &&
               (*it).GetPriority() <= operations_.top().GetPriority() &&
               operations_.top().GetPriority() < 4) {
      while (operations_.size() &&
             operations_.top().GetPriority() >= (*it).GetPriority() &&
             operations_.top().GetPriority() < 4) {
        postfix_.push_back(operations_.top());
        operations_.pop();
      }
      operations_.push(*it);

    } else {
      operations_.push(*it);
    }
  }
}

void CalcModel::OperatorSearch() {
  correct_ = false;
  if (SearchFunctions() || SearchOperation()) {
    correct_ = true;
  }
}

bool CalcModel::SearchFunctions() {
  for (auto i : mapFunctions) {
    if (!strncmp(&it_[0], i.first.data(), i.first.size()) &&
        *(it_ + i.first.size()) == '(') {
      infix_.push_back(i.second);
      it_ += i.first.size();
      countBracket_++;
      return true;
    }
  }
  return false;
}

bool CalcModel::SearchOperation() {
  for (auto i : mapOperators) {
    if (!strncmp(&it_[0], i.first.data(), i.first.size())) {
      infix_.push_back(i.second);
      it_ += i.first.size() - 1;
      return true;
    }
  }
  return false;
}

void CalcModel::AddUnarOper() {
  std::list<Lexeme>::iterator i = infix_.begin();
  std::list<Lexeme>::iterator i_ = i;
  for (; i != infix_.end(); ++i) {
    if (i == infix_.begin()) {
      if ((*i).GetOperation() == MINUS || (*i).GetOperation() == PLUS)
        infix_.push_front(Lexeme(NUMBER, 0));
    } else {
      if (((*i).GetOperation() == MINUS || (*i).GetOperation() == PLUS) &&
          (*(i_)).GetOperation() == OPENBRACKET) {
        infix_.insert(i, Lexeme(NUMBER, 0));
      }
    }
    i_ = i;
  }
}

const std::map<std::string, Operation> CalcModel::mapFunctions = {
    {"cos", COS},   {"acos", ACOS}, {"sin", SIN}, {"asin", ASIN}, {"tan", TAN},
    {"atan", ATAN}, {"sqrt", SQRT}, {"ln", LN},   {"log", LOG}};

const std::map<std::string, Operation> CalcModel::mapOperators = {
    {"+", PLUS}, {"-", MINUS}, {"*", MUL},
    {"/", DIV},  {"mod", MOD}, {"^", EXP}};

}  // namespace calc
