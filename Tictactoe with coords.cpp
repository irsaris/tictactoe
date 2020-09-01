/* I wanna kms
 * INGE 3016 M40
 * TicTacToe.cpp 
 * For: December 8, 2016
 */

#include <iostream>
#include <string>
using namespace std;

void printBoard(char [3][3]);
int checkWinner(char [3][3]);
void clearScreen();

int main()
{	
		
	char flag;	
	
	do{
		
	int turns = 1; //Turn counter variable
	char Board[3][3] = {{' ', ' ', ' '}, // ' ' means to have a blank space
						{' ', ' ', ' '}, // Also useful to change for whatever 
						{' ', ' ', ' '}};// other character you may need like X, O
	char player1 = 0;
	char player2 = 0;
	bool checkSymbol = false; // enables player to choose a starting symbol
	char playerTurn;
	int coord_x, coord_y;	
	bool check_x, check_y;
	
	cout<< "***********************************************" << endl;
	cout<< "    -Welcome to Fer's TIc Tac Toe emulator-    " << endl;
	cout<< "***********************************************\n\n\n" << endl;	
		
		while(checkSymbol == false){ 
			cout << "Player 1, select your starting symbol with a capital letter (X, O): "; cin >> player1;
	
			if (player1 == 'X' || player1 == 'x' || player1 == 'O' || player1 == 'o'){
				checkSymbol = true;
				player1 = toupper(player1); // enables the X or O to be entered to switch into capital letter
				cout << "\nPlayer 1 your symbol is " << player1 << endl;
			}
			else{
				checkSymbol=false;
				cout << "\nPlease select a valid symbol.\n" << endl;	
			}
		}//Enables the first player to select a symbol (X, O) and thus assign the other one by default to player 2
		
		if (player1 == 'X'){
			player2 = 'O';
			cout << "\nPlayer 2 your symbol is " << player2 << endl;
		}
				
		else if (player1 == 'O'){
			player2 = 'X';
			cout << "\nPlayer 2 your symbol is " << player2 << endl;
		}
			printBoard(Board);
	
	do{
		
				if (turns%2 == 1){ //Alternates between pares e impares y asi sale 1 y 0 en el remainder
					playerTurn = player1;
					cout << "\nPlayer 1 it's your turn." << endl;
				}
		
				else{
					playerTurn = player2;
					cout << "\nPlayer 2 it's your turn." << endl;
				}
				
				//Makes it so that the loop updates and enables players to take turns
				check_x = false;
				check_y = false;
				while(check_x == false){
					cout<< "Enter X coordinate: "; cin>>coord_x;
					if(cin.fail())	{  //if user inputs a character, ask until a integer is entered 																
						while(cin.fail()) {
        				cout << "Error enter a valid coordinate." << endl;
       					cin.clear();
       					cin.ignore(10000,'\n');
        				cout<< "Enter X coordinate: "; cin>>coord_x;
   						}
   	
						if (coord_x< 0 | coord_x> 2){
							check_x = false;
							cout << "\nEnter a valid X coordinate!" << endl;
						}
					
						else{
							check_x = true;
						}
					}
					
					else{
						if (coord_x< 0 | coord_x> 2){
							check_x = false;
							cout << "\nEnter a valid X coordinate!" << endl;
						}
					
						else{
							check_x = true;
						}
					}
				}
				
				
				
				
				while(check_y == false){
					cout<< "Enter Y coordinate: "; cin>>coord_y;
					if(cin.fail())	{  //if user inputs a character, ask until a integer is entered 																
						while(cin.fail()) {
        					cout << "Error enter a valid coordinate." << endl;
       						cin.clear();
       						cin.ignore(10000,'\n');
        					cout<< "Enter Y coordinate: "; cin>>coord_y;
   						}
   	
						if (coord_y< 0 | coord_y> 2){
							check_y = false;
							cout << "\nEnter a valid Y coordinate!" << endl;
						}
				
						else{
							check_y = true;
						}
					}
					
					else{
						if (coord_y< 0 | coord_y> 2){
							check_y = false;
							cout << "\nEnter a valid Y coordinate!" << endl;
						}
					
						else{
							check_y = true;
						}
					}
				}
					
				if(Board[coord_y][coord_x] != ' '){
					cout<< "\nInvalid space, please select a blank coordinate." << endl;
					turns--;
				}//If a player enters an invalid coordinate, the turn counter nullifies so that they can go again
				
				else{
					Board[coord_y][coord_x]= playerTurn;
					printBoard(Board);
					cout<< "\n\n\n\n\n" << endl;
				}//switches Board with elements x and y for the character that the player choose (X/O)
		turns++;		
		}while(turns <= 9 && checkWinner(Board)!= 1||0 );

//Calls checkwinner with the Board array to validate either win/draw	
				if(checkWinner(Board) == 1){
					cout << "The player using " << playerTurn << " is the winner!!!!" << endl;					
				}
							
				else if(checkWinner(Board) == 0){
					cout << "The game is a draw :(" << endl;					
				}
		
		cout<< "\nWould you like to try again?"; cin>>flag;
		clearScreen();
}while(flag == 'Y' || flag == 'y');
	
return 0;
}


