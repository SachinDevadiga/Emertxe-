#include "main.h"

int main()
{
	//Declare the variables
	slist *head = NULL;
	data_t data, n_data;
	int option, status;

	while(1)
	{
		//Prompt to select an option
		printf("1.Insert at first\n2.Insert at last\n3.Delete first\n4.Delete last\n5.Find Node\n6.Delete list\n7.Print list\n8.Exit\n");
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
				//Calling the delete first function
				status = delete_first(&head);
				if (status == SUCCESS)
				{
					printf("First node has been deleted\n\n");
				}
				else
				{
					printf("Unable to delete node\n\n");
				}
				break;

			case 4:
				//Calling the delete last function
				status = delete_last(&head);
				if (status == SUCCESS)
				{
					printf("Last node has been deleted\n\n");
				}
				else
				{
					printf("Unable to delete node\n\n");
				}
				break;
				
			case 5:
				//Prompt + read the node data
				printf("Enter node data: ");
				scanf("%d", &n_data);
				//Calling the find node function
				status = find_node(&head, n_data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Data is present\n\n");
				}
				else
				{
					printf("Data not present\n\n");
				}
				break;

			case 6:
				//Calling the delete list function
				status = delete_list(&head);
				if (status == SUCCESS)
				{
					printf("List is deleted\n\n");
				}
				else
				{
					printf("Unable to delete list\n\n");
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
				printf("Select a valid option\n");
		}
	}
}
