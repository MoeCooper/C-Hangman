#include <iostream>
#include <cstring>
#include <limits>

const char* INPUT_ERROR_STRING = "Input Error! Please try again.";

void playGame();
bool wantToPlayAgain();
int getSecretPhrase(char secretPhrase[], int maxLength); 

int main() {
    do{
        playGame();
    } while(wantToPlayAgain());

    
}

void playGame(){
    const int MAX_LENGTH_OF_SECRET_PHRASE = 255;
    const int MAX_NUMBER_OF_GUESSES = 6;

    // reads from player
    char secretPhrase[MAX_LENGTH_OF_SECRET_PHRASE];

    // char pointer to hidden phrase, this will be from heap memory
    char* hiddenPhrase = nullptr;
    int numberOfGuessLeft = MAX_NUMBER_OF_GUESSES;

    getSecretPhrase(secretPhrase, MAX_LENGTH_OF_SECRET_PHRASE);
}

// user inputs secret phrase
int getSecretPhrase(char secretPhrase[], int maxLength){
    bool failure;

    do{
        failure = false;

        std::cout << "Please enter the secret phrase: " << std::endl;
        std::cin.get(secretPhrase, maxLength);

        // checks for input, or if input fails
        if(!std::cin){
            // clears the internal state of the stream. sets internal state to goodbit (no errors)
            std::cin.clear();

            // removes extra input from the stream that we don't want with until max int length, ingore new line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << INPUT_ERROR_STRING;
            failure = true;
        } else {
            // checks to see if input is zero
            if(strlen(secretPhrase) == 0){
                std::cout << "Please enter a word longer than 0 characters!";
                failure = true;
            }
        }
    } while(failure);
    
    return strlen(secretPhrase);
}