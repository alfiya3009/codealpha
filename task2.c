#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate mean
double mean(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the slope (m) and intercept (b) using the least-squares formula
void linear_regression(double x[], double y[], int n, double *m, double *b) {
    double x_mean = mean(x, n);
    double y_mean = mean(y, n);
    
    double numerator = 0.0, denominator = 0.0;
    
    for (int i = 0; i < n; i++) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }
    
    *m = numerator / denominator;
    *b = y_mean - (*m * x_mean);
}

// Function to predict y for a given x
double predict(double x, double m, double b) {
    return m * x + b;
}

int main() {
    // Example dataset: Areas of houses (in square feet) and corresponding prices
    double area[] = {1200, 1500, 1800, 2000, 2200, 2500, 2700, 3000, 3200, 3500};
    double price[] = {200000, 250000, 270000, 300000, 320000, 350000, 370000, 400000, 420000, 450000};
    int n = sizeof(area) / sizeof(area[0]);
    
    double m, b;
    
    // Calculate the slope (m) and intercept (b)
    linear_regression(area, price, n, &m, &b);
    
    printf("Linear Regression Model: Price = %.2f * Area + %.2f\n", m, b);
    
    // Predict price for a house with an area of 2800 sq. ft.
    double area_to_predict = 2800;
    double predicted_price = predict(area_to_predict, m, b);
    
    printf("Predicted price for a house with area %.2f sq. ft.: %.2f\n", area_to_predict, predicted_price);
    
    return 0;
}
