#include <iostream>


void removeColumn(int**& matrix, int& numRows, int& numCols, int columnIndex) {
    if (matrix == nullptr || numRows <= 0 || numCols <= 0 || columnIndex < 0 || columnIndex >= numCols) {
        
        std::cout << "Ќев≥рн≥ вх≥дн≥ дан≥." << std::endl;
        return;
    }

    
    int** newMatrix = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        newMatrix[i] = new int[numCols - 1];
    }

    for (int i = 0; i < numRows; ++i) {
        int colCount = 0;

        for (int j = 0; j < numCols; ++j) {
            if (j != columnIndex) {
                newMatrix[i][colCount] = matrix[i][j];
                colCount++;
            }
        }
    }

    
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = newMatrix;
    numCols--; 
}

int main() {
    system("chcp 1251");
    system("cls");
    int numRows, numCols;
    std::cout << "¬вед≥ть к≥льк≥сть р€дк≥в: ";
    std::cin >> numRows;
    std::cout << "¬вед≥ть к≥льк≥сть стовпц≥в: ";
    std::cin >> numCols;

    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        matrix[i] = new int[numCols];
    }

    
    std::cout << "¬веденн€ даних у матрицю:" << std::endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << "matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    int columnIndexToRemove;
    std::cout << "¬вед≥ть номер стовпц€ дл€ видаленн€ (рахунок починаЇтьс€ з 0): ";
    std::cin >> columnIndexToRemove;

    removeColumn(matrix, numRows, numCols, columnIndexToRemove);

    
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

