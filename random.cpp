#include <iostream>
#include <vector>
#include <string>

using namespace std;

class point{
public:
    char d;
    int x;
    int y;
    int steps = 20;
};

string table [5][7] = {
                            {"[]","[]","[]","[]","[]","[]","[]"},
                            {"[]","[]","[]","__","[]","[]","[]"},
                            {"[]","[]","[]","[]","[]","[]","[]"},
                            {"[]","[]","[]","[]","[]","[]","[]"},
                            {" x","[]","[]","[]","[]","[]","o "},
                        };

void grid(){
    for(int i = 0; i < 5; ++i){
        for(int z = 0; z < 7; ++z){
            cout << table[i][z];
        }
        cout << endl;
    }
}

int gridchange1(char Direction1, int StepsLeft){
    
    //Player1 inheritance
    point player1;

    //Declare position of player 1
    player1.y;
    player1.x;

    //Find where Player1 is on the grid
    for(int i = 0; i < 5; ++i){
        for(int z = 0; z < 7; ++z){
            if(table[i][z] == " x"){
                player1.y = i;
                player1.x = z;
            }
        }
    }
    
    //Replacement after moving forward
    if(player1.y == 1 && player1.x==3)
        table[player1.y][player1.x] = "__";
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
    for(int i = 0; i < 5; ++i){
        for(int z = 0; z < 7; ++z){
            cout << table[i][z];
        }
        cout << endl;
    }

    return(player1.x == 3 && player1.y == 1)? 1:0;
}

int gridchange2(char Direction2, int StepsLeft){
    
    //Player2 inheritance
    point player2;

    //Declare position of player 2
    player2.y;
    player2.x;

    //Find where Player2 is on the grid
    for(int i = 0; i < 5; ++i){
        for(int z = 0; z < 7; ++z){
            if(table[i][z] == "o "){
                player2.y = i;
                player2.x = z;
            }
        }
    }
    
    //Replacement after moving forward
    if(player2.y == 1 && player2.x==3)
        table[player2.y][player2.x] = "__";
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
    for(int i = 0; i < 5; ++i){
        for(int z = 0; z < 7; ++z){
            cout << table[i][z];
        }
        cout << endl;
    }

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
        cin >> player1.d;
        cout << endl;
        gridchange1(player1.d,player1.steps);
        cin >> player2.d;
        cout << endl;
        gridchange2(player2.d,player2.steps);
    }
    
}