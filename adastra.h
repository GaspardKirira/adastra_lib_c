#ifndef ADASTRA_H
#define ADASTRA_H

#include <stdbool.h>
#include <stddef.h>

// Function prototypes
char *get_string(const char *prompt);
int get_int(const char *prompt);
double get_double(const char *prompt);
char get_char(const char *prompt);
float get_float(const char *prompt);
bool get_bool(const char *prompt);
void selectionSort(int arr[], size_t size);
void printArray(int arr[], size_t size);
void bubbleSort(int arr[], size_t size);
void merge(int arr[], int left, int right);
void mergeSort(int arr[], size_t size);

#endif // ADASTRA_H
