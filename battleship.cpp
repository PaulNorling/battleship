//Import the inbuild libraries in CPP
#include <iostream>
#include <stdlib.h>
using namespace std;

//variables
bool gameOn = true;
char rowCharacter;
char fleet[10][10];
int columnInteger;
int row;
int column;
int turns;
int hits;

//fleet hit points
int destroyerHits;
int carrierHits;
int patrolboatHits;
int battleshipHits;
int submarineHits;

//Array of the board
char board[10][10]={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},};

//random number for choosing fleet position
void randomFleet() {
     // Providing a seed value
	srand((unsigned) time(NULL));

	// Get a random number
	int random = rand() % 3;
    //fleet position 1
    if(random == 0){
        fleet[0][0]=' ',fleet[0][1]='D',fleet[0][2]='D',fleet[0][3]='D',fleet[0][4]=' ',fleet[0][5]=' ',fleet[0][6]=' ',fleet[0][7]=' ',fleet[0][8]=' ',fleet[0][9]=' ',
        fleet[1][0]=' ',fleet[1][1]=' ',fleet[1][2]=' ',fleet[1][3]=' ',fleet[1][4]=' ',fleet[1][5]=' ',fleet[1][6]=' ',fleet[1][7]=' ',fleet[1][8]=' ',fleet[1][9]=' ',
        fleet[2][0]=' ',fleet[2][1]='C',fleet[2][2]='C',fleet[2][3]='C',fleet[2][4]='C',fleet[2][5]='C',fleet[2][6]=' ',fleet[2][7]='S',fleet[2][8]='S',fleet[2][9]='S',
        fleet[3][0]=' ',fleet[3][1]=' ',fleet[3][2]=' ',fleet[3][3]='B',fleet[3][4]=' ',fleet[3][5]=' ',fleet[3][6]=' ',fleet[3][7]=' ',fleet[3][8]=' ',fleet[3][9]=' ',
        fleet[4][0]=' ',fleet[4][1]=' ',fleet[4][2]=' ',fleet[4][3]='B',fleet[4][4]=' ',fleet[4][5]=' ',fleet[4][6]=' ',fleet[4][7]=' ',fleet[4][8]=' ',fleet[4][9]=' ',
        fleet[5][0]=' ',fleet[5][1]=' ',fleet[5][2]=' ',fleet[5][3]='B',fleet[5][4]=' ',fleet[5][5]=' ',fleet[5][6]=' ',fleet[5][7]='P',fleet[5][8]=' ',fleet[5][9]=' ',
        fleet[6][0]=' ',fleet[6][1]=' ',fleet[6][2]=' ',fleet[6][3]='B',fleet[6][4]=' ',fleet[6][5]=' ',fleet[6][6]=' ',fleet[6][7]='P',fleet[6][8]=' ',fleet[6][9]=' ',
        fleet[7][0]=' ',fleet[7][1]=' ',fleet[7][2]=' ',fleet[7][3]=' ',fleet[7][4]=' ',fleet[7][5]=' ',fleet[7][6]=' ',fleet[7][7]=' ',fleet[7][8]=' ',fleet[7][9]=' ',
        fleet[8][0]=' ',fleet[8][1]=' ',fleet[8][2]=' ',fleet[8][3]=' ',fleet[8][4]=' ',fleet[8][5]=' ',fleet[8][6]=' ',fleet[8][7]=' ',fleet[8][8]=' ',fleet[8][9]=' ',
        fleet[9][0]=' ',fleet[9][1]=' ',fleet[9][2]=' ',fleet[9][3]=' ',fleet[9][4]=' ',fleet[9][5]=' ',fleet[9][6]=' ',fleet[9][7]=' ',fleet[9][8]=' ',fleet[9][9]=' ';
    }
    //fleet position 2
    else if(random == 1){
        fleet[0][0]=' ',fleet[0][1]='D',fleet[0][2]='D',fleet[0][3]='D',fleet[0][4]=' ',fleet[0][5]=' ',fleet[0][6]=' ',fleet[0][7]=' ',fleet[0][8]='B',fleet[0][9]=' ',
        fleet[1][0]=' ',fleet[1][1]=' ',fleet[1][2]=' ',fleet[1][3]=' ',fleet[1][4]=' ',fleet[1][5]=' ',fleet[1][6]=' ',fleet[1][7]=' ',fleet[1][8]='B',fleet[1][9]=' ',
        fleet[2][0]=' ',fleet[2][1]=' ',fleet[2][2]='C',fleet[2][3]=' ',fleet[2][4]='S',fleet[2][5]=' ',fleet[2][6]=' ',fleet[2][7]=' ',fleet[2][8]='B',fleet[2][9]=' ',
        fleet[3][0]=' ',fleet[3][1]=' ',fleet[3][2]='C',fleet[3][3]=' ',fleet[3][4]='S',fleet[3][5]=' ',fleet[3][6]=' ',fleet[3][7]=' ',fleet[3][8]='B',fleet[3][9]=' ',
        fleet[4][0]=' ',fleet[4][1]=' ',fleet[4][2]='C',fleet[4][3]=' ',fleet[4][4]='S',fleet[4][5]=' ',fleet[4][6]=' ',fleet[4][7]=' ',fleet[4][8]=' ',fleet[4][9]=' ',
        fleet[5][0]=' ',fleet[5][1]=' ',fleet[5][2]='C',fleet[5][3]=' ',fleet[5][4]=' ',fleet[5][5]=' ',fleet[5][6]='P',fleet[5][7]='P',fleet[5][8]=' ',fleet[5][9]=' ',
        fleet[6][0]=' ',fleet[6][1]=' ',fleet[6][2]='C',fleet[6][3]=' ',fleet[6][4]=' ',fleet[6][5]=' ',fleet[6][6]=' ',fleet[6][7]=' ',fleet[6][8]=' ',fleet[6][9]=' ',
        fleet[7][0]=' ',fleet[7][1]=' ',fleet[7][2]=' ',fleet[7][3]=' ',fleet[7][4]=' ',fleet[7][5]=' ',fleet[7][6]=' ',fleet[7][7]=' ',fleet[7][8]=' ',fleet[7][9]=' ',
        fleet[8][0]=' ',fleet[8][1]=' ',fleet[8][2]=' ',fleet[8][3]=' ',fleet[8][4]=' ',fleet[8][5]=' ',fleet[8][6]=' ',fleet[8][7]=' ',fleet[8][8]=' ',fleet[8][9]=' ',
        fleet[9][0]=' ',fleet[9][1]=' ',fleet[9][2]=' ',fleet[9][3]=' ',fleet[9][4]=' ',fleet[9][5]=' ',fleet[9][6]=' ',fleet[9][7]=' ',fleet[9][8]=' ',fleet[9][9]=' ';
    }
    //fleet position 3
    else if(random == 2){
        fleet[0][0]=' ',fleet[0][1]='D',fleet[0][2]=' ',fleet[0][3]=' ',fleet[0][4]=' ',fleet[0][5]=' ',fleet[0][6]=' ',fleet[0][7]=' ',fleet[0][8]='P',fleet[0][9]='P',
        fleet[1][0]=' ',fleet[1][1]='D',fleet[1][2]=' ',fleet[1][3]='S',fleet[1][4]='S',fleet[1][5]='S',fleet[1][6]=' ',fleet[1][7]=' ',fleet[1][8]=' ',fleet[1][9]=' ',
        fleet[2][0]=' ',fleet[2][1]='D',fleet[2][2]=' ',fleet[2][3]=' ',fleet[2][4]=' ',fleet[2][5]=' ',fleet[2][6]=' ',fleet[2][7]=' ',fleet[2][8]=' ',fleet[2][9]=' ',
        fleet[3][0]=' ',fleet[3][1]=' ',fleet[3][2]=' ',fleet[3][3]=' ',fleet[3][4]=' ',fleet[3][5]=' ',fleet[3][6]=' ',fleet[3][7]=' ',fleet[3][8]=' ',fleet[3][9]=' ',
        fleet[4][0]=' ',fleet[4][1]=' ',fleet[4][2]=' ',fleet[4][3]='C',fleet[4][4]='C',fleet[4][5]='C',fleet[4][6]='C',fleet[4][7]='C',fleet[4][8]=' ',fleet[4][9]=' ',
        fleet[5][0]=' ',fleet[5][1]=' ',fleet[5][2]=' ',fleet[5][3]=' ',fleet[5][4]=' ',fleet[5][5]=' ',fleet[5][6]=' ',fleet[5][7]=' ',fleet[5][8]=' ',fleet[5][9]=' ',
        fleet[6][0]=' ',fleet[6][1]=' ',fleet[6][2]=' ',fleet[6][3]=' ',fleet[6][4]=' ',fleet[6][5]=' ',fleet[6][6]=' ',fleet[6][7]=' ',fleet[6][8]=' ',fleet[6][9]=' ',
        fleet[7][0]=' ',fleet[7][1]=' ',fleet[7][2]=' ',fleet[7][3]=' ',fleet[7][4]=' ',fleet[7][5]=' ',fleet[7][6]=' ',fleet[7][7]=' ',fleet[7][8]=' ',fleet[7][9]=' ',
        fleet[8][0]=' ',fleet[8][1]='B',fleet[8][2]='B',fleet[8][3]='B',fleet[8][4]='B',fleet[8][5]=' ',fleet[8][6]=' ',fleet[8][7]=' ',fleet[8][8]=' ',fleet[8][9]=' ',
        fleet[9][0]=' ',fleet[9][1]=' ',fleet[9][2]=' ',fleet[9][3]=' ',fleet[9][4]=' ',fleet[9][5]=' ',fleet[9][6]=' ',fleet[9][7]=' ',fleet[9][8]=' ',fleet[9][9]=' ';
    }
    //fleet position 4
    else if(random == 3){
        fleet[0][0]=' ',fleet[0][1]='B',fleet[0][2]='B',fleet[0][3]='B',fleet[0][4]='B',fleet[0][5]=' ',fleet[0][6]=' ',fleet[0][7]=' ',fleet[0][8]=' ',fleet[0][9]='C',
        fleet[1][0]=' ',fleet[1][1]=' ',fleet[1][2]=' ',fleet[1][3]=' ',fleet[1][4]=' ',fleet[1][5]=' ',fleet[1][6]=' ',fleet[1][7]=' ',fleet[1][8]=' ',fleet[1][9]='C',
        fleet[2][0]=' ',fleet[2][1]=' ',fleet[2][2]=' ',fleet[2][3]=' ',fleet[2][4]=' ',fleet[2][5]=' ',fleet[2][6]=' ',fleet[2][7]=' ',fleet[2][8]=' ',fleet[2][9]='C',
        fleet[3][0]=' ',fleet[3][1]=' ',fleet[3][2]=' ',fleet[3][3]=' ',fleet[3][4]=' ',fleet[3][5]=' ',fleet[3][6]=' ',fleet[3][7]=' ',fleet[3][8]=' ',fleet[3][9]='C',
        fleet[4][0]=' ',fleet[4][1]=' ',fleet[4][2]=' ',fleet[4][3]=' ',fleet[4][4]=' ',fleet[4][5]=' ',fleet[4][6]=' ',fleet[4][7]=' ',fleet[4][8]=' ',fleet[4][9]='C',
        fleet[5][0]=' ',fleet[5][1]=' ',fleet[5][2]='S',fleet[5][3]=' ',fleet[5][4]='P',fleet[5][5]='P',fleet[5][6]=' ',fleet[5][7]=' ',fleet[5][8]=' ',fleet[5][9]=' ',
        fleet[6][0]=' ',fleet[6][1]=' ',fleet[6][2]='S',fleet[6][3]=' ',fleet[6][4]=' ',fleet[6][5]=' ',fleet[6][6]=' ',fleet[6][7]=' ',fleet[6][8]=' ',fleet[6][9]=' ',
        fleet[7][0]=' ',fleet[7][1]=' ',fleet[7][2]='S',fleet[7][3]=' ',fleet[7][4]=' ',fleet[7][5]=' ',fleet[7][6]=' ',fleet[7][7]=' ',fleet[7][8]=' ',fleet[7][9]=' ',
        fleet[8][0]=' ',fleet[8][1]=' ',fleet[8][2]=' ',fleet[8][3]=' ',fleet[8][4]=' ',fleet[8][5]=' ',fleet[8][6]=' ',fleet[8][7]=' ',fleet[8][8]=' ',fleet[8][9]=' ',
        fleet[9][0]=' ',fleet[9][1]=' ',fleet[9][2]=' ',fleet[9][3]=' ',fleet[9][4]='D',fleet[9][5]='D',fleet[9][6]='D',fleet[9][7]=' ',fleet[9][8]=' ',fleet[9][9]=' ';
    }
}

