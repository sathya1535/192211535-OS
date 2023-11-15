#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100], c;

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }

    printf("Enter contents to write to the file: ");
    while ((c = getchar()) != EOF) {
        fputc(c, fp);
    }

    fclose(fp);

    printf("\nFile saved successfully.\n");

    return 0;
}
