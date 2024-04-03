#include<bits/stdc++.h>
#include<algorithm>
// #include"pieces.cpp"
#include"board.cpp"
using namespace std;

// steing i.e. e2-g3

bool parse(string move){
    if(move.length()!=5         
    || (move[0]<'a' || 'h'<move[0])
    || (move[1]<'1' || '8'<move[1])
    || move[2]!='-'         
    || (move[3]<'a' || 'h'<move[3])
    || (move[4]<'1' || '8'<move[4])){
        cout<<"Syntax Error..."<<endl
            <<"Enter move again."<<endl;
        return false;
    }
    cout<<"correct syntax"<<endl;
    return true;
}

// pair<pair<int, int>, pair<int, int>> translate(string move){
// }
// using array/vector will be easier

// 0,1 ->starting position
// 2,3 ->final position

vector<int> translate(string& m){
    vector<int> move(4, 0);
    move[0]='8'-m[1];
    move[1]=m[0]-'a';
    move[2]='8'-m[4];
    move[3]=m[3]-'a';
    return move;
}

void move_(vector<int>& move, vector<vector<piece>>& board){
    board[move[2]][move[3]]=board[move[0]][move[1]];
    board[move[0]][move[1]].type="null";
}

int mod(int a, int b){
    if(a-b>0)   return a-b;
    return b-a;
}

