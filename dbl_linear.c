#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static bool contains(const int *sequence, int size, int value)
{
    for (int i = 0; i < size; i++) {
        if (sequence[i] == value) {
            return true;
        }
    }
    return false;
}

static void insert_sorted(int *sequence, int *size, int value)
{
    if (contains(sequence, *size, value)) {
        return;
    }

    int i = *size - 1;
    while (i >= 0 && sequence[i] > value) {
        sequence[i + 1] = sequence[i];
        i--;
    }
    sequence[i + 1] = value;
    (*size)++;
}

int dbl_linear(int n)
{
    if (n < 0) {
        fprintf(stderr, "Error: Negative index is not allowed\n");
        return -1;
    }

    // Initial buffer size (n + some margin to avoid reallocations)
    const int initial_size = n + 1000;
    int *sequence = malloc(initial_size * sizeof(int));
    if (sequence == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -1;
    }

    sequence[0] = 1;
    int current_size = 1;

    for (int i = 0; current_size <= n; i++) {
        int x = 2 * sequence[i] + 1;
        int y = 3 * sequence[i] + 1;

        insert_sorted(sequence, &current_size, x);
        insert_sorted(sequence, &current_size, y);

        // Check if we need to expand the array
        if (current_size >= initial_size - 2) {
            fprintf(stderr, "Error: Buffer overflow\n");
            free(sequence);
            return -1;
        }
    }

    int result = sequence[n];
    free(sequence);
    return result;
}

int main(void)
{
    const int test_value = 9;
    int result = dbl_linear(test_value);
    
    if (result != -1) {
        printf("U(%d) = %d\n", test_value, result);
    } else {
        fprintf(stderr, "Failed to compute U(%d)\n", test_value);
    }
    
    return result == -1 ? EXIT_FAILURE : EXIT_SUCCESS;
}
