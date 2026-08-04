#include<iostream>
#include<vector>
using namespace std;
void linear_search(vector<int> arr1,int target){
	for(int i=0;i<arr1.size();i++){
		if (arr1[i]==target){
			cout<<i;
			return;
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int t;
	cin>>t;
	linear_search(arr,t);
	return 69;
}