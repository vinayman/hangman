#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>

#include <boost/algorithm/string.hpp>

#define LOG_VAR(var)  #var << "=" << var << " "

std::string logHangman(int& attempt)
{
    std::string append1, append2, append3, append4, append5, append6, attemptString;

    switch (attempt)
    {
        case 1:
            append6 = "      _     \n";
            break;
        case 2:
            append6 = "     __     \n";
            break;
        case 3:
            append6 = "    ___     \n";
            break;
        case 4:
            append6 = "   ____     \n";
            break;
        case 5:
            append6 = "  |____     \n";
            break;
        case 6:
            append6 = " _|____     \n";
            break;
        case 7:
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        case 8:
        {
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 9:
        {
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 10:
        {
            append2 = "  |         \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 11:
        {
            append1 = "  _         \n";
            append2 = "  |         \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 12:
        {
            append1 = "  __        \n";
            append2 = "  |         \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 13:
        {
            append1 = "  ___       \n";
            append2 = "  |         \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 14:
        {
            append1 = "  ____      \n";
            append2 = "  |         \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 15:
        {
            append1 = "  _____     \n";
            append2 = "  |         \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 16:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |         \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 17:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |    0    \n";
            append4 = "  |         \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 18:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |    0    \n";
            append4 = "  |    |    \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 19:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |    0    \n";
            append4 = "  |   -|    \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 20:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |    0    \n";
            append4 = "  |   -|-   \n";
            append5 = "  |         \n";
            append6 = " _|____     \n";
            break;
        }
        case 21:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |    0    \n";
            append4 = "  |   -|-   \n";
            append5 = "  |   /     \n";
            append6 = " _|____     \n";
            break;
        }
        case 22:
        {
            append1 = "  _____     \n";
            append2 = "  |    |    \n";
            append3 = "  |    0    \n";
            append4 = "  |   -|-   \n";
            append5 = "  |   / \\  \n";
            append6 = " _|____     \n";
            break;
        }
    };

    attemptString.append(append1);
    attemptString.append(append2);
    attemptString.append(append3);
    attemptString.append(append4);
    attemptString.append(append5);
    attemptString.append(append6);

    return attemptString;
}

std::string logFailedLetters(const std::vector<std::string>& failedLetters)
{
    std::stringstream ss;
    std::vector<std::string>::const_iterator it;
    for (it = failedLetters.begin(); it != failedLetters.end(); it++)
    {
        ss << *it << ",";
    }
    return ss.str();
}

int main()
{
    std::cout << "Welcome to Hangman! Please enter some words to randomly play Hangman with!" << std::endl;
    std::vector<std::string> hangmanWords;
    while (hangmanWords.size() < 3)
    {
        std::string elem;
        std::getline(std::cin, elem);
        hangmanWords.push_back(elem);
    }
    std::cout << "  _____    \n"  <<
                 "  |    |   \n"  <<
                 "  |    0   \n"  <<
                 "  |   -|-  \n"  <<
                 "  |   / \\ \n"  <<
                 " _|____    \n"  << std::endl;

    std::cout << "Randomly selecting the word to play with!" << std::endl;
    std::string chosenWord = hangmanWords.at(rand() % 9 + 0);
    boost::to_upper(chosenWord);

    std::string coveredWord(chosenWord.length(), '_');

    std::cout << "Start guessing letters to match!" << std::endl;

    int attempts = 0;
    std::vector<std::string> failedLetters;

    while (attempts < 22)
    {
        std::string guess;
        std::getline(std::cin, guess);
        boost::to_upper(guess);
        if (guess.length() > 1)
        {
            std::cout << "Guess length is greater than 1 - attempting a full string match!" << std::endl;
            if (strcmp(chosenWord.c_str(), guess.c_str()) == 0)
            {
                std::cout << "You were successful!" << std::endl;
                return false;
            }
            else
            {
                std::cout << "Guess was unsuccessful! Lose another life" << std::endl;
                attempts++;
                std::cout << logHangman(attempts);
            }
        }
        else if (chosenWord.find(guess) != std::string::npos)
        {
            std::cout << "Successful guess!" << std::endl;
            std::vector<size_t> positions;
            std::vector<size_t>::iterator positionIter;
            size_t pos = chosenWord.find(guess);
            while (pos != std::string::npos)
            {
                positions.push_back(pos);
                pos = chosenWord.find(guess, pos+1);
            }
            for (positionIter = positions.begin(); positionIter != positions.end(); positionIter++)
            {
                char * insertChar = new char[guess.length() + 1];
                strcpy(insertChar, guess.c_str());
                coveredWord[*positionIter] = *insertChar;
            }
            std::cout << LOG_VAR(coveredWord) << std::endl;
        }
        else
        {
            std::cout << "Unsuccessful guess! Removing from lifelines!" << std::endl;
            attempts++;
            std::cout << logHangman(attempts);
            failedLetters.push_back(guess);
            std::cout << logFailedLetters(failedLetters) << std::endl;
        }
    }
}
