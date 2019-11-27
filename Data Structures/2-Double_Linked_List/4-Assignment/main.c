#include "main.h"

int main()
{
	//Declare the variables
	Dlist *head = NULL;
	Dlist *tail = NULL;
	data_t data, n_data, g_data;
	int option, status;

	while(1)
	{
		//Prompt to select an option
		printf("1.Insert element\n2.Insert after\n3.Insert before\n4.Delete element\n5.Print from head\n6.Print from tail\n7.Exit\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				//Prompt + read the value
				printf("Enter the data: ");
				scanf("%d", &data);
				//Calling the insert element function
				status = insert_element(&head, &tail, data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Element has been inserted\n\n");
				}
				else
				{
					printf("Element not inserted\n\n");
				}
				break;

			case 2:
				//Prompt + read the n_data value
				printf("Enter n_data value: ");
				scanf("%d", &n_data);
				//Prompt + read the g_data value
				printf("Enter g_data value: ");
				scanf("%d", &g_data);
				//Calling the insert after function
				status = insert_after(&head, &tail, n_data, g_data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Element %d has been inserted after %d\n\n", g_data, n_data);
				}
				else
				{
					printf("Element not inserted\n\n");
				}
				break;

			case 3:
				//Prompt + read the n_data value
				printf("Enter n_data value: ");
				scanf("%d", &n_data);
				//Prompt + read the g_data value
				printf("Enter g_data value: ");
				scanf("%d", &g_data);
				//Calling the insert before function
				status = insert_before(&head, &tail, n_data, g_data);
				//Displaying result based on the return status from the function
				if (status == SUCCESS)
				{
					printf("Element %d has been inserted before %d\n\n", g_data, n_data);
				}
				else
				{
					printf("Element not inserted\n\n");
				}
				break;

			case 4:
				//Prompt + read the n_data value
				printf("Enter n_data value: ");
				scanf("%d", &n_data);
				//Calling the delete element function
				status = delete_element(&head, &tail, n_data);
				if (status == SUCCESS)
				{
					printf("Element %d is deleted\n\n", n_data);
				}
				else
				{
					printf("Element not found\n\n");
				}
				break;

			case 5:
				//Calling the list printing function
				print_list(head, 1);
				putchar('\n');
				break;
			
			case 6:
				//Calling the list printing function
				print_list(tail, 0);
				putchar('\n');
				break;

			case 7:
				//Exiting the while loop
				return 0;

			default:
				printf("Select a valid option\n");
		}
	}
}
