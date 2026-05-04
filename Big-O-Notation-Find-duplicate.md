# Find Duplicate

Time Complexity O(n)
Space Complexity O(1)
```
#include <iostream>

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	long long mask = 0;
	bool duplicate = false;
	for(int i = 0; i < n ; ++i) {
        if(mask & (1LL<<arr[i])) {duplicate = true; break; }

        mask |= (1LL<<arr[i]);
	}

	if(duplicate) std::cout<<"duplicate"; else std::cout<<"not duplicate";
	return 0;
}
```
