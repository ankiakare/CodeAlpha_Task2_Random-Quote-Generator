#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Quote {
    string text;
    string author;
};

int main() {
    vector<Quote> quotes = {
        {"The only way to do great work is to love what you do.", "Steve Jobs"},
        {"Life is what happens when you're busy making other plans.", "John Lennon"},
        {"Simplicity is the ultimate sophistication.", "Leonardo da Vinci"},
        {"Success is not in what you have, but who you are.", "Bo Bennett"},
        {"The best revenge is massive success.", "Frank Sinatra"}
    };

    srand(static_cast<unsigned int>(time(nullptr)));

    bool running = true;
    string cmd;
    while (running) {
        int idx = rand() % quotes.size();
        cout << "---------------------------";
        cout << """ << quotes[idx].text << " ; 
        cout << "— " << quotes[idx].author << " ";
        cout << "Type 'new' for a new quote or 'exit' to quit.";
        cout << "Command: ";
        getline(cin, cmd);

        if (cmd == "exit") {
            running = false;
        }
    }
    cout << "Goodbye!";
    return 0;
}
