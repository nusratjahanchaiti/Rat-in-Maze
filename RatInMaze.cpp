#include <iostream>
#include <cstdlib>

using namespace std;

struct Pair {
    int row;
    int col;
};

void start(int* score);
void menu(int* score);

int isValid(int** arr, int row, int col, int n) {
    if (row < n && col < n && arr[row][col] == 1) {
        return 1;
    }
    return 0;
}

int solveMaze(int** ar, int row, int col, int n, int** solAr) {
    if (row == n - 1 && col == n - 1 && ar[row][col] == 1) {
        solAr[row][col] = 1;
        return 1;
    }
    if (isValid(ar, row, col, n)) {
        solAr[row][col] = 1;
        if (solveMaze(ar, row + 1, col, n, solAr)) {
            return 1;
        }
        if (solveMaze(ar, row, col + 1, n, solAr)) {
            return 1;
        }
        solAr[row][col] = 0;
        return 0;
    }
    return 0;
}

void start(int* score) {
    Pair myStack[1000]; // Assuming maximum stack size
    int top = -1;

    cout << "\n\n\n\t\t\tEnter the Maze size: ";
    int n;
    cin >> n;

    int** maze = new int*[n];
    int** solMaze = new int*[n];

    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
        solMaze[i] = new int[n];
    }

    cout << "\n\t\t\tEnter the Maze Structure:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "maze[" << i << "][" << j << "] = ";
            cin >> maze[i][j];
        }
        cout << endl;
    }

    cout << "\n\n\nUnsolved Maze:\n\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            solMaze[i][j] = 0;
        }
    }

    if (solveMaze(maze, 0, 0, n, solMaze)) {
        cout << "\nSolved Maze Path:\n\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (solMaze[i][j] == 0) {
                    cout << solMaze[i][j] << " ";
                } else if (solMaze[i][j] == 1) {
                    myStack[++top].row = i;
                    myStack[top].col = j;
                    cout << solMaze[i][j] << " ";
                }
            }
            cout << endl;
        }

        cout << "\nRat path using stack...\n";
        while (top >= 0) {
            cout << "(" << myStack[top].row << ", " << myStack[top].col << ")  ";
            top--;
        }

        (*score)++;
        cout << "\n\n\n\n\t\t\t\t\tYour Score: " << *score << endl;
    } else {
        cout << "\n\nSORRY! NO Path.\n";
    }

    cout << "\n\n\n\n\t\t\t\t\tWant to play again??\n";
    cout << "\t\t\t\t\tPRESS 1 for YES\n";
    cout << "\t\t\t\t\tPRESS 2 for NO\n";
    int t;
    cin >> t;
    switch (t) {
        case 1:
            menu(score);
            break;
        case 2:
            cout << "\n\n\n\n\t\t\t\tEXITING..........\n";
            exit(0);
        default:
            cout << "ERROR!!! PRESS 1 or 2 only......\n";
    }

    // Cleanup dynamic memory
    for (int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] solMaze[i];
    }
    delete[] maze;
    delete[] solMaze;
}

void menu(int* score) {
    int choice;
    cout << "\n\n\n\t\t\t\tWELCOME TO RAT IN A MAZE PROJECT.........\n";
    cout << "\t\t\t\tPRESS 1 to Start....\n";
    cout << "\t\t\t\tPRESS 2 to EXIT....\n";
    cin >> choice;
    switch (choice) {
        case 1:
            system("cls"); // Note: system("cls") is for Windows, you might need a different command for clearing the screen on other platforms.
            start(score);
            break;
        case 2:
            cout << "\n\n\n\n\t\t\t\tEXITING..........\n";
            exit(0);
        default:
            cout << "ERROR!!! PRESS 1 or 2 only......\n";
    }
}

int main() {
    int score = 0;
    menu(&score);
    return 0;
}
