#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<array>
#include<string>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

void printarr(string arr[][COLS]);
void welcomemsg();
void goodbyemsg();
bool checkcards(bool arr[][COLS]);
bool flip(int x, int y, bool [][COLS], string c[][COLS], string a[][COLS]);
void match(int, int , int, int, bool b[][COLS], string c[][COLS]);


void welcomemsg(){
  cout << endl << endl;
  cout << "Welcome to the memory game! Pick two cards and try to make them match!" << endl;
  cout << "If they match, they will disappear from the table, try and get them all to match to win" << endl;
  cout << "Have fun and try your luck!" << endl << endl;
}

void gooodbyemsg(){
  cout << "I hope you had fun playing this game! Have a nice day and see you around!" << endl << endl;
}

bool checkcards(){
  for(int i = 0; i <  ROWS; i++){
    for(int j = 0; j < COLS; j++)
      if(arr[i][j] == false)
        return = true;
  }
  return false;
}

bool flip(int x, int y, bool b[][COLS], string c[][COLS], string a[][COLS]){
  if(x > ROWS || x < 1 || y > COLS || y < 1){
    cout << "The row and column is not valid" << endl;
    return false;
  }
  if(b[x - 1][y - 1] == false){
    c[x - 1][y - 1] = a[x - 1][y - 1];
    cout << endl << endl;
    printarr[c];
    cout << endl;
    return true;
  }else{
    cout << "Pick again!" << endl << endl;
    return false;
  }
}

void match(int r1, int c1, int r2, int c2, bool b[][COLS], string c[][COLS]){
  if(c[r1 - 1][c1 - 1] == c[r2 - 1][c2 - 1]){
    c[r1 - 1][c1 - 1] = "_";
    c[r2 - 1][c2 - 1] = "_";
    b[r1 - 1][c1 - 1] = true;
    b[r2 - 1][c2 - 1] = true;
    cout << "The cards match and are removed" << endl << endl;
    printarr[c];
    cout << endl;
  }else{
    cout << "The cards do not match :( ";
    b[r1 - 1][c1 - 1] = false;
    b[r2 - 1][c2 - 1] = false;
    c[r1 - 1][c1 - 1] = "*";
    c[r2 - 1][c2 - 1] = "*";
    printarr[c];
    cout << endl << endl;
  }
}

void printarr(string arr[][COLS]){
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++)
      cout << arr[i][j] << " ";
    cout << endl << endl;
  }
}


int main()
{
  char choice = 'y';

  while(choice=='y'){

    string cards[ROWS][COLS] = {{"*", "*", "*", "*"},
                                {"*", "*", "*", "*"},
                                {"*", "*", "*", "*"}};
    bool check[ROWS][COLS] = {{false, false, false, false},
                              {false, false, false, false},
                              {false, false, false, false}};

    string ans[ROWS][COLS];

    ifstream inputfile;
    string filename;
    cout << "Please enter the name of the file: ";
    cin >> filename;

    string card;
    int pos1 = 0, pos2 = 0;

    inputfile.open(filename);

    if(inputfile){
      while(inputfile >> card){
        ans[pos1][pos2] = card;
        if(pos2 < (COLS - 1))
          pos2++;
        else if(pos1 < (ROWS - 1)){
          pos2 = 0;
          pos1++;
        }
      }}else{
        cout << "The file did not open properly" << endl;
        return 0;
      }


      welcomemsg();

      int turn = 0;
      printarr(cards);
      cout << endl; 

      while(checkcards(check)){
        int r1, c1, r2, c2;
        do{
          cout << "Enter a row and column" << endl;
          cin >> r1 >> c1;
        }while(!flip(r1, c1, check, cards, ans));

          do{
           cout << "Enter another row and column" << endl;
           cin >> r2 >> c2;
          }while(!flip(r2, c2, check, cards, ans));

          match(r1, c1, r2, c2, check, cards);
          turn++;
      }


      cout << "You won! you took " << turn << "to finish!";
      cout << "Would you like to play again? y/n ";
      cin >> choice;
    }

    goodbyemsg();
  }
           
 
