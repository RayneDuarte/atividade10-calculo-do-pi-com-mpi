#include <mpi.h>
#include <stdio.h>
#include <conio.h>

int N = 100000000;

int main(int argc, char** argv)
{
	int i;
	double pi, soma = 0, x, step = (1.0 / N);
	//Iniciando MPI
	MPI_Init(NULL, NULL);
	int ncpus;
	MPI_Comm_size(MPI_COMM_WORLD, &ncpus);
	int meu_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);

	for (i = meu_rank; i < N; i = i + ncpus)
	{
		x = (i + 0.5) * step;
		soma += 4 / (1 + x * x);
	}
	pi = soma * step;
	printf("PI %.8lf\n", pi);
	MPI_Finalize();
	_getch();
}
