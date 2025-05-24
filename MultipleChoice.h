#ifndef MULTIPLECHOICE_H
#define MULTIPLECHOICE_H

/*
Represents a multiple answer question with four options, A/B/C/D. There may
be more than one correct answer. Thus correctAnswers will store a string containing
all the correct answers like "C" or "ABD"
*/
#include "Question.h"

// declare MultipleChoice here

class MultipleChoice: public Question {
    private:
        std::string correctAnswers;
        std::string options[4];

    public:

    // Constructor
    MultipleChoice(const std::string& promptStr, int pointValue,
    const std::string& correctChoices);

    std::string getText() const override;

    bool validate() const override;

    void setOption(int index, const std::string& option);

    double scoreAnswer(const std::string& answer) const override;

};

#endif
