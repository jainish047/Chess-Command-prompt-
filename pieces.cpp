// we can make this without using classes,
// but just every time we will have to detect type of piece by character on graphic board

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// class Board{};

class piece{
public:
    string type;
    bool colour;    //black 0-false, white 1-true
    piece(string s, bool c):type(s), colour(c) {}
};



// class king:public piece{
// public:
//     bool is_sp_valid(){

//     }
// };

// class queen:public piece{
// public:
//     bool is_sp_valid(){
        
//     }
// };

// class pawn:public piece{
// public:
//     bool is_sp_valid(){
        
//     }
// };

// class bishop:public piece{
// public:
//     bool is_sp_valid(){
        
//     }
// };

// class rook:public piece{
// public:
//     bool is_sp_valid(){
        
//     }
// };