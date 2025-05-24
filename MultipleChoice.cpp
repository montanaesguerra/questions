
#include "MultipleChoice.h"

MultipleChoice::MultipleChoice(const std::string& promptStr, int point,
    const std::string& correct)
    : Question(promptStr, point), correctAnswers(correct){
        // initialize options with empty strings
        for (int i = 0; i < 4; ++i) {
            options[i] = "";
        }
    }


void MultipleChoice::setOption(int index, const std::string& option) {
    if (index >= 0 && index < 4) {
        options[index] = option;
    }
}

std::string MultipleChoice::getText() const{
    std::string finalText = Question::getText();

    for (int i = 0; i < 4; ++i) {
        char label = 'A' + i;
        finalText += "\n";
        finalText += label;
        finalText += ": " + options[i];
    }
    return finalText;
}

bool MultipleChoice::validate() const {

    // Call base class validate first
    if (!Question::validate()) {
        return false;
    }

    return !correctAnswers.empty();

}

double MultipleChoice::scoreAnswer(const std::string& answer) const {
    if (answer == correctAnswers)
        return pointValue;
    
    return 0.0;
}