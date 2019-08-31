#include <stdio.h>

int main(){
	
	int n,cnt=0;
	long long p;
	scanf("%d %lld",&n,&p);
	long long num[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	} 
	
	long long min=num[0];
	for(int i=0;i<n;i++){
		if(min>num[i]){
			min=num[i];
		}
	}

	for(int i=0;i<n;i++){
		if(num[i]<=min*p){
			cnt++;
		}
	}
	printf("%d",cnt);
	
	return 0;
}
