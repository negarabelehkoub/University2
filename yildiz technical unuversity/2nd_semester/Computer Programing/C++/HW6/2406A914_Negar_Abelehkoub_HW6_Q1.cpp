#include <stdio.h>
#include <limits.h>

// Function to reverse the array
void reverseArray(int arr[], int n) {
    int i, temp;

    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("The reversed array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to find the second maximum element
int findSecondMax(const int arr[], int n) {
    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return second;
}

// Function to merge two sorted arrays
void mergeSortedArrays(const int A[], int m, const int B[], int n, int C[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < m)
        C[k++] = A[i++];
    while (j < n)
        C[k++] = B[j++];
}

int main() {
    int choice;

    do {
        printf("1- Reverse Array\n");
        printf("2- Find Second Max\n");
        printf("3- Merge Sorted Arrays\n");
        printf("4- Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int n, i;
            printf("Enter the number of elements:\n");
            scanf("%d", &n);
            int arr[n];
            printf("Enter the elements:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            reverseArray(arr, n);

        } else if (choice == 2) {
            int n;
            printf("Enter the number of elements:\n");
            scanf("%d", &n);
            int arr[n];
            printf("Enter the elements:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            int secondMax = findSecondMax(arr, n);
            printf("Second max: %d\n", secondMax);

        } else if (choice == 3) {
            int m, n;
            printf("Enter the size of the first array:\n");
            scanf("%d", &m);
            int A[m];
            printf("Enter the elements of the first sorted array:\n");
            for (int i = 0; i < m; i++) {
                scanf("%d", &A[i]);
            }

            printf("Enter the size of the second array:\n");
            scanf("%d", &n);
            int B[n];
            printf("Enter the elements of the second sorted array:\n");
            for (int i = 0; i < n; i++) {
                scanf("%d", &B[i]);
            }

            int C[m + n];
            mergeSortedArrays(A, m, B, n, C);

            printf("Merged array:\n");
            for (int i = 0; i < m + n; i++) {
                printf("%d ", C[i]);
            }
            printf("\n");

        } else if (choice == 4) {
            printf("Program terminated.\n");
        } else {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
