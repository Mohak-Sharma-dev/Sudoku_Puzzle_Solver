#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

class SudokuSolver {
private:
    vector<vector<int>> board;

    bool isValid(int row, int col, int num) {
        // Check row
        for (int x = 0; x < 9; x++)
            if (board[row][x] == num) return false;

        // Check column
        for (int x = 0; x < 9; x++)
            if (board[x][col] == num) return false;

        // Check 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + startRow][j + startCol] == num)
                    return false;

        return true;
    }

    bool findEmptyPlace(int &row, int &col) {
        for (row = 0; row < 9; row++)
            for (col = 0; col < 9; col++)
                if (board[row][col] == 0)
                    return true;
        return false;
    }

public:
    SudokuSolver(const vector<vector<int>>& puzzle) : board(puzzle) {}

    bool solve() {
        int row, col;
        
        if (!findEmptyPlace(row, col))
            return true; // Puzzle already solved

        for (int num = 1; num <= 9; num++) {
            if (isValid(row, col, num)) {
                board[row][col] = num;
                if (solve())
                    return true;
                board[row][col] = 0; // Backtrack
            }
        }
        return false;
    }

    void printBoard() {
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0 && i != 0)
                cout << "------+-------+------" << endl;

            for (int j = 0; j < 9; j++) {
                if (j % 3 == 0 && j != 0)
                    cout << "| ";
                cout << (board[i][j] == 0 ? "." : to_string(board[i][j])) << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> getSolution() { return board; }
};

vector<vector<int>> parseInput(const string& input) {
    vector<vector<int>> board(9, vector<int>(9));
    if (input.length() != 81) {
        throw invalid_argument("Input must be exactly 81 characters");
    }

    for (int i = 0; i < 81; i++) {
        char c = input[i];
        int row = i / 9;
        int col = i % 9;

        if (c == '.' || c == '0') {
            board[row][col] = 0;
        } else if (isdigit(c)) {
            board[row][col] = c - '0';
        } else {
            throw invalid_argument("Invalid character in input");
        }
    }
    return board;
}


int main() {
    bool running = true;
    while (running) {
        cout << "\nSudoku Solver Menu:\n"
             << "1. Solve a puzzle\n"
             << "2. Exit\n"
             << "Choose option: ";
        
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

        switch(choice) {
            case 1: {
                try {
                    string input;
                    cout << "\nEnter puzzle (81 chars) or filename: ";
                    getline(cin, input);

                    // Check if input is a valid file
                    ifstream file(input);
                    if (file) {
                        string content;
                        string line;
                        while (getline(file, line)) {
                            content += line;
                        }
                        input = content;
                    }

                    // Process input
                    input.erase(remove_if(input.begin(), input.end(), 
                                  [](unsigned char c){ return isspace(c); }), 
                               input.end());
                    
                    vector<vector<int>> puzzle = parseInput(input);
                    SudokuSolver solver(puzzle);

                    cout << "\nUnsolved Sudoku:" << endl;
                    solver.printBoard();

                    if (solver.solve()) {
                        cout << "\nSolved Sudoku:" << endl;
                        solver.printBoard();
                    } else {
                        cout << "\nNo solution exists" << endl;
                    }
                }
                catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    cout << "Goodbye!\n";
    return 0;
}


// int main(int argc, char* argv[]) {
//     try {
//         string input;
//         if (argc > 1) {
//             ifstream file(argv[1]);
//             if (!file) throw runtime_error("Could not open file");
//             string line;
//             while (getline(file, line)) {
//                 input += line;
//             }
//         } else {
//             cout << "Enter Sudoku puzzle (81 characters, 0 or . for empty cells):\n";
//             getline(cin, input);
//         }

//         // Remove whitespace from input
//         //input.erase(remove(input.begin(), input.end(), [](unsigned char c){ return isspace(c); }), input.end());
//         input.erase(remove_if(input.begin(), input.end(), [](unsigned char c){ return isspace(c); }), input.end());
        
//         vector<vector<int>> puzzle = parseInput(input);
//         SudokuSolver solver(puzzle);

//         cout << "\nUnsolved Sudoku:" << endl;
//         solver.printBoard();

//         if (solver.solve()) {
//             cout << "\nSolved Sudoku:" << endl;
//             solver.printBoard();
//         } else {
//             cout << "\nNo solution exists" << endl;
//         }
//     } catch (const exception& e) {
//         cerr << "Error: " << e.what() << endl;
//         return 1;
//     }
//     return 0;
// }