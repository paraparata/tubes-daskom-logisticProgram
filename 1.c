#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *daftar, *ruang, *ruangU;

struct data{
	char nama[100], nim[20], kelas[10], usr[20], pw[50];
}d;
char lusr[20], lpw[50];

void signup(){
	daftar = fopen("database.tt08", "ab+");
	printf("Nama     : "); fflush(stdin); gets(d.nama);
	printf("NIM      : "); gets(d.nim);
	printf("Kelas    : "); gets(d.kelas);
	printf("Username : "); gets(d.usr);
	printf("Password : "); gets(d.pw);
	fwrite(&d, sizeof(d), 1, daftar);
	fclose(daftar);
}

void roomU(int a){
	int i, nomor;
	
	switch(a){
		case 0:{
			ruang = fopen("ruangan.tt08", "wb"); //deklarasi absolut jumlah ruangan ada 12
			for(i=1; i<13; i++){
				fwrite(&i, sizeof(i), 1, ruang);
			}
			fclose(ruang);
			break;
		}
		case 1:{
			scanf("%d", &nomor);	
			ruang = fopen("ruangan.tt08", "ab+");
			ruangU = fopen("ruanganU.tt08", "ab+");
			//konfirmasi admin
			while(fread(&i, sizeof(i), 1, ruang)==1){
				if(i != nomor)
					fwrite(&i, sizeof(i), 1, ruangU);
			}
			fclose(ruang);
			fclose(ruangU);
			rename("ruangan.tt08", "ruanganU-1.tt08");
			rename("ruanganU.tt08", "ruangan.tt08");
			rename("ruanganU-1.tt08", "ruanganU.tt08");
			//diterima atau tidak
			break;
		}
	}
}

void admin(){
	
}

void roomShow(){
	int i;
	ruang = fopen("ruangan.tt08", "rb");
	while(fread(&i, sizeof(i), 1, ruang)==1){
		printf("| %d |_", i);
	}
	fclose(ruang);
}

void denah(){
	int i, j, n=9;
		for(i=0; i<n; i++){
			for(j=0; j<n*2-1; j++){
				if((i==0)||(j==0)||(j==n-1)||(j==n*2-2)||(i==n-1)||(j==4)||(j==12||(i==4)))
					printf("n ");
				else if((i==1)&&(j==1))
					printf("1 ");
				else if((i==1)&&(j==5))
					printf("2 ");
				else if((i==1)&&(j==9))
					printf("3 ");
				else if((i==1)&&(j==13))
					printf("4 ");
				else if((i==5)&&(j==1))
					printf("5 ");
				else if((i==5)&&(j==5))
					printf("6 ");
				else if((i==5)&&(j==9))
					printf("7 ");
				else if((i==5)&&(j==13))
					printf("8 ");
				else
					printf("  ");
			}
			printf("\n");
		}
		for(i=0; i<n-1; i++){
			for(j=0; j<n ; j++){
				if((j==0)||(i==n-2)||(j==n-1)||(j==4)||(i==3))
					printf("n ");
				else if((i==0)&&(j==1))
					printf("9 ");
				else if((i==0)&&(j==5))
					printf("10");
				else if((i==4)&&(j==1))
					printf("11");
				else if((i==4)&&(j==5))
					printf("12");
				else
					printf("  ");
			}
			printf("\n");
		}
}

void menu(){
	int n;
	char p;
	do{
		system("cls");
		printf("=== Welcome to Daskom University ===\n");
		printf("Kami memilili 3 gedung dengan masing-masing gedung memiliki 3 ruangan\n\n");
		printf("Tampilkan denah? (Y/n)"); scanf("%c", &p); printf("\n");
		if(p == 'Y'){
			denah();	
		}
		printf("\nPilih TampilPinjamRuang/Notifikasi/Exit (1/2/3) : "); scanf("%d", &n);
		switch(n){
			case 1:{
				printf("\nTampilkan ruangan kosong : ");
				roomU(0); roomShow();
				printf("\nPilih nomor ruangan yang akan dipinjam : ");
				roomU(1);
				getch();
				break;
			}
			case 2:{
				
				break;
			}
			case 3:{
				printf("\nThankyou :)");
				getch();
				break;
			}
			default: printf("\nMenu yang anda pilih tidak tersedia :("); getch();
		}
	}
	while(n!=3);
}

void login(){
	daftar = fopen("database.tt08", "rb");
	system("cls");
	printf("\n### Login ###\n");
	printf("Username : "); fflush(stdin); gets(lusr);
	printf("Password : "); gets(lpw);
		
	while(fread(&d, sizeof(d), 1, daftar) == 1){
		if((strcmp(lusr, d.usr)==0) && (strcmp(lpw, d.pw)==0)){
			printf("\n==> Login berhasil !");
			getchar();
			menu();
		}
		else if((strcmp(lusr, "admin")==0) && (strcmp(lpw, "admin")==0)){
			printf("\n==> Mode Administrator telah aktif #admin");
			getchar();
			menu();
		}
		else{
			printf("\nIncorrect username or password :'(");
			break;
		}
		
	}
	fclose(daftar);
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
