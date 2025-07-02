#include <iostream>
#include "../include/questionbank.h"
#include "../include/question.h"

using namespace std;

int main() {
    QuestionBank qb;
    int choice;

    do {
        cout << "\n===== QUESTION BANK MENU =====" << endl;
        cout << "1. Add Question" << endl;
        cout << "2. Display All Questions" << endl;
        cout << "3. Update Question" << endl;
        cout << "4. Remove Question" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Question q;
                int id, evalId;
                string subject, title, a, b, c, d;
                char key;

                cout << "Enter Question ID: ";
                cin >> id;
                cin.ignore(); // flush newline

                cout << "Enter Subject: ";
                getline(cin, subject);

                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Option A: ";
                getline(cin, a);

                cout << "Enter Option B: ";
                getline(cin, b);

                cout << "Enter Option C: ";
                getline(cin, c);

                cout << "Enter Option D: ";
                getline(cin, d);

                cout << "Enter Answer Key (A/B/C/D): ";
                cin >> key;

                cout << "Enter Evaluation ID: ";
                cin >> evalId;

                q.setId(id);
                q.setSubject(subject);
                q.setTitle(title);
                q.setOptionA(a);
                q.setOptionB(b);
                q.setOptionC(c);
                q.setOptionD(d);
                q.setAnswerKey(key);
                q.setEvaluationId(evalId);

                qb.addQuestion(q);
                break;
            }

            case 2:
                qb.displayQuestions();
                break;

            case 3: {
                int updateId;
                cout << "Enter ID of question to update: ";
                cin >> updateId;
                cin.ignore();

                Question updated;
                string subject, title, a, b, c, d;
                char key;
                int evalId;

                cout << "Enter new Subject: ";
                getline(cin, subject);
                cout << "Enter new Title: ";
                getline(cin, title);
                cout << "Enter new Option A: ";
                getline(cin, a);
                cout << "Enter new Option B: ";
                getline(cin, b);
                cout << "Enter new Option C: ";
                getline(cin, c);
                cout << "Enter new Option D: ";
                getline(cin, d);
                cout << "Enter new Answer Key (A/B/C/D): ";
                cin >> key;
                cout << "Enter new Evaluation ID: ";
                cin >> evalId;

                updated.setId(updateId);
                updated.setSubject(subject);
                updated.setTitle(title);
                updated.setOptionA(a);
                updated.setOptionB(b);
                updated.setOptionC(c);
                updated.setOptionD(d);
                updated.setAnswerKey(key);
                updated.setEvaluationId(evalId);

                qb.updateQuestion(updateId, updated);
                break;
            }

            case 4: {
                int removeId;
                cout << "Enter ID of question to remove: ";
                cin >> removeId;
                qb.removeQuestion(removeId);
                break;
            }

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}