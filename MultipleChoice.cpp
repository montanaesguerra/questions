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

// std::string MultipleChoice::getText() const {
//     std::string text = getPrompt() + "\n";
//     char label = 'A';
//     for (int i = 0; i < 4; ++i) {
//         text += label;
//         text += ": " + options[i] + "\n";
//         ++label;
//     }
//     return text;
// }

bool MultipleChoice::validate() const {

    // Call base class validate first
    if (!Question::validate()) {
        return false;
    }

    //Check that correct Answers is not empty

    for (int i = 0; i < 4; ++i) {
        if (options[i].empty())
        return false;
    }

    return !correctAnswers.empty();

    //validate correctAnswers contains only A-D
    //TODO
}

double MultipleChoice::scoreAnswer(const std::string& answer) const {
    if (answer == correctAnswers)
        return pointValue;
    
    return 0.0;
}