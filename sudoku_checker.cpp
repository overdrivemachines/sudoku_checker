#include <iostream>

using namespace std;

bool is_row_valid(int row);

int sudoku[9][9] = {
  { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
  { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
  { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
  { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
  { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
  { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
  { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
  { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
  { 0, 0, 0, 0, 8, 0, 1, 7, 9 }
};

bool is_row_valid(int row) {
  int element = 0;
  for (int i = 0; i < 9; i++) {
    element = sudoku[row][i];
    // Check if element is present in the row. Do not check 0s.
    if (element != 0) {
      for (int j = i + 1; j < 9; j++) {
        if (element == sudoku[row][j])
          return false;
      }
    }
  }
  return true;
}

bool is_column_valid(int column) {
  int element = 0;
  for (int i = 0; i < 9; i++) {
    element = sudoku[i][column];
    // Check if element is present in the row. Do not check 0s.
    if (element != 0) {
      for (int j = i + 1; j < 9; j++) {
        if (element == sudoku[j][column])
          return false;
      }
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 9; i++) {
    if (is_row_valid(i) == false)
      cout << "Row: " << i << " is not valid\n";

    if (is_column_valid(i) == false)
      cout << "Column: " << i << " is not valid\n";
  }

  return 0;
}
