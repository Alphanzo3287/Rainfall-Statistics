# Lesson plan
  // Rainfall Statistics
  #include<iostream>
  #include <iomanip>
  using namespace std;

  // Constant for the number of months
  const int NUM_MONTHS = 12;

  // Function prototypes
  double getTotal(double [], int);
  double getAverage(double [], int);
  double getLargest(double [], int, int &);
  double getSmallest(double [], int, int &);

  int main()
  {
     // Array to hold the rainfall data
     double rainFall[NUM_MONTHS];

     // Get the rainfall for each month.
     for (int month = 0; month < NUM_MONTHS; month++)
     {
        // Get this month's rainfall.
        cout << "Enter the rainfall (in inches) for month #";
        cout << (month + 1) << ": ";
        cin >> rainFall[month];

        // Validate the value entered.
        while (rainFall[month] < 0)
        {  
           cout << "Rainfall must be 0 or more.\n"
                << "Please re-enter: ";
           cin  >> rainFall[month];
        }
     }

     // Set the numeric output formatting.
     cout << fixed << showpoint << setprecision(2) << endl;

     // Display the total rainfall.
     cout << "The total rainfall for the year is ";
     cout << getTotal(rainFall, NUM_MONTHS)
          << " inches." << endl;

     // Display the average rainfall.
     cout << "The average rainfall for the year is ";
     cout << getAverage(rainFall, NUM_MONTHS)
          << " inches." << endl;

     // Now display the largest & smallest amounts.
     // The subscript variable will be passed by reference
     // the the getLargest and getSmallets functions.
     int subScript;

     // Display the largest amount of rainfall.
     cout << "The largest amount of rainfall was ";
     cout << getLargest(rainFall, NUM_MONTHS, subScript)
          << " inches in month ";
     cout << (subScript + 1) << "." << endl;

     // Display the smallest amount of rainfall.
     cout << "The smallest amount of rainfall was ";
     cout << getSmallest(rainFall, NUM_MONTHS, subScript)
          << " inches in month ";
     cout << (subScript + 1) << "." << endl << endl;

     return 0;
  }

  // ********************************************************
  // The getTotal function calculates and returns the       *
  // total of the values stored in the array parameter.     *
  // The size parameter indicates the number of elements    *
  // in the array.                                          *
  // ********************************************************
  double getTotal(double values[], int size)
  {
     double total = 0.0; // Accumulator

     // Step through the array and add each value
     // to the total variable.
     for (int count = 0; count < size; count++)
        total += values[count];

     return total;
  }

  // ********************************************************
  // The getAverage function returns the average of the     *
  // values in the array parameter. The size parameter      *
  // indicates the number of elements in the array.         *
  // ********************************************************
  double getAverage(double values[], int size)
  {
     // Simpy get the total of the array values
     // and divide by the number of elements.
     double average = getTotal(values, size) / size;

     return average;
  }

  // ********************************************************
  // The getLargest function returns the smallest value in  *
  // the array parameter, and stores the subscript of the   *
  // largest value in the element reference parameter.      *
  // ********************************************************
  double getLargest(double values[], int size, int &element)
  {
     double largest;  // To hold the largest value.

     // Assume element 0 holds the largest value.
     largest = values[0];
     element = 0;

     // Compare the value in largest to all the
     // other values in the array.
     for (int count = 1; count < size; count++)
     {
        if (values[count] > largest)
        {
           largest = values[count];
           element = count;
        }
     }

     return largest;
  }

  // ********************************************************
  // The getSmallest function returns the smallest value in *
  // the array parameter, and stores the subscript of the   *
  // smallest value in the element reference parameter.     *
  // ********************************************************
  double getSmallest(double values[], int size, int &element)
  {
     double smallest;  // To hold the smallest value

     // Assume element 0 holds the smallest value.
     smallest = values[0];
     element = 0;

     // Compare the value in largest to all the
     // other values in the array. 
     for (int count = 1; count < size; count++)
     {
        if (values[count] < smallest)
        {
           smallest = values[count];
           element = count;
        }
     }

     return smallest;
  }
