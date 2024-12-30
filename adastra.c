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