void Rook_range(vector<vector<bool>>& temp, vector<vector<piece>>& board, int& i, int& j){
    int p=i-1, q=j;
    while (p >= 0 && (board[p][q].type == "null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q] = false;
        p--;
    }
    if (p >= 0)
        temp[p][q] = false;

    p = i + 1, q = j;
    while (p <= 7 && (board[p][q].type == "null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q] = false;
        p++;
    }
    if (p <= 7)
        temp[p][q] = false;

    p = i, q = j - 1;
    while (q >= 0 && (board[p][q].type == "null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q] = false;
        q--;
    }
    if (q >= 0)
        temp[p][q] = false;

    p = i, q = j+1;
    while (q<=7 && (board[p][q].type == "null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q] = false;
        q++;
    }
    if (q<=7)
        temp[p][q] = false;
}

bool move_rook(vector<vector<piece>>& board, vector<int>& move){
    cout<<"r"<<endl;
    if(move[0]==move[2]){
        cout<<"r1"<<endl;
        if(move[1]<move[3]){
            int j=move[1]+1;
            while(j<move[3] && board[move[0]][j].type=="null")   j++;
            if(j!=move[3]){
                cout<<"r2"<<endl;
                cout<<"invalid move"<<endl;
                return false;
            }
            else{    // j==move[3]
            cout<<"r3"<<endl;
                if(board[move[0]][j].type!="null" && board[move[0]][j].colour==board[move[0]][move[1]].colour){
                    cout<<"invalid move"<<endl;
                    cout<<"r4"<<endl;
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        else{
            cout<<"r5"<<endl;
            int j=move[1]-1;
            while(j>move[3] && board[move[0]][j].type=="null")   j--;
            if(j!=move[3]){
                cout<<"r6"<<endl;
                cout<<"invalid move"<<endl;
                return false;
            }
            else{  // j==move[3]
                if(board[move[0]][j].type!="null" && board[move[0]][j].colour==board[move[0]][move[1]].colour){
                    cout<<"invalid move"<<endl;
                    cout<<"r7"<<endl;
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }
    else if(move[1]==move[3]){
        if(move[0]<move[2]){
            cout<<"r8"<<endl;
            int i=move[0]+1;
            while(i<move[2] && board[i][move[1]].type=="null")   i++;
            if(i!=move[2]){
                cout<<"r9"<<endl;
                cout<<"invalid move"<<endl;
                return false;
            }
            else{  // j==move[3]
                if(board[i][move[1]].type!="null" && board[i][move[1]].colour==board[move[0]][move[1]].colour){
                    cout<<"r10"<<endl;
                    cout<<"invalid move"<<endl;
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        else{
            cout<<"r11"<<endl;
            int i=move[0]-1;
            while(i>move[2] && board[i][move[1]].type=="null")   i--;
            if(i!=move[2]){
                cout<<"r12"<<endl;
                cout<<"invalid move"<<endl;
                return false;
            }
            else{  // j==move[3]
            cout<<"r13"<<endl;
                if(board[i][move[1]].type!="null" && board[i][move[1]].colour==board[move[0]][move[1]].colour){
                    cout<<"invalid move"<<endl;
                    cout<<"r14"<<endl;
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }
    else{
        cout<<"r15"<<endl;
        cout<<"invalid move"<<endl;
        return false;
    }
}

void print_movable(vector<vector<bool>>& m){
        for(int i=0; i<8; i++){
            cout<<"    +---+---+---+---+---+---+---+---+"<<endl;
            cout<<8-i<<"   | ";
            for(int j=0; j<8; j++){
                cout<<(int)m[i][j]<<" | ";
            }
            cout<<endl;
        }
        cout<<"    +---+---+---+---+---+---+---+---+"<<endl;
        cout<<"      a   b   c   d   e   f   g   h"<<endl<<endl;
}

void Bishop_range(vector<vector<bool>>& temp, vector<vector<piece>>& board, int& i, int& j){
    // cout<<0;
    int p=i-1, q=j-1;
    while(p>=0 && q>=0 && (board[p][q].type=="null" || ( board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q]=false;
        p--;
        q--;
    }
    if(p>=0 && q>=0)    temp[p][q]=false;
    // cout<<1;
    p=i-1, q=j+1;
    while(p>=0 && q<=7 && (board[p][q].type=="null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q]=false;
        p--;
        q++;
    }
    if(p>=0 && q<=7)    temp[p][q]=false;
    // cout<<2;
    p=i+1, q=j-1;
    while(p<=7 && q>=0 && (board[p][q].type=="null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q]=false;
        p++;
        q--;
    }
    if(p<=7 && q>=0)    temp[p][q]=false;
    // cout<<3;
    p=i+1, q=j+1;
    while(p<=7 && q<=7 && (board[p][q].type=="null" ||  (board[p][q].type=="King" && board[p][q].colour!=board[i][j].colour))){
        temp[p][q]=false;
        p++;
        q++;
    }
    if(p<=7 && q<=7)    temp[p][q]=false;
    // cout<<4;
}

bool bishope_movable(vector<vector<piece>>& board, vector<int>& move){
    cout<<"mb"<<endl;
    if(mod(move[0], move[2]==mod(move[1], move[3])))    return true;
    cout<<"invalid move"<<endl;
    return false;
}

bool move_bishop(vector<vector<piece>>& board, vector<int>& move){
    cout<<"b"<<endl;
    if(!bishope_movable(board, move))   return false;
    cout<<"b1"<<endl;
    int i=move[0], j=move[1], a, b;
    if(move[2]<i && move[3]<j){
        cout<<"b2"<<endl;
        a=i-1, b=j-1;
        while(a>move[2] && b>move[3] && board[a][b].type=="null"){
            a--;
            b--;
        }
        if(a==move[2] && b==move[3])
        {cout<<"b3"<<endl;
            return true;}
        else{
            cout<<"b4"<<endl;
            cout<<"invalid move"<<endl;
            return false;
        }
    }
    else if(move[2]<i && move[3]>j){
        cout<<"b04"<<endl;
        a=i-1; b=j+1;
        while(a>move[2] && b<move[3] && board[a][b].type=="null"){
            a--;
            b++;
        }
        if(a==move[2] && b==move[3])
        {cout<<"b5"<<endl;
            return true;}
        else{
            cout<<"b6"<<endl;
            cout<<"invalid move"<<endl;
            return false;
        }
    }
    else if(move[2]>i && move[3]<j){
        cout<<"b7"<<endl;
        a=i+1; b=j-1;
        while(a<move[2] && b>move[3] && board[a][b].type=="null"){
            a++;
            b--;
        }
        if(a==move[2] && b==move[3])
        {cout<<"b8"<<endl;
            return true;}
        else{
            cout<<"b9"<<endl;
            cout<<"invalid move"<<endl;
            return false;
        }
    }
    else if(move[2]>i && move[3]>j){
        a=i+1; b=j+1;
        cout<<"b10"<<endl;
        while(a<move[2] && b<move[3] && board[a][b].type=="null"){
            a++;
            b++;
        }
        if(a==move[2] && b==move[3])
        {cout<<"b11"<<endl;
            return true;}
        else{
            cout<<"b12"<<endl;
            cout<<"invalid move"<<endl;
            return false;
        }
    }
    else{
        cout<<"b13"<<endl;
        cout<<"invalid move"<<endl;
        return false;
    }
}

void Horse_range(vector<vector<bool>>& temp, vector<vector<piece>>& board, int& i, int& j){
    // cout<<"a"<<endl;
    int a, b;
    a=i-1;
    if(a>=0){
        b=j-2;
        if(b>=0)    temp[a][b]=false;
        b=j+2;
        if(b<=7)    temp[a][b]=false;
    }
    // cout<<"b"<<endl;
    a=i+1;
    if(a<=7){
        b=j-2;
        if(b>=0)    temp[a][b]=false;
        b=j+2;
        if(b<=7)    temp[a][b]=false;
    }
    a=i-2;
    // cout<<"c"<<endl;
    if(a>=0){
        b=j-1;
        if(b>=0)    temp[a][b]=false;
        b=j+1;
        if(b<=7)    temp[a][b]=false;
    }
    a=i+2;
    // cout<<"d"<<endl;
    if(a<=7){
        b=j-1;
        if(b>=0)    temp[a][b]=false;
        b=j+1;
        if(b<=7)    temp[a][b]=false;
    }
    // cout<<"e"<<endl;
}

bool belongs_to(int& i, int& j, vector<int>& move){
    // cout<<"a"<<endl;
    int a, b;
    a=i-1;
        b=j-2;  if(a==move[2] && b==move[3])    return true;
        b=j+2;  if(a==move[2] && b==move[3])    return true;
    // cout<<"b"<<endl;
    a=i+1;
        b=j-2;  if(a==move[2] && b==move[3])    return true;
        b=j+2;  if(a==move[2] && b==move[3])    return true;
    a=i-2;
    // cout<<"c"<<endl;
        b=j-1;  if(a==move[2] && b==move[3])    return true;
        b=j+1;  if(a==move[2] && b==move[3])    return true;
    a=i+2;
    // cout<<"d"<<endl;
        b=j-1;  if(a==move[2] && b==move[3])    return true;
        b=j+1;  if(a==move[2] && b==move[3])    return true;
    return false;
}

void King_range(vector<vector<bool>>& temp, vector<vector<piece>>& board, int& i, int& j){
    // cout<<0;
    for(int a=i-1; a<=i+1; a++){
        for(int b=j-1; b<=j+1; b++){
            if(0<=a && a<=7 && 0<=b && b<=7)    temp[a][b]=false;
        }
    }
    // cout<<1;
}

void movable(vector<vector<piece>>& board, bool& c, vector<vector<bool>>& temp){
    // vector<vector<bool>> temp(8, vector<bool> (8, true));
    // setting all vlues to true
    // cout<<"okk"<<endl;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++){
            temp[i][j]=true;
            // if(board[i][j].type=="null")    board[i][j].colour=(!c);
        }
    // print_movable(temp);
// cout<<"okk1"<<endl;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            // cout<<board[i][j].type<<" ";
            // cout<<"ok"
            if(board[i][j].colour==c && board[i][j].type!="King" && board[i][j].type!="null"){
                temp[i][j]=false;
            }
            else if(board[i][j].type=="Pawn" && c!=board[i][j].colour){
                // cout<<"pp1"<<endl;
                if(board[i][j].colour==1){
                    // cout<<"ppp1"<<endl;
                    if(j-1>=0)  temp[i-1][j-1]=false;
                    if(j+1<=7)  temp[i-1][j+1]=false;
                }
                else{
                    // cout<<"ppp1"<<endl;
                    if(j-1>=0)  temp[i+1][j-1]=false;
                    if(j+1<=7)  temp[i+1][j+1]=false;
                }
                // cout<<"pp2"<<endl;
            }
            else if(board[i][j].type=="Rook" && c!=board[i][j].colour){
                Rook_range(temp, board, i, j);
            }
            else if(board[i][j].type=="Bishop" && c!=board[i][j].colour){
                Bishop_range(temp, board, i, j);
            }
            else if(board[i][j].type=="Queen" && c!=board[i][j].colour){
                Rook_range(temp, board, i, j);
                Bishop_range(temp, board, i, j);
            }
            else if(board[i][j].type=="Horse" && c!=board[i][j].colour){
                Horse_range(temp, board, i, j);
            }
            else if(board[i][j].type=="King" && c!=board[i][j].colour){
                King_range(temp, board, i, j);
            }
        }
        // cout<<endl;
    }
    cout<<"okk2"<<endl;
    // print_movable(temp);
    // return temp;
}

bool is_valid_move(vector<int>& move, bool& turn, vector<vector<piece>>& board, vector<vector<bool>>& temp){
    // cout<<0<<endl;
    // if there exists piece at final position
    // if(board[move[0]][move[1]].type=="null" || board[move[2]][move[3]].type!="null")    return false;
    
    cout<<1<<endl;
    piece p=board[move[0]][move[1]];

    cout<<2<<endl;
    if(p.colour!=turn){
        cout<<"its not your turn"<<endl;
        return false;
    }

    if(board[move[2]][move[3]].type!="null" && board[move[2]][move[3]].colour==turn){
        cout<<"you can't attack your piece"<<endl;
        return false;
    }
    // turn = (!turn);

    if(p.type=="Pawn"){
        cout<<"p"<<endl;
        if(p.colour==0 && move[1]==move[3]){
            cout<<"p1"<<endl;
            if(move[2]-move[0]==2 && move[0]==1 && board[2][move[1]].type=="null" && board[3][move[1]].type=="null"){
                return true;
            }
            else if(move[2]-move[0]==1 && board[move[0]+1][move[1]].type=="null"){
                return true;
            }
            else{
                cout<<"Invalid move..."<<endl;
                return false;
            }
        }
        else if(p.colour==1 && move[1]==move[3]){
            cout<<"p2"<<endl;
            if((move[0]==6 && move[0]-move[2]==2) || (move[0]-move[2]==1)){
                return true;
            }
            else{
                cout<<"Invalid move..."<<endl;
                return false;
            }
        }
        else if(board[move[2]][move[3]].type!="null" && p.colour==0 && move[2]-move[0]==1 && (move[3]-move[1]==1 || move[3]-move[1]==-1)){
            cout<<"p3"<<endl;
            return true;
        }
        else if(board[move[2]][move[3]].type!="null" && p.colour==1 && move[0]-move[2]==1 && (move[3]-move[1]==1 || move[3]-move[1]==-1)){
            cout<<"p4"<<endl;
            return true;
        }
        else{
            cout<<"p5"<<endl;
            cout<<"Invalid move..."<<endl;
            return false;
        }
    }
    else if(p.type=="King"){
        cout<<"k"<<endl;
        // defining movable blocks
        // vector<vector<bool>> temp=movable(board, p);

        if(mod(move[0], move[2])<=1 && mod(move[1], move[3])<=1 && temp[move[2]][move[3]]==true){
            cout<<"k1"<<endl;
            return true;
        }
        else{
            cout<<"k2"<<endl;
            cout<<"invalid move"<<endl;
            return false;
        }
    }
    else if(p.type=="Rook"){
        return move_rook(board, move);
    }
    else if(p.type=="Bishop"){
        return move_bishop(board, move);
    }
    else if(p.type=="Queen"){
        return move_rook(board, move) || move_bishop(board, move);
    }
    else if(p.type=="Horse"){
        // cout<<"a"<<endl;
        int a=move[2], b=move[3], i=move[0], j=move[1];
        // a=i-1;
        // if(a>=0){
        //     b=j-2;
        //     if(b>=0 && (board[a][b].type=="null" || (board[a][b].type!="null" && board[a][b].colour!=board[i][j].colour)))
        //         return true;
        //     b=j+2;
        //     if(b<=7)    temp[a][b]=false;
        // }
        // cout<<"b"<<endl;
        if(belongs_to(i, j, move) && (board[a][b].type=="null" || (board[a][b].type!="null" && board[a][b].colour!=board[i][j].colour)))
            return true;
        return false;
    }
    else{
        cout<<"there is no element to move"<<endl;
        return false;
    }
}   

bool ischeck(vector<int>& move, bool& turn, vector<vector<piece>> board, vector<vector<bool>> temp){
    cout<<"checking check"<<endl;
    move_(move, board);
    Board chess;
    chess.board=board;
    chess.print_board();
    cout<<"moved"<<endl;
    cout<<"turn: "<<(int)turn<<endl;
    int i=0, j=0;
    bool found=false;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            cout<<board[i][j].type<<" "<<(int)board[i][j].colour<<endl;
            if(board[i][j].type=="King" && board[i][j].colour==turn){
                found=true;
                break;
            }
        }
        if(found)   break;
    }
    cout<<"found king: "<<i<<" "<<j<<endl;
    movable(board, turn, temp);
    if(i<8 && j<8 && temp[i][j]==false){
        cout<<"you got check, invalid move..."<<endl;
        return true;
    }
    cout<<"no check"<<endl;
    return false;
}