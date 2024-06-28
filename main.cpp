/**------------------------------------------
    Program 2: Great 13
    name: Farhan Ahmed
    Course: CS 141, Fall 2022.
    System: Linux x86_64 and G++
    Author: George Maratos and David Hayes
 ---------------------------------------------**/

#include <iostream>

#include <iomanip>

#include <cstdlib>

#include <map>

#include <string>


using namespace std;

// Function that displays the instructions to the user

void display_instructions() {
  cout << "Class: CS 141" << endl <<
    "Program 2: Great 13" << endl << endl <<
    "Make a series of jumps until there is a single piece left" << endl <<
    "anywhere on board. On each move you must jump an adjacent" << endl <<
    "piece   into   an  empty  square,  jumping  horizontally," << endl <<
    "vertically, or diagonally." << endl << endl <<
    "Input of 'R' resets the board back to the beginning, and " << endl <<
    "'X' exits the game." << endl;
}


char board[13] {};

// funtion checks what symbol a letter from postion is on the board

char get_element(char position) {
  if ((position < 'A') || (position > 'M')) {
    cout << "Failed to get element at position " << position << endl <<
      "Make sure the given position is an uppercase letter " << endl <<
      "between A-M." << endl;
    exit(1);
  }
  return board[position - 'A'];
}

// funtion turns each position character on board to # or .
void set_element(char position, char value) {
  if ((position < 'A') || (position > 'M')) {
    cout << "Failed to set element at postion " << position << endl <<
      "Make sure the given position is an uppercase letter " << endl <<
      "between A-M." << endl;
    exit(1);
  }
  board[position - 'A'] = value;
}

// print out the board with the legend on the right

void display_board() {
  cout << endl;
  cout << setw(7) << "Board" << setw(12) << "Position" << endl;
  cout << setw(5) << board[0] << setw(11) << 'A' << endl <<
    setw(3) << board[1] << ' ' << board[2] << ' ' << board[3] <<
    setw(11) << "B C D" << endl <<
    board[4] << ' ' << board[5] << ' ' << board[6] << ' ' <<
    board[7] << ' ' << board[8] << ' ' <<
    " E F G H I" << endl <<
    setw(3) << board[9] << ' ' << board[10] << ' ' << board[11] <<
    setw(11) << "J K L" << endl <<
    setw(5) << board[12] << setw(11) << 'M' << endl;
  cout << endl;
}



void make_move();
void initialize_board();
bool game_over();

int main() {
  // instruction are pritned first then the initial board is displayed
  // make move then is the user playing the game until game is over
  display_instructions();
  initialize_board();
  display_board();
  make_move();
}

