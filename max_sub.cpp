#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int max_crossing(int a[], int l, int mid, int h){
	int left_sum = INT_MIN;
	int sum = 0; 
	int max_left =0;
	int max_right = 0;
	for(int i = mid; i >= l; i--){
		sum = sum + a[i];
		if(sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	
	}
	int right_sum = INT_MIN;
	sum = 0;
	for(int j = mid+1; j <= h; j++){
		sum = sum + a[j];
		if(sum > right_sum){
			right_sum = sum;
			max_right = j;
		}	
	}
	return(max_left,max_right,left_sum+right_sum);
}

int max_subarray(int a[], int l, int h){
	if(h == l){
		return a[l];
	}else{
		int mid = (l+h)/2;
		int ret = max(max_subarray(a,l,mid),max_subarray(a,mid+1,h));
		return max(ret, max_crossing(a,l,mid,h));
	}
return 1;
}

int max_sub_Dyn(int a[], int size){
	int max_now = a[0];
	int curr = a[0];
	for(int i =1; i < size; i++){
		curr = max(a[i], curr+a[i]);
		max_now = max(max_now, curr);
	
	}
return max_now;
}

int main(){
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int b[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int c[] = {12,124,33,1,5}; 
	int d[] = {-22,-35,-122,-12,-3}; 
	
	for(int i = 0; i < 8; i++){
		cout << a[i] << " ";
	}
	   		cout << endl; 
	int max_sum = max_subarray(a, 0,7); 
   	cout << "Divide and Conquer " << max_sum;
   		cout << endl; 
   	max_sum = max_sub_Dyn(a, 8);
   	cout << "Dynamic " << max_sum; 
	cout << endl;
	
	
	
	for(int i = 0; i < 16; i++){
		cout << b[i] << " ";
	}
	   		cout << endl; 
	max_sum = max_subarray(b, 0,15); 
   	cout << "Divide and Conquer " << max_sum;
   		cout << endl; 
   	max_sum = max_sub_Dyn(b, 16);
   	cout << "Dynamic " << max_sum; 
	cout << endl;
	
	
	
	
	for(int i = 0; i < 5; i++){
		cout << c[i] << " ";
	}
	   		cout << endl; 
	   		
	max_sum = max_subarray(c, 0,4); 
   	cout << "Divide and Conquer " << max_sum; 
   		cout << endl;
   	max_sum = max_sub_Dyn(c, 5);
   	 cout << "Dynamic " << max_sum; 
	cout << endl;
	
	
	for(int i = 0; i < 5; i++){
		cout << d[i] << " ";
	}
	   		cout << endl; 
	max_sum = max_subarray(d, 0,4); 
   	cout << "Divide and Conquer " << max_sum; 
   		cout << endl;
   	max_sum = max_sub_Dyn(d, 5);
   	 cout << "Dynamic " << max_sum; 
	cout << endl;
}

