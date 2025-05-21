#ifndef NUMERICANSWER_H
#define NUMERICANSWER_H

#include "ShortAnswer.h"

// declare NumericAnswer here

class NumericAnswer: public Question {
private:
  double correctAnswer;

public:
  NumericAnswer(const std::string& promptStr, int value, double correct);

  double scoreAnswer(const std::string& answer) const override;
  bool validate() const override;
};

#endif
