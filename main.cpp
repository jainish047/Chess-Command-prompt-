#include <bits/stdc++.h>
#include <algorithm>
#include "rules.cpp"
// #include "termcolor.hpp"
// #include"board.cpp"
#define RESET "\033[0m"
#define BLUE "\033[34m"
using namespace std;

int main()
{
    // vector<vector<piece>> game;
    // board.generate();
    // // cout<<board[4][4].type;
    Board chess;
    string s;
    vector<int> move;
    bool turn = true;
    bool past = false;
    vector<vector<bool>> temp (8, vector<bool> (8, true));
    // bool temp[8][8];
    while (!chess.isCheckmate()){
        do{
            do{
                if(turn==past)  cout<<"invalid move (from main) ..."<<endl;
                else            past=turn;

                movable(chess.board, turn, temp);
                // cout<<"ok"<<endl;
                print_movable(temp);
                // cout<<"ok2"<<endl;

                chess.print_board();
                if (turn == true)
                    cout << "enter move: ";
                else
                    cout << BLUE << "enter move " << RESET << ": ";
                cin >> s;
                std::system("cls");
                // termcolor::clear_screen();
            } while (!parse(s)); // checks syntax
            move = translate(s);
            cout << move[0] << " " << move[1] << " ," << move[2] << " " << move[3] << endl;
            // turn = (!turn);
        } while (!is_valid_move(move, turn, chess.board, temp) || ischeck(move, turn, chess.board, temp));
        // cout<<"okkkkkkkkkkkkk"<<endl;
        move_(move, chess.board);
        turn=(!turn);
    }
    return 0;
}
