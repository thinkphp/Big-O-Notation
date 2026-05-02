# Big O Notation Peak Element 

Time Complexity O(n)
```
int findPeakElementLinear(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n-1;

    for (int i = 1; i < n-1; i++) {
        if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
            return i;
    }
    return -1; // teoretic nu se ajunge aici
}

```

Time Complexity O(log n)
```
int findPeakElementBinary(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // suntem pe panta ascendentă → peak în dreapta
            left = mid + 1;
        } else {
            // suntem pe panta descendentă → peak în stânga (sau mid)
            right = mid;
        }
    }

    return left; // left == right → peak
}

```
