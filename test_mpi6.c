#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// Example of broadcast with MPI
// MPI_Bcast: Broadcasts a message from the process with rank "root" to all other processes of the communicator

#define BUFFER_SIZE 100000000 // takes a bit to run
// #define BUFFER_SIZE 1000000000 // almost max with 12 cores and 48Gb RAM
// #define BUFFER_SIZE 2147483647 // freezes the machine, don't run

int main(int argc, char*argv[]) {

	int i,proc_id,num_procs;
	// int *buffer = (int *) malloc(BUFFER_SIZE*sizeof(int));
	int *buffer = (int *) calloc(BUFFER_SIZE,sizeof(int));
	
	double sizeGb = ((double)BUFFER_SIZE*sizeof(int)) / (1024.0 * 1024.0 * 1024.0);

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&proc_id);
	MPI_Comm_size( MPI_COMM_WORLD, &num_procs );

	// Build data to be broadcasted
	if(proc_id == 0){
		printf("Transfering %1.1f GiB to %d processes. Total of %1.1f GiB\n",sizeGb,num_procs,sizeGb*(double)num_procs);
		// for(i=0;i<BUFFER_SIZE;i++)
		// buffer[i]=i;
	}

	MPI_Bcast(buffer, BUFFER_SIZE, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Barrier( MPI_COMM_WORLD );

	printf("P%-2d: Got the data (%1.1f Gb) \n",proc_id,sizeGb);

	// printf("P%-2d: [ ",proc_id);
	// for(i=0;i<BUFFER_SIZE;i++){
	// 	printf("%d ",buffer[i]);
	// }
	// printf("]\n");

	MPI_Finalize();
}
