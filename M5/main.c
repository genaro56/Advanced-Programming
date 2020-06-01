#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <pthread.h>
/**
 * author: Genaro Martinez A01566055
 * 
 * Description: using the Windows Thread API to
 * calculate an aproximation of PI by joining different thread after
 * each calculation is done.
 * 
*/
#define AMOUNT_OF_RECTANGLES 100000000

double deltaX;
double accum = 0.0;
CRITICAL_SECTION cs;

DWORD WINAPI threadRoutine(LPVOID p)
{
  double x;
  double fdx;
  double localAccum = 0.0;
  double *initialX = (double *)p;
  double finalX = (initialX) + deltaX(AMOUNT_OF_RECTANGLES / 53);
  printf("x=%lf\n", *initialX);
  for (x = *initialX; x < finalX; x += deltaX)
  {
    fdx = 4.0 / (1.0 + x * x);
    localAccum = localAccum + (fdx * deltaX);
  }
  EnterCriticalSection(&cs);
  accum += localAccum;
  LeaveCriticalSection(&cs);
}

void main()
{
  pthread_t tid[53];
  int i, rc;
  time_t start, stop;
  HANDLE t[53];
  double param[53];
  deltaX = 1.0 / AMOUNT_OF_RECTANGLES;
  start = clock();
  InitializeCriticalSection(&cs);
  // Create the threads
  printf("initializing threads...\n");
  for (i = 0; i < 53; i++)
  {
    // changed the calculation per param to 
    param[i] = (1.0 / 53) * i;
    rc = pthread_create(&tid[i], NULL, (void()(void *))threadRoutine, &param[i]);
  }

  for (i = 0; i < 53; i++)
  {
    rc = pthread_join(tid[i], NULL);
  }

  WaitForMultipleObjects(53, &t[0], TRUE, INFINITE);
  // Wait for the threads to finish
  DeleteCriticalSection(&cs);
  stop = clock();
  printf("aproximation of PI: %1.15lf (%ld)\n", accum, stop - start);
}