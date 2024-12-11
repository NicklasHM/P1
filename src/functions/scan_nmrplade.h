#ifndef SCAN_NMRPLADE_H
#define SCAN_NMRPLADE_H
#include <stdio.h>
#include <string.h>
// Tjekker om en linje eksisterer i en fil
int line_exists(FILE *file, const char *input);

// Skriver input til filen
void write_to_file(FILE *file, const char *input, int præferenceHandicap, int præferenceEl, int valg);

// Udskriver filens indhold
void print_file_content(const char *filename);
#endif //SCAN_NMRPLADE_H
