# Sudoku Solver

## 📌 Overview

This is a **C++-based Sudoku Solver** that takes a 9x9 Sudoku puzzle as input, solves it using a **backtracking algorithm**, and displays the solution. The program can accept input directly or from a file and provides a simple menu-driven interface for ease of use.

---

## 🚀 Features

✅ **Backtracking Algorithm** – Efficiently solves even complex Sudoku puzzles.  
✅ **Flexible Input Handling** – Accepts input as an **81-character string** or reads from a file.  
✅ **Interactive Console UI** – Provides a **menu-driven experience** for solving puzzles.  
✅ **Pretty-Printed Sudoku Board** – Displays the board in a structured, easy-to-read format.  
✅ **Error Handling** – Detects **invalid inputs** and provides user-friendly error messages.  

---

## 🛠️ How It Works

1. **Input Parsing**  
   - The program reads an **81-character** string where:
     - `.` or `0` represents an empty cell.
     - Digits (`1-9`) represent pre-filled values.
   - Input can also be provided via a **file**.
   
2. **Sudoku Solving**  
   - The backtracking algorithm:
     - Finds an **empty cell**.
     - Attempts numbers **1-9**.
     - Checks **row, column, and 3x3 subgrid constraints**.
     - Recursively solves the rest of the puzzle.
     - **Backtracks** if a conflict is found.

3. **Displaying the Output**  
   - The board is printed before and after solving.
   - If no solution exists, the user is informed.

---

## 🔧 Installation & Usage

### 🔹 Compile the Code

```bash
g++ Sudoku_Solver.cpp -o sudoku_solver
```

### 🔹 Run the Program

```bash
./sudoku_solver
```

### 🔹 Example Input & Output

#### ✅ Sample Input (81-character string)

```
53..7....6..195....98....6.8...6...34..8..3..17...2...6.6....28....419..5....8..79
```

#### 🔄 Unsolved Board:

```
5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .
------+-------+------
8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6
------+-------+------
. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9
```

#### ✅ Solved Board:

```
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
```

---

## ⚡ Challenges & Solutions

### **1️⃣ Challenge: Input Parsing**
   - **Problem:** Handling both **file-based** and **direct** inputs while ensuring the correct format.
   - **Solution:**  
     ✅ Used `ifstream` to check if the input is a file.  
     ✅ **Stripped whitespace** and ensured **exactly 81 characters** are processed.  
     ✅ Handled **invalid characters** and provided error messages.  

### **2️⃣ Challenge: Efficient Solving**
   - **Problem:** Ensuring backtracking doesn’t become too slow for complex puzzles.
   - **Solution:**  
     ✅ Used **optimized row, column, and subgrid checks**.  
     ✅ Implemented **early pruning** to avoid unnecessary computations.  

### **3️⃣ Challenge: Console Formatting**
   - **Problem:** Displaying the board in an easy-to-read format.
   - **Solution:**  
     ✅ Used **dividers** (`------+-------+------`) to separate 3x3 blocks.  
     ✅ Displayed `.` for empty cells in the unsolved board.  

---

## 🛠️ Future Improvements

🔹 Add **GUI support** using SFML or Qt for better visuals.  
🔹 Implement a **graph-based approach** for solving instead of brute-force backtracking.  
🔹 Add a **difficulty rating system** based on the number of pre-filled cells.  

---

## 🏆 Credits & License

Created by **[Mohak Sharma]**  
Licensed under **MIT License** – Free to use, modify, and distribute.  
