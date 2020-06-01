#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
/**
 * author: Genaro Martinez S. A01566055
 * 
 * 22 de mayo del 2020
 * 
 * Mision 4
 * Descripcion: se utiliza una librería parecido a los hooks de Windows
 * pero de la distribucion linux para detectar los movimientos y el clickeo 
 * del ratón por el usuario por medio de un servidor acivo de monitor, utilzando <X11/Xlib.h>, <X11/Xutil.h>.
 * */

//Apuntador para el archivo que se va a usar
FILE* fp;

int main()
{
	int run = 0;
   fp = fopen("coordenadas.txt", "a");
	do {
      // inicializa las coordenadas.
	int x = -1, y = -1;
	XEvent event;
	int button;
	Display *display = XOpenDisplay(NULL);
	if (display == NULL)
	{
		fprintf(stderr, "Cannot connect to X server!\n");
		exit(EXIT_FAILURE);
	}
   // utiliza el default window root que visualiza los eventos del monitor.
	Window root = XDefaultRootWindow(display);
   // inicializa un apuntador para utilizarlo en el input.
	XGrabPointer(display, root, False, ButtonPressMask, GrabModeAsync,
				 GrabModeAsync, None, None, CurrentTime);
   // inicializa el monitor
	XSelectInput(display, root, ButtonPressMask);

	while (1)
	{
		XNextEvent(display, &event);
      // registra el evento
		switch (event.type)
		{
         // registra el tipo de boton
		case ButtonPress:
			switch (event.xbutton.button)
			{
			case Button1:
         // registra las coordenadas
				x = event.xbutton.x;
				y = event.xbutton.y;
				button = Button1;
				break;

			case Button3:
         // registra las coordenadas
				x = event.xbutton.x;
				y = event.xbutton.y;
				button = Button3;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		if (x >= 0 && y >= 0)
			break;
	}
   // si el boton es del tipo uno despliega sus coordenadas en el monitor.
	if (button == Button1) {
		fprintf("leftclick at x: %d  y: %d \n", x, y);
		printf("leftclick at x: %d  y: %d \n", x, y);
		run += 1;
	} else {
		fprintf("rightclick at x: %d y: %d \n", x, y);
		printf("rightclick at x: %d y: %d \n", x, y);
	}
   // cierra el monitor al registrar el evento.
		XCloseDisplay(display);
		} while (run < 10);
   fclose(fp);
	return 0;
}