/*
 * Genaro Martínez S.
 * A01566055
 * Este programa usa un menu para registrar, buscar. editar y eliminar agentes, validando su informacion.
 * 08/03/2019
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// struct agent
typedef struct
{
    char cNombre[10];
    char cApellido[10];
    int iNoAsignaciones;
    char cAsignaciones[10][14];
    int iEdad;
    int iNoMisiones;
    char cMision[10][13];
} agent;

//Funcion access
//Esta funcion regresa un booleano que determinara si la información se muestra de manera cifrada o no.
//cArreglo: Arreglo de apuntadores de caracteres que se modificaran en caso de ingresar una contraseña erronea.
bool access(char *cArreglo[5])
{
    int iContraseña = 0;
    int iEncriptar = 0;
    char *ptr;

    printf("Ingresa la contraseña de acceso: ****\n");
    scanf("%d", &iContraseña);

    if (iContraseña == 1234)
    {
        printf("Bienvenido agente\n\n\n");
        return true;
    }
    else
    {
        printf("Contraseña incorrecta\n");
        iEncriptar = 3;

        for (int i = 0; i < 5; i++)
        {
            ptr = cArreglo[i];
            while (*ptr != '\0')
            {
                *ptr = *ptr + iEncriptar;
                *ptr++;
            }
        }
        printf("%s\n\n%s\n%s\n%s\n%s\n\n", cArreglo[0], cArreglo[1], cArreglo[2], cArreglo[3], cArreglo[4]);
        return false;
    }
}

//Funcion validateAsignee
//Esta funcion valida que el string contenga 4 letras y 9 digitos.
//cValidar: String a validar.
bool validateAsignee(char cValidar[14])
{

    int letras = 0, digitos = 0, i;
    for (i = 0; cValidar[i] != '\0'; i++)
    {
        // revisa letras
        if (isalpha(cValidar[i]) != 0)
            letras++;

        // revisa digitos
        else if (isdigit(cValidar[i]) != 0)
            digitos++;
    }

    if (letras == 4 && digitos == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Funcion validateMission
//Esta funcion valida que el string contenga 3 letras y 9 digitos.
//cValidar: String a validar.
bool validateMission(char cValidar[14])
{

    int letras = 0, digitos = 0, i;
    for (i = 0; cValidar[i] != '\0'; i++)
    {
        // revisa letras
        if (isalpha(cValidar[i]) != 0)
            letras++;

        // revisa digitos
        else if (isdigit(cValidar[i]) != 0)
            digitos++;
    }

    if (letras == 3 && digitos == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Funcion entrada
//Esta funcion asigna datos a un agente.
//Agentes: Arreglo de agentes.
//*iContador: Apuntador al numero de agentes registrados.
void entrada(agent Agentes[10], int *iContador)
{

    char cValidar[14];

    //Registrar nombre
    printf("Teclea el nombre del agente:\n");
    scanf("%s", Agentes[*iContador].cNombre);

    //Registrar apellido
    printf("Teclea tu apellido:\n");
    scanf("%s", Agentes[*iContador].cApellido);

    //Registrar numero de activos de inteligencia
    printf("Teclea el numero de activos de inteligencia asignados: (maximo 10)\n");
    scanf("%d", &Agentes[*iContador].iNoAsignaciones);

    //Registrar activos de inteligencia
    for (int i = 0; i < Agentes[*iContador].iNoAsignaciones; i++)
    {
        printf("Ingresa el agente numero %d\n", i + 1);
        scanf("%s", cValidar);

        //Validar Activo de inteligencia
        if (validateAsignee(cValidar))
        {
            strcpy(Agentes[*iContador].cAsignaciones[i], cValidar);
        }
        else
        {
            printf("Codigo incompatible\n");
            i--;
        }
    }

    //Registrar edad
    printf("Teclea tu edad:\n");
    scanf("%d", &Agentes[*iContador].iEdad);

    //Registrar numero de misiones
    printf("Teclea el numero de misiones asignadas: (maximo 10)\n");
    scanf("%d", &Agentes[*iContador].iNoMisiones);

    //Registrar misiones
    for (int i = 0; i < Agentes[*iContador].iNoMisiones; i++)
    {
        printf("Ingresa la mision numero %d\n", i + 1);
        scanf("%s", cValidar);

        //Validar Mision
        if (validateMission(cValidar))
        {
            strcpy(Agentes[*iContador].cMision[i], cValidar);
        }
        else
        {
            printf("El codigo de la mision es incompatible. Reingresa el codigo\n");
            i--;
        }
    }

    printf("Datos capturados\n");

    *iContador = *iContador + 1;
}

//Funcion eliminateEntrada
//Esta funcion borra los datos de un agente.
//Agentes: Arreglo de agentes.
//*iContador: Apuntador al numero de agentes registrados.
void eliminateEntrada(agent Agentes[10], int *iContador)
{

    printf("Entradas existentes: %d\n", *iContador);

    if (*iContador != 0)
    {

        int iOpcion;

        //Desplegar informacion
        printf("Selecciona el indice que quieres eliminar\n");
        for (int i = 0; i < *iContador; i++)
        {
            printf("%d: %s %s\n", i + 1, Agentes[i].cNombre, Agentes[i].cApellido);
        }
        printf("%d: Volver al menu\n", *iContador + 1);

        scanf("%d", &iOpcion);

        //Opcion para salir
        if (iOpcion == *iContador + 1)
        {
            return;
        }
        else
        {
            for (int i = iOpcion; i < *iContador; i++)
            {
                Agentes[i - 1] = Agentes[i];
            }
            *iContador = *iContador - 1;
            printf("Agente eliminado exitosamente\n");
        }
    }
    else
    {
        printf("\n\nNo puedes eliminar ninguna entrada\n\n");
    }
}

//Funcion editAgent
//Esta funcion edita los activos y las misiones asignadas a un agente.
//Agentes: Arreglo de agentes.
//indice: Indice del agente a editar.
void editAgent(agent Agentes[10], int indice)
{

    char cValidar[14];

    //Registrar numero de activos de inteligencia
    printf("Teclea el numero de activos de inteligencia asignados: (maximo 10)\n");
    scanf("%d", &Agentes[indice].iNoAsignaciones);

    //Registrar activos de inteligencia
    for (int i = 0; i < Agentes[indice].iNoAsignaciones; i++)
    {
        printf("Ingresa el agente numero %d\n", i + 1);
        scanf("%s", cValidar);

        //Validar Activo de inteligencia
        if (validateAsignee(cValidar))
        {
            strcpy(Agentes[indice].cAsignaciones[i], cValidar);
        }
        else
        {
            printf("Codigo incompatible\n");
            i--;
        }
    }

    //Registrar numero de misiones
    printf("Teclea el numero de misiones asignadas: (maximo 10)\n");
    scanf("%d", &Agentes[indice].iNoMisiones);

    //Registrar misiones
    for (int i = 0; i < Agentes[indice].iNoMisiones; i++)
    {
        printf("Ingresa la mision numero %d\n", i + 1);
        scanf("%s", cValidar);

        //Validar Mision
        if (validateMission(cValidar))
        {
            strcpy(Agentes[indice].cMision[i], cValidar);
        }
        else
        {
            printf("El codigo de la mision es incompatible. Reingresa el codigo\n");
            i--;
        }
    }
}

//Funcion eliminateAgent
//Esta funcion elimina a un agente.
//Agentes: Arreglo de agentes.
//*iContador: Apuntador al numero de agentes registrados.
//indice: Indice del agente a editar.
void eliminateAgent(agent Agentes[10], int *iContador, int indice)
{

    for (int i = indice + 1; i < *iContador; i++)
    {
        Agentes[i - 1] = Agentes[i];
    }
    *iContador = *iContador - 1;
    printf("Agente eliminado exitosamente\n");
}

//Funcion findLName
//Esta funcion busca coincidencias con apellido.
//Agentes: Arreglo de agentes.
//*iContador: Apuntador al numero de agentes registrados.
void findLName(agent Agentes[10], int *iContador)
{

    char apellido[14];
    int iIndices[10];
    int iIndex = 0;
    bool boton;
    char *ptr;

    printf("¿Que apellido buscas?\n");
    scanf("%s", apellido);

    //Busqueda
    for (int i = 0; i < *iContador; i++)
    {
        boton = true;
        ptr = Agentes[i].cApellido;
        for (int j = 0; j < strlen(apellido); j++)
        {
            if (*ptr != apellido[j])
            {
                boton = false;
                break;
            }
            *ptr++;
        }
        if (boton)
        {
            iIndices[iIndex] = i;
            iIndex++;
        }
    }

    printf("Entradas encontradas: %d\n", iIndex);

    if (iIndex != 0)
    {

        int iOpcion;

        //Desplegar informacion
        printf("Selecciona un indice\n");
        for (int i = 0; i < iIndex; i++)
        {
            printf("%d: %s %s\n", i + 1, Agentes[iIndices[i]].cNombre, Agentes[iIndices[i]].cApellido);
        }
        printf("%d: Volver al menu\n", iIndex + 1);

        scanf("%d", &iOpcion);

        //Opcion para salir
        if (iOpcion == iIndex + 1)
        {
            return;
        }
        else
        {

            int iOpcion1;
            printf("¿Que quieres hacer con el agente?\n1: Editar\n2: eliminateEntrada\n");
            scanf("%d", &iOpcion1);

            switch (iOpcion1)
            {
            case 1: //Editar
                editAgent(Agentes, iIndices[iOpcion - 1]);
                break;
            case 2: //eliminateEntrada
                eliminateAgent(Agentes, iContador, iIndices[iOpcion - 1]);
                break;
            default:
                break;
            }
        }
    }
    else
    {
        printf("\n\nNo se encontraron coincidencias\n\n");
    }
}

//Funcion findActivo
//Esta funcion busca coincidencias con los activos.
//Agentes: Arreglo de agentes.
//*iContador: Apuntador al numero de agentes registrados.
void findActivo(agent Agentes[10], int *iContador)
{

    char activo[14];
    int iIndices[10];
    int iIndex = 0;
    bool boton;
    int ptr;
    char *ptr1;

    printf("¿Que activos de inteligencia buscas?\n");
    scanf("%s", activo);

    //Busqueda
    for (int i = 0; i < *iContador; i++)
    {
        //boton = true;
        ptr = Agentes[i].iNoAsignaciones;
        for (int j = 0; j < ptr; j++)
        {
            boton = true;
            ptr1 = Agentes[i].cAsignaciones[j];
            for (int k = 0; k < strlen(activo); k++)
            {
                if (*ptr1 != activo[k])
                {
                    boton = false;
                    break;
                }
                *ptr1++;
            }
            if (boton)
            {
                iIndices[iIndex] = i;
                iIndex++;
                break;
            }
        }
    }

    printf("Entradas encontradas: %d\n", iIndex);

    if (iIndex != 0)
    {

        int iOpcion;

        //Desplegar informacion
        printf("Selecciona un indice\n");
        for (int i = 0; i < iIndex; i++)
        {
            printf("%d: %s %s\n", i + 1, Agentes[iIndices[i]].cNombre, Agentes[iIndices[i]].cApellido);
        }
        printf("%d: Volver al menu\n", iIndex + 1);

        scanf("%d", &iOpcion);

        //Opcion para salir
        if (iOpcion == iIndex + 1)
        {
            return;
        }
        else
        {
            /*for(int i = iOpcion;i<*iContador;i++){
                Agentes[i-1] = Agentes[i];
            }
            *iContador = *iContador-1;
            printf("Agente eliminado exitosamente\n");*/
            int iOpcion1;

            printf("¿Que quieres hacer con el agente?\n1: Editar\n2: eliminateEntrada\n");

            scanf("%d", &iOpcion1);

            switch (iOpcion1)
            {
            case 1: //Editar
                editAgent(Agentes, iIndices[iOpcion - 1]);
                break;
            case 2: //eliminateEntrada
                eliminateAgent(Agentes, iContador, iIndices[iOpcion - 1]);
                break;
            default:
                break;
            }
        }
    }
    else
    {
        printf("\n\nNo se encontraron coincidencias\n\n");
    }
}

