
#include<stdio.h>
typedef struct  {
	char id[20];
	char title[100];
	char author[100];
	char price[30];
	char category[20];

}Book;
void searchBook(Book book[],int*n,char title);
void sortBook(Book book[],int*n);
void updateBook(Book book[],char id[],int *n);
void moreBook(Book book[],int* n , int index);
void menu();
void printBook(Book book[],int* n);
void addBook(Book book[],int* n);
void deleteBook(Book book[], char id[],int*n);
int main(){
	char nameCheck[20];
	int choice;
	int position;
	Book book[100];
	int n;
	char idCheck[20];
do{
	menu();
	printf("Moi ban nhap lua chon\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("Nhap so luong sach \n");
			scanf("%d",&n);
			addBook(book,&n);
			break;
		
		case 2:
			printBook(book,&n);
			break;
		
		case 3:
		printf("Moi ban nhap vi tri can them : ");
		scanf("%d",&position);
		moreBook(book, &n,position);
			break;
		case 4:
			printf("moi ban nhap id : ");
			fflush(stdin);
		fgets(idCheck, sizeof(idCheck), stdin);
			deleteBook(book,idCheck,&n);
			break;
			
		case 5:
				printf("moi ban nhap id : ");
			fflush(stdin);
			fgets(idCheck, sizeof(idCheck), stdin);
			updateBook(book,idCheck,&n);
			break;
			
		case 6:
			sortBook(book,&n);
			break;
		case 7:
			fflush(stdin);
			printf("moi ban nhap ten : ");
			fgets(nameCheck,sizeof(nameCheck),stdin);
			searchBook(book,n,nameCheck);
		break;
			
	}
	
}while(choice !=8);



return 0;

}
menu(){
	printf("\nMenu\n");
	printf("1. Nhap so luong va thong tin sach\n");
	printf("2. Hien thi thong tin  sach\n");
	printf("3. Them sach vao vi tri\n");
	printf("4. Xoa sach theo ma sach\n");
	printf("5. Cap nhap thong tin sach theo ma sach\n");
	printf("6. sap xep sach thep gia\n");
	printf("7. tim kiem sach theo ten sach\n");
	printf("8. Thoat\n");
}
addBook(Book book[],int* n){
	for (int i =0;i<*n ;i++){
		fflush(stdin);
		printf("moi ban nhap thong tin sach thu %d\n",i+1);
		printf("Ma Sach : \n");
		fgets(book[i].id,sizeof(book[i]).id,stdin);
	
		printf("Ten Sach : \n");
		fgets(book[i].title,sizeof(book[i]).title,stdin);
	
		printf("Ten Tac Gia : \n");
		fgets(book[i].author,sizeof(book[i]).author,stdin);
	
		printf("Gia Tien : \n");
	
		fgets(book[i].price,sizeof(book[i]).price,stdin);
	
		printf("The Loai : \n");		
		fgets(book[i].category,sizeof(book[i]).category,stdin);	
	}
}
void printBook(Book book[],int* n){
	for ( int i =0;i<*n;i++){
		printf("Ma sach : %s\n",book[i].id);
		printf("Ten sach : %s\n",book[i].title);
		printf("Ten Tac Gia  : %s\n",book[i].author);
		printf("Gia tien : %s\n",book[i].price);
		printf("The Loai : %s\n",book[i].category);
	}
}
void moreBook(Book book[],int*n, int index){
		fflush(stdin);
		
		printf("Ma Sach : \n");
		fgets(book[index-1].id,sizeof(book[index-1]).id,stdin);
	
		printf("Ten Sach : \n");
		fgets(book[index-1].title,sizeof(book[index-1]).title,stdin);
	
		printf("Ten Tac Gia : \n");
		fgets(book[index-1].author,sizeof(book[index-1]).author,stdin);
	
		printf("Gia Tien : \n");
		fgets(book[index-1].price,sizeof(book[index-1]).price,stdin);
	
		printf("The Loai : \n");		
		fgets(book[index-1].category,sizeof(book[index-1]).category,stdin);	
		(*n)++;
}
void deleteBook(Book book[], char id[], int *n){
	for(int i=0;i<*n;i++){
		if(strcmp(book[i].id,id)==0){
			for(int j =i;j<*n;j++){
				book[j]=book[j+1];
			}
		}
		
	}
	(*n)--;
}
void updateBook(Book book[],char id[],int *n){
	for(int i=0;i<*n;i++){
		if(strcmp(book[i].id,id)==0){
			fflush(stdin);
		printf("moi ban nhap thong tin sach thu %d\n",i+1);
	
	
		printf("Ten Sach : \n");
		fgets(book[i].title,sizeof(book[i]).title,stdin);
	
		printf("Ten Tac Gia : \n");
		fgets(book[i].author,sizeof(book[i]).author,stdin);
	
		printf("Gia Tien : \n");
		fgets(book[i].price,sizeof(book[i]).price,stdin);
	
		printf("The Loai : \n");		
		fgets(book[i].category,sizeof(book[i]).category,stdin);	
		}
		
	}
}
void sortBook(Book book[],int*n){
  for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if (atof(book[i].price) > atof(book[j].price)) {
                Book temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
}
void searchBook(Book book[],int*n,char title){
for(int i=0;i<*n;i++){
		if(strcmp(book[i].title,title)==0){
		printf("Ma sach : %s\n",book[i].id);
		printf("Ten sach : %s\n",book[i].title);
		printf("Ten Tac Gia  : %s\n",book[i].author);
		printf("Gia tien : %s\n",book[i].price);
		printf("The Loai : %s\n",book[i].category);
		}
		
	}
}
