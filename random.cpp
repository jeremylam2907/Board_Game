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
    int x;
    int y;
    int steps = 20;
    int change;
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
int gridchange1(char Direction1, int StepsLeft){
    
    //Player1 inheritance
    point player1;

    //Declare position of player 1
    player1.y;
    player1.x;
    
    //Find where Player1 is on the grid
    for(int i = 0; i < table.size(); ++i){
        for(int z = 0; z < table[i].size(); ++z){
            if(table[i][z] == " x"){
                player1.y = i;
                player1.x = z;
            }
        }
    }
    
    //Replacement after moving forward
    if(player1.y == 1 && player1.x==3)
        table[player1.y][player1.x] = "__"; //Temporary to be removed later on
    else
        table[player1.y][player1.x] = "[]";

    //Change direction
    switch(Direction1){
        case 'w':
            table[player1.y - 1][player1.x] = " x";
            break;
        case 's':
            table[player1.y + 1][player1.x] = " x";
            break;
        case 'a':
            table[player1.y][player1.x - 1] = " x";
            break;
        case 'd':
            table[player1.y][player1.x + 1] = " x";
            break;
    }

    cout << endl;

    //Print the updated grid
    grid();

    return(player1.x == 3 && player1.y == 1)? 1:0;
}

//Player2's turn
int gridchange2(char Direction2, int StepsLeft){
    
    //Player2 inheritance
    point player2;

    //Declare position of player 2
    player2.y;
    player2.x;

    //Find where Player2 is on the grid
    for(int i = 0; i < table.size(); ++i){
        for(int z = 0; z < table[i].size(); ++z){
            if(table[i][z] == "o "){
                player2.y = i;
                player2.x = z;
            }
        }
    }
    
    //Replacement after moving forward
    if(player2.y == 1 && player2.x==3)
        table[player2.y][player2.x] = "__"; //Temporary to be removed later on
    else
        table[player2.y][player2.x] = "[]";

    //Change position based on input
    switch(Direction2){
        case 'w':
            table[player2.y - 1][player2.x] = "o ";
            break;
        case 's':
            table[player2.y + 1][player2.x] = "o ";
            break;
        case 'a':
            table[player2.y][player2.x - 1] = "o ";
            break;
        case 'd':
            table[player2.y][player2.x + 1] = "o ";
            break;
    }

    cout << endl;

    //Print out the updated grid
    grid();

    return(player2.x == 3 && player2.y == 1)? 1:0;
}

int main(){
    //Player1 declaration
    point player1;
    player1.d;
    player1.steps;

    //Player2 declaration
    point player2;
    player2.d;
    player2.steps;
    
    //Call for grid display
    grid();

    //Game loop
    while(player1.steps > 0|| player2.steps > 0){
        
        //Player 1's turn
        cout<< endl << "Do you want to block[enter 1] or move [enter 2]?" << endl;
        cin >> player1.change;
        if(player1.change == 1){
            block();
        }
        else if(player1.change == 2){
            cin >> player1.d;
            cout << endl;
            gridchange1(player1.d,player1.steps);
        }
        
        //Player 2's turn
        cout<< endl << "Do you want to block[enter 1] or move [enter 2]?" << endl;
        cin >> player2.change;
        if(player2.change == 1){
            block();
        }
        else if(player2.change == 2){
            cin >> player2.d;
            cout << endl;
            gridchange1(player2.d,player2.steps);
        }
    }
}