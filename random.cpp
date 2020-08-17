#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/*TODO:
Add in constraints of game board
Add in constraints of blocking
Add in non-step over opponent function
Repeated entry bug
*/

using namespace std;

class point{
public:
    char d;
    int steps = 20;
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

//Player1's turn
int gridchange(char Direction, int StepsLeft, string piece){
    
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
    if(y == 1 && x==3)
        table[y][x] = "__"; //Temporary to be removed later on
    else
        table[y][x] = "[]";

    //Change direction
    switch(Direction){
        case 'w':
            if(table[y - 1][x] == "B "){
                table[y][x] = piece;
                break;
            }
            table[y - 1][x] = piece;
            break;
        case 's':
            if(table[y + 1][x] == "B "){
                table[y][x] = piece;
                break;
            }
            table[y + 1][x] = piece;
            break;
        case 'a':
            if(table[y][x-1] == "B "){
                table[y][x] = piece;
                break;
            }
            table[y][x - 1] = piece;
            break;
        case 'd':
            if(table[y][x+1] == "B "){
                table[y][x] = piece;
                break;
            }
            table[y][x + 1] = piece;
            break;
    }

    cout << endl;

    //Print the updated grid
    grid();

    return (y == 1 && x==3)? 1:0;
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
    while(player1.steps > 0|| player2.steps > 0){
        
        //Player 1's turn
        cout<< endl << "Player1, do you want to block[enter 1] or move [enter 2]?" << endl;
        cin >> player1.change;
        if(player1.change == 1){
            block();
        }
        else if(player1.change == 2){
            cin >> player1.d;
            cout << endl;
            gridchange(player1.d,player1.steps,player1.emblem);
        }
        
        //Player 2's turn
        cout<< endl << "Player2, do you want to block[enter 1] or move [enter 2]?" << endl;
        cin >> player2.change;
        if(player2.change == 1){
            block();
        }
        else if(player2.change == 2){
            cin >> player2.d;
            cout << endl;
            gridchange(player2.d,player2.steps,player2.emblem);
        }
    }
}