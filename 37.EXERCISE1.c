#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char fline[100];
    char *newline;
    int i, count = 0, occ = 0;

    fp = fopen(argv[1], "r");
    while (fgets(fline, 100, fp) != NULL) {
        count++;
        if (newline = strchr(fline, '\\n'))
            *newline = '\\0';
        if (strstr(fline, argv[2]) != NULL) {
            printf("%s %d %s", argv[1], count, fline);
            occ++;
        }
    }
    printf("\\n Occurence= %d", occ);
    return 0;
}
