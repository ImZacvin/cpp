#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "Zac";
    printf("%s\n", name);

    int i = 0;
    while (name[i] != '\0') {
        printf("Character %d: %c\n", i, name[i]);
        i += 1;
    }
    printf("Manual length: %d\n", i);

    printf("strlen length: %d\n", (int)strlen(name));
}