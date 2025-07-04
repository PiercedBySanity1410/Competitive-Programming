#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to perform bucket sort
template <typename T>
void bucketSort(vector<T>& arr) {
    int n = arr.size();
    if (n == 0) return;

    // Find the minimum and maximum value in the array
    T minVal = *min_element(arr.begin(), arr.end());
    T maxVal = *max_element(arr.begin(), arr.end());
    T range = maxVal - minVal;

    if (range == 0) return; // all elements are equal

    // Use √n buckets
    int bucketCount = sqrt(n);
    if (bucketCount == 0) bucketCount = 1;

    vector<vector<T>> buckets(bucketCount);

    // Put elements into buckets with normalization
    for (T num : arr) {
        int bucketIndex = static_cast<int>(((num - minVal) / range) * (bucketCount - 1));
        buckets[bucketIndex].push_back(num);
    }

    // Sort individual buckets
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr
    int index = 0;
    for (const auto& bucket : buckets) {
        for (const T& num : bucket) {
            arr[index++] = num;
        }
    }
}

int main() {
    // Input array
    vector<double> arr = {10011, 94, 66, 7, 21, 54, 71, 99, 0.79, 0.55, 0.78, 0.76, 0.29, 0.03, 0.12, 0.22, 0.43};

    // Perform bucket sort
    bucketSort(arr);

    // Output sorted array
    cout << "Sorted array: ";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
