#include <iostream>
#include "sudoku.h"

int main() {
  std::vector<std::vector<int>> board = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9},
  };

  std::vector<std::vector<std::vector<int>>> solution;
  solve(board, solution);
  for (int i = 0; i < solution.size(); ++i) {
    print(solution[i]);
  }
}

void solve (std::vector<std::vector<int>> &board, std::vector<std::vector<std::vector<int>>> &solution) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      if (board[i][j] == 0) {
        for (int number = 1; number < 10; ++number){
          if (isAvailable (board, number, i, j)){
            board[i][j] = number;
            solve(board, solution);
            board[i][j] = 0;
          }
        }
        return;
      }
    }
  }
  solution.push_back(board);
}

bool isAvailable (std::vector<std::vector<int>> &board, int number, int row, int col) {
  return 
    isRowAvailabe(board, number, row) &&
    isColAvailabe(board, number, col) &&
    isSquareAvailabe(board, number, row, col);
}

bool isRowAvailabe (std::vector<std::vector<int>> &board, int number, int row) {
  for (int i = 0; i < board.size(); ++i) {
    if (board[row][i] == number){
      return false;
    }
  }
  return true;
}

bool isColAvailabe (std::vector<std::vector<int>> &board, int number, int col) {
  for (int i = 0; i < board.size(); ++i) {
    if (board[i][col] == number){
      return false;
    }
  }
  return true;
}

bool isSquareAvailabe (std::vector<std::vector<int>> &board, int number, int row, int col){
  int col_beg = (col/3) * 3;
  int col_end = col_beg+3;
  int row_beg = (row/3) * 3;
  int row_end = row_beg+3;
  for (int i = row_beg; i < row_end; ++i) {
    for (int j = col_beg; j < col_end; ++j) {
      if (board[i][j] == number){
        return false;
      }
    }
  }
  return true;
}

void print (std::vector<std::vector<int>> &board) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      std::cout << board[i][j] << ",";
    }
    std::cout << std::endl;
  }
  std::cout << "------------------" << std::endl;
}
