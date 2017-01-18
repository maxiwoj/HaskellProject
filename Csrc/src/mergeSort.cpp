//#include <iostream>
#include <mergeSort.hpp>
#include <cstdlib>
//#include <ctime>
//#define N 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//void mergeSort(int x[],int y[],int l,int r);
//void Merge(int x[],int y[],int l,int s,int r);
//int main(int argc, char** argv) {
//	srand(time(NULL));
//	int tab[N];
//	int r[N];
//	for(int i=0;i<N;i++){
//		tab[i]=rand()%10000;
//		cout<<tab[i]<<" ";
//	}
//	cout<<"wylosowano"<<endl;
//	mergeSort(tab,r,0,N-1);
//	for(int i=0;i<N;i++){
//		cout<<tab[i]<<" ";
//	}
//	return 0;
//}
//-------------------------------------------------------------
void Merge(int x[],int y[],int l,int s,int r){
	int a=l,b=s;
	int i=l;
	while(a<s && b<=r){
		if(x[a]<=x[b]){					//Porównaj i wpisz mniejszą
			y[i]=x[a];
			a++;
		}
		else{
			y[i]=x[b];
			b++;
		}
		i++;
	}
	while(a<s && b>r){
		y[i]=x[a];
		a++;
		i++;
	}
	while(a>=s && b<=r){
		y[i]=x[b];
		b++;
		i++;
	}
	while(l<=r){					//Przepisz wszystkie do tablicy a
		x[l]=y[l];
		l++;
	}
}
//-------------------------------------------------------
void mergeSort(int x[],int y[],int l,int r){
	int s=(r+l)/2;
	if(l==r) return;
	if(l==s) {
		if(x[l]>=x[r]){
			int tmp=x[l];
			x[l]=x[r];
			tmp=x[r];
			return;
		}
		else return;
	}
	mergeSort(x,y,l,s);
	mergeSort(x,y,s,r);
	Merge(x,y,l,s,r);
}
