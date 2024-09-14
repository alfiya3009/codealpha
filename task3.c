#include <stdio.h>
#include <math.h>
// by using the formulaA/B Testing in C (Two-Sample t-Test)
// Function to calculate mean
double mean(double data[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate variance
double variance(double data[], int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sum / (n - 1); // Use (n - 1) for sample variance
}

// Function to calculate t-statistic for two independent samples
double t_statistic(double meanA, double meanB, double varA, double varB, int nA, int nB) {
    double pooled_se = sqrt((varA / nA) + (varB / nB)); // Pooled standard error
    return (meanA - meanB) / pooled_se;
}

int main() {
    // Example data: conversion rates for Group A and Group B
    double groupA[] = {0.1, 0.2, 0.15, 0.12, 0.14, 0.18, 0.13, 0.11};
    double groupB[] = {0.3, 0.28, 0.35, 0.25, 0.31, 0.29, 0.32, 0.34};
    
    int nA = sizeof(groupA) / sizeof(groupA[0]);
    int nB = sizeof(groupB) / sizeof(groupB[0]);
    
    // Calculate means
    double meanA = mean(groupA, nA);
    double meanB = mean(groupB, nB);
    
    // Calculate variances
    double varA = variance(groupA, nA, meanA);
    double varB = variance(groupB, nB, meanB);
    
    // Calculate t-statistic
    double t_value = t_statistic(meanA, meanB, varA, varB, nA, nB);
    
    // Output results
    printf("Group A Mean: %.4f\n", meanA);
    printf("Group B Mean: %.4f\n", meanB);
    printf("Group A Variance: %.4f\n", varA);
    printf("Group B Variance: %.4f\n", varB);
    printf("t-statistic: %.4f\n", t_value);
    
    // Compare t_value with a critical value (for 95% confidence, critical value = 2.145 for df ~14)
    double critical_value = 2.145; // for 95% confidence level
    if (fabs(t_value) > critical_value) {
        printf("Result: Reject the null hypothesis. The difference is statistically significant.\n");
    } else {
        printf("Result: Fail to reject the null hypothesis. No significant difference.\n");
    }
    
    return 0;
}