void printBoard(char array[3][3]){    //Prints tic tac toe board in a box with cooordinates
	cout << "\n\n\nPlease enter a X and Y coordinate (from 0-2)\n" << endl;		
	cout << "         0     1     2  " << endl;
	cout << "       _____ _____ _____" << endl;
	cout << "      |     |     |     |" <<endl;
	cout << "  0   |  " << array[0][0] << "  |  " << array[0][1] << "  |  " << array[0][2] << "  |" << endl;          
	cout << "      |_____|_____|_____|" << endl;
	cout << "      |     |     |     |" << endl;
	cout << "  1   |  " << array[1][0] << "  |  " << array[1][1] << "  |  " << array[1][2] << "  |" << endl;
	cout << "      |_____|_____|_____|" << endl;
	cout << "      |     |     |     |" << endl;
	cout << "  2   |  " << array[2][0] << "  |  " << array[2][1] << "  |  " << array[2][2] << "  |" << endl;
	cout << "      |_____|_____|_____|" << endl;		
}

int checkWinner(char Board[3][3]){ //function to check board for a winner/tie
	int checkwinner=0; // slightly different variable, doesnt interfere with the function 
	
	if(Board [0][0] == 'X' && Board [1][0] == 'X' && Board [2][0] == 'X' ||
	   Board [0][1] == 'X' && Board [1][1] == 'X' && Board [2][1] == 'X' ||
	   Board [0][2] == 'X' && Board [1][2] == 'X' && Board [2][2] == 'X'){
			checkwinner=1;
		}
	
	else if(Board [0][0] == 'X' && Board [0][1] == 'X' && Board [0][2] == 'X' ||
			Board [1][0] == 'X' && Board [1][1] == 'X' && Board [1][2] == 'X' ||
	  		Board [2][0] == 'X' && Board [2][1] == 'X' && Board [2][2] == 'X'){
				checkwinner=1;
			}
			
	else if(Board [0][0] == 'X' && Board [1][1] == 'X' && Board [2][2] == 'X' ||
	        Board [0][2] == 'X' && Board [1][1] == 'X' && Board [2][0] == 'X' ){
				checkwinner=1;
	        }
	        
	else if(Board [0][0] == 'O' && Board [1][0] == 'O' && Board [2][0] == 'O' ||
	   Board [0][1] == 'O' && Board [1][1] == 'O' && Board [2][1] == 'O' ||
	   Board [0][2] == 'O' && Board [1][2] == 'O' && Board [2][2] == 'O'){
			checkwinner=1;
		}
	
	else if(Board [0][0] == 'O' && Board [0][1] == 'O' && Board [0][2] == 'O' ||
			Board [1][0] == 'O' && Board [1][1] == 'O' && Board [1][2] == 'O' ||
	  		Board [2][0] == 'O' && Board [2][1] == 'O' && Board [2][2] == 'O'){
				checkwinner=1;
			}
			
	else if(Board [0][0] == 'O' && Board [1][1] == 'O' && Board [2][2] == 'O' ||
	        Board [0][2] == 'O' && Board [1][1] == 'O' && Board [2][0] == 'O' ){
				checkwinner=1;
			} //Checks all possible combinations so that one player wins either be player 1 or 2
	
	else if(Board[0][0]!=' ' && Board[0][1]!=' '
		 && Board[0][2]!=' ' && Board[1][0]!=' ' 
	   	 && Board[1][1]!=' ' && Board[1][2]!=' ' 
	   	 && Board[2][0]!=' ' && Board[2][1]!=' '
	 	 && Board[2][2]!=' '){ 
				checkwinner=0;// The game is a draw	
			}	
	else 
	{checkwinner=-1;}//If every spot isnt replaced with X or O game is still going
	
return (checkwinner);
}

void clearScreen(){
    cout << string( 100, '\n' );
    }




