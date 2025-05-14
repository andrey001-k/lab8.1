#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Функція для перевірки містить стовпець лише непарні числа
bool containsOnlyOdd(const vector<vector<int>>& matrix, int colNum)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        // Якщо число парне (ділиться на 2 без залишку) 
        if (matrix[i][colNum] % 2 == 0)
        {
            return false; // Стовпець містить парне число 
        }
    }
    return true; // Усі числа непарні
}

// Функція для пошуку першого стовпця з непарними числами
int findFirstOddColumn(const vector<vector<int>>& matrix)
{
    int m = matrix.size();
    if (m == 0) return 0; // Порожня матриця 

    int n = matrix[0].size();

    for (int j = 0; j < n; j++)
    {
        if (containsOnlyOdd(matrix, j))
        {
            return j + 1; // Повертаємо номер стовпця (нумерація з 1) 
        }
    }

    return 0; // Стовпців тільки з непарними числами немає
}

int matrix_35() 
{
    string fileName;
    cout << "Введите имя файла: ";
    cin >> fileName;

    // Відкриваємо файл для читання
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    // Зчитуємо розміри матриці
    int m, n;
    inputFile >> m >> n;

    // Перевіряємо коректність розмірів
    if (m <= 0 || n <= 0)
    {
        cerr << "Incorrect matrix dimensions!" << endl;
        inputFile.close();
        return 1;
    }

    // Зчитуємо матрицю
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (!(inputFile >> matrix[i][j])) 
            {
                cerr << "Error reading matrix element!" << endl;
                inputFile.close();
                return 1;
            }
        }
    }

    // Закриваємо файл після читання
    inputFile.close();

    // Виводимо матрицю для перевірки
    cout << "Read matrix:" << endl;
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Знаходимо номер першого стовпця лише з непарними числами
    int result = findFirstOddColumn(matrix);

    // Виводимо результат на екран
    if (result > 0)
    {
        cout << "First column number with only odd numbers: " << result << endl;
    }
    else
    {
        cout << "There are no columns with only odd numbers (0)" << endl;
    }

    // Відкриваємо файл для доповнення (append)
    ofstream outputFile(fileName, ios::app);
    if (!outputFile.is_open()) 
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Записуємо результат у кінець файлу
    outputFile << "\nNumber of the first column with only odd numbers: " << result << endl;

    // Закриваємо файл
    outputFile.close();

    cout << "The result has been successfully added to the file " << fileName << endl;

    return 0;
}
