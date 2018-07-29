//Gurkan Gokdemir
#include <stdio.h>
#include <stdlib.h>

int concat(int x, int y)
{
    char str1[20];
    char str2[20];

    sprintf(str1,"%d",x);
    sprintf(str2,"%d",y);

    strcat(str1,str2);

    return atoi(str1);
}


int readline(FILE *f, char *buffer, size_t len)
{
    char c;
    int i;

    memset(buffer, 0, len);

    for (i = 0; i < len; i++)
    {
        int c = fgetc(f);

        if (!feof(f))
        {
            if (c == '\r')
                buffer[i] = 0;
            else if (c == '\n')
            {
                buffer[i] = 0;

                return i+1;
            }
            else
                buffer[i] = c;
        }
        else
        {
            fprintf(stderr, "read_line(): recv returned %d\n", c);
            return -1;
        }
    }

    return -1;
}

int main()
{
    char no_namesurname[100];


    int new_second_education_students = 1;
    int new_first_education_students = 1;
    int planner;
    int pass = 0;
    printf("\nWelcome to the Class Planner by gurkangokdemir!\n\n");

    while(pass==0)
    {

        printf("What is your plan ? You can use numbers to choose. \n");
        printf("    Delete same people in database then refresh the database : [press 1]\n");
        printf("    Just delete blank lines in the the database : [press 2]\n");
        printf("    Generate student numbers to new students in the database : [press 3]\n");
        printf("    Sort students in the database by student number : [press 4]\n");
        printf("    Distrubute students in the database to the classes : [press 5]\n");
        printf("    Add new student to the database : [press 6]\n\n - ");
        scanf("%d",&planner);
        printf("\n");

        switch (planner)
        {
        case 1:
            printf("Delete same people in database... \n - ");
            char filename[] = "file.txt";
            FILE *file2 = fopen ( filename, "r" );

            if (file2 != NULL)
            {

                char line [1000];
                char line_check [1000];
                int counter = 0;
                int filesdeletecount=0;
                int filesdelete[100];

                while(!feof(file2))
                {
                    fgets(line_check,sizeof line_check,file2);
                    printf("********%s \n",line_check);

                    FILE *file = fopen ( filename, "r" );
                    int i;

                    counter=0;
                    int isdelete = 0;
                    while(!feof(file))
                    {

                        if (!strcmp(line_check,line))
                        {

                            printf("%s %s is equal \n",line_check,line);

                            fgets(line,sizeof line,file);


                            counter++;
                            isdelete++;
                            if(isdelete>1)
                            {
                                filesdeletecount++;
                                printf("--------------------------------------------------%d line will be delete \n",counter);
                                filesdelete[filesdeletecount]=counter;
                            }
                        }
                        if (strcmp(line_check,line))
                        {


                            printf("%s %s Not equal \n",line_check,line);

                            fgets(line,sizeof line,file);
                            counter++;

                        }
                    }
                    fclose(file);
                }


                fclose(file2);

                FILE *fileptr3, *fileptr4;

                char filename5[40] = "file.txt";
                char ch;
                char linee [100];
                char linee_check [100] = "emp";
                int delete_line, temp = 1;

                fileptr3 = fopen(filename5, "r");
                int i=0, j=0, k=0;
                printf("\nLines gonne be delete  : ");
                for (i = 0; i < filesdeletecount; i++)
                {
                    for (j = i + 1; j < filesdeletecount;)
                    {
                        if (filesdelete[j] == filesdelete[i])
                        {
                            for (k = j; k < filesdeletecount; k++)
                            {
                                filesdelete[k] = filesdelete[k + 1];
                            }
                            filesdeletecount--;
                        }
                        else
                            j++;
                    }
                }

                for (i = 1; i < filesdeletecount-1; i++)
                {
                    printf("%d ", filesdelete[i]);
                    delete_line = filesdelete[i]-1;
                    printf(" \n  deleteline is %d \n  ",delete_line);

                    fileptr4 = fopen("replica.c", "w");
                    ch = 'A';
                    while (ch != EOF)
                    {
                        ch = getc(fileptr3);

                        if (temp != delete_line)
                        {

                            putc(ch, fileptr4);
                        }
                        if (ch == '\n')
                        {
                            temp++;
                        }
                    }
                    fclose(fileptr3);
                    fclose(fileptr4);
                    remove(filename5);

                    rename("replica.c", filename5);
                    printf("\n The contents of file after being modified are as follows:\n");
                    fileptr3 = fopen(filename5, "r");
                    ch = getc(fileptr3);
                    while (ch != EOF)
                    {
                        printf("%c", ch);
                        ch = getc(fileptr3);
                    }
                    fclose(fileptr3);

                }

            }

            else
            {
                perror(filename);
            }
            pass = 1;
            break;

        case 2:
            printf("Deleting blank lines in database... \n");

            char lines[300];
            int emptyLine = 0;
            FILE *fp = fopen("file.txt", "r");
            FILE *fp2 = fopen("newfile.txt","w");
            if (fp == NULL)
            {
                printf("Error: Could not open specified file!\n");
                return -1;
            }
            else
            {
                while(fgets(lines, 300, fp))
                {
                    int i = 0;
                    int len = strlen(lines);
                    emptyLine++;
                    for (i = 0; i < len; i++)
                    {
                        if (lines[i] != '\n' && lines[i] != '\t' && lines[i] != ' ')
                        {
                            emptyLine--;
                            printf("%s",lines);

                            fprintf(fp2,lines);

                            break;
                        }
                        else
                        {
                            break;
                        }

                    }
                }
                fclose(fp);
                fclose(fp2);
                remove("file.txt");

                rename("newfile.txt", "file.txt");

            }

            printf("\n\n");

            pass = 1;
            break;


        case 3:
            printf("Generate student numbers to new students... \n - ");
            char line [1000];
            char line_check [1000];

            fgets(line_check,sizeof line_check,file2);
            printf("***%s \n",line_check);

            FILE *file4 = fopen ( filename, "r" );
            fgets(line,sizeof line,file4);

            int second_education = 0;
            int student_number = 0;
            printf("New student's number is %d \n",student_number );
            if(second_education == 0)
            {
                student_number = concat(1702,0);
                student_number = concat(student_number,2);
                printf("New student's number is %d \n",student_number );
                if(new_first_education_students < 10)
                {
                    student_number = concat(student_number,0);
                    printf("New student's number is %d \n",student_number );
                    student_number = concat(student_number,new_second_education_students);
                    printf("New student's number is %d \n",student_number );
                }
                else
                {
                    student_number = concat(student_number,new_second_education_students);
                    printf("New student's number is %d \n",student_number );
                }
                new_second_education_students++;
            }

            else
            {
                student_number = concat(1702,0);
                student_number = concat(student_number,1);
                printf("New student's number is %d \n",student_number );
                if(new_first_education_students < 10)
                {
                    student_number = concat(student_number,0);
                    printf("New student's number is %d \n",student_number );
                    student_number = concat(student_number,new_first_education_students);
                    printf("New student's number is %d \n",student_number );
                }
                else
                {
                    student_number = concat(student_number,new_first_education_students);
                    printf("New student's number is %d \n",student_number );
                }
                new_first_education_students++;
            }
            printf("New student's number is %d \n",student_number );
            pass = 1;
            break;

        case 4:

            printf("Sort students by student number...   \n");

            char filename2[] = "file.txt";

            FILE *file = fopen ( filename2, "r" );

            if (file != NULL)
            {
                char line [1000];

                while(fgets(line,sizeof line,file)!= NULL)
                {
                    fprintf(stdout,"%s",line);
                    char token [1000];

                }
            }

            pass = 1;
            break;

        case 5:
            printf("Distrubute students to the classes... \n");
            printf("How many classes do you have? \n ");
            int choose=0;
            while(choose != 1 || choose != 2)
            {
                printf("Do you want to distribute students equally to classes [press 1]\n or distribute in order? [press 2] \n - ");
                scanf("%d",&choose);
                if (choose == 1)
                {
                    int classes=0;
                    printf("Students are distributing equally. \n");

                    printf("How many classes do you have? = ");
                    scanf("%d",&classes);

                    char filename[] = "file.txt";
                    FILE *fp = fopen(filename,"r");
                    int ch=0;
                    int lines=0;

                    int allclasses[100];
                    if (fp == NULL)
                    {
                        printf("There is no file that you called \n");
                        return 0;
                    }

                    while(!feof(fp))
                    {
                        ch = fgetc(fp);
                        if(ch == '\n')
                        {
                            lines++;
                        }
                    }
                    fclose(fp);

                    printf("You have %d students. \n ",lines);
                    int free_stdnt=0;
                    free_stdnt=lines % classes;
                    printf("free students whitout having class = %d \n", free_stdnt);
                    if( free_stdnt == 0)
                    {
                        printf("No problem detected students has distributed equally \n");

                    }
                    if(free_stdnt != 0)
                    {
                        printf("Distribution is :  \n");

                        int i;
                        for (i=0 ; i<free_stdnt ; i++)
                        {
                            allclasses[i]=(lines/classes)+1;
                        }
                        int j;
                        for (j=free_stdnt ; j<free_stdnt+classes-free_stdnt ; j++)
                        {
                            allclasses[i]=(lines/classes);
                        }
                        for (i=0 ; i<classes ; i++)
                        {
                            printf(" - %d \n ", allclasses[i]);
                        }

                    }

                    int z;
                    for (z=0; z < classes; z++)
                    {
                        printf("allclasses[%d] = %d \n",z,allclasses[z]);





                        printf("%d th class has %d students \n",z+1,allclasses[z]);

                        char filename[] = "file.txt";
                        char newfile[100];
                        FILE *file7 = fopen ( filename, "r" );

                        if (file7 != NULL)
                        {

                            char line [1000];

                            int j=0;
                            printf("\n please insert a new class name :\n ");
                            scanf("%s",&newfile);

                            FILE *file0 = fopen ( newfile, "a" );

                            for(j=0; j<allclasses[z]; j++)

                            {
                                fgets(line,sizeof line,file7);

                                printf("%s \n",line);
                                fprintf(file0,line);
                            }
                            fclose(file7);

                        }





                    }

                    break;
                }
                if (choose == 2)
                {
                    int capability=0;
                    printf("Students are distributing in order. \n");
                    printf("How many student capability do you have by class? = ");
                    scanf("%d",&capability);

                    char filename[] = "file.txt";
                    FILE *fp = fopen(filename,"r");
                    int ch=0;
                    int lines=0;

                    if (fp == NULL)
                    {
                        printf("There is no file that you called \n");
                        return 0;
                    }

                    while(!feof(fp))
                    {
                        ch = fgetc(fp);
                        if(ch == '\n')
                        {
                            lines++;
                        }
                    }
                    fclose(fp);

                    printf("You have %d students. \n ",lines);
                    int classnumber = 0;
                    int allclasses2 [100];
                    while (capability <= lines)
                    {

                        lines = lines - capability ;
                        classnumber++;
                        allclasses2[classnumber-1]=capability;
                    }

                    if(capability != lines)
                    {
                        classnumber++;
                        int extraclassstudents = lines;
                        allclasses2[classnumber-1]=lines;
                    }
                    printf("You must use %d classes \n",classnumber);
                    int a;
                    for(a=0; a<classnumber; a++)
                    {
                        printf("%d th class has %d students \n",a+1,allclasses2[a]);

                        char filename[] = "file.txt";
                        char newfile[100];
                        FILE *file5 = fopen ( filename, "r" );

                        if (file5 != NULL)
                        {

                            char line [1000];

                            int j=0;
                            printf("\n please insert a new class name :\n ");
                            scanf("%s",&newfile);

                            FILE *file6 = fopen ( newfile, "a" );

                            for(j=0; j<allclasses2[a]; j++)

                            {
                                fgets(line,sizeof line,file5);

                                printf("%s \n",line);
                                fprintf(file6,line);
                            }
                            fclose(file5);

                        }

                    }
                    break;

                }

            }

            pass = 1;
            break;

        case 6:

            printf("Add new student... \n  ");
            printf("Please insert a student number name and surname with '-': \n - ");
            scanf("%s",&no_namesurname);

            char filename3[] = "file.txt";

            FILE *file3 = fopen ( filename3, "a" );

            fprintf(file3,no_namesurname);

            pass = 1;
            break;

        default:
            printf("Choose a number between 1 - 6 \n ");
            pass = 0;
        }

    }

    return 0;
}
