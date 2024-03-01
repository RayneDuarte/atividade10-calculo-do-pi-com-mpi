#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int meu_rank, tam, tag = 99;
	char msg[20];
	MPI_Status status;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &tam);

	if (meu_rank == 0) {
		strcpy_s(msg, "Olá Mundo!");
		MPI_Send(&msg, strlen(msg), MPI_CHAR, 1, tag, MPI_COMM_WORLD);
		// Envia uma mensagem ao processo #1
	}
	else { 
		strcpy_s(msg, "Oii");
		printf(msg);
		MPI_Recv(msg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
		// Recebe uma mensagem do processo #0
		printf(msg);
	}
	MPI_Finalize();
	return 0;
}
