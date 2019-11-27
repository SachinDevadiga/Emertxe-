#include "main.h"

int main()
{
	//Declare the variables
	Dlist *head = NULL;
	Dlist *tail = NULL;
	data_t data;
	int option, status;

	while(1)
	{
		//Prompt to select an option
		printf("1.Insert at first\n2.Insert at last\n3.Delete first\n4.Delete last\n5.Delete list\n6.Print from head\n7.Print from tail\n8.Exit\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				//Prompt + read the value
				printf("Enter the data: ");
				scanf("%d", &data);
				//Calling the insert at first function
				status = insert_first(&head, &tail, data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
                {
				     printf("Data inserted at the first\n\n");
                }
                else
                {
                     printf("Data not inserted at the first\n\n");
                }
                break;

			
			case 2:
				//Prompt + read the value
				printf("Enter the data: ");
				scanf("%d", &data);
				//Calling the insert at last function
				status = insert_last(&head, &tail, data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data inserted at the last\n\n");
				}
				else
				{
					printf("Data not inserted at last\n\n");
				}
				break;

			case 3:
				//Calling the delete first function
				status = delete_first(&head, &tail);
				if (status == SUCCESS)
				{
					printf("First node has been deleted\n\n");
				}
				else
				{
					printf("List is empty\n\n");
				}
				break;

			case 4:
				//Calling the delete last function
				status = delete_last(&head, &tail);
				if (status == SUCCESS)
				{
					printf("Last node has been deleted\n\n");
				}
				else
				{
					printf("List is empty\n\n");
				}
				break;
				

			case 5:
				//Calling the delete list function
				status = delete_list(&head, &tail);
				if (status == SUCCESS)
				{
					printf("List is deleted\n\n");
				}
				else
				{
					printf("List is empty\n\n");
				}
				break;

			case 6:
				//Calling the list printing function
				print_list(head, 1);
				putchar('\n');
				break;
			
			case 7:
				//Calling the list printing function
				print_list(tail, 0);
				putchar('\n');
				break;

			case 8:
				//Exiting the while loop
				return 0;

			default:
				printf("Select a valid option\n");
		}
	}
}
