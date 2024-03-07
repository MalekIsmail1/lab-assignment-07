#include <stdio.h>

void bubbleSort(int arr[], int n, int* totalSwaps) {
    int i, j;
    *totalSwaps = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Increment total swaps
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int* totalSwaps) {
    int i, j;
    *totalSwaps = 0;

    for (i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            // Increment total swaps
            (*totalSwaps)++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int totalSwaps1, totalSwaps2;

    // Bubble Sort on array1
    bubbleSort(array1, n1, &totalSwaps1);

    printf("Bubble Sort on array1:\n");
    printf("Individual swaps per element: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", i == 0 ? 0 : totalSwaps1);
    }
    printf("\nTotal swaps: %d\n", totalSwaps1);

    // Selection Sort on array2
    selectionSort(array2, n2, &totalSwaps2);

    printf("\nSelection Sort on array2:\n");
    printf("Individual swaps per element: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", i == 0 ? 0 : totalSwaps2);
    }
    printf("\nTotal swaps: %d\n", totalSwaps2);

    return 0;
}
