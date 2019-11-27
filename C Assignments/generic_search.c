#include <stdio.h>
#include <stdlib.h>

const void * generic_search(const void *key, void *base, size_t nmemb, size_t size, int (*comp)(const void *,const void *));
void populate(float *array, int array_size);
void populate_int(int *array, int array_size);
void populate_char(char *array, int array_size);
void populate_double(double *array, int array_size);
int comp(const void *a, const void *b);
int comp_char(const void *a, const void *b);
int comp_int(const void *a, const void *b);
int comp_double(const void *a, const void *b);

void populate(float *array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++)
	{
		printf("\narray[%d] :", i);
		scanf("%f", (array + i));
	}
}
void populate_int(int *array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++)
	{
		printf("\narray[%d] :", i);
		scanf("%d", (array + i));
	}
}
void populate_char(char *array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++)
	{
		printf("\narray[%d] :", i);
		scanf("\n\n%c", (array + i));
	}
}
void populate_double(double *array, int array_size)
{
	int i;
	for(i = 0; i < array_size; i++)
	{
		printf("\narray[%d] :", i);
		scanf("%lf", (array + i));
	}
}

const void * generic_search(const void *key,void *base, size_t nmemb, size_t size, int (*comp)(const void *,const void *))
{

	int i;
	printf("%ld\n", nmemb);
	for(i = 0; i < nmemb; i++)
	{
		printf("%d\t", i);
		if((*comp)(key, (base + (i * size))))
		{
			return (base + (i *size));
			break;
		}
		printf("%d\n", i);
	}
	printf("5");
	return NULL;
}

int comp(const void *a, const void *b)
{
	if (*(float *)a == *(float *)b)
	{
		printf("comp%f\n",*(float *)a );
		return 1;
	}
	printf("2\t");
	return 0;
}
int comp_char(const void *a, const void *b)
{
	if (*(char *)a == *(char *)b)
	{
		printf("comp%c\n",*(char *)a );
		return 1;
	}
	printf("2\t");
	return 0;
}
int comp_int(const void *a, const void *b)
{
	if (*(int *)a == *(int *)b)
	{
		printf("comp%d\n",*(int *)a );
		return 1;
	}
	printf("2\t");
	return 0;
}
int comp_double(const void *a, const void *b)
{
	if (*(double *)a == *(double *)b)
	{
		printf("comp%lf\n",*(float *)a );
		return 1;
	}
	printf("2\t");
	return 0;
}


int main()
{
	char option;
	int array_size, user_choice;
	float key;
	char key_char;
	int key_int;
	double key_double;

	system("clear");

	do
	{
		printf("Choice From Below Option:\n 1.char\n 2.int\n 3.float\n 4.double\n 5.string\nEnter Your Choice:");
		scanf("%d", &user_choice);

		switch(user_choice)
		{
			case 1:
					printf("Enter the size of the array:");
					scanf("%d", &array_size);
					
					char *array_char = malloc(array_size * sizeof(char));

					populate_char(array_char, array_size);

					printf("Enter the Key:");
					scanf("\n%c", &key_char);
					
					//int (*comp)(const void *, const void *) = comp;

				const	char *address_1 = generic_search(&key_char, array_char, array_size, sizeof(char), comp_char); 

					if (*address_1)
					{
						printf("\nAddress of the search %p: %c\n", address_1, *address_1);
					}
					else
					{
						printf("\nKey %c Not Found", key_char);
					}
					break;
			case 2:
					printf("Enter the size of the array:");
					scanf("%d", &array_size);
					
					int *array_int = malloc(array_size * sizeof(int));

					populate_int(array_int, array_size);

					printf("Enter the Key:");
					scanf("%d", &key_int);
					
					//int (*comp)(const void *, const void *) = comp;

				const	int *address_2 = generic_search(&key_int, array_int, array_size, sizeof(int), comp_int); 

					if (*address_2)
					{
						printf("\nAddress of the search %p:%d\n", address_2, *address_2);
					}
					else
					{
						printf("\nKey %d Not Found", key_int);
					}
					break;
			case 3:
					printf("Enter the size of the array:");
					scanf("%d", &array_size);
					
					float *array_float = malloc(array_size * sizeof(float));

					populate(array_float, array_size);

					printf("Enter the Key:");
					scanf("%f", &key);
					
					//int (*comp)(const void *, const void *) = comp;

					const float *address_3 = generic_search(&key, array_float, array_size, sizeof(float), comp); 

					if (*address_3)
					{
						printf("\nAddress of the search %p: %f\n", address_3, *address_3);
					}
					else
					{
						printf("\nKey %f Not Found", key);
					}
					break;
			case 4:
					printf("Enter the size of the array:");
					scanf("%d", &array_size);
					
					double *array_double = malloc(array_size * sizeof(double));

					populate_double(array_double, array_size);

					printf("Enter the Key:");
					scanf("%lf", &key_double);
					
				//int (*comp)(const void *, const void *) = comp;

					const double *address_4 = generic_search(&key_double, array_double, array_size, sizeof(double), comp_double); 

					if (*address_4)
					{
						printf("\nAddress of the search %p: %lf\n", address_4, *address_4);
					}
					else
					{
						printf("\nKey %lf Not Found", key_double);
					}
					break;
			default :
					printf("Invalid entry.....");

		}

		printf("\nDo you want to continue?[Y/N]:");
		scanf("\n\n%c", &option);
	}while (option == 'Y' || option == 'y');

	return 0;
}
