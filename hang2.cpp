#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include<unistd.h>
using namespace std;
//checking the player won?
bool isCorrectGuess(const string &secretWord, const vector<bool> &guessedLetters)
{
    for (size_t i = 0; i < secretWord.size(); ++i)
    {
        if (!guessedLetters[i])
        {                 
            return false; // return false. The player has not won the game
        }
    }
    return true; //return true. The player has won the game
}

// figure
void drawHangman(int incorrectGuesses)
{
    if (incorrectGuesses == 0){
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 1)
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 2)
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |        |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 3)
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 4)
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|\\" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else if (incorrectGuesses == 5)
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|\\" << endl;
        cout << " |       / " << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
    else
    {
        cout << "  ________" << endl;
        cout << " |        |" << endl;
        cout << " |        O" << endl;
        cout << " |       /|\\" << endl;
        cout << " |       / \\" << endl;
        cout << " |" << endl;
        cout << "_|________" << endl;
    }
}
int i = 0,j=0;
int main()
{
    vector<string> words;      //to store words 
    string word;
    while (i < 6)
    {
        ifstream inputFile("words.txt"); //opens text files.
        while (getline(inputFile, word))               //for reading the text file
        {
            if (!word.empty() && word[word.size() - 1] == '\r')
            {                                                           // Remove endline "\n" of each word
                word = word.substr(0, word.size() - 1);
            }
            words.push_back(word);                          // adding the word to a vector
        }
        inputFile.close();                               // Closes text file
        
        string secretWord = words[i];   //to access words from the vector.
        vector<bool> guessedLetters(secretWord.size(), false);
        int attemptsLeft = 6; // Initialize the number of attempts given to a user
        cout << "Hangman Game" << endl;

        while (attemptsLeft > 0)
        { // While, the user has remaining attempts
            if (j==0){
                if(i==0){
                    j=1;                                            //TO DISPLAY THE VIDEO IN YT
                    system("start https://youtu.be/TKfdyMxySNc");
                }
                else if(i==1){
                system("start https://youtube.com/shorts/1bk1uIZMVXE");
                j=1;
            }else if(i==2){
                j=1;
                system("start https://youtube.com/shorts/VMrAtWVONUY");
            }else if(i==3){
                j=1;
                system("start https://youtube.com/shorts/FfxCepd6bww");
            }else if(i==4){
                j=1;
                system("start https://youtube.com/shorts/Of85U6--sDo");
            }else if(i==5){
                j=1;
                system("start https://www.youtube.com/shorts/gBs6Do_dWZ4");
            }
            }
            cout << "Secret Word: ";


            //PRINTING THE MISSING WORD AND GUESSED WORD
            for (size_t i = 0; i < secretWord.size(); ++i)
            {
                if (guessedLetters[i])
                {
                    cout << secretWord[i] << " "; // if letter is guessed correctly, display the letter
                }
                else
                {
                    cout << "_ "; //display letters as a series of underscores
                }
            }
            cout << endl;
            char inputChar;
            cout << "Guess a letter: "; // CHARACTER INPUT
            cin >> inputChar;
            bool letterFound = false;
            for (int i = 0; i < secretWord.size(); ++i)   ///to check the char is present in word
            { 
                if (secretWord[i] == inputChar)           // if present returns true
                {
                    guessedLetters[i] = true;
                    letterFound = true;
                }
            }

            if (!letterFound)   //if the letter is not found
            {
                --attemptsLeft;                    //attempts decreases.
                cout << "Incorrect guess. Attempts left: " << attemptsLeft << endl;
            }
            
            
            drawHangman(6 - attemptsLeft);  //to display the figure



            if (isCorrectGuess(secretWord, guessedLetters))  //if the level is completed.
            { 
            i++;
                cout << "Congratulations! You have won the game. The word was:" << secretWord << endl;
                if(i==1){
                system("start https://youtube.com/shorts/_ET5CkcXhC0");
                sleep(17);    //sleep is used to give some delay in the execution 
            }else if(i==2){
                system("start https://youtube.com/shorts/p-aHKE5QzSQ");
                sleep(15);
            }else if(i==3){
                system("start https://youtube.com/shorts/9mxb98tol4U");
                sleep(10);
            }else if(i==4){
                system("start https://youtube.com/shorts/LPgI-y0gsoE");
                sleep(20);
            }else if(i==5){
                system("start https://www.youtube.com/shorts/vQGv11ksQp4");
                sleep(15);
            }else if(i==6){
                system("start https://www.youtube.com/shorts/FQHFmh9Vli4");
                
            }
                j=0;
                break;
            }
        }

        if (attemptsLeft <= 0)
        {                                                             
            cout << "Game Over! The word was: " << secretWord << endl; //if the attempts=0 game ends;
            break; // Game over. The user has lost the game
        }
    }
    return 0;
}
