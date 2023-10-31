#include <stdio.h>

struct Student {
    char name[20];
    int regno;
};

int main(){
    printf("Enter no. of students: ");
    int n;
    scanf("%d", &n);
    struct Student s[n];
    for(int i=0; i<n; i++){
        printf("\nStudent %d\n", i+1);
        printf("Enter name: ");
        scanf("%s", &s[i].name);
        printf("\nEnter regno: ");
        scanf("%d", &s[i].regno);
    }

    printf("\nRecords: \n");
    for(int i=0; i<n; i++){
        printf("\nStudent %d\n", i+1);
        printf("Name: %s\n", s[i].name);
        printf("Reg no: %d\n\n", s[i].regno);
    }

    return 0;
}