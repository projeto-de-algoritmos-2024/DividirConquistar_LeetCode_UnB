class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, temp, left, mid) + mergeSort(nums, temp, mid + 1, right);
        count += merge(nums, temp, left, mid, right);
        return count;
    }

    int merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1; 

        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        int i = left, k = left;
        j = mid + 1; // Reset j for merging purpose
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (int i = left; i <= right; i++) {
            nums[i] = temp[i];
        }

        return count;
    }
};
