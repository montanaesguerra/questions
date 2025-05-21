#ifndef QUESTION_H
#define QUESTION_H

#include <string>

// declare Question here

class Question {
protected:
  std::string prompt;
  int pointValue;

public:
  // Default Constructor
  Question(const std::string& promptStr, int value);

  int getPointValue() const;

  std::string getText() const;

  virtual double scoreAnswer(const std::string& answer) const = 0;

  virtual bool validate() const;

  // Destructor
  virtual ~Question()
  {
  }
};

#endif
