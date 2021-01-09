#include <stdio.h>
#include <stdlib.h>

void F(int *Af, int N){
	int i, c;
	for (i = N-2; i>= 0; i--)
	{
		for (int j =i+1; j<N; j++)
		{
			if(Af[i]>Af[j]) {
				c= Af[i];
				Af[i] = Af[j];
				Af[j] = c;
			}
		}
	}
}

int main(){
	int N=10;
	int A[10]= {100, 99, 60,3 ,12, 76, 34, 88, 90, 14};
		F(A, N);
	for (int i =0; i < N; i++) printf("%d ", A[i]);
}