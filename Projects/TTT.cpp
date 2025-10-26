//Todo: Make a Tic Tac Toe game

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>  // For console color and screen manipulation

using namespace std;

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen(){
    system("cls");
}

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);


int main()
{
    char playAgain;
    srand(time(0));
    
    do{
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char player = 'X';
        char computer = 'O';
        bool running = true;

        drawBoard(spaces);
        setColor(14);  //Yellow for instructions
        cout << "  You are X (Green) | Computer is O (Red)\n\n";
        setColor(7);   //Reset to white

        while(running){
            playerMove(spaces, player);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer)){
                running = false;
            }
            else if(checkTie(spaces)){
                running = false;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer)){
                running = false;
            }
            else if(checkTie(spaces)){
                running = false;
            }
        }
        
        setColor(11);  //Cyan for restart
        cout << "\n  Thanks for playing!\n";
        cout << "  Play again? (Y/N): ";
        setColor(7);   //Reset to white
        cin >> playAgain;
        
    } while(playAgain == 'Y' || playAgain == 'y');
    
    setColor(14);
    cout << "\n  Goodbye!\n";
    setColor(7);
    system("pause");  //Keep window open until user presses a key

    return 0;
}

void drawBoard(char *spaces){
    clearScreen();  
    setColor(11);   //Cyan color for title
    cout << "\n  === TIC TAC TOE ===\n\n";
    setColor(7);    //Reset to white
    
    for(int i = 0; i < 9; i++){
        if(i % 3 == 0) cout << "  ";
        
        if(spaces[i] == 'X'){
            setColor(10);  //Green for player X
            cout << " " << spaces[i] << " ";
            setColor(7);
        }
        else if(spaces[i] == 'O'){
            setColor(12);  //Red for computer O
            cout << " " << spaces[i] << " ";
            setColor(7);
        }
        else{
            setColor(8);   //Gray for empty spaces
            cout << " " << (i+1) << " ";
            setColor(7);
        }
        
        if(i % 3 < 2) cout << "|";
        if(i % 3 == 2 && i < 6){
            cout << "\n  -----------\n";
        }
        else if(i % 3 == 2) cout << "\n";
    }
    cout << "\n";
}

void playerMove(char *spaces, char player){
    
    int num;
    do{
        cout << "Enter a number between 1 and 9: ";
        cin >> num;
        num--;
        if(spaces[num] == ' '){
            spaces[num] = player;
            break;
        }
    }while(num < 0 || num > 8);

    
}

void computerMove(char *spaces, char computer){
    
    int num;

    while(true){
        num = rand() % 9;
        if(spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer){
    
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        if(spaces[0] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);  //Green for win
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7); //Red for loss
        }
        return true;
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        if(spaces[3] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        if(spaces[6] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        if(spaces[0] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        if(spaces[1] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        if(spaces[2] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        if(spaces[0] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        if(spaces[2] == player){
            setColor(10); cout << "\n  YOU WIN!\n"; setColor(7);
        } else {
            setColor(12); cout << "\n  YOU LOSE!\n"; setColor(7);
        }
        return true;
    }
    return false;
}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    setColor(14);  //Yellow for tie message
    cout << "\n  IT'S A TIE!\n";
    setColor(7);   //Reset to white
    return true;
}
