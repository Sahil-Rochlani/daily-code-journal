#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, int &row, int &col, char num){
        //row check
        for(int i = 0;i < 9;i++){
            if(board[row][i] == num)return false;
        }
        //col check
        for(int i = 0;i < 9;i++){
            if(board[i][col] == num)return false;
        }
        //sub grid check
        int rowstart = row - row % 3, colstart = col - col % 3;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(board[rowstart + i][colstart + j] == num)return false;
            }
        }

        return true;
    }
    bool findEmptyLoc(vector<vector<char>>& board, int &row, int &col){
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.'){
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool solveSudokuHelper(vector<vector<char>>& board) {
        //need to write one case

        //find empty cell
        int row, col;
        if(!findEmptyLoc(board, row, col))return true;

        //fill that with a suitable number;
        for(int i = 1;i <= 9;i++){
            //convert num to char
            char num = i + '0';
            if(isSafe(board, row, col, num)){
                board[row][col] = num;
                if(solveSudokuHelper(board)){
                    return true;
                }
                //backtrack
                board[row][col] = '.';

            }
        }

        //if it reached here it means i was not able to put any number on cel [wor, col]
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        //need to write one case

        //find empty cell
        solveSudokuHelper(board);
    }