#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[256];

    printf("Reading file contents:\n");

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "title") != NULL) {
            printf("Found line: %s", line);
        }
    }

    fclose(file);

    return 0;
}
