#include "../include/questionbank.h"
#include "../include/question.h"
#include <iostream>
#include <algorithm>



QuestionBank::QuestionBank() {
    // Constructor implementation
}



void QuestionBank::addQuestion( Question question) {
    questions.push_back(question);
}

void QuestionBank::removeQuestion(int id) {
    auto it = remove_if(questions.begin(), questions.end(),
                             [id]( Question q) { return q.getId() == id; });
    if (it != questions.end()) {
        questions.erase(it, questions.end());
    } else {
        std::cout << "Question with ID " << id << " not found." << std::endl;
    }
}

void QuestionBank::displayQuestions() {
    for ( auto &question : questions) {
        question.display();
    }
}

void QuestionBank::updateQuestion(int id,  Question updatedQuestion) {
    for (auto &question : questions) {
        if (question.getId() == id) {
            question = updatedQuestion; // Assuming operator= is defined for Question
            return;
        }
    }
    std::cout << "Question with ID " << id << " not found." << std::endl;
}
QuestionBank::~QuestionBank() {
    // Destructor implementation
    // No dynamic memory to clean up, but can be overridden in derived classes if needed
}

