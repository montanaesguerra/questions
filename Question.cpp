#include "Question.h"
#include <sstream>

// Default Constructor
Question::Question(const std::string& promptStr, int value):
    prompt(promptStr), pointValue(value)
{
}

// getPointValue()
// Returns the number of points
int Question::getPointValue() const
{
  return pointValue;
}

// getText()
// Returns prompt with the point value
std::string Question::getText() const
{
  std::ostringstream oss;
  oss << prompt << " (" << pointValue << " pts)";
  return oss.str();
}

// validate()
bool Question::validate() const
{
  return !prompt.empty() && pointValue >= 0;
}