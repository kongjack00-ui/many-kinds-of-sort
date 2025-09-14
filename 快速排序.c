#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int size;
	int N[100];
}L;
int Part(L *L,int low,int high){
	int pivot;
	while(low<high){
		pivot=L->N[low];
		while(low<high&&L->N[high]>=pivot)
		high--;
		L->N[low]=L->N[high];
		while(low<high&&L->N[low]<=pivot)
		low++;
		L->N[high]=L->N[low];
		
	}
	L->N[low]=pivot;
	return low;
}
void Qsort(L *L,int low,int high){
	int pivotadd;
	if(low<high){
		pivotadd=Part(L,low,high);
		Qsort(L,low,pivotadd-1);
		Qsort(L,pivotadd+1,high);
	}
}
void QuickSort(L *L){
	Qsort(L,1,L->size);
}
int main(){
	L L;
	scanf("%d",&L.size);
	for(int i=1;i<=L.size;i++){
		scanf("%d",&L.N[i]);
	}
	QuickSort(&L);
	for(int i=1;i<=L.size;i++){
		printf("%d ",L.N[i]);
	}
	return 0;
}