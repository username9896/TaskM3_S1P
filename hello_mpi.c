#include <stdio.h>
#include <mpi.h>    // for MPI functions

int main(int argc, char **argv)
{
    int rank, size;

    MPI_Init(&argc, &argv);  // Initialize MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get the rank of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get the total number of processes

    if (rank == 0)  // If the current process is the master process (rank 0)
    {
        printf("Hello message from master\n");  // Print a message from the master
    }
    if (rank == size - 1)  // If the current process is the head process (rank size - 1)
    {
        printf("Hello message from head\n");  // Print a message from the head
    }

    MPI_Finalize();  // Finalize MPI environment
    return 0;
}
