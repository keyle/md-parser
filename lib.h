#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct token {
    int pos;
    char* str;
} token_t;

typedef struct obj {
    char name[20];
    char before1;
    char before2;
    char start;
    char end;
} obj_t;

long size_of_file(FILE* fp) {
    fseek(fp, 0, SEEK_END);
    int sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return sz;
}

void parse(char* str) {
    obj_t header = {.name = "h1",
                    .before1 = '\n',
                    .before2 = '\n',
                    .start = '#',
                    .end = '\n'};
    size_t textlen = strlen(str);
    char c, pc, ppc;
    size_t i = 0;
    while (i <= textlen) {
        if (i >= 2) ppc = pc;
        if (i >= 1) pc = c;
        c = str[i];
        printf("%c", c);
        if (c == header.start) {
            // could be a header
            if (header.before1 == pc && header.before2 == ppc) {
                printf("found header: "); // comment
            }
        }
        i++;
    }
    printf("len of content: %lu\n", strlen(str));
}

// char** split_str(char* contents, char* splitter) {
//     char* line = strtok(contents, splitter);
//     while (line != NULL) {
//         printf("> %s\n", line);
//         line = strtok(NULL, splitter);
//     }
// }

char* get_file_contents(FILE* fp) {
    char c;
    long sz = size_of_file(fp);
    char* m = calloc(sz + 1, sizeof(char)); // ignore error
    while ((c = fgetc(fp)) != EOF) { strncat(m, &c, 1); }
    return m;
}

#endif
