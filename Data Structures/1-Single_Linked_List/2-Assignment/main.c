#include "main.h"

int main()
{
	//Declare the variables here
	slist *head = NULL;
	data_t data, n_data, g_data, pos;
	int option, status;

	while(1)
	{
		//Prompt to select an option
		printf("1.Insert at first\n2.Insert at last\n3.Insert After\n4.Insert Before\n5.Insert nth\n6.Delete element\n7.Print list\n8.Exit\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1: 
				//Prompt + read the value
				printf("Enter the data: ");
				scanf("%d", &data);
				//Calling the insert at first function
				status = insert_at_first(&head, data);
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
				status = insert_at_last(&head, data);
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
				//Prompt + read the node data value
				printf("Enter the n_data: ");
				scanf("%d", &n_data);
				//Prompt + read the new data value
				printf("Enter the g_data: ");
				scanf("%d", &g_data);
				//Calling the insert after function
				status = insert_after(&head, n_data, g_data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data inserted after %d\n\n", n_data);
				}
				else
				{
					printf("Data %d not available\n\n", n_data);
				}
				break;

			case 4:
				//Prompt + read the node data value
				printf("Enter the n_data: ");
				scanf("%d", &n_data);
				//Prompt + read the new data value
				printf("Enter the g_data: ");
				scanf("%d", &g_data);
				//Calling the insert before function
				status = insert_before(&head, n_data, g_data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data inserted before %d\n\n", n_data);
				}
				else
				{
					printf("Data %d not available\n\n", n_data);
				}
				break;

			case 5:
				//Prompt + read the n value
				printf("Enter the pos value: ");
				scanf("%d", &pos);
				//Prompt + read the new data value
				//printf("Enter the g_data: ");
				//scanf("%d", &g_data);
				//Calling the insert before function
				status = insert_nth(&head, pos);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data inserted after the %d node\n\n", pos);
				}
				else
				{
					printf("%d is greater than the existing list\n\n", pos);
				}
				break;

			case 6:
				//Prompt + read the node data to be deleted
				printf("Enter the n_data: ");
				scanf("%d", &n_data);
				//Calling the delete element function
				status = delete_element(&head, n_data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Element Deleted\n\n");
				}
				else
				{
					printf("Element not available\n\n");
				}
				break;

			case 7:
				//Calling the list printing function
				print_slist(head);
				putchar('\n');
				break;

			case 8:
				//Exiting the while loop
				return 0;

			default: 
				printf("Please select a valid option\n");
				return 0;
		}
	}
}
