//Alphanzo Moore
//CIS-5 Online
//October 7, 2023
//Assignment 10C: Rainfall Statistics

#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 12; // Constant for the number of months

// Function prototypes
double getTotal(double[], int);
double getAverage(double[], int);
double getLargest(double[], int, int&);
double getSmallest(double[], int, int&);

int main() {
    // Array to hold the rainfall data
    double rainfall[MONTHS];

    // Get the rainfall for each month.
    for (int i = 0; i < MONTHS; i++) {
        cout << "Enter the rainfall for month " << i + 1 << ": ";
        cin >> rainfall[i];

        // Validate the value entered.
        while (rainfall[i] < 0) {
            cout << "Rainfall cannot be negative. Enter the rainfall for month " << i + 1 << ": ";
            cin >> rainfall[i];
        }
    }

    // Calculate and display the total rainfall for the year
    double total = getTotal(rainfall, MONTHS);
    cout << "Total rainfall for the year: " << total << " inches" << endl;

    // Calculate and display the average monthly rainfall
    double average = getAverage(rainfall, MONTHS);
    cout << "Average monthly rainfall: " << average << " inches" << endl;

    // Find and display the month with the highest amount of rainfall
    int highestMonth;
    double highest = getLargest(rainfall, MONTHS, highestMonth);
    cout << "Month with the highest rainfall: Month " << highestMonth + 1 << " (" << highest << " inches)" << endl;

    // Find and display the month with the lowest amount of rainfall
    int lowestMonth;
    double lowest = getSmallest(rainfall, MONTHS, lowestMonth);
    cout << "Month with the lowest rainfall: Month " << lowestMonth + 1 << " (" << lowest << " inches)" << endl;

    return 0;
}

// Function to calculate the total rainfall
double getTotal(double arr[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate the average monthly rainfall
double getAverage(double arr[], int size) {
    return getTotal(arr, size) / size;
}

// Function to find the largest amount of rainfall and its month
double getLargest(double arr[], int size, int &index) {
    double largest = arr[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
            index = i;
        }
    }
    return largest;
}

// Function to find the smallest amount of rainfall and its month
double getSmallest(double arr[], int size, int &index) {
    double smallest = arr[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            index = i;
        }
    }
    return smallest;
}
