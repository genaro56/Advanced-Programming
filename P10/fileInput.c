... if (!errorFlag)
{
    rewind(ptrFile); //Must use attribute "w+” while opening
    while (fread(&student, sizeof(struct _student), 1, ptrFile) && (!errorFlag))
        if (!feof(ptrFile))
            printf("%d %s %s\n", student.studentID, student.fname, student.lname);
        else
        {
  printf(”Error while reading\n");
  errorFlag=1;
        }
}
if (fclose(ptrFile) == 0)
  printf(”File closed\n");
  else
  printf(”Error in fclose op.");
}
else
{
    printf("Error in fopen op.\n");
}
}
