#include <bits/stdc++.h>
using namespace std;

string playerMove()
{

    string playerChoice;
    cout << "Enter Your Choice : ";
    cin >> playerChoice;

    return playerChoice;
}

string computerMove()
{

    srand(time(0));

    string computerChoice;

    int random = 1 + (rand() % 10);

    if (random >= 1 && random <= 3)
    {
        computerChoice = "rock";
    }

    else if (random >= 4 && random <= 7)
    {
        computerChoice = "paper";
    }

    else
    {
        computerChoice = "scissors";
    }

    return computerChoice;
}

void playGame()
{

    string playerChoice = playerMove();
    string computerChoice = computerMove();

    if (playerChoice == computerChoice)
    {
        cout << "It's a Tie." << endl;
    }

    else if ((playerChoice == "paper" && computerChoice == "rock") ||

             (playerChoice == "rock" && computerChoice == "scissors") ||

             (playerChoice == "scissors" && computerChoice == "paper"))
    {

        cout << "You Won!." << endl;
    }

    else
    {
      cout << "Computer Won" << endl;
    }
}

int main()
{
    cout << "        ========================================\n";
    cout << "             Welcome to Rock Paper Scissors! \n";
    cout << "        ========================================\n\n";
    cout << "Instructions:\n";
    cout << "- Type 'rock', 'paper', or 'scissors' to play.\n";
    cout << "- The computer will make a random choice.\n";
    cout << "- Rock beats scissors, scissors beat paper, paper beats rock.\n\n";
    cout << "Let's play!\n\n";

    playGame();
    return 0;
}