#include<bits/stdc++.h>
using namespace std;

int kLargestElements(vector<int> &A,int k){
	int max = A[0];
	for(int i=0;i<A.size();i++){
		if(A[i] > max){
			max = A[i];
		}
	}
	
	
	vector<int> C(max+1);
	for(int i=0;i<max+1;i++){
		C[i] = 0;
	}

	for(int i=0;i<A.size();i++){
		C[A[i]]++;
	}

	int i=0;
	int j=0;
	while(i<max+1){
		if(C[i] > 0){
			A[j++] = i;
			C[i]--;
		}else{
			i++;
		}
	}
	for(int i=A.size()-1;i>A.size()-k;i--){
		cout<<A[i]<<"\t";
	}
	cout<<"\n";

}



int main(){
	vector<int> v;
	v = {10,15,79,36,12,32,41,69,50,80};
	kLargestElements(v,6);

}

