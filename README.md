# 🐭 Rat in a Maze 

##  Project Overview

This project implements the classic **Rat in a Maze** problem using **recursive backtracking** in C++. The goal is to find a valid path for the rat to move from the top-left corner (0, 0) to the bottom-right corner (n-1, n-1) of a user-defined maze grid, following only allowed paths (cells with value 1).

The solution also features:
- Interactive menu-driven interface
- Stack-based path tracking
- Score tracking across multiple games

---

## 🎮 How It Works

- The user enters the size of the maze (`n × n`)
- Then the maze structure is input, using 1s (open path) and 0s (walls)
- The algorithm recursively attempts to reach the goal by moving **right or down**
- If a solution is found, the program:
  - Prints the solved maze with the path
  - Prints the path from stack (in reverse order)
  - Updates the player's score
- Users are given the option to play again

---

## ⚙️ Key Features

-  **Backtracking-based solver**
-  **Stack storage** of the solution path
-  **Score tracking** for multiple plays
-  **Dynamic memory management**
-  **Clean input-output structure**
-  **Cross-platform note**: Uses `system("cls")` for clearing screen (works on Windows)

---

## 📊 Theoretical Analysis

### Time Complexity

- The backtracking algorithm tries each possible path:
  - Worst case: visits each cell multiple times
  - **Time Complexity**: `O(2^(n^2))` in brute-force, but practical execution is much faster due to pruning via invalid/blocked cells

### Space Complexity

- Uses `O(n^2)` space for the maze and solution grid
- A `stack` of maximum size `n²` is used for storing path coordinates

---
