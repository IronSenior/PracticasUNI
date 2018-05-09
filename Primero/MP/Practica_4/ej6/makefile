#Fichero: Makefile_ej6

crucigrama: libMemoria.a main.o ficheros.o crucigrama.o
	gcc -o crucigrama main.o ficheros.o crucigrama.o libMemoria.a

libMemoria.a: reservaMemoria.o liberaMemoria.o
	ar -rsv libMemoria.a reservaMemoria.o liberaMemoria.o

reservaMemoria.o: reservaMemoria.c
	gcc -c reservaMemoria.c

liberaMemoria.o:
	gcc -c liberaMemoria.c

clean: 
	@echo Eliminando archivos objeto
	@rm *.o