#include <bits/stdc++.h>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tied = false;
string n1 = "";
string n2 = "";

void functionOne() {
    cout << "   |     |  \n";
    cout << " " << space[0][0] << " | " << space[0][1] << "   | " << space[0][2] << "  \n";
    cout << "___|_____|___\n";
    cout << "   |     |  \n";
    cout << " " << space[1][0] << " | " << space[1][1] << "   | " << space[1][2] << "  \n";
    cout << "___|_____|___\n";
    cout << "   |     |  \n";
    cout << " " << space[2][0] << " | " << space[2][1] << "   | " << space[2][2] << "  \n";
    cout << "   |     |  \n";
}

void functionTwo() {
    int digit;
    
    if(token == 'x'){
        cout << n1 << " please enter: ";
        cin >> digit;
    } else {
        cout << n2 << " please enter: ";
        cin >> digit;
    }

    // Convert digit to corresponding row and column
    if(digit == 1){ row = 0; column = 0; }
    else if(digit == 2){ row = 0; column = 1; }
    else if(digit == 3){ row = 0; column = 2; }
    else if(digit == 4){ row = 1; column = 0; }
    else if(digit == 5){ row = 1; column = 1; }
    else if(digit == 6){ row = 1; column = 2; }
    else if(digit == 7){ row = 2; column = 0; }
    else if(digit == 8){ row = 2; column = 1; }
    else if(digit == 9){ row = 2; column = 2; }
    else {
        cout << "Invalid input! Please enter a number between 1 and 9.\n";
        functionTwo();
        return;
    }

    if(space[row][column] != 'x' && space[row][column] != '0'){
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "There is no empty space! Try again.\n";
        functionTwo();
    }
    functionOne();
}

bool functionThree() {
    // Check rows and columns for a win
    for(int i = 0; i < 3; i++) {
        if((space[i][0] == space[i][1] && space[i][1] == space[i][2]) || 
           (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }

    // Check diagonals for a win
    if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
       (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    // Check for a draw
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'x' && space[i][j] != '0') {
                return false; // If any space is still a number, the game is not over
            }
        }
    }
    
    tied = true;
    return true; // If no win and no spaces left, it's a draw
}

int main() {
    cout << "Enter the name of the first player:\n";
    getline(cin, n1);
    cout << "Enter the name of the second player:\n";
    getline(cin, n2);
    
    cout << n1 << " is player 1 and will play first.\n";
    cout << n2 << " is player 2 and will play second.\n";
    
    while(!functionThree()) {
        functionOne();
        functionTwo();
    }

    if(tied) {
        cout << "It's a draw!" << endl;
    } else if(token == 'x') {
        cout << n2 << " Wins!!!" << endl;
    } else {
        cout << n1 << " Wins!!!" << endl;
    }
}
