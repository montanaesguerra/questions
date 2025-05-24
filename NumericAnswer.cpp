#include "NumericAnswer.h"
#include <cmath> // used for abs()
#include <sstream>

NumericAnswer::NumericAnswer(const std::string& promptStr, int value,
                             const std::string& correct, double margin):
    ShortAnswer(promptStr, value, correct), allowableMargin(margin)
{
}

double NumericAnswer::scoreAnswer(const std::string& answer) const
{
  std::istringstream iss(answer);
  double userAnswer;
  double correct = 0.0;

  // Try to convert input string to double
  if (!(iss >> userAnswer)) {
    // Invalid input (Example: not a number)
    return 0.0;
  }

  std::istringstream corrIss(correctAnswer);
  if (!(corrIss >> correct)) {
    return 0.0;
  }

  return (std::abs(userAnswer - correct) <= allowableMargin) ? pointValue : 0.0;
}

bool NumericAnswer::validate() const
{
  if (!ShortAnswer::validate()) {
    return false;
  }

  if (allowableMargin < 0){
    return false;
  }

  std::istringstream iss(correctAnswer);
  double test;
  return static_cast<bool>(iss >> test);
}