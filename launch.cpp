//
//  launch.cpp
//  othello
//
//  Created by Yakumorin on 2018/11/10.
//

#include <iostream>
#include <algorithm>
#include <string>
#include "Board.h"

using namespace std;


void game(Board &board) {
    int count = board.get_count();
    if(count % 2 == 0) {
        if(board.check_b() == 0) {
            board.check_win();
            return;
        }
        cout << "Please choose a position for black(A1 to H8)" << endl;
        string op;
        cin >> op;
        int x, y;
        x=op[1]-'1'; y = op[0]-'A';
        bool ok = board.isok(x, y, 'b');
        while(!ok || op.size() != 2 || op[0] > 'H' || op[0] < 'A' || op[1] > '8' || op[1] < '1') {
            cout << "Invalid input!\nPlease choose a position for black(A1 to H8)" << endl;
            cin >> op;
            x=op[1]-'1'; y = op[0]-'A';
            ok = board.isok(x, y, 'b');
        }
        board.set(x, y, 'b');
        board.show();
        game(board);
    } else {
        if(!board.check_w()) {
            board.check_win();
            return;
        }
        board.show();
        game(board);
    }
}

int main(int argc, const char * argv[]) {
    
    if(argc > 1) { //has input arguments
        
    } else {
        string op;
        cout << "import a exist game push 1, otherwise start a new game" << endl;
        cin >> op;
        Board board;
        board.show();
        game(board);
    }
    
    
    return 0;
}
