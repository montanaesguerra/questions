#include "ShortAnswer.h"
#include <algorithm> // for transform
#include <cctype>    //for tolower

ShortAnswer::ShortAnswer(const std::string& promptStr, int value,
                         const std::string& correct):
    Question(promptStr, value), correctAnswer(correct)
{
}

// Helper function to lowercase a string (for string comparison)
// static std::string toLower(const std::string& str)
// {
//   std::string result = str;
//   std::transform(result.begin(), result.end(), result.begin(),
//                  [](unsigned char c) { return std::tolower(c); });

//   return result;
// }

double ShortAnswer::scoreAnswer(const std::string& answer) const
{
  if (answer == correctAnswer) {
    return pointValue;
  }
  // if (toLower(answer) == toLower(correctAnswer)) {
  //   return pointValue;
  // }
  return 0.0;
}

// Validate()
bool ShortAnswer::validate() const
{
  // Call base class validate first
  if (!Question::validate()) {
    return false;
  }

  // Additional check: Correct Answer should not be empty
  return !correctAnswer.empty();
}

// getCorrectAnswer()
std::string ShortAnswer::getCorrectAnswer()
{
  return correctAnswer;
}
