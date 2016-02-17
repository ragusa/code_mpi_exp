#include <mpi.h>
#include <stdio.h>

// Each processors salutes

int main(int argc, char **argv)
{
	
	int numberOfProcess;
	int rank;

	MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcess);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Hello from rank[%2d/%2d]!\n",rank,numberOfProcess);

	MPI_Finalize();
	

	return 0;
}