//Funcion buscar
//Esta funcion discierne entre buscar por apellido o por activo.
//Agentes: Arreglo de agentes.
//*iContador: Apuntador al numero de agentes registrados.
void buscar(agent Agentes[10], int *iContador)
{

    int iOpcion;

    printf("Por favor seleccione\n\n1: buscar por apellido\n2: buscar por activos\n");

    scanf("%d", &iOpcion);

    switch (iOpcion)
    {
    case 1: //buscar por apellido
        findLName(Agentes, iContador);
        break;
    case 2: //buscar por activo
        findActivo(Agentes, iContador);
        break;
    default:
        break;
    }
}

//Funcion principal
int main()
{

    bool bContinuar = true;
    int iOpcion = 2;
    agent Agentes[10];
    int iContador = 0;
    char cSaludo[] = "Por favor seleccione:";
    char cOpcion1[] = "1: Crear una nueva entrada";
    char cOpcion2[] = "2: buscar una entrada";
    char cOpcion3[] = "3: eliminateEntrada una entrada";
    char cOpcion4[] = "4: Salir";
    char *cArreglo[5];

    cArreglo[0] = cSaludo;
    cArreglo[1] = cOpcion1;
    cArreglo[2] = cOpcion2;
    cArreglo[3] = cOpcion3;
    cArreglo[4] = cOpcion4;

    //Cifrar datos
    if (!access(cArreglo))
    {
        return 0;
    }

    while (bContinuar)
    {
        printf("____________________________\n");
        printf("    `'-.,________,,..-  ___ \\_________      \n");
        printf("       > `'-.,_____,,.-`<_>\\ )__     `\\    \n");
        printf("         >            `'-._    _)____  \\   \n");
        printf("          >          _.-'`  _______  `\\ |  \n");
        printf("           >   _,,..--'''```       `'-.\\|  \n");
        printf("          >-'``                        `'    \n");
        printf("       ****ADVANCED PROGRAMMING SEMINARY****     ");
        printf("\n");

        printf("%s\n\n%s\n%s\n%s\n%s\n\n", cSaludo, cOpcion1, cOpcion2, cOpcion3, cOpcion4);

        scanf("%d", &iOpcion);

        switch (iOpcion)
        {
        case 1: //Registrar nuevo agente
            entrada(Agentes, &iContador);
            break;
        case 2: //buscar agente agente
            buscar(Agentes, &iContador);
            break;
        case 3: //eliminateEntrada un agente
            eliminateEntrada(Agentes, &iContador);
            break;
        case 4: //Salir
            printf("\nDatos almacenados!\nGraciar por usar el sistema.");
            bContinuar = false;
            break;
        default:
            break;
        }
    }
    return 0;
}