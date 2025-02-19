class Solution {
public:
void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int r = mid + 1;
        int ct = 0;

        for (int i = low; i <= mid; i++) {
            while (r <= high && (long long)arr[i] > 2 * (long long)arr[r]) {
                r++;
            }
            ct += (r - (mid + 1));
        }

        return ct;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int ct = 0;
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        ct += mergeSort(arr, low, mid);
        ct += mergeSort(arr, mid + 1, high);
        ct += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return ct;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};