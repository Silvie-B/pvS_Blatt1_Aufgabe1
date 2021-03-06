#include "pch.h"		
#include "stdafx.h"
#include <stdio.h>		//Einbindung der Ein- & Ausgabefunktionen der STD
#include <omp.h>		// Einbindung der OpenMP Bibliothek 

int main(int argc, char* argv[])
{
	int numThreads;		//deklarieren Int zum Speichern der Threadanzahl
	int threadID;		//deklarieren Int zum Speichern der ThreadID
	float start, end;	//Floats zum Speichern der Start und Endzeit des parallelen Abschnitts

	start = omp_get_wtime();		//Startzeit

#pragma omp parallel num_threads(8)		//Beginn paralleler Abschnitt, num_threads() legt die max. Anzahl an Threads fest, die ihn durchfueren
	{
		threadID = omp_get_thread_num();	// gibt die Anzahl der Threads im aktuellen Team zureuck
		printf("Hello from thread %d\n", threadID);

		if (threadID == 0)	//wenn der aktuelle Thread die ID 0 hat wird Gesamtnzahl an Threads in numThreads gespeichert und, wird nur bei 1 Thread durchlaufen
		{
			numThreads = omp_get_num_threads();
			printf("Number of threads: %d\n", numThreads);
		}

	}
	end = omp_get_wtime();		//Speichern der Zeit bei Beenden des parallelen Abschnitts

	printf("This task took  %f seconds\n", end - start);

	return 0;

}
/*
numThreads() legt die Anzahl an Threads im Team fest. Setzt man den Wert auf 1 wird die If-Bedingung durchlaufen, da dann get_thread_num 1
zurückgibt und diesrer Wert in threadID gespeichert wird. Wird der Wert höher gesetzt ist (threadID == 0)
nicht wahr. Und es wird nicht die Anzahl an Threads ausgeben.

*/