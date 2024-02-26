#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file;
    char filename[] = "example.txt";
    char buffer[100];
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test file.\n");
    fclose(file);
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
      while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}

