#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void insertFirstElement(vector<int>& arr) 
{
    if (arr.size() <= 1) 
    {
        return; // Нічого не робимо, якщо масив порожній або з одного елемента
    }

    int firstElement = arr[0];
    int position = 0;

    // Знаходимо позицію для вставки першого елемента
    while (position < arr.size() - 1 && firstElement > arr[position + 1]) 
    {
        position++;
    }

    // Зрушуємо елементи для звільнення місця для вставки
    for (int i = 0; i < position; i++) 
    {
        arr[i] = arr[i + 1];
    }

    // Вставляємо перший елемент на знайдену позицію
    arr[position] = firstElement;
}

int array_87() 
{
    string inputFileName, outputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    // Відкриваємо вхідний файл
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) 
    {
        cerr << "Input file opening error!" << endl;
        return 1;
    }

    // Читаємо розмір масиву
    int n;
    inputFile >> n;

    // Перевіряємо коректність розміру масиву
    if (n <= 0) 
    {
        cerr << "Incorrect array size!" << endl;
        inputFile.close();
        return 1;
    }

    // Читаємо елементи масиву
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        if (!(inputFile >> arr[i])) 
        {
            cerr << "Error reading array element!" << endl;
            inputFile.close();
            return 1;
        }
    }
    inputFile.close();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортуемo масив
    insertFirstElement(arr);

    cout << "Ordered array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Відкриваємо вихідний файл
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) 
    {
        cerr << "Error opening the output file!" << endl;
        return 1;
    }

    // Записуємо результат у вихідний файл
    outputFile << n << endl; // Записуємо розмір масиву
    for (int i = 0; i < n; i++) 
    {
        outputFile << arr[i];
        if (i < n - 1) 
        {
            outputFile << " "; // Додаємо пробіл між елементами 
        }
    }
    outputFile << endl;
    outputFile.close();

    cout << "The result was successfully written to the file " << outputFileName << endl;

    return 0;
}
