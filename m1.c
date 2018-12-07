#include   <mpi.h>
#include<stdio.h>
  
  void main(int argc, char *argv[])
  {
	int rank,size;
	double param[6],mine;
	int sndcnt,rcvcnt;
	int i;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	sndcnt=1;
	mine=23.0+rank;
	if(rank==3) rcvcnt=1;

	MPI_Gather(&mine,sndcnt,MPI_DOUBLE,param,rcvcnt,MPI_DOUBLE,3,MPI_COMM_WORLD);

	if(rank==3)
		for(i=0;i<size;++i) 
		  printf("PE:%d param[%d] is %f \n",rank,i,param[i]);  

	MPI_Finalize();
}
