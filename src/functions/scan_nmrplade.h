#ifndef SCAN_NMRPLADE_H
#define SCAN_NMRPLADE_H
#include <stdio.h>
#include <string.h>
int line_exists(FILE *file, const char *input);

void write_to_file(FILE *file, const char *input, int præferenceHandicap, int præferenceEl, int valg);

void print_file_content(const char *filename);
#endif //SCAN_NMRPLADE_H
