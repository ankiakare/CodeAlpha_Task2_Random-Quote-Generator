#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Flashcard {
    string question;
 string answer;
};
void show_flashcard(const Flashcard &card, bool showAnswer)
{
    cout << "Question:\n " << card.question << endl;
    if (showAnswer) {
        cout << "Answer: " << card.answer << endl;
    }
}
int main() {
    vector<Flashcard> flashcards = {
        {"What is the capital of France?", "Paris"},
        {"What is 2 + 2?", "4"},
        {"Who wrote '1984'?", "George Orwell"}
    };
    int current = 0;
    bool running = true;
    bool showAnswer = false;
    string cmd;
    while (running) {
        cout << "---------------";
        show_flashcard(flashcards[current], showAnswer);
        cout << "Type: next, prev, show, hide, add, edit, delete, exit";
        cout << "Command: ";
        getline(cin, cmd);

        if (cmd == "next") {
            current = (current + 1) % flashcards.size();
            showAnswer = false;
        } else if (cmd == "prev") {
            current = (current - 1 + flashcards.size()) % flashcards.size();
            showAnswer = false;
        } else if (cmd == "show") {
            showAnswer = true;
        } else if (cmd == "hide") {
            showAnswer = false;
        } else if (cmd == "add") {
            Flashcard newCard;
            cout << "Enter question: ";
            getline(cin, newCard.question);
            cout << "Enter answer: ";
            getline(cin, newCard.answer);
            flashcards.push_back(newCard);
            current = flashcards.size() - 1;
            showAnswer = false;
        } else if (cmd == "edit") {
            cout << "Edit question (current: " << flashcards[current].question << "): ";
            getline(cin, flashcards[current].question);
            cout << "Edit answer (current: " << flashcards[current].answer << "): ";
            getline(cin, flashcards[current].answer);
            showAnswer = false;
        } else if (cmd == "delete") {
            if (flashcards.size() > 1) {
                flashcards.erase(flashcards.begin() + current);
                current = current % flashcards.size();
                showAnswer = false;
            } else {
                cout << "Cannot delete the last flashcard!";
            }
        } else if (cmd == "exit") {
            running = false;
        } else {
            cout << "Invalid command.";
        }
    }
      cout << "Goodbye!";
    return 0;
}
