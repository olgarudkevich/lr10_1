#include <iostream>
#include <iomanip> 

using namespace std;

void inputArray(int arr[], int size);
void printArray(int arr[], int size, const char* title);
void sortArray(int arr[], int size);
long long calculateProductDivisibleBy5(int arr[], int size);

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // Оголошуємо розміри для двох масивів
    const int SIZE1 = 5;
    const int SIZE2 = 7;

    // Оголошуємо два масиви
    int array1[SIZE1];
    int array2[SIZE2];

    // Викликаємо функцію введення для першого масиву
    cout << "--- Введення першого масиву (" << SIZE1 << " елементів) ---" << endl;
    inputArray(array1, SIZE1);

    // Викликаємо функцію введення для другого масиву
    cout << "\n--- Введення другого масиву (" << SIZE2 << " елементів) ---" << endl;
    inputArray(array2, SIZE2);

    cout << "\n";
    printArray(array1, SIZE1, "Масив 1 (початковий):");
    printArray(array2, SIZE2, "Масив 2 (початковий):");

    // Викликаємо функцію обчислення для кожного масиву
    long long product1 = calculateProductDivisibleBy5(array1, SIZE1);
    long long product2 = calculateProductDivisibleBy5(array2, SIZE2);

    cout << "\n--- Результати обчислення (Варіант 12) ---" << endl;
    cout << "Добуток елементів, кратних 5 (Масив 1): " << product1 << endl;
    cout << "Добуток елементів, кратних 5 (Масив 2): " << product2 << endl;

    // Викликаємо функцію сортування для кожного масиву
    sortArray(array1, SIZE1);
    sortArray(array2, SIZE2);

    cout << "\n--- Результати сортування ---" << endl;
    printArray(array1, SIZE1, "Масив 1 (відсортований):");
    printArray(array2, SIZE2, "Масив 2 (відсортований):");

    return 0;
}

// Реалізація функцій

void inputArray(int arr[], int size) {
    cout << "Будь ласка, введіть " << size << " цілих чисел:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Елемент [" << i << "]: ";
        cin >> arr[i];
    }
}

void printArray(int arr[], int size, const char* title) {
    cout << title << endl;
    for (int i = 0; i < size; ++i) {
        cout << setw(5) << arr[i];
    }
    cout << endl;
}

// ТУТ БУЛА ПОМИЛКА (відсутній код). Тепер функція додана:
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

long long calculateProductDivisibleBy5(int arr[], int size) {
    long long product = 1;
    bool found = false;

    for (int i = 0; i < size; ++i) {
        // Перевіряємо, чи ділиться елемент на 5 без остачі
        if (arr[i] % 5 == 0) {
            product *= arr[i];
            found = true;
        }
    }

    if (!found) {
        return 0;
    }
    return product;
}