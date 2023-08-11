// PROGRMMERS                          REG NUMBERS

// RUKUNDO OLIVIER.                     222014827
// UMUHOZA KAMANA NADINE.               222013252
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    srand(time(0)); // Seed the random number generator

    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew"};
    string secretWord = words[rand() % words.size()]; // Randomly select a word
    int numGuesses = 6;
    int warnings = 3;
    string guessedLetters = "";

    cout << "Welcome to Hangman!\n";
    cout << "Guess the word: ";
    for (size_t i = 0; i < secretWord.length(); ++i) {
        cout << "-";
    }
    cout << endl;

    while (numGuesses > 0) {
        cout << "Guesses remaining: " << numGuesses << "\n";
        cout << "Warnings remaining: " << warnings << "\n";
        cout << "Letters not guessed yet: ";
        for (char c = 'a'; c <= 'z'; ++c) {
            if (guessedLetters.find(c) == string::npos) {
                cout << c << " ";
            }
        }
        cout << "\nGuess a letter: ";
        
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (!isalpha(guess)) {
            cout << "Invalid input. Please enter a letter.\n";
            if (warnings > 0) {
                --warnings;
            } else {
                --numGuesses;
            }
            continue;
        }

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter.\n";
            if (warnings > 0) {
                --warnings;
            } else {
                --numGuesses;
            }
            continue;
        }

        guessedLetters += guess;

        if (secretWord.find(guess) != string::npos) {
            cout << "Correct guess!\n";
        } else {
            cout << "Incorrect guess!\n";
            if (isVowel(guess)) {
                numGuesses -= 2;
            } else {
                --numGuesses;
            }
        }

        // Display the partially guessed word
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (guessedLetters.find(secretWord[i]) != string::npos) {
                cout << secretWord[i];
            } else {
                cout << "-";
            }
        }
        cout << endl;

        // Check if the player won
        if (secretWord == guessedLetters) {
            int score = numGuesses * set<char>(guessedLetters.begin(), guessedLetters.end()).size();
            cout << "Congratulations! You guessed the word. Your score is: " << score << "\n";
            break;
        }
    }

    if (numGuesses == 0) {
        cout << "Sorry, you've run out of guesses. The word was: " << secretWord << "\n";
    }

    return 0;
}
