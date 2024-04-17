#pragma once
#include <iostream>
using namespace std;

struct Node {
    int col;
    int value;
    Node* next;

    Node(int c, int v) : col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int rows, cols;
    Node** matrix; 

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        matrix = new Node * [rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = nullptr;
        }
    }

    void addElement(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            Node* newNode = new Node(col, value);
            newNode->next = matrix[row];
            matrix[row] = newNode;
        }
        else {
            cout << "Invalid row or column indices." << endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << getElement(i, j) << " ";
                }
            cout << "; ";
            }
            cout << endl;
        }
    


    int getElement(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            Node* current = matrix[row];
            while (current != nullptr) {
                if (current->col == col) {
                    return current->value;
                }
                current = current->next;
            }
        }
        return 0;
    }

    void scalarMultiply(int scalar) {
        for (int i = 0; i < rows; ++i) {
            Node* current = matrix[i];
            while (current != nullptr) {
                current->value *= scalar;
                current = current->next;
            }
        }
    }

    void scalarAdd(int scalar) {
        for (int i = 0; i < rows; ++i) {
            Node* current = matrix[i];
            while (current != nullptr) {
                current->value += scalar;
                current = current->next;
            }
        }
    }

    Node* findElementByValue(int targetValue) {
        for (int i = 0; i < rows; ++i) {
            Node* current = matrix[i];
            while (current != nullptr) {
                if (current->value == targetValue) {
                    return current; // Повертаємо вказівник на знайдений елемент
                }
                current = current->next;
            }
        }
        return nullptr; // Повертаємо nullptr, якщо елемент не знайдено
    }


    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    ~SparseMatrix() {
        for (int i = 0; i < rows; ++i) {
            Node* current = matrix[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] matrix;
    }
};

