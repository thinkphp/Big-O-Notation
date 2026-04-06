#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void next_permutation(vector<int>&v) {

	//first step
	int n = v.size();
	int i = n - 2;

    //cautam primul element din dreapta pivot care respecta conditia
    //v[i] < v[i+1];
	while(i >= 0 && v[i] >= v[i+1]) i--;

	//cautam primul cel mai mare din dreapta

    if(i >= 0) {

	   int j = n - 1;

	   while(v[j] <= v[i]) j--;

	   swap(v[i], v[j]);
	}   

	reverse(v.begin() + i + 1, v.end());

}

int main(int argc, char const *argv[])
{

	vector<int> vec = {1,4,3,2};

	for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {

		cout<<*it<<" ";
	}

	cout<<endl;

	next_permutation(vec);

	for(int x: vec) {

		cout<<x<<" ";
	}

	
	return 0;
}
