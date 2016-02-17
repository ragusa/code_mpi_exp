#include <mpi.h>
#include <stdio.h>
 
// MPI_Sendrecv interleaved

// EG with 3 processors
// Sends an array of 10 ints from:
// From 0->1
// From 1->2
// From 2->0

#define TAG 100

int main(int argc, char *argv[]){
    int myid, numprocs;
    int left, right;
    int buffer1[10];
    int buffer2[10];
    MPI_Request request;
    MPI_Status status;
 
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
 
    right = (myid + 1) % numprocs;
    left = myid - 1;
    if (left < 0)
        left = numprocs - 1;
    printf("%d) %d\t%d\n",myid,right,left);
    MPI_Sendrecv(buffer1, 10, MPI_INT, left,  TAG, //send to
                 buffer2, 10, MPI_INT, right, TAG, MPI_COMM_WORLD, &status); //recieve from


    // This causes a deadlock
    // int bef, aft;

    // bef = myid-1;
    // aft = myid+1;

    // if (bef < 0)
    //     bef = numprocs - 1;

    // if (aft > (numprocs - 1))
    //     aft = 0;

    // // printf("b%d | c%d | a%d\n",bef,myid,aft);
    // printf("%d -> %d\n",myid,aft);
 
    // MPI_Sendrecv(buffer1, 10, MPI_INT, aft,  TAG, //send to
    //              buffer2, 10, MPI_INT, myid, TAG, MPI_COMM_WORLD, &status); //recieve from

    MPI_Finalize();
    return 0;
}

// Another at
// http://www.mcs.anl.gov/research/projects/mpi/tutorial/mpiexmpl/src/exchange/C/shift/main.html

