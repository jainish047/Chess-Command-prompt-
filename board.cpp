#include<bits/stdc++.h>
#include<algorithm>
#include"pieces.cpp"
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
using namespace std;

class Board{
public:
    vector<vector<piece>> board;
    bool bk=true;
    bool wk=true;
    // vector<vector<piece>> generate(){
    Board(){
        // piece king ("king", 0);
        vector<vector<piece>> board (8, vector<piece> (8, piece ("null", 0)));
        board[0][0] = board[0][7] = *(new piece ("Rook", 0));
        board[0][1] = board[0][6] = *(new piece ("Horse", 0));
        board[0][2] = board[0][5] = *(new piece ("Bishop", 0));
        board[0][3] = *(new piece ("Queen", 0));
        board[0][4] = *(new piece ("King", 0));

        board[1][0] = board[1][1] = board[1][2] = board[1][3] = board[1][4] = board[1][5] = board[1][6] = board[1][7] = *(new piece ("Pawn", 0));

        board[7][0] = board[7][7] = *(new piece ("Rook", 1));
        board[7][1] = board[7][6] = *(new piece ("Horse", 1));
        board[7][2] = board[7][5] = *(new piece ("Bishop", 1));
        board[7][3] = *(new piece ("Queen", 1));
        board[7][4] = *(new piece ("King", 1));

        board[6][0] = board[6][1] = board[6][2] = board[6][3] = board[6][4] = board[6][5] = board[6][6] = board[6][7] = *(new piece ("Pawn", 1));
        this->board=board;
        bk=wk=true;
    }
    void print_board(){
        for(int i=0; i<8; i++){
            cout<<"    +---+---+---+---+---+---+---+---+"<<endl;
            cout<<8-i<<"   | ";
            for(int j=0; j<8; j++){
                if(board[i][j].type!="null"){
                    if(board[i][j].colour==0)   cout<<BLUE<<board[i][j].type[0]<<RESET;
                    else                        cout<<board[i][j].type[0];
                }
                else{
                    cout<<" ";
                }
                cout<<" | ";
            }
            cout<<endl;
        }
        cout<<"    +---+---+---+---+---+---+---+---+"<<endl<<endl;
        cout<<"      a   b   c   d   e   f   g   h"<<endl<<endl;
        // for(int i=0; i<8; i++)  cout<<" "<<char('a'+i)<<" ";
    }
    bool isCheckmate(){
        cout<<"no checkmte"<<endl;
        return false;
    }
};