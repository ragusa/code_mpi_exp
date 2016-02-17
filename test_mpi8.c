#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define totalSize 100
#define chunkSize 5

void generateArray(char *NAME, int *array, int size_array){
	int iloop;
	for (iloop=0; iloop<size_array; iloop++){
		array[iloop] = iloop+1;
	}
}

void printArray(char *NAME, int *array, int size_array, int proc_id){
	int iloop;
	for (iloop=0; iloop<size_array; iloop++){
		printf("P%-2d | %s[%d] = %d\n",proc_id,NAME,iloop,array[iloop]);
	}
}

int main (int argc, char *argv[]){

	int proc_id,procs_num;
	int iloop;
	int A[totalSize];
	int a[chunkSize];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &proc_id);
	MPI_Comm_size(MPI_COMM_WORLD, &procs_num);

	if (proc_id == 0) {
		generateArray("A",A,totalSize);
		printArray("A",A,totalSize,0);
	}

	MPI_Scatter(A, chunkSize, MPI_INT, 
				a, chunkSize, MPI_INT, 
				0, MPI_COMM_WORLD);

	printArray("a",a,chunkSize,proc_id);

	MPI_Finalize();
}