#ifndef SHORTANSWER_H
#define SHORTANSWER_H

// Represents a question where the quiz taker will give a short typed response
// with a specific correct answer.

#include "Question.h"

// declare ShortAnswer here

class ShortAnswer: public Question {
protected:
  std::string correctAnswer;

public:
  ShortAnswer(const std::string& promptStr, int value,
              const std::string& answer);

  // Should if the correctAnswer is an empty string. If so, return false.
  // If not, validate it according to the same logic Question uses.
  bool validate() const override;

  // Should return the point value of the question if the given answer
  // matches the correctAnswer. Otherwise, 0.
  double scoreAnswer(const std::string& answer) const override;

  // Return correctAnswer
  std::string getCorrectAnswer();
};

#endif
