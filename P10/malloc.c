//
//  main.c
//  mision_1
//
//  Created by Oscar Francisco Lopez Escobar on 05/03/2020
//  A01561676
//  Copyright © 2020 Pacorobot. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char temporal [15];
char bigafString [100];
char numeros [20];
int revolver[20];
int new [20];
int c = 0;


void randomize(int n) {
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < n; i++) {
        new[i]=revolver[rand()%n];
    }
    for (int i = 0; i < n; i++) {
        revolver[i]=new[i];
    }

}


void asignaMision(){
    char tmp [14];
    printf("ID agente(4 letras 9 digitos): ");
    scanf("%s",tmp);
    for (int i = 0; i<13; i++) {
        if (i>=4) {
            if(!(tmp[i]>='0'&&tmp[i]<='9')){
                printf("Incorrecto ingrese de nuez");
                asignaMision();
            }
        }else{
            if(!((tmp[i]>='a'&&tmp[i]<='z')||(tmp[i]>='A'&&tmp[i]<='Z'))){
                printf("Incorrecto ingrese de nuevo");
                asignaMision();
            }
        }
        
        }
    for (int j = 0; j<13; j++) {
        temporal[j]=tmp[j];
    }
    
}



void separa(){
    int i = 0;
    int t = 0;
    while (bigafString[i] != '\0'){
        //encuentra
        if(bigafString[i]==','){
            t=0;
        }else if (bigafString[i]!= ' ' && t == 0){
            if(bigafString[i]== 'c'){
                if (bigafString[i+1]=='u') {
                    numeros[c]='q';
                    c++;
                    t=1;
                }else{
                    numeros[c]='c';
                    c++;
                    t=1;
                }
            }else if(bigafString[i]== 's'){
                if (bigafString[i+1]=='e') {
                    numeros[c]='s';
                    c++;
                    t=1;
                }else{
                    numeros[c]='z';
                    c++;
                    t=1;
                }
            }else if(bigafString[i]== 'd'){
                if (bigafString[i+1]=='i') {
                    numeros[c]='e';
                    c++;
                    t=1;
                }else{
                    numeros[c]='d';
                    c++;
                    t=1;
                }
                
            }else{
            numeros[c] = bigafString[i];
            c++;
            t=1;
                
            }
        }
        i++;
    }
}

void imprime(int n){
    for (int i = 0; i<4; i++) {
        printf("%c",temporal[i]);
    }
    for (int i = 0; i < n; i++) {
            printf("%d", revolver[i]);
        }
}


void numerador(char a, int n){
    if (a=='u'){
        revolver[n] = 1;
    }else if(a=='d'){
        revolver[n] = 2;
    }else if(a=='t'){
        revolver[n] = 3;
    }else if(a=='q'){
        revolver[n] = 4;
    }else if(a=='c'){
        revolver[n] = 5;
    }else if(a=='s'){
        revolver[n] = 6;
    }else if(a=='z'){
        revolver[n] = 7;
    }else if(a=='o'){
        revolver[n] = 8;
    }else if(a=='n'){
        revolver[n] = 9;
    }else if(a=='e'){
        revolver[n] = 10;
    }
}
void cambia(){
    int i = 0;
    while (i<c) {
        numerador(numeros[i], i);
        i++;
    }
    imprime(i);
    randomize(i);
    printf("\n");
    imprime(i);
}
void numeritos (){
    printf("Numero separados por coma\n");
    scanf("%s", bigafString);
    separa();
    cambia();
    
        
}

void io(){
    asignaMision();
    numeritos();
    
}


int main(){
    io();
    return 0;
    
}





