#include "tests.h"

class TestCalc : public testing::Test {
 protected:
  calc::CalcModel data_;

  std::string test1_ = "sqrt(30)+4^5";
  double result1_ = sqrt(30) + pow(4, 5);

  std::string test2_ = "acos(cos(180))- tan(30)";
  double result2_ = acos(cos(180)) - tan(30);

  std::string test3_ = "asin(sin(180))- atan(30)";
  double result3_ = asin(sin(180)) - atan(30);

  std::string test4_ = "5^2/4";
  double result4_ = pow(5, 2) / 4;

  std::string test5_ = "5.006 * 97.83 +3.7^8.37/(-5.6) + ln(25.6)";
  double result5_ = 5.006 * 97.83 + pow(3.7, 8.37) / (-5.6) + log(25.6);

  std::string test6_ = "(5 + 3) * 6 + 20 * log(25.6)";
  double result6_ = (5 + 3) * 6 + 20 * log10(25.6);

  std::string test7_ = "5.68 * (4+log(4.3+ cos(29.7)))";
  double result7_ = 5.68 * (4 + log10(4.3 + cos(29.7)));

  std::string test8_ = "5.34 * (45.33 mod 3.563)";
  double result8_ = 5.34 * fmod(45.33, 3.563);

  std::string testX1_ = "5.34 * (x mod 3.563)";
  double x1_ = 45.33;
  double resultX1_ = 5.34 * fmod(x1_, 3.563);

  std::string testX2_ = "5.68*(x+log(4.3+ cos(29.7)))";
  double x2_ = 4;
  double resultX2_ = 5.68 * (x2_ + log10(4.3 + cos(29.7)));

  std::string testX3_ = "(5+3)*x+20*log(25.6)";
  double x3_ = 6;
  double resultX3_ = (5 + 3) * x3_ + 20 * log10(25.6);

  std::string testX4_ = "5.006 * 97.83 +3.7^8.37/(-5.6)*x + ln(x)";
  double x4_ = 25.6;
  double resultX4_ = 5.006 * 97.83 + pow(3.7, 8.37) / (-5.6) * x4_ + log(x4_);

  std::string testX5_ = "x^2/4";
  double x5_ = 5.8;
  double resultX5_ = pow(x5_, 2) / 4;

  std::string testX6_ = "asin(sin(x))- atan(x)";
  double x6_ = 30;
  double resultX6_ = asin(sin(x6_)) - atan(x6_);

  std::string testX7_ = "acos(cos(x))- tan(30)";
  double x7_ = 180;
  double resultX7_ = acos(cos(x7_)) - tan(30);

  std::string testX8_ = "sqrt(x)+4^5";
  double x8_ = 30.567;
  double resultX8_ = sqrt(x8_) + pow(4, 5);

  std::string testError1_ = "5.006* 97.83 +3.7^8.37/(-5.6) + ln(";
  std::string testError2_ = "sin(24.5)+cos";
  std::string testError3_ = "5.34 * (45.33 mo 3.563)";
  std::string testError4_ = "5.006* 97.83 +x^8.37/(-5.6) + ln(";
};

TEST_F(TestCalc, Test1) {
  data_.SetExpression(test1_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result1_);
}

TEST_F(TestCalc, Test2) {
  data_.SetExpression(test2_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result2_);
}

TEST_F(TestCalc, Test3) {
  data_.SetExpression(test3_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result3_);
}

TEST_F(TestCalc, Test4) {
  data_.SetExpression(test4_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result4_);
}

TEST_F(TestCalc, Test5) {
  data_.SetExpression(test5_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result5_);
}

TEST_F(TestCalc, Test6) {
  data_.SetExpression(test6_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result6_);
}

TEST_F(TestCalc, Test7) {
  data_.SetExpression(test7_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result7_);
}

TEST_F(TestCalc, Test8) {
  data_.SetExpression(test8_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(), result8_);
}

TEST_F(TestCalc, TestX1) {
  data_.SetExpression(testX1_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x1_), resultX1_);
}

TEST_F(TestCalc, TestX2) {
  data_.SetExpression(testX2_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x2_), resultX2_);
}

TEST_F(TestCalc, TestX3) {
  data_.SetExpression(testX3_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x3_), resultX3_);
}

TEST_F(TestCalc, TestX4) {
  data_.SetExpression(testX4_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x4_), resultX4_);
}

TEST_F(TestCalc, TestX5) {
  data_.SetExpression(testX5_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x5_), resultX5_);
}

TEST_F(TestCalc, TestX6) {
  data_.SetExpression(testX6_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x6_), resultX6_);
}

TEST_F(TestCalc, TestX7) {
  data_.SetExpression(testX7_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x7_), resultX7_);
}

TEST_F(TestCalc, TestX8) {
  data_.SetExpression(testX8_);
  EXPECT_TRUE(data_.Correct());
  EXPECT_DOUBLE_EQ(data_.GetResult(x8_), resultX8_);
}

TEST_F(TestCalc, TestError1) {
  data_.SetExpression(testError1_);
  EXPECT_FALSE(data_.Correct());
}

TEST_F(TestCalc, TestError2) {
  data_.SetExpression(testError2_);
  EXPECT_FALSE(data_.Correct());
}

TEST_F(TestCalc, TestError3) {
  data_.SetExpression(testError3_);
  EXPECT_FALSE(data_.Correct());
}

TEST_F(TestCalc, TestError4) {
  data_.SetExpression(testError4_);
  EXPECT_FALSE(data_.Correct());
}