#include<stdio.h>

typedef struct{
	int id;
	char name[30];
	float price;
	int quantity;
}Product;	

void add_product(Product *s){
	FILE *fp;

	fp = fopen("inventory.txt", "a");

	if(fp == NULL){
		printf("Error");
	}
	else{
		printf("Enter ID: ");
		scanf("%d", &s->id);
		printf("Enter name: ");
		scanf("%s", s->name);
		printf("Enter price: ");
		scanf("%f", &s->price);
		printf("Enter amount: ");
		scanf("%d", &s->quantity);

		fprintf(fp, "%d %s %.2f %d\n", s->id, s->name, s->price, s->quantity);
		fclose(fp);

		printf("Product added successfully");
	}
}

void display_all(Product *s){
	FILE *fp;

	fp = fopen("inventory.txt", "r");

	if(fp == NULL){
		printf("Error");
	}
	else{
		while(fscanf(fp, "%d %s %f %d", &s->id, s->name, &s->price, &s->quantity) == 4){
			printf("\tProduct: %s || ID: %d || Price: %.2f || Stock: %d\n", s->name, s->id, s->price, s->quantity);
		}
		fclose(fp);
	}
}

void Calc(Product *s){
	float total = 0.0;
	FILE *fp;

	fp = fopen("inventory.txt", "r");	

	if(fp == NULL){
		printf("Error");
	}
	else{
		while(fscanf(fp, "%d %s %f %d", &s->id, s->name, &s->price, &s->quantity) == 4){
			total += (s->quantity * s->price);
		}
		fclose(fp);
		printf("Total is: %.2f\n", total);
	}
}

void search_product(Product *s){
	int search_id = 0, found = 0;
	FILE *fp;

	fp = fopen("inventory.txt", "r");

	if(fp == NULL){
		printf("Error\n");
	}
	else{
		printf("Enter search ID: ");
		scanf("%d", &search_id);

		while(fscanf(fp, "%d %s %f %d", &s->id, s->name, &s->price, &s->quantity) == 4){
			if(s->id == search_id){
				printf("Product: %s\n", s->name);	
				found = 1;
			}
		}

		if(found == 0){
			printf("Product not found\n");
		}
		fclose(fp);
	}
}

void update_inventory(Product *s){
	int target_id = 0, found = 0;
	FILE *fp;
	FILE *temp;

	fp = fopen("inventory.txt", "r");

	if(fp == NULL){
		printf("Error\n");
	}
	else{
		temp = fopen("temp.txt", "w");
		if(temp == NULL){
			printf("Error\n");
		}
		else{
			printf("Enter ID to update product: ");
			scanf("%d", &target_id);

			while(fscanf(fp, "%d %s %f %d", &s->id, s->name, &s->price, &s->quantity) == 4){
				if(s->id == target_id){
					printf("Product %s to update quantity: ", s->name);
					scanf("%d", &s->quantity);
					found = 1;
				}

			fprintf(temp, "%d %s %.2f %d\n", s->id, s->name, s->price, s->quantity);
			}

			fclose(fp);
			fclose(temp);

			if(found == 1){
				remove("inventory.txt");
				rename("temp.txt", "inventory.txt");
				printf("Update successful!");
			}
			else{
				remove("temp.txt");
				printf("ID not found, no changes made\n");
			}
		}
	}
}

int main(){
	Product s;
	int opt;
	int run = 1;

	while(run == 1){
		do{
			printf("\t1. Add product \t2. Show list \t3. Inventory total \t4. Search product");
			printf("\t5. Update inventory \t6. Quit");
			printf("\nChose an option: ");
			scanf(" %d", &opt);
		}while(!(1 <= opt && opt <= 6));

	
		switch(opt){
			case 1: 
				add_product(&s);
			break;
			case 2:
				display_all(&s);
			break;
			case 3:
				Calc(&s);
			break;
			case 4:
				search_product(&s);
			break;
			case 5:
				update_inventory(&s);
			break;
			case 6:
				printf("Goodbye!\n");
				run = 0;
			break;
			default:
				printf("Invalid option!!\n");
			break;
		}
	}
return 0;
}
