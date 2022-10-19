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

bool is_row_column_valid(int index) {
  int row_element = 0;
  int column_element = 0;
  for (int i = 0; i < 9; i++) {
    row_element = sudoku[index][i];
    column_element = sudoku[i][index];

    // Check if row_element is present in the row. Do not check 0s.
    if (row_element != 0) {
      for (int j = i + 1; j < 9; j++) {
        if (row_element == sudoku[index][j])
          return false;
      }
    }

    // Check if column_element is present in the column. Do not check 0s.
    if (column_element != 0) {
      for (int j = i + 1; j < 9; j++) {
        if (column_element == sudoku[j][index])
          return false;
      }
    }
  }
  return true;
}

bool is_sub_array_valid(int index) {
  // 0 1 2 3 4 5 6 7 8 9
  //

  int element_row = 3 * (index / 3);
  int element_column = (index - element_row) * 3;
  int element = 0;
  // cout << "index: " << index << " start: [" << element_row << ", " << element_column << "]\n";
  // cout << "***Subarray: ";

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // cout << "[" << i + element_row << ", " << j + element_column << "] ";
      element = sudoku[i + element_row][j + element_column];
      // cout << element << ",";
      if (element!= 0) {
        int count = 0;
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            if (element == sudoku[k + element_row][l + element_column]) {
              count++;
            }
          }
        }
        if (count > 1)
          return false;
      }
    }
  }
  // cout << "\n";

  // int element_column = 0;

  // int start_element = sudoku[][];
  return true;
}

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 9; i++) {
    if (is_row_column_valid(i) == false)
      cout << "Row or Column: " << i << " is not valid\n";

    if (is_sub_array_valid(i) == false)
      cout << "Subarray " << i << " is not valid\n";
  }

  return 0;
}
