#include "ShortAnswer.h"
#include <algorithm> // for transform
#include <cctype>    //for tolower

ShortAnswer::ShortAnswer(const std::string& promptStr, int value,
                         const std::string& correct):
    Question(promptStr, value), correctAnswer(correct)
{
}

// Helper function to lowercase a string (for string comparison)
static std::string toLower(const std::string& str)
{
  std::string result = str;
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  return result;
}

bool ShortAnswer::validate()
{
  return false;
}

double ShortAnswer::scoreAnswer(const std::string& answer) const
{
  if (toLower(answer) == toLower(correctAnswer)) {
    return pointValue;
  }
  return 0.0;
}
