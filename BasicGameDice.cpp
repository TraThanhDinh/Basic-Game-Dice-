#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

int random_int(int a, int b);
int get_positive_int(string prompt);
void print_report(int total_games,
                  int player_win_count,
                  double player_winnings,
                  int house_win_count,
                  double house_winnings);

int main() {
     // constant definitions
    const   string LINE = "----------------------------------------";

    // variable declarations
    int     exit_status = 0;
    int     bet;
    char    response = 'y';

    // seed the random number generator
    // srand(static_cast<unsigned>(time(nullptr)));
    srand(42);

    // game variables
    int     total_games      = 0;   //total game play
    int     player_win_count = 0;   //the number of player win in the game
    double  player_winnings  = 0.0; //the total player win the game
    int     house_win_count  = 0;   //the number of house win in the game
    double  house_winnings   = 0.0; //the total house win the game

    while (response == 'y' || response == 'Y') {
     // check if bet is valid
        bet = get_positive_int("Enter a positive integer dollar amount: ");
        if (bet == -1) {
            cout << "You have exceeded the maximum number of attempts." << endl;
        }
            //simulate the game
            int dice1 = rand() % 6 + 1;
            int dice2 = rand() % 6 + 1;
            int sum = dice1 + dice2;

            cout << "Roll is [" << dice1 << "," << dice2 << "]" << endl;

            //update game variables
            total_games++;

            //If the total is 7 or 11, the player wins
            if (sum == 7 || sum == 11)
            {
                //player wins double the Bet!
                player_win_count++;
                player_winnings += bet * 2;
                house_winnings -= bet;
                cout << "Player Wins Double the Bet!" << endl;
            }
            //if the total is a pair of 2s, 4s, or 5s, the player wins
            else if (dice1 == dice2 && (sum == 4 || sum == 8 || sum == 10))
            {
                //increment the number of player wins
                player_win_count++;
                //increased by 50% and added to the variable tracking player.
                player_winnings += bet * 1.5;
                cout << "Player Wins 1.5 times the bet!" << endl;
            }
            //if the total is a pair of 1s, 3s, or 6s, the house wins
            else if (dice1 == dice2 && (sum == 2 || sum == 6 || sum ==  12))
             {

                //house wins
                house_win_count++;
                house_winnings += bet;
                cout <<  "House Wins!" << '\n';
            }
            //the total rolled by the computer is 3, 5, or 9, the house wins
            else if (sum == 3 || sum == 5 || sum == 9) {
                //house wins
                house_win_count++;
                house_winnings += bet;
                cout <<  "House Wins!" << '\n';
            }
            else
            {
                cout << "No winner for this roll." << endl;;
            }

        //print game report
        print_report(total_games,
                     player_win_count,
                     player_winnings,
                     house_win_count,
                     house_winnings);


    // ask player to play again
    cout << "Do you want to play again Y/N? ";
    cin  >> response;
    }


    cout << "Game over. Thanks for playing!" << endl;

    return exit_status;
}

int random_int(int a, int b) {

    // Set the seed for the random number generator based on the current time
    //srand(static_cast<unsigned>(time(nullptr)));
    srand(42);

    // Swap a and b if a is greater than b
     if (a > b) {
         int temp = a;
         a = b;
         b = temp;
    }

    // Generate a random integer between a and b (inclusive)
    int random_num = rand() % (b - a + 1) + 1;

    // Return the random integer
    return random_num;
}

int get_positive_int(string prompt) {

    int num_attempts = 3;
    int n;
    for (int i = 1; i <= num_attempts; i++)
        {
        cout << prompt;
        if (cin >> n && n > 0)
            {
            return n;
            }
            cin.clear();

        }
    return -1;
}

void print_report(int total_games,
                  int player_win_count,
                  double player_winnings,
                  int house_win_count,
                  double house_winnings) {

    cout << '\n' << endl;
    cout << "Game Start" << endl;
    cout << "----------------------------------------" << endl;
    cout << right << setw(31) << "Total Games:"
         << setw(9)
         << total_games
         << endl;
    cout << right << setw(31) << "Number of times the player won:"
         << fixed << setprecision(2)
         << setw(9)
         << player_win_count
         << endl;
    cout << right << setw(31) << "Player Winnings:"
         << setw(9)
         << player_winnings
         << endl;
    cout << right << setw(31) << "Number of times the house won:"
         << setw(9)
         << fixed << setprecision(2)
         << house_win_count
         << endl;
    cout << right << setw(31) << "House Winnings:"
         << setw(9)
         << house_winnings
         << endl;
}
