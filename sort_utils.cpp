#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Функція для бінарного пошуку позиції для вставки елемента
int binarySearch(const vector<int>& arr, int item, int low, int high)
{
    // Якщо верхня межа менша від нижньої, значить місце для вставки знайдено 
    if (high <= low)
    {
        return (item > arr[low]) ? (low + 1) : low;
    }

    // Знаходимо середину діапазону 
    int mid = (low + high) / 2;

    // Якщо елемент дорівнює середньому, вставляємо після нього 
    if (item == arr[mid])
    {
        return mid + 1;
    }

    // Якщо елемент більше середнього, шукаємо у правій частині 
    if (item > arr[mid])
    {
        return binarySearch(arr, item, mid + 1, high);
    }

    // Інакше шукаємо у лівій частині 
    return binarySearch(arr, item, low, mid - 1);
}

// Функція сортування вставками з бінарним пошуком
void binaryInsertionSort(vector<int>& arr)
{
    int n = arr.size();

    // Проходимо по всіх елементах, починаючи з другого 
    for (int i = 1; i < n; i++)
    {
        // Запам'ятовуємо поточний елемент 
        int key = arr[i];
        int j = i - 1;

        // Знаходимо позицію для вставки за допомогою бінарного пошуку 
        int loc = binarySearch(arr, key, 0, j);

        // Зрушуємо всі елементи праворуч від позиції вставки 
        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Вставляємо елемент на знайдену позицію 
        arr[loc] = key;
    }
}

// Функція демонстрації роботи алгоритму з прикладу
void demonstrateAlgorithm(vector<int>& arr)
{
    cout << "Demonstration of insertion sort with binary serch:" << endl;
    cout << "Initial array:";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Покрокова демонстрація алгоритму 
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        cout << "Step " << i << ":" << endl;
        cout << " Current element: " << arr[i] << endl;

        // Зберігаємо поточний елемент 
        int key = arr[i];
        int j = i - 1;

        // Знаходимо позицію для вставки 
        int loc = binarySearch(arr, key, 0, j);
        cout << " Position for insertion (found by binary search): " << loc << endl;

        // Показуємо зсув елементів 
        if (loc < i)
        {
            cout << "Move elements:";
            for (int k = loc; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }

        // Зрушуємо елементи вправо 
        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Вставляємо елемент 
        arr[loc] = key;

        // Показуємо поточний стан масиву 
        cout << "Array after step " << i << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl << endl;
    }
}

int sort_12()
{
    string inputFileName, outputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;
    cout << "Enter the output file name: ";
    cin >> outputFileName;

    /// Відкриваємо вхідний файл
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

    // Якщо в масиві 7 елементів, демонструємо роботу алгоритму 
    if (n == 7)
    {
        demonstrateAlgorithm(arr);
    }
    else
    {
        // Інакше просто сортуємо 
        cout << "Original array: ";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;

        binaryInsertionSort(arr);
    }

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
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

    cout << "\nThe result was successfully written to the file " << outputFileName << endl;

    return 0;
}
