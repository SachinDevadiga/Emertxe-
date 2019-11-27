#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure
typedef struct
{
	char *name;
	int roll_no;
	float *marks;
	float avg;
	char grade;
}student_t;

//Declare the functions
void populate(student_t *, size_t, size_t);
void avg_grade(student_t *, size_t, size_t);
void search_db(student_t *, char *, size_t, size_t, int);
void print_db(student_t *, size_t, size_t);

int main()
{
	//Clear the output screen
	system("clear");

	//Declare the variables
	size_t m, n;
	int select, method, num;
	char option, buffer[20] = {'\0'};

	do
	{
		//Prompt + Read the values
		printf("Enter the number of students: ");
		scanf("%zu", &m);

		printf("Enter the number of subjects: ");
		scanf("%zu", &n);

		//Allocating the memory for the structure
		student_t *p = malloc(m *  sizeof(student_t));
		if (!p)
		{
			perror("malloc");
			return 0;
		}

		//Calling the populate function
		populate(p , m, n);

		//Calling the average and grade function
		avg_grade(p, m, n);

		//Prompt + read the selection
		printf("Please enter your choice:\n1.Single student details\n2.All student's details\n");
		scanf("%d", &select);

		switch (select)
		{
			case 1:	
				//Prompt + read the method of search
				printf("Select your choice of search:\n1.Student's name\n2.Student's Roll No.\n");
				scanf("%d", &method);

				switch (method)
				{
					case 1:
						//Prompt + read the name
						printf("Enter the student's name: ");
						scanf("%s", buffer);

						//Calling the database search funtion
						search_db(p, buffer, m, n, num);
						break;

					case 2:		
						//Prompt + read the roll no
						printf("Enter the roll no: ");
						scanf("%d", &num);

						//Calling the database search function
						search_db(p, buffer, m, n, num);
						break;

					default:	
						printf("Invalid entry.. Please select option 1 or option 2\n");
						return 0;

				}
				break;

			case 2:
				//Calling the database display function
				print_db(p, m, n);
				break;

			default:
				printf("Invalid entry.. Please select option 1 or option 2\n");
				return 0;

		}

		//Prompt if the program is to be repeated
		printf("Do you wish to continue..Press [Yy | Nn]: ");
		scanf("\n%c", &option);

	}while (option == 'Y' || option == 'y');
	return 0;
}

//Defining the populate function
void populate(student_t *p, size_t m, size_t n)
{
	size_t i, j, SIZE;
	char buffer[20] = {'\0'};

	for (i = 0; i < m; i++)
	{
		printf("Enter the student name: ");
		scanf("%s", buffer);

		//Obtaining the string length
		SIZE = strlen(buffer);

		//Allocating the memory for the entered string name
		p[i].name = malloc(SIZE + 1);

		//Copying the data from buffer to the allocated memory
		strcpy(p[i].name, buffer);

		//Prompt + read the value
		printf("Enter the roll number: ");
		scanf("%d", &p[i].roll_no);

		printf("Enter the subject marks: ");

		//Allocating the memory for storing the marks
		p[i].marks = malloc(n * sizeof(float));
		for (j = 0; j < n; j++)
		{
			scanf("%f",p[i].marks +j);
		}
		//Resetting the buffer to hold new values for the next itiration
		memset(buffer, '\0', 20);
	}
}

//Defining the average and grading function
void avg_grade(student_t *p, size_t m, size_t n)
{
	size_t i, j;
	float sum, avg;

	for (i = 0; i < m; i++)
	{	
		sum = 0;
		for (j = 0; j < n; j++)
		{
			sum += *(p[i].marks + j);
		}
		p[i].avg = sum / n;

		//Assigning the grade based on the average
		if(p[i].avg >= 90)
		{
			p[i].grade = 'A';
		}
		else if(p[i].avg >= 80 && p[i].avg < 90)
		{
			p[i].grade = 'B';
		}
		else if(p[i].avg >= 70 && p[i].avg < 80)
		{
			p[i].grade = 'C';
		}
		else if(p[i].avg >= 60 && p[i].avg < 70)
		{
			p[i].grade = 'D';
		}
		else if(p[i].avg >= 50 && p[i].avg < 60)
		{
			p[i].grade = 'E';
		}
		else
		{
			p[i].grade = 'F';
		}
	}
}

//Defining the search function
void search_db(student_t *p, char *student_name, size_t m, size_t n, int roll_no)
{
	size_t i, j;
	for (i = 0; i < m; i++)
	{
		if(*(p[i].name) == *student_name || p[i].roll_no == roll_no)
		{
			printf("Student name: %s\nRoll_no: %d\nMarks: ", p[i].name, p[i].roll_no);

			for (j = 0; j < n; j++)
			{
				printf("%f ", *(p[i].marks + j));
			}

			printf("\nAverage: %f\nGrade: %c\n", p[i].avg, p[i].grade);
			return ;
		}
	}
	printf("Student not found in database: \n");
}

//Defining the database print function
void print_db(student_t *p, size_t m, size_t n)
{
	size_t i, j;
	for (i = 0; i < m; i++)
	{
		printf("Student name: %s\nRoll_no: %d\nMarks: ", p[i].name, p[i].roll_no);

		for (j = 0; j < n; j++)
		{
			printf("%f ", *(p[i].marks + j));
		}

		printf("\nAverage: %f\nGrade: %c\n", p[i].avg, p[i].grade);
	}
}
