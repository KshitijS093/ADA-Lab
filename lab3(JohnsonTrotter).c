#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the permutation
void printPermutation(int permutation[], int direction[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", permutation[i]);
    }
    printf("\n");
}

// Function to generate permutations using the Johnson-Trotter algorithm
void generatePermutations(int n) {
    int permutation[MAX_N];
    int direction[MAX_N];
    bool mobile[MAX_N];

    // Initialize the permutation, direction, and mobile arrays
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        direction[i] = -1;
        mobile[i] = true;
    }

    printPermutation(permutation, direction, n);

    int mobileElement, mobileIndex, temp;

    while (true) {
        mobileElement = -1;
        mobileIndex = -1;

        // Find the largest mobile element
        for (int i = 0; i < n; i++) {
            if (direction[i] == -1 && i > 0 && permutation[i] > permutation[i - 1] && mobile[i]) {
                if (mobileElement == -1 || permutation[i] > mobileElement) {
                    mobileElement = permutation[i];
                    mobileIndex = i;
                }
            }
            if (direction[i] == 1 && i < n - 1 && permutation[i] > permutation[i + 1] && mobile[i]) {
                if (mobileElement == -1 || permutation[i] > mobileElement) {
                    mobileElement = permutation[i];
                    mobileIndex = i;
                }
            }
        }

        // If no mobile element is found, the algorithm terminates
        if (mobileIndex == -1) {
            break;
        }

        // Swap the mobile element with the adjacent element in the direction it is moving
        if (direction[mobileIndex] == -1) {
            swap(&permutation[mobileIndex], &permutation[mobileIndex - 1]);
            swap(&direction[mobileIndex], &direction[mobileIndex - 1]);
        } else {
            swap(&permutation[mobileIndex], &permutation[mobileIndex + 1]);
            swap(&direction[mobileIndex], &direction[mobileIndex + 1]);
        }

        // Reverse the direction of all elements greater than the mobile element
        for (int i = 0; i < n; i++) {
            if (permutation[i] > mobileElement) {
                direction[i] *= -1;
            }
        }

        printPermutation(permutation, direction, n);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_N) {
        printf("Invalid input!\n");
        return 0;
    }

    generatePermutations(n);

    return 0;
}