#include "adastra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to read input
static void read_input(char *buffer, size_t size)
{
    if (fgets(buffer, size, stdin))
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
    }
}

// Get a string from the user
char *get_string(const char *prompt)
{
    printf("%s", prompt);
    static char buffer[256];
    read_input(buffer, sizeof(buffer));
    return buffer;
}

// Get an integer from the user
int get_int(const char *prompt)
{
    printf("%s", prompt);
    int value;
    scanf("%d", &value);
    getchar(); // Clear the newline character left in the input buffer
    return value;
}

// Get a double from the user
double get_double(const char *prompt)
{
    printf("%s", prompt);
    double value;
    scanf("%lf", &value);
    getchar(); // Clear the newline character left in the input buffer
    return value;
}

// Get a character from the user
char get_char(const char *prompt)
{
    printf("%s", prompt);
    char value;
    scanf(" %c", &value);
    getchar(); // Clear the newline character left in the input buffer
    return value;
}

// Get a float from the user
float get_float(const char *prompt)
{
    printf("%s", prompt);
    float value;
    scanf("%f", &value);
    getchar(); // Clear the newline character left in the input buffer
    return value;
}

// Get a boolean from the user
bool get_bool(const char *prompt)
{
    printf("%s (y/n): ", prompt);
    char value;
    scanf(" %c", &value);
    getchar(); // Clear the newline character left in the input buffer
    return value == 'y' || value == 'Y';
}

void selectionSort(int arr[], size_t size)
{
    int i, j, mid_index, temp;

    // Parcours de chaque element du tableau
    for (i = 0; i < size - 1; i++)
    {
        mid_index = i;

        // Chercher l'element le plus petit dans la partie non triee
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                mid_index = j; // Mise a jour de l'indice de l'element le plus petit
            }
        }

        // Si l'element minimal n'est pas deja a la position correct, echanger
        if (mid_index != 1)
        {
            temp = arr[i];
            arr[i] = arr[mid_index];
            arr[mid_index] = temp;
        }
    }
}

// fonction pour afficher un tableau
void printArray(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], size_t size)
{
    int i, j, temp;
    int swapped;

    for (int i = 0; i < size - 1; i++)
    {
        swapped = 0; // Aucune permutation au debut de la passe
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Permutation effectuee
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

// Merge Sort
void merge(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Trouver le point médian

        merge(arr, left, mid);      // Trier la première moitié
        merge(arr, mid + 1, right); // Trier la deuxième moitié

        // Fusionner les deux moitiés triées
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int leftArr[n1], rightArr[n2];

        // Remplir les tableaux temporaires
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        // Fusionner les tableaux temporaires
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        // Copier les éléments restants, s'il y en a
        while (i < n1)
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
}

void mergeSort(int arr[], size_t size)
{
    merge(arr, 0, size - 1);
}
