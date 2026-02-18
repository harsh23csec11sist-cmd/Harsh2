#include <stdio.h>

/**
 * Removes duplicates from a sorted integer array in-place.
 * 
 * @param nums The sorted array of integers.
 * @param numsSize The number of elements in the array.
 * @return The new length of the array after removing duplicates.
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int i = 0; // index of the last unique element found
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;                // move to the next position for a unique element
            nums[i] = nums[j];  // store the new unique element
        }
    }
    return i + 1;
}

/**
 * Prints the first k elements of an integer array.
 * If k == 0, it prints "[]" without accessing the array pointer.
 */
void printArray(int* nums, int k) {
    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%d", nums[i]);
        if (i < k - 1) printf(", ");
    }
    printf("]");
}

int main() {
    // Test case 1: Typical case with duplicates
    int nums1[] = {1, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = removeDuplicates(nums1, size1);
    printf("Test 1: ");
    printArray(nums1, k1);
    printf(" (length = %d)\n", k1);
    
    // Test case 2: Larger example
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = removeDuplicates(nums2, size2);
    printf("Test 2: ");
    printArray(nums2, k2);
    printf(" (length = %d)\n", k2);
    
    // Test case 3: Single element
    int nums3[] = {7};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int k3 = removeDuplicates(nums3, size3);
    printf("Test 3: ");
    printArray(nums3, k3);
    printf(" (length = %d)\n", k3);
    
    // Test case 4: All duplicates
    int nums4[] = {5, 5, 5, 5};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    int k4 = removeDuplicates(nums4, size4);
    printf("Test 4: ");
    printArray(nums4, k4);
    printf(" (length = %d)\n", k4);
    
    // Test case 5: Empty array (standard‑compliant way)
    int *nums5 = NULL;   // pointer to nowhere – we won't dereference it
    int size5 = 0;       // explicit size 0
    int k5 = removeDuplicates(nums5, size5);
    printf("Test 5: ");
    printArray(nums5, k5);   // k5 == 0 → prints "[]" safely
    printf(" (length = %d)\n", k5);
    
    return 0;
}