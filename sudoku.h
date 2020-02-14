
#include <vector>

bool isRowAvailabe (std::vector<std::vector<int>> &board, int number, int row);
bool isColAvailabe (std::vector<std::vector<int>> &board, int number, int col);
bool isSquareAvailabe (std::vector<std::vector<int>> &board, int number, int row, int col);
bool isAvailable (std::vector<std::vector<int>> &board, int number, int row, int col);
void solve (std::vector<std::vector<int>> &board, std::vector<std::vector<std::vector<int>>> &solution);
void print (std::vector<std::vector<int>> &board);