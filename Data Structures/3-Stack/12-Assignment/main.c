#include "main.h"

int main()
{
	//Declare the variables
	slist *stack_top = NULL;
	data_t data;
	int option, status;

	
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
				status = push(&stack_top, data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
                {
				     printf("Data has been pushed\n\n");
                }
                else
                {
                     printf("Stack Full\n\n");
                }
                break;

			
			case 2:

				//Calling the pop function
				status = pop(&stack_top, &data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data %d has been popped\n\n", data);
				}
				else
				{
					printf("Stack Empty\n\n");
				}
				break;

			case 3:
				//Calling the peak function
				status = peak(&stack_top, &data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("The peak element: %d\n\n", data);
				}
				else
				{
					printf("Stack empty\n\n");
				}
				break;

			case 4:
				//Calling the peep function
				status = peep(stack_top);
				//Displaying result based on the return status from the function
				if (status != SUCCESS)
				{
					printf("Stack empty\n\n");
				}
				putchar('\n');	
				break;
			
			case 5:
				//Exiting from the loop
				return 0;

			default:
				printf("Select a valid option\n");
		}
	}
}