// funtion allows user to make a move and determins if it valid or invalid
void make_move() {
  
  string userInput;
  string line;
  char pos;
  char one;
  char two;
  char three;


  while (userInput != "X" || userInput != "x"){
    cout << "Enter positions from, jump, and to (e.g. EFG):";
    cin >> userInput;
    // the first check for userInput is if its size is 3
    if(userInput.size() == 3){
      // userInput is capitalized
      for (int i = 0; i < userInput.length(); i++) {
        userInput[i] = toupper(userInput[i]);
    }
  
  // only starts if moves are invalid
      if ((userInput != "ABE") && (userInput != "ACG") && (userInput != "ADI") && (userInput != "BFJ") && (userInput != "BGL") && (userInput != "BCD") && (userInput != "CGK") && (userInput != "DCB") && (userInput != "DHL") && (userInput != "DGJ") && (userInput != "EBA") && (userInput != "EJM") && (userInput != "EFG") && (userInput != "FGH") && (userInput != "GCA") && (userInput != "GKM") && (userInput != "GHI") && (userInput != "GFE") && (userInput != "HGF") && (userInput != "IHG") && (userInput != "IDA") && (userInput != "ILM") && (userInput != "JFB") && (userInput != "JGD") && (userInput != "JKL") && (userInput != "KGC") && (userInput != "LKJ") && (userInput != "LHD") && (userInput != "LGB") && (userInput != "MLI") && (userInput != "MJE") && (userInput != "MKG")
        ){
        // each character in the string userInput is stored as a seperate character 
        for (int i = 0; i < userInput.size(); i++){
          if (i == 0){
            one = userInput.at(i);
          }
          else if (i == 1){
            two = userInput.at(i);
          }
          else if (i ==2) {
            three = userInput.at(i);
          }
        }
        // each character has to be between A-M
        if ((one < 'A' || one > 'M') || (two < 'A' || two > 'M') ||(three < 'A' || three > 'M')){
          cout << "*** Given move has positions not on the board! Please retry." << endl;
          display_board();

        }
        else{
          cout << "*** Move is invalid. Please retry." << endl;
          display_board();
        }

        
      }
      // valid moves are entered by user
      if (userInput == "ABE" || userInput == "ACG" || userInput == "ADI" || userInput == "BFJ" || userInput == "BGL" || userInput == "BCD" || userInput == "CGK" || userInput == "DCB" || userInput == "DHL" || userInput == "DGJ" || userInput == "EBA" || userInput == "EJM" || userInput == "EFG" || userInput == "FGH" || userInput == "GCA" || userInput == "GKM" || userInput == "GHI" || userInput == "GFE" || userInput == "HGF" || userInput == "IHG" || userInput == "IDA" || userInput == "ILM" || userInput == "JFB" || userInput == "JGD" || userInput == "JKL" || userInput == "KGC" || userInput == "LKJ" || userInput == "LHD" || userInput == "LGB" || userInput == "MLI" || userInput == "MJE" || userInput == "MKG"){
        // Once again string is sliced and each character is stored as an individual character
        for (int i = 0; i < userInput.size(); i++){
          if (i == 0) {
            one = userInput.at(i);
          } 
          else if (i == 1) {
            two = userInput.at(i);
          } 
          else if (i == 2) {
            three = userInput.at(i);
          } 
        }
      // if moves is valid board updates until one # is left and gives user a message telling they win
        if (get_element(three) != '#' && get_element(one) == '#' && get_element(two) == '#') {
            set_element(one, '.');
            set_element(two, '.');
            set_element(three, '#');
            if (game_over() == true){
              cout << "Congrats you win!" << endl;
              break;
            }
            else{
              display_board();

            }
        }
      
      // userInput cant have second character as a . on the board
        else if (get_element(two) == '.'){
            cout << "*** Must jump a piece. Please retry." << endl;
              display_board();
        }
      
      // userInput cannot have the first letter as . on the baord
        else if (get_element(one) == '.'){
            cout << "*** Source needs a piece. Please retry." << endl;
              display_board();
      
        }
      
        // userInput cannot have the third letter as a # on the board
        else if (get_element(three) == '#' && get_element(one) == '#' && get_element(two) == '#'){
          cout << "*** Destination must be empty. Please retry." << endl;
          display_board();
      
        } 
        
      }

}
    // user can press r and restart the board back tot he beginning
    else if (userInput.size() == 1 && (userInput == "R" || userInput == "r")){
      cout << "Restarting game." << endl;
      initialize_board();
      display_board();
    }
  // user can exit the game by inputing x
    else if (userInput.size() == 1 && (userInput == "x" || userInput == "X")){
      cout << "Exiting." << endl;
      break;
    }
  // if move not diagnol, vertical, and horizontal then this outputs
    else{
      cout << "Invalid sequence. Please retry." << endl;
        display_board();
  
    }
  }





  }


bool game_over() {
// looping over board symbol and checking if there is only oe # on board
  int count = 0;
  for (int i = 0; i < 13; i++){
    if(board[i] == '#'){
      count ++;
    }
  }
  if (count == 1){
    return true;
  }

    
  
  return false;
}
// baord begins with # on all positions except for G
void initialize_board() {
  for (int i = 0; i < 13; i++) {
    if (i == 6) {
      board[i] = '.';
    } else {
      board[i] = '#';
    }

  }


}
