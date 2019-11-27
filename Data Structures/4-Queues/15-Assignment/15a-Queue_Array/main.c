#include "main.h"

int main()
{
	//Declare the variables
	data_t data;
	int option, status;
	
	//Allocating the memory for the array
	Q_array *Q = malloc(sizeof(Q_array));

	//Valdation
	if (Q == NULL)
	{
		return FAILURE;
	}
	//Initialising the location pointing variable values
	Q->front = -1;
	Q->rear = -1;
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
				//Calling the enque function
				status = enque(Q, data);
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

				//Calling the deque function
				status = deque(Q, &data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data %d has been dequeued\n\n", data);
				}
				else
				{
					printf("Queue empty\n\n");
				}
				break;

			case 3:
				//Calling the print queue function
				status = print_queue(Q);
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
