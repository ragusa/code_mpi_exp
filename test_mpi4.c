#include "mpi.h"
#include <stdio.h>
#include <string.h>

// Sending and array of chars. MPI_Send and MPI_Recv
// Sends "hello there" from proc0 to proc1
// Run with 2 cores only

#define MSG_MAX_LEN 20
#define TAG 100

int main(int argc, char** argv)
{
   char msg[MSG_MAX_LEN];
   int myrank, np;
   MPI_Status status;

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &np);
   MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  
   if(myrank == 0) {
      strcpy(msg, "Hello there");
      // strlen(msg)+1 = 12;
      MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 1, TAG, MPI_COMM_WORLD);
      printf("from node %d, message: %s (sent)\n", myrank, msg);
   }
   else if (myrank == 1) {
      MPI_Recv(msg, MSG_MAX_LEN, MPI_CHAR, 0, TAG, MPI_COMM_WORLD, &status);
      printf("from node %d, message: %s (received)\n", myrank, msg);
   }

   MPI_Finalize();
   return 0;
}