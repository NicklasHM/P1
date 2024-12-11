#include "scan_nmrplade.h"
#include <stdio.h>
#include <string.h>

int line_exists(FILE *file, const char *input) {
    char line[256];
    rewind(file);
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\r\n")] = 0; // Remove newline and carriage return
        if (strncmp(line, input, strlen(input)) == 0 &&
            (line[strlen(input)] == ' ' || line[strlen(input)] == '\0')) {
            strncpy(input, line, 256);
            return 1; // Line exists
            }
    }
    return 0; // Linjen eksisterer ikke
}

void write_to_file(FILE *file, const char *input, int præferenceHandicap, int præferenceEl, int præferenceKriterium) {
    if (input == NULL || input[0] == '\0') {
        return;  // Do nothing if the input is empty or just a newline
    }
    if (line_exists(file, input)) {
        printf("The numberplate '%s' is already registered.\n", input);
    } else {
        fprintf(file, "%s %d %d %d \n", input, præferenceHandicap, præferenceEl, præferenceKriterium);

        fflush(file);
    }
}

void print_file_content(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'!\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Udskriver hver linje
    }

    fclose(file);
}