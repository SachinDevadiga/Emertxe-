#include "main.h"

int main()
{
	//Declare the variables
	data_t data;
	int option, status;

	s_array *s = malloc(sizeof(s_array));

	//Valdation
	if (s == NULL)
	{
		return FAILURE;
	}
	s->top = -1;
	while(1)
	{
		//Prompt to select an option
		printf("1.PUSH\n2.POP\n3.PEAK\n4.PEEP\n5.Exit\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				//Prompt + read the value
				printf("Enter the data: ");
				scanf("%d", &data);
				//Calling the push function
				status = push(s, data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
                {
				     printf("Data has been pushed\n\n");
                }
                else
                {
                     printf("Unable to push data\n\n");
                }
                break;

			
			case 2:

				//Calling the insert at last function
				status = pop(s, &data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data has been popped\n\n");
				}
				else
				{
					printf("Unable to pop data\n\n");
				}
				break;

			case 3:
				//Calling the delete first function
				status = peak(s, &data);
				if (status == SUCCESS)
				{
					printf("The peak element: %d\n\n", data);
				}
				else
				{
					printf("Unable to print peak element\n\n");
				}
				break;

			case 4:
				//Calling the delete last function
				peep(s);
				putchar('\n');	
				break;
			
			case 5:
				return 0;

			default:
				printf("Select a valid option\n");
		}
	}
}
