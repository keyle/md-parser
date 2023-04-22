#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "lib.h"

const int LIMIT = 50000;

// char* split(char* str);

int main(void) {
    FILE* fp;
    fp = fopen("file.md", "r");
    if (fp == NULL) {
        printf("file not found or io error\n");
        return 1;
    }

    char* m = get_file_contents(fp);
    parse(m);
    //     char** mc = split_str(m, "\n\n");

    //     printf("%s\n", m);

    fclose(fp);
    return 0;
}

// char* split(char* str) {
//     char* res = calloc(LIMIT, sizeof(char));
//     char* line = strtok(str, "\n");
//     while (line != NULL) {
//         printf("%s\n", line);
//         strcat(res, line);
//         line = strtok(NULL, "\n");
//     }
//     return res;
// }