//what ship is hit
void shipHit() {
    if(fleet[row][column] == 'D'){
        cout<<"Destroyer \n";
        destroyerHits++;
        return;
    }
    else if(fleet[row][column] == 'C'){
        cout<<"Carrier \n";
        carrierHits++;
        return;
    }
    else if(fleet[row][column] == 'P'){
        cout<<"Patrolboat \n";
        patrolboatHits++;
        return;
    }
    else if(fleet[row][column] == 'B'){
        cout<<"Battleship \n";
        battleshipHits++;
        return;
    }
    else if(fleet[row][column] == 'S'){
        cout<<"Submarine \n";
        submarineHits++;
        return;
    }
}

//count ships sunk
void shipSunkCount() {
   int shipSunk=0;
    if(destroyerHits == 3){
        shipSunk++;
    }if(carrierHits == 5){
        shipSunk++;
    }if(patrolboatHits == 2){
        shipSunk++;
    }if(battleshipHits == 4){
        shipSunk++;
    }if(submarineHits == 3){
        shipSunk++;
    }
  cout<<shipSunk<<" ships sunk \n";
  shipSunk = 0;
}

//display board
void display_board() {
    cout<<"------Battle Ship------\n";
    cout<<"  "<<1<<'|'<<2<<'|'<<3<<'|'<<4<<'|'<<5<<'|'<<6<<'|'<<7<<'|'<<8<<'|'<<9<<'|'<<10<<endl;
    cout<<'A'<<'|'<<board[0][0]<<'|'<<board[0][1]<<'|'<<board[0][2]<<'|'<<board[0][3]<<'|'<<board[0][4]<<'|'<<board[0][5]<<'|'<<board[0][6]<<'|'<<board[0][7]<<'|'<<board[0][8]<<'|'<<board[0][9]<<'|'<<endl;
    cout<<'B'<<'|'<<board[1][0]<<'|'<<board[1][1]<<'|'<<board[1][2]<<'|'<<board[1][3]<<'|'<<board[1][4]<<'|'<<board[1][5]<<'|'<<board[1][6]<<'|'<<board[1][7]<<'|'<<board[1][8]<<'|'<<board[1][9]<<'|'<<endl;
    cout<<'C'<<'|'<<board[2][0]<<'|'<<board[2][1]<<'|'<<board[2][2]<<'|'<<board[2][3]<<'|'<<board[2][4]<<'|'<<board[2][5]<<'|'<<board[2][6]<<'|'<<board[2][7]<<'|'<<board[2][8]<<'|'<<board[2][9]<<'|'<<endl;
    cout<<'D'<<'|'<<board[3][0]<<'|'<<board[3][1]<<'|'<<board[3][2]<<'|'<<board[3][3]<<'|'<<board[3][4]<<'|'<<board[3][5]<<'|'<<board[3][6]<<'|'<<board[3][7]<<'|'<<board[3][8]<<'|'<<board[3][9]<<'|'<<endl;
    cout<<'E'<<'|'<<board[4][0]<<'|'<<board[4][1]<<'|'<<board[4][2]<<'|'<<board[4][3]<<'|'<<board[4][4]<<'|'<<board[4][5]<<'|'<<board[4][6]<<'|'<<board[4][7]<<'|'<<board[4][8]<<'|'<<board[4][9]<<'|'<<endl;
    cout<<'F'<<'|'<<board[5][0]<<'|'<<board[5][1]<<'|'<<board[5][2]<<'|'<<board[5][3]<<'|'<<board[5][4]<<'|'<<board[5][5]<<'|'<<board[5][6]<<'|'<<board[5][7]<<'|'<<board[5][8]<<'|'<<board[5][9]<<'|'<<endl;
    cout<<'G'<<'|'<<board[6][0]<<'|'<<board[6][1]<<'|'<<board[6][2]<<'|'<<board[6][3]<<'|'<<board[6][4]<<'|'<<board[6][5]<<'|'<<board[6][6]<<'|'<<board[6][7]<<'|'<<board[6][8]<<'|'<<board[6][9]<<'|'<<endl;
    cout<<'H'<<'|'<<board[7][0]<<'|'<<board[7][1]<<'|'<<board[7][2]<<'|'<<board[7][3]<<'|'<<board[7][4]<<'|'<<board[7][5]<<'|'<<board[7][6]<<'|'<<board[7][7]<<'|'<<board[7][8]<<'|'<<board[7][9]<<'|'<<endl;
    cout<<'I'<<'|'<<board[8][0]<<'|'<<board[8][1]<<'|'<<board[8][2]<<'|'<<board[8][3]<<'|'<<board[8][4]<<'|'<<board[8][5]<<'|'<<board[8][6]<<'|'<<board[8][7]<<'|'<<board[8][8]<<'|'<<board[8][9]<<'|'<<endl;
    cout<<'J'<<'|'<<board[9][0]<<'|'<<board[9][1]<<'|'<<board[9][2]<<'|'<<board[9][3]<<'|'<<board[9][4]<<'|'<<board[9][5]<<'|'<<board[9][6]<<'|'<<board[9][7]<<'|'<<board[9][8]<<'|'<<board[9][9]<<'|'<<endl;
    cout<<"-----------------------\n";
}

