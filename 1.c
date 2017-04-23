#include<stdio.h>
#include<string.h>

FILE *daftar;

struct data{
	char nama[100], nim[20], kelas[10], usr[20], pw[50];
	char lusr[20], lpw[50];
}d;


void signup(){
	daftar = fopen("database.tt08", "ab");
	printf("Nama     : "); fflush(stdin); gets(d.nama);
	printf("NIM      : "); gets(d.nim);
	printf("Kelas    : "); gets(d.kelas);
	printf("Username : "); gets(d.usr);
	printf("Password : "); gets(d.pw);
	fwrite(&d, sizeof(d), 1, daftar);
}

void menu(){
	int p;
	system("cls");
	printf("=== Welcome to Daskom University ===\n");
	printf("Kami memilili 3 gedung dengan masing-masing gedung memiliki 3 ruangan\n\n");
	printf("Tampilkan denah? (Y/n)"); getch(p);
	if(p=='Y'){
		int i, j, n=9;
		for(i=0; i<n; i++){
			for(j=0; j<n*2-1; j++){
				if((i==0)||(j==0)||(j==n-1)||(j==n*2-2)||(i==n-1))
					printf("n ");
				else
					printf("  ");
			}
			printf("\n");
		}
		for(i=0; i<n-1; i++){
			for(j=0; j<n ; j++){
				if((j==0)||(i==n-2)||(j==n-1))
					printf("n ");
				else
					printf("  ");
			}
			printf("\n");
	}
			
	}
	printf("Pilih nomor ");
	
	
}
void login(){
	daftar = fopen("database.tt08", "rb");
	int n;
	do{
		system("cls");
		printf("\n### Login ###\n");
		printf("Username : "); fflush(stdin); gets(d.lusr);
		printf("Password : "); gets(d.lpw);
		while(fread(&d, sizeof(d), 1, daftar) == 1){
			if((strcmp(d.lusr, d.usr)==1) && (strcmp(d.lpw, d.pw)==1)){
				printf("\n==> Login berhasil !");
				getchar();
				menu();
			}
			else if((strcmp(d.lusr, "admin")==1) && (strcmp(d.lpw, "admin")==1)){
				printf("\n==> Mode Administrator telah aktif #admin");
				menu();
			}
			else{
				printf("\n==> Login gagal\n==> Masukkan \"1\" untuk kembali login, atau \"0\" untuk keluar");
				scanf("%d", &n);
			}
		}
	}
	while(n!=0);
	printf("\nTerimakasih !");
}



main(){
	
	int menu, n;
	do{
		system("cls");
		printf("=== PROGRAM LOGISTIC ===\n");
		printf("Menu:\n");
		printf("1. Sign-Up\n");
		printf("2. Login\n");
		printf("3. Exit\n\n");
		printf("Pilih Menu: "); scanf("%d", &menu); 
		switch(menu){
			case 1:{
				system("cls");
				printf("\n### Sign-Up ###\n");
				signup();
				getch();
				break;
			}
			case 2:{
				login();
				
				getch();
				break;
			}
			case 3: printf("Selesai. Thank you :]"); break;
			default: printf("Input tidak sesuai  daftar menu"); getch(); break;
	    }
	}
	while(menu!=3);
}
