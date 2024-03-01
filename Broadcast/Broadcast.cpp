#include <stdio.h>
#include <mpi.h>
#include <string.h>
#include <locale.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portuguese");
	int meu_rank, tam, tag = 99;
	char msg[20], *m;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &tam);
	if (meu_rank == 0) {
		strcpy_s(msg, "Olá Mundo!\n");
		MPI_Bcast(&msg, 20, MPI_CHAR, 0, MPI_COMM_WORLD);
		// Executa Broadcast com conteúdo no processo #0
	}
	else {
		MPI_Bcast(msg, 20, MPI_CHAR, 0, MPI_COMM_WORLD);
		// Executa Broadcast com conteúdo no processo #0
		printf("N do Processo % d | msg: ", meu_rank);
		printf(msg);
	}
	MPI_Finalize();
	return 0;
}