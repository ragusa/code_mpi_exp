#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	
	int numberOfProcess;
	int rank;

	printf("antes\n");

	MPI_Init(&argc,&argv);

	MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcess);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("rank[%2d/%2d]\n",rank,numberOfProcess);

	printf("durante\n");

	MPI_Finalize();
	
	printf("despues\n");

	return 0;
}