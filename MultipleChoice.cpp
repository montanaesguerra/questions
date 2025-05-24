
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
    
    double pointsPerCorrect = pointValue / correctAnswers.size();
    double score = 0.0;

    for (char c : answer) {
        
        if (correctAnswers.find(c) != std::string::npos) {
            score += pointsPerCorrect;
        }

        else {
            score -= pointsPerCorrect;
        }
    }


    // Check if score goes below 0 : give 0 points
    if (score < 0) {
        return 0.0;
    }

    // Check if there are no correct answers
    if ( correctAnswers.size() == 0) {
        return 0.0;
    }

    return score;
}