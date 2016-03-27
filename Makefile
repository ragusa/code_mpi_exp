
hello:
	mpic++ -O3 helloBLACS.cpp -o helloBLACS.out
	mpirun -np 1 ./helloBLACS.out matrixFile 4 4 2 2


run1:
	mpicc -O3 test_mpi1.c
	mpirun -np 2 ./a.out

run2:
	mpicc -O3 test_mpi2.c
	mpirun -np 3 ./a.out

run21:
	mpicc -O3 test_mpi21.c
	mpirun -np 2 ./a.out

run3:
	mpicc -O3 test_mpi3.c
	mpirun -np 6 ./a.out

run4:
	mpicc -O3 test_mpi4.c
	mpirun -np 4 ./a.out

run5:
	mpicc -O3 test_mpi5.c
	mpirun -np 4 ./a.out

run6:
	mpicc -O3 test_mpi6.c
	mpirun -np 12 ./a.out

run7:
	mpicc -O3 test_mpi7.c
	mpirun -np 4 ./a.out

run8:
	mpicc -O3 test_mpi8.c
	mpirun -np 20 ./a.out

run9:
	mpicc -O3 test_mpi9.c
	mpirun -np 4 ./a.out

run10:
	mpicc -O3 test_mpi10.c
	mpirun -np 4 ./a.out

run11:
	mpicc -O3 test_mpi11.c
	mpirun -np 4 ./a.out

# all:
# 	mpicc -O3 test_mpi2.c
# 	mpirun -np 2 ./a.out