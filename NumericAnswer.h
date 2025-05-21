#ifndef NUMERICANSWER_H
#define NUMERICANSWER_H

#include "ShortAnswer.h"

// declare NumericAnswer here

class NumericAnswer: public ShortAnswer {
private:
  double allowableMargin;

public:
  NumericAnswer(const std::string& promptStr, int value,
                const std::string& correct, double margin);

  double scoreAnswer(const std::string& answer) const override;
  bool validate() const override;
};

#endif
