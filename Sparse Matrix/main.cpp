#include <iostream>
#include "sparse_matrix.h"
using namespace std;
int main() {
    SparseMatrix matrix(3, 3);
    matrix.addElement(0, 1, 1);
    matrix.addElement(0, 2, 2);
    matrix.addElement(1, 1, 3);
    matrix.addElement(2, 0, 4);
    matrix.addElement(2, 2, 5);

    int targetValue = 3;
    Node* foundElement = matrix.findElementByValue(targetValue); // Викликаємо метод
    if (foundElement != nullptr) {
        cout << "Element with value " << targetValue << " found at row: " << foundElement->col << ", col: " << foundElement->value << endl;
    }
    else {
        cout << "Element with value " << targetValue << " not found." << endl;
    }

    cout << "Sparse Matrix:" << endl;
    matrix.display();


    int element = matrix.getElement(1, 1);
    cout << "Element at row 1, column 1: " << element << endl;

    matrix.scalarMultiply(2);
    cout << "Sparse Matrix after scalar multiplication:" << endl;
    matrix.display();

    matrix.scalarAdd(3);
    cout << "Sparse Matrix after scalar addition:" << endl;
    matrix.display();

    int numRows = matrix.getRows();
    int numCols = matrix.getCols();
    cout << "Number of rows: " << numRows << ", Number of columns: " << numCols << endl;

   
    return 0;
}