//collect player selection 
void selection() {
    cout<<"Select Row[a,b,c,d,e,f,g,h,i,j] \n";
    cin>>rowCharacter;
    switch(rowCharacter){
        case ('a'): row=0; break;
        case ('b'): row=1; break;
        case ('c'): row=2; break;
        case ('d'): row=3; break;
        case ('e'): row=4; break;
        case ('f'): row=5; break;
        case ('g'): row=6; break;
        case ('h'): row=7; break;
        case ('i'): row=8; break;
        case ('j'): row=9; break;
        default:
        cout<<"invalid selection \n";
        return;
    }
    cout<<"Select Column [1,2,3,4,5,6,7,8,9,10] \n";
    cin>>columnInteger;
    switch(columnInteger){
        case (1): column=0; break;
        case (2): column=1; break;
        case (3): column=2; break;
        case (4): column=3; break;
        case (5): column=4; break;
        case (6): column=5; break;
        case (7): column=6; break;
        case (8): column=7; break;
        case (9): column=8; break;
        case (10): column=9; break;
        default:
        cout<<"invalid selection \n";
        return;
    }
    if(board[row][column] != 'X' && fleet[row][column] == ' ' && board[row][column] != '0' ){
        board[row][column] = '0';
        cout<<"MISS!\n";
        turns++;
        
    }else if(board[row][column] != 'X' && fleet[row][column] != ' '){
        board[row][column] = 'X';
        cout<<"HIT! \n";
        hits++;
        turns++;
    }else{
        cout<<"invalid selection \n";
        return;
    } 
}
//check if all ships have been sunk
void gameIsWon() {
    if(hits == 17){
        shipSunkCount();
        display_board();
        cout << "Congratulations, you have won the game!\n";
        cout<<"It took you "<<turns<<" guesses to win.\n";
        gameOn = false;
    }
}

//main function
int main() {
    cout<<"BattleShip \n";
    randomFleet();
      while(gameOn){
        display_board();
        shipSunkCount();
        cout<<turns<<" guesses \n";
        selection();
        shipHit();
        gameIsWon();
      }
    return 0;
}
