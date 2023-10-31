#include <stdio.h>

struct Student {
    char name[20];
    int regno;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    struct Student *p;

    for (int i = 0; i < n; i++) {
        p = &s[i];
        printf("\nStudent %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", p->name);
        printf("Enter regno: ");
        scanf("%d", &p->regno);
    }

    for (int i = 0; i < n; i++) {
        p = &s[i];
        printf("\nRecords of Student %d:\n", i + 1);
        printf("Name: %s\nRegNo: %d\n", p->name, p->regno);
    }

    return 0;
}
