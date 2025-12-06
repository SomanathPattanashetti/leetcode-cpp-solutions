// Leetcode Problem: 912. Sort an Array
// Link: https://leetcode.com/problems/sort-an-array/
// Difficulty: Medium
// Tags: Array, Divide & Conquer, Sorting, Merge Sort

// ✅ Approach (Merge Sort):
// We use the classic MERGE SORT algorithm (Divide and Conquer).
//
// Steps:
//
// 1️⃣ Divide:
//     - Recursively split the array into two halves:
//          left  = start → mid
//          right = mid+1 → end
//
// 2️⃣ Conquer:
//     - Recursively sort both halves using mergeSort().
//
// 3️⃣ Merge:
//     - Combine the two sorted halves into a temporary array.
//     - Use two pointers (i and j) to compare elements from both halves.
//     - Copy the smaller element into temp.
//     - When one half finishes, copy the remaining elements of the other half.
//     - Finally, write temp[] back into the original array (arr[start..end]).
//
// ✔ Merge Sort has guaranteed O(n log n) time complexity.
// ✔ Stable sort: keeps relative order of equal elements.
// ✔ Uses extra space O(n) for merging.

class Solution {
public:

    // Function to merge two sorted halves of arr[]
    void merge(vector<int>& arr, int start, int mid, int end) {

        int i = start;       // Pointer for left half
        int j = mid + 1;     // Pointer for right half
        vector<int> temp;    // Temporary array to store merged output

        // 🔹 Merge the two sorted halves
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // 🔹 Copy remaining elements from left half (if any)
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // 🔹 Copy remaining elements from right half (if any)
        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        // 🔹 Copy merged result back into original array
        for (int k = 0; k < temp.size(); k++) {
            arr[start + k] = temp[k];
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int start, int end) {
        if (start < end) {

            // Middle index for dividing the array
            int mid = start + (end - start) / 2;

            // Sort left half
            mergeSort(arr, start, mid);

            // Sort right half
            mergeSort(arr, mid + 1, end);

            // Merge the sorted halves
            merge(arr, start, mid, end);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);   // Sort the entire array

        return nums;   // Return sorted array
    }
};
