#include <iostream>
using namespace std;

double find_total(double arr[], int SIZE);

void normalize();

void metrics();

int main() {
    int choice = 0;
    cout << "Choose function (1 for normalization, 2 for metric importance): ";
    cin >> choice;
    if (choice == 1) {
        normalize();
    } else if (choice == 2) {
        metrics();
    }
}

void normalize() {
    int SIZE = 0;
    cout << "Enter number of requirements: ";
    cin >> SIZE;
    double arr[SIZE];

    cout << "Enter " << SIZE << " array elements: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    int total = find_total(arr, SIZE);

    cout << "Normalizations: " << endl;
    for (int i = 0; i < SIZE; i++) {
        double percent = arr[i] / total * 100;
        cout << percent << endl;
    }
}

void metrics() {
    int SIZE_COL = 0; // number of columns (S_n values)
    int SIZE_ROW = 0; // number of rows (values you multiply)

    cout << "Enter number of requirements: ";
    cin >> SIZE_ROW;
    cout << "Enter number of specifications: ";
    cin >> SIZE_COL;

    double who_what[SIZE_ROW];
    double arr[SIZE_COL];

    cout << "Enter " << SIZE_ROW << " who_what values: ";
    for (int i = 0; i < SIZE_ROW; i++) {
        cin >> who_what[i];
    }

    for (int j = 0; j < SIZE_COL; j++) {
        double sum = 0;
        cout << "Enter " << SIZE_ROW << " how_what values for column " << j + 1 << ": ";

        for (int k = 0; k < SIZE_ROW; k++) {
            double val;
            cin >> val;
            sum += val * who_what[k];
        }
        arr[j] = sum;
    }

    double total = find_total(arr, SIZE_COL);

    cout << "Metrics (percentages): " << endl;
    for (int i = 0; i < SIZE_COL; i++) {
        double percent = arr[i] / total * 100;
        cout << percent << endl;
    }
}

double find_total(double arr[], int SIZE) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    cout << "Total: "<< sum << endl;
    return sum;
}