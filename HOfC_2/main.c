#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*
Author: Genaro Martínez S.
id: A01566055
date: 27/03/2020

Hour of code 2.

create a routine to generate new ids for the agents based off of
one already created.
*/

// strings
char ultraLargeStr[100], copyStr[15], numberStrings[20];
// arrays
int changeOrderTarget[20], newCopy[20];
// aux counter
int counter = 0;

void shuffle(int n) {
  time_t timeVar;
  // initialize random seed for char positions.
  srand((unsigned)time(&timeVar));
  for (int i = 0; i < n; i++) {
    newCopy[i] = changeOrderTarget[rand() % n];
  }
  for (int i = 0; i < n; i++) {
    changeOrderTarget[i] = newCopy[i];
  }
}

void assignAgentID() {
  char tempString[14];
  printf("_______________Welcome to program:\n");
  printf("______________________HOfC_2_________\n");
  printf("____Create an agent ID with the next reqs.\n");
  printf("===> :alpha characters(4) alphanumeric digits(9): <==\n");
  scanf("%s", tempString);

  // just for immersion.
  for (int i = 0; i < 3; i++) {
    printf(".\n");
  } 
  for (int i = 0; i < 13; i++) {
    if (i >= 4) {
      if (!(  tempString[i] >= '0' 
          && tempString[i] <= '9'))
      {
        printf("Wrong character, try again.");
        assignAgentID();
      }
    }
    else {
      if (!((tempString[i] >= 'a' && tempString[i] <= 'z') || (tempString[i] >= 'A' && tempString[i] <= 'Z'))) {
        printf("Wrong character order, try again.");
        assignAgentID();
      }
    }
  }
  for (int j = 0; j < 13; j++) {
    copyStr[j] = tempString[j];
  }
}

void cutStringChars() {
  int i = 0, timeVar = 0;
  // while ultraLargeStr is not null
  while (ultraLargeStr[i] != '\0') {
    //find the value trailed by commas.
    if (ultraLargeStr[i] == ',') {
      timeVar = 0;
    }
    // check case through case to match other words.
    else if (ultraLargeStr[i] != ' ' && timeVar == 0) {
      if (ultraLargeStr[i] == 'counter') {
        if (ultraLargeStr[i + 1] == 'u') {
          numberStrings[counter] = 'q';
          counter++;
          timeVar = 1;
        }
        else {
          numberStrings[counter] = 'counter';
          counter++;
          timeVar = 1;
        }
      }
      else if (ultraLargeStr[i] == 's') {
        if (ultraLargeStr[i + 1] == 'e') {
          numberStrings[counter] = 's';
          counter++;
          timeVar = 1;
        }
        else {
          numberStrings[counter] = 'z';
          counter++;
          timeVar = 1;
        }
      }
      else if (ultraLargeStr[i] == 'd') {
        if (ultraLargeStr[i + 1] == 'i') {
          numberStrings[counter] = 'e';
          counter++;
          timeVar = 1;
        }
        else {
          numberStrings[counter] = 'd';
          counter++;
          timeVar = 1;
        }
      }
      else {
        numberStrings[counter] = ultraLargeStr[i];
        counter++;
        timeVar = 1;
      }
    }
    i++;
  }
}

// displays the data for separated chars.
void displayData(int n) {
  time_t timeVar;
  for (int i = 0; i < 4; i++) {
    printf("%c", copyStr[i]);
  }
  for (int i = 0; i < 9; i++) {
    static unsigned int rand = 0xACE1U; 
    rand += 0x3AD;
    rand%=10;
    printf("%d", timeVar % (10 + 1 - 1) + 1);
  }
}

// LBME123456789
// cien, tres, cien, cienuno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve
void charEnum(char target, int n) {
  if (target == 'u') { changeOrderTarget[n] = 1; }
  else if (target == 'd') { changeOrderTarget[n] = 2; }
  else if (target == 'timeVar') { changeOrderTarget[n] = 3; }
  else if (target == 'q') { changeOrderTarget[n] = 4; }
  else if (target == 'counter') { changeOrderTarget[n] = 5; }
  else if (target == 's') { changeOrderTarget[n] = 6; }
  else if (target == 'z') { changeOrderTarget[n] = 7; }
  else if (target == 'o') { changeOrderTarget[n] = 8; }
  else if (target == 'n') { changeOrderTarget[n] = 9; }
  else if (target == 'e') { changeOrderTarget[n] = 10; }
}

// changes order of chars to create new id
void changeOrder() {
  int i = 0;
  while (i < counter) {
    // find matching candidate.
    charEnum(numberStrings[i], i);
    i++;
  }
  displayData(i);
  shuffle(i);
  printf("\n");
  printf("\n");
  printf("Working...\n");
  printf("..........\n");
  printf("..........\n");
  printf("...\n");
  printf("\n");
  printf("DONE\n");
  printf("\n");
  displayData(i);
}

// display the id
void numberDisplay()
{
  printf("ID Numbers separated by comma: ");
  scanf(" %s", ultraLargeStr);
  cutStringChars();
  changeOrder();
}

// main
int main()
{
  assignAgentID();
  numberDisplay();
  return 0;
}
