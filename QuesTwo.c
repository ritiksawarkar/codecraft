#include <stdio.h>
#include <stdlib.h>

// Forward declaration of the compare function
int compare(const void* a, const void* b);

void printTriplets(int* nums, int size) {
    // Sort the array
    qsort(nums, size, sizeof(int), compare);
    
    for (int i = 0; i < size - 2; i++) {
        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = size - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                printf("%d, %d, %d\n", nums[i], nums[left], nums[right]);
                
                // Skip duplicates for left pointer
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // Skip duplicates for right pointer
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int nums[] = { -1, 0, 1, 2, -1, -4 };
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Triplets that sum to zero:\n");
    printTriplets(nums, size);

    return 0;
}
