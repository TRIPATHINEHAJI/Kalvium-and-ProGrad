#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Enum to represent the gestures in the game
enum Gesture
{
    Rock,
    Paper,
    Scissors
};

// Function to get the gesture from user input
Gesture getGesture()
{
    int input;
    cout << "Enter your gesture (0 for Rock, 1 for Paper, 2 for Scissors): ";
    cin >> input;

    return (Gesture)input;
}

// Function to determine the result of a round given the player gestures
int determineResult(Gesture player1, Gesture player2)
{
    if (player1 == Rock)
    {
        if (player2 == Scissors)
            return 1;
        else if (player2 == Paper)
            return 2;
        else
            return 0;
    }
    else if (player1 == Paper)
    {
        if (player2 == Rock)
            return 1;
        else if (player2 == Scissors)
            return 2;
        else
            return 0;
    }
    else
    {
        if (player2 == Paper)
            return 1;
        else if (player2 == Rock)
            return 2;
        else
            return 0;
    }
}

int main()
{
    // Variables to store player names and scores
    string player1Name, player2Name;
    int player1Score = 0, player2Score = 0;
    int highestScore = 0;
    string playerName;
    // Read the highest score from file
    ifstream file("highscore.txt");
    if (file.good())
    {
        file >> playerName >> highestScore;
        cout << playerName << " " << highestScore << "\n";
    }
    file.close();

    // Get the names of the players
    cout << "Enter player 1 name: ";
    cin >> player1Name;
    cout << "Enter player 2 name: ";
    cin >> player2Name;

    while (true)
    {
        // Get the gestures from the players
        Gesture player1Gesture = getGesture();
        Gesture player2Gesture = getGesture();

        // Determine the result of the round
        int result = determineResult(player1Gesture, player2Gesture);
        if (result == 1)
        {
            cout << player1Name << " wins!" << endl;
            player1Score++;
        }
        else if (result == 2)
        {
            cout << player2Name << " wins!" << endl;
            player2Score++;
        }
        else
        {
            cout << "Draw." << endl;
        }

        cout << player1Name << ": " << player1Score << " points" << endl;
        cout << player2Name << ": " << player2Score << " points" << endl;

        // Update the highest score if necessary
        // Update the highest score if necessary
        int currentScore = max(player1Score, player2Score);
        if (currentScore > highestScore)
        {
            highestScore = currentScore;
            if (currentScore == player1Score)
                playerName = player1Name;
            else
                playerName = player2Name;
            // Write the updated highest score to file
            ofstream file("highscore.txt");
            if (file.good())
            {
                file << playerName << " " << highestScore << endl;
            }
            file.close();
        }
        // Ask if the players want to continue
        cout << "Do you want to play another round? (yes/no): ";
        string response;
        cin >> response;
        if (response != "yes")
        {
            break;
        }
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}