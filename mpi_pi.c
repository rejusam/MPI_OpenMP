#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv) {

    int n_tasks, taskid, len;
    double h, sum, x;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &n_tasks);
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid); 
    
    len = 10000; 
    h   = 1.0 / (double) len;
    sum = 0;
    
    for (x = h * taskid; x <= 1.0; x+= h * n_tasks) {
        sum += (4.0 / (1.0 + x*x));
    }
    sum = h * sum;
    
    MPI_Reduce(&sum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 

    if (taskid == 0) {
        printf("pi is %f\n", sum);
    }

    MPI_Finalize();
}
