#include <mpi.h>
#include <stdio.h>

// Sends 2 ints, one from rank 1 and one from rank 2, to rank 0.

#define MY_TAG 1

int main(int argc, char **argv)
{	
	int numberOfProc,rank; // Identificators
	int rec_val1,rec_val2; // variables to collect data
	MPI_Status status;
	// int MY_TAG = 100;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numberOfProc);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank == 0){ 
		int get_count;

		//Recieve from rank 1
		MPI_Recv(&rec_val1, 1, MPI_INT,					// what
				1, MY_TAG, MPI_COMM_WORLD, &status);	// from whom
		MPI_Get_count(&status,MPI_INT,&get_count);
		printf("rank%2d | Recv rec_val1 = %3d | count = %d, from_tag %d, from_source %d\n",rank,rec_val1,get_count,status.MPI_TAG,status.MPI_SOURCE);

		//Recieve from rank 2
		MPI_Recv(&rec_val2, 1, MPI_INT,					// what
				2, MY_TAG, MPI_COMM_WORLD, &status);	// from whom
		MPI_Get_count(&status,MPI_INT,&get_count);
		printf("rank%2d | Recv rec_val2 = %3d | count = %d, from_tag %d, from_source %d\n",rank,rec_val2,get_count,status.MPI_TAG,status.MPI_SOURCE);
	}

	else if (rank==1) { //Send to rank 0
		int send_val1 = 71;
		MPI_Send(&send_val1, 1, MPI_INT,	 	// what
				0, MY_TAG, MPI_COMM_WORLD );	// to whom
		printf("rank%2d | Send send_val1 = %3d\n",rank,send_val1);
	}

	else if (rank==2) { //Send to rank 0
		int send_val2 = 72;
		MPI_Send(&send_val2, 1, MPI_INT,	 	// what
				0, MY_TAG, MPI_COMM_WORLD );	// to whom
		printf("rank%2d | Send send_val2 = %3d\n",rank,send_val2);
	}

	MPI_Finalize();
	return 0;
}