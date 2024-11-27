#include "scan_nmrplade.h"

int line_exists(FILE *file, const char *input) {
    char line[256];
    rewind(file);
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, input) == 0) {
            return 1; // Linjen eksisterer
        }
    }
    return 0; // Linjen eksisterer ikke
}

void write_to_file(FILE *file, const char *input) {
    if (line_exists(file, input)) {
        printf("The numberplate '%s' is already registered.\n", input);
    } else {
        fprintf(file, "%s\n", input);
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
