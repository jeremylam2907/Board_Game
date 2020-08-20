#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/*TODO:
Out of bound grid re-enter
*/

using namespace std;

class point{
public:
    char d;
    int steps = 0;
    int change;
    string emblem;
};

//The game table
vector < vector <string> > table{
                            {"5","[]","[]","[]","[]","[]","[]","[]"},
                            {"4","[]","[]","[]","__","[]","[]","[]"},
                            {"3","[]","[]","[]","[]","[]","[]","[]"},
                            {"2","[]","[]","[]","[]","[]","[]","[]"},
                            {"1"," x","[]","[]","[]","[]","[]","o "},
                            {"  ","A"," B"," C"," D"," E"," F"," G"},
                        };

//Funtion to print out the board
void grid(){
    for(int i = 0; i < table.size(); ++i){
        for(int z = 0; z < table[i].size(); ++z){
            cout << table[i][z];
        }
        cout << endl;
    }
}

// Create a function for blocking
void block(){
    cout << "Enter location where to block (Column then Row no space)";
    string BlockLocation;
    cin >> BlockLocation;
    transform(BlockLocation.begin(), BlockLocation.end(), BlockLocation.begin(), ::toupper);
    table[53-int(BlockLocation[1])][int(BlockLocation[0])-64]="B ";
    grid();
}

//Player's move
int PlayerMove(char Direction, int StepsLeft, string piece){
    
    int x;
    int y;
    
    //Find where Player1 is on the grid
    for(int i = 0; i < table.size(); ++i){
        for(int z = 0; z < table[i].size(); ++z){
            if(table[i][z] == piece){
                y = i;
                x = z;
            }
        }
    }
    
    //Replacement after moving forward
        table[y][x] = "[]";

    //Change direction
    switch(Direction){
        case 'w':
            if(table[y - 1][x] == "B "||y  == 0){    //Being blocked
                table[y][x] = piece;
                break;
            }
            table[y - 1][x] = piece;        //Move
            break;
        case 's':
            if(table[y + 1][x] == "B "||y + 1 == 5){    //Being blocked
                table[y][x] = piece;
                break;
            }
            table[y + 1][x] = piece;        //Move
            break;
        case 'a':
            if(table[y][x - 1] == "B "||x == 1){    //Being blocked
                table[y][x] = piece;
                break;
            }
            table[y][x - 1] = piece;        //Move
            break;
        case 'd':
            if(table[y][x + 1] == "B "||x == 7){    //Being blocked
                table[y][x] = piece;
                break;
            }
            table[y][x + 1] = piece;        //Move
            break;
    }
    cout << endl;

    //Print the updated grid
    grid();

    return (table[1][4] == piece)? 1:0;
}


int main(){
    //Player1 declaration
    point player1;
    player1.emblem = " x";

    //Player2 declaration
    point player2;
    player2.emblem = "o ";
    
    //Call for grid display
    grid();

    //Game loop
    while(player1.steps < 20 || player2.steps < 20){
        
        //Player 1's turn
        cout<< endl << "Player1, do you want to block[enter 1] or move [enter 2]?" << endl;
        cin >> player1.change;
        if(player1.change == 1){        //Blocking opponent
            block();
            ++++player1.steps;
        }
        else if(player1.change == 2){   //Move piece
            cin >> player1.d;
            cout << endl;
            if(PlayerMove(player1.d,player1.steps,player1.emblem) == 1){
                cout << endl << "Player 1 wins";
                return 0;
            }
            ++player1.steps;
        }
        
        //Player 2's turn
        cout<< endl << "Player2, do you want to block[enter 1] or move [enter 2]?" << endl;
        cin >> player2.change;
        if(player2.change == 1){        //Blocking opponent
            block();
            ++++player2.steps;
        }
        else if(player2.change == 2){   //Move piece
            cin >> player2.d;
            cout << endl;
            if(PlayerMove(player2.d,player2.steps,player2.emblem) == 1){
                cout << endl << "Player 2 wins";
                return 0;
            }
            ++player2.steps;
        }
    }
}