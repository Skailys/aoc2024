#include <stdio.h>
#include <stdlib.h>

// 3   4
// 4   3
// 2   5
// 1   3
// 3   9
// 3   3

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int sum_diff(int firstlist[], int secondlist[], int n) {
    qsort(firstlist, n, sizeof(int), compare);
    qsort(secondlist, n, sizeof(int), compare);

    if (sizeof(firstlist) != sizeof(secondlist)) {
        printf("Error: The lists are not the same size\n");
        return 1;
    }

    int sum = 0;
    n = 0;
    while (n < sizeof(firstlist) / sizeof(firstlist[0])) {
        if (firstlist[n] > secondlist[n]) {
            sum += firstlist[n] - secondlist[n];
        } else {
            sum += secondlist[n] - firstlist[n];
        }
        n++;
    }
    
    return sum;
}

int count_occurrences(int list[], int value, int size) {
    int count = 0;
    int n = 0;
    while (n < size) {
        if (list[n] == value) {
            count++;
        }
        n++;
    }

    return count;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    int *firstlist = malloc(1000 * sizeof(int));
    int *secondlist = malloc(1000 * sizeof(int));
    int a, b, size;
    size = 0;

    while (fscanf(file, "%d %d", &a, &b) != EOF)
    {
        firstlist[size] = a;
        secondlist[size] = b;
        size++;
    }

    printf("n = %d\n", size);

    firstlist = realloc(firstlist, size * sizeof(int));
    secondlist = realloc(secondlist, size * sizeof(int));
    if (firstlist == NULL || secondlist == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }
    
    int sum = 0;
    int n = 0;
    while (n < size) {
        sum += firstlist[n] * count_occurrences(secondlist, firstlist[n], size);
        n++;
    }
    
    
    printf("The score is %d\n", sum);
    return 0;
}