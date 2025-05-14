#include <iostream>
#include "array_utils.h"
#include "matrix_utils.h"
#include "sort_utils.h"

using namespace std;
int main()
{
    int choice;

    do
    {
        cout << "\nSelect task:\n"
            << "1. Array87\n"
            << "2. Matrix35\n"
            << "3. Sort12\n"
            << "0. Exit\n"
            << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            array_87();
            break;
        case 2:
            matrix_35();
            break;
        case 3:
            sort_12();
            break;
        case 0:
            cout << "Exit the program.\n";
            break;
        default:
            cout << "Wrong choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
