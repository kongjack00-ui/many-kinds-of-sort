#include<stdio.h>
typedef struct{
	int r[200];
	int length;
}Sqlist;
void Intersort(Sqlist *l,int add){
	int i,j;
	for(i=add+1;i<=l->length;++i){//从第一add点开始往前排,间隔add比较一次，小的放前面，然后直到最后一个
		if(l->r[i]<l->r[i-add]){//这里就是往前排的具体过程
			l->r[0]=l->r[i];
			for(j=i-add;j>0&&l->r[j]>l->r[0];j=j-add)
			l->r[j+add]=l->r[j];
		l->r[j+add]=l->r[0];
		}
	}
}
void print(Sqlist l){
	int i;
	for(int i=1;i<=l.length;i++){
		printf("%d ",l.r[i]);
	}
	printf("\n");
}
int main(){
	Sqlist l;
	int n;
	scanf("%d",&n);
	int s[n];
	for(int j=0;j<n;j++){
		scanf("%d",&s[j]);
	}
	int i=0;
	for(i=0;i<n;i++ ){
		l.r[i+1]=s[i];
	}
	l.length=n;
    for(int j=3;j>=1;j--){
    	Intersort(&l,2*j-1);
	}
	print(l);
	return 0;
}