#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <pthread.h>
/**
 * MISSION 05:
 * author: Genaro Martinez A01566055
 * 
 * Description: using the Windows Thread API to
 * calculate an aproximation of PI by joining each different thread 
 * after its critical section is done.
*/

#define AMOUNT_OF_RECTANGLES 100000000
#define NUMBER_OF_THREADS 53

double deltaX;
double accum = 0.0;
CRITICAL_SECTION cs;

DWORD WINAPI threadRoutine(LPVOID p)
{
  double x;
  double fdx;
  double localAccum = 0.0;
  double *initialX = (double *)p;
  // divides the number of rectangles in circle by number of threads
  double finalX = (*initialX) + deltaX * (AMOUNT_OF_RECTANGLES / NUMBER_OF_THREADS);
  for (x = *initialX; x < finalX; x += deltaX)
  {
    // augments accum fdx
    fdx = 4.0 / (1.0 + x * x);
    localAccum = localAccum + (fdx * deltaX);
  }
  // begins critical section
  EnterCriticalSection(&cs);
  accum += localAccum;
  LeaveCriticalSection(&cs);
  return accum;
}

void main()
{
  pthread_t tid[NUMBER_OF_THREADS];
  int i;
  time_t start, stop;
  HANDLE t[NUMBER_OF_THREADS];
  double param[NUMBER_OF_THREADS];
  deltaX = 1.0 / AMOUNT_OF_RECTANGLES;
  start = clock();
  // initializes critical section.
  InitializeCriticalSection(&cs);
  printf() for (i = 0; i < NUMBER_OF_THREADS; i++)
  {
    param[i] = (1.0 / NUMBER_OF_THREADS) * i;
    /**
     * CRITICAL Section call.
     * create threads and initialize them in void values.
     * then call the thread routine to calculate the value
     * in the critical section.
     */
    pthread_create(&tid[i], NULL, (void *(*)(void *))threadRoutine, &param[i]);
  }

  for (i = 0; i < NUMBER_OF_THREADS; i++)
  {
    //Wait for all threads and join the accum
    pthread_join(tid[i], NULL);
  }
  // deletes the critical section value.
  DeleteCriticalSection(&cs);
  stop = clock();
  // returns cacultated PI.
  printf("PI aproximate: %1.15lf (%ld)\n", accum, stop - start);
  pthread_exit(NULL);
}