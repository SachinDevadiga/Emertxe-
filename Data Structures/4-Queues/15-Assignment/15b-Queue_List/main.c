#include "main.h"

int main()
{
	//Declare the variables
	slist *front = NULL;
	data_t data;

	int option, status;
	while(1)
	{
		//Prompt to select an option
		printf("1.Enqueue\n2.Dequeue\n3.Print Queue\n4.Exit\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				//Prompt + read the value
				printf("Enter the data: ");
				scanf("%d", &data);
				//Calling the push function
				status = enque(&front, data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
                {
				     printf("Data has been enqueued\n\n");
                }
                else
                {
                     printf("Queue Full\n\n");
                }
                break;

			
			case 2:

				//Calling the insert at last function
				status = deque(&front, &data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data %d has been dequeued\n\n", data);
				}
				else
				{
					printf("Queue Empty\n\n");
				}
				break;

			case 3:
				//Calling the delete first function
				status = print_queue(front);
				//Displaying result based on the return status from the function
				if (status != SUCCESS)
				{
					printf("Queue is empty\n\n");
				}
				
				break;

			case 4:
				return 0;

			default:
				printf("Select a valid option\n");
		}
	}
}
