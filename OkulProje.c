
/*
												BMG D�NEM PROJES�
ATIF TOLGAHAN KEKE� 21110131042
MEHMET KAAN ARIKAN 21110131006
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//zar atma i�lemini bir fonksiyon �zerinden tan�mlad�k
int ZarAt(){
	int zar;
	zar = rand() % 4 +1;
	return zar;
	
}

//oyuncular i�in zar atan d��erlerse canlar�n� azaltan ve konumlar�n� g�ncelleyen fonksiyon
//d�nd�rd���m�z diziye d��ar�dan eri�ilebilmemiz i�in statik int olarak tan�mlad�k
int * HamleYap(int atilanZar,int konum[2],int can,char k[10][4]){
	static int hamleSonucu[3]={};
//	printf("fonksiyon ; atilanzar :%d konum0 :%d konum1 :%d can :%d\n",atilanZar,konum[0],konum[1],can);
	if(k[konum[0]][atilanZar-1]=='1'){
		can-=1;
		printf("Oyuncu dustu,kalan cani :%d\n",can);
		konum[0]=-1;
		konum[1]=-1;
	}
	else{
		konum[0]++;
		konum[1]=atilanZar-1;
	}
//	printf("%d",konum[0]+1);
//	printf("%d\n",konum[1]+1);
	
	hamleSonucu[0]=can;
	hamleSonucu[1]=konum[0];
	hamleSonucu[2]=konum[1];
	return hamleSonucu;
}

int main(){
	int aKonum[2]={-1,-1};//a oyuncusunun kordinatlar�
	int bKonum[2]={-1,-1};//b oyuncusunun kordinatlar�
	int cKonum[2]={-1,-1};//c oyuncusunun kordinatlar�
	int aCan=3,bCan=3,cCan=3;//oyuncular�n canlar�
	int i,j,n;//d�ng�ler i�in
	int aAtilanZar,bAtilanZar,cAtilanZar;//oyncular�n zarlar�
	int kZar;//k�r�k cam i�in at�lan zar
	int *hamleSonucu;
	char k[10][4] = {{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'},{'0','0','0','0'}};
	
	printf("A oyuncusunun cani :%d\n",aCan);
	printf("B oyuncusunun cani :%d\n",bCan);
	printf("C oyuncusunun cani :%d\n",cCan);		
	//rand i�in anl�k zaman� bir ba�lang�� noktas� belirledik
	srand(time(NULL));
	
	for(i=0;i<10;i++){
		
		//zarat fonksiyonundaki i�lemi �a��rd�k
		kZar = ZarAt();
		
		//gelen zara ve at�� say�s�na g�re matrisdeki k�r�k ve sa�lam alanlar� belirledik
		k[i][kZar-1]='1';
	}
	
	printf("\n");
	
	//oyuncular�n can� bitene kadar ya da sona ula�ana kadar devam edecekler
	while ((aCan>0&&aKonum[0]!=9)||(bCan>0&&bKonum[0]!=9)||(cCan>0&&cKonum[0]!=9)){
		//a oyuncusu i�in fonksiyona de�i�kenler g�nderdik
		if(aCan>0){
			aAtilanZar=ZarAt();
			printf("A nin attigi zar : %d\n",aAtilanZar);
			hamleSonucu=HamleYap(aAtilanZar,aKonum,aCan,k);
			aCan=hamleSonucu[0];
			aKonum[0]=hamleSonucu[1];
			aKonum[1]=hamleSonucu[2];
		}
		if(aCan==0){
			printf("A oyuncusu elendi...\n");			
			aKonum[0]=-1;
			aKonum[1]=-1;
			aCan=-1;
		}
		//b oyuncusu i�in fonksiyona de�i�kenler g�nderdik	
		if(bCan>0){
			bAtilanZar=ZarAt();			
			if(aKonum[1]!=-1&&(aKonum[1]==bAtilanZar-1&&aKonum[0]==bKonum[0]+1)){
				while(aKonum[1]!=bAtilanZar-1){
					bAtilanZar=ZarAt();
					printf("B nin tekrar zari :%d\n",bAtilanZar);
				}
			}
			printf("B nin attigi zar : %d\n",bAtilanZar);
			hamleSonucu=HamleYap(bAtilanZar,bKonum,bCan,k);
			bCan=hamleSonucu[0];
	 		bKonum[0]=hamleSonucu[1];
			bKonum[1]=hamleSonucu[2];	
	 	}	
		if(bCan==0){
			printf("B oyuncusu elendi...\n");
			bKonum[0]=-1;
			bKonum[1]=-1;
			bCan=-1;

		}
		//c oyuncusu i�in fonksiyona de�i�kenler g�nderdik 
		if(cCan>0){
			cAtilanZar=ZarAt();
			if(aKonum[1]!=-1&&(aKonum[1]==cAtilanZar-1&&aKonum[0]==cKonum[0]+1)){
				while(aKonum[1]!=cAtilanZar-1){
					cAtilanZar=ZarAt();
					printf("C nin tekrar zari :%d\n",cAtilanZar);
				}
			}
			if(bKonum[1]!=-1&&(bKonum[1]==cAtilanZar-1&&bKonum[0]==cKonum[0]+1)){
				while(bKonum[1]!=cAtilanZar-1){
					cAtilanZar=ZarAt();
					printf("C nin tekrar zari :%d\n",cAtilanZar);
				}		
			}
			printf("C nin attigi zar : %d\n",cAtilanZar);
			hamleSonucu=HamleYap(cAtilanZar,cKonum,cCan,k);
			cCan=hamleSonucu[0];
			cKonum[0]=hamleSonucu[1];
			cKonum[1]=hamleSonucu[2];		
		}
		if(cCan==0){
			printf("C oyuncusu elendi...\n");
			cKonum[0]=-1;
			cKonum[1]=-1;
			cCan=-1;
		}
	}
	
	//oyuncular kazan�rsa ne olaca��n�n yazd�r�l���
	if(aKonum[0]==9){
		printf("A oyuncusu kazandi..\n");
		k[9][aKonum[1]]='A';	
	}
	else if(bKonum[0]==9){
		printf("B oyuncusu kazandi..\n");
		k[9][bKonum[1]]='B';	
	}
	else if(cKonum[0]==9){
		printf("C oyuncusu kazandi..\n");
		k[9][cKonum[1]]='C';
	}

//	////tablonun matris halinin yazd�r�l���
//	for(i=0;i<10;i++){		
//		for(n=0;n<4;n++){
//			printf("%c",k[i][n]);
//		}
//		printf("\n");
//	}
	
	//tablonun ilk 9 sat�r�n�n yazd�r�l���
	for(i=1;i<10;i++){
		if(k[i-1][0]=='1'){
			k[i-1][0]='K';
			printf("|____%c____|",k[i-1][0]);
			printf("|_________|");
			printf("|_________|");
			printf("|_________|%d\n",i);			
		}
		else if(k[i-1][1]=='1'){
			k[i-1][1]='K';
			printf("|_________|");
			printf("|____%c____|",k[i-1][1]);
			printf("|_________|");
			printf("|_________|%d\n",i);			
		}		
		else if(k[i-1][2]=='1'){
			k[i-1][2]='K';
			printf("|_________|");
			printf("|_________|");
			printf("|____%c____|",k[i-1][2]);
			printf("|_________|%d\n",i);			
		}
		else if(k[i-1][3]=='1'){
			k[i-1][3]='K';
			printf("|_________|");
			printf("|_________|");
			printf("|_________|");
			printf("|____%c____|%d\n",k[i-1][3],i);			
		}
	}
	//tablonun 10. sat�r�n�n yazd�r�l���
	if(k[9][0]=='1'&&aKonum[0]==9){
		k[9][0]='K';
			if(aKonum[1]==1){
				printf("|____%c____|",k[9][0]);
				printf("|____%c____|",k[9][1]);
				printf("|_________|");				
				printf("|_________|%d\n",i);			
			}
			else if(aKonum[1]==2){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(aKonum[1]==3){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][1]=='1'&&aKonum[0]==9){
		k[9][1]='K';
			if(aKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|_________|%d\n",i);			
			}
			else if(aKonum[1]==2){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(aKonum[1]==3){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][2]=='1'&&aKonum[0]==9){
		k[9][2]='K';
			if(aKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}
			else if(aKonum[1]==1){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(aKonum[1]==3){
				printf("|_________|");
				printf("|_________|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][3]=='1'&&aKonum[0]==9){
		k[9][3]='K';
			if(aKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
			else if(aKonum[1]==1){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}		
			else if(aKonum[1]==2){
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}		
	if(k[9][0]=='1'&&bKonum[0]==9){
		k[9][0]='K';
			if(bKonum[1]==1){
				printf("|____%c____|",k[9][0]);
				printf("|____%c____|",k[9][1]);
				printf("|_________|");				
				printf("|_________|%d\n",i);			
			}
			else if(bKonum[1]==2){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(bKonum[1]==3){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
	}
	if(k[9][1]=='1'&&bKonum[0]==9){
		k[9][1]='K';
			if(bKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|_________|%d\n",i);			
			}
			else if(bKonum[1]==2){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(bKonum[1]==3){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][2]=='1'&&bKonum[0]==9){
		k[9][2]='K';
			if(bKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}
			else if(bKonum[1]==1){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(bKonum[1]==3){
				printf("|_________|");
				printf("|_________|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][3]=='1'&&bKonum[0]==9){
		k[9][3]='K';
			if(bKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
			else if(bKonum[1]==1){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}		
			else if(bKonum[1]==2){
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|____%c____|%c\n",k[9][3],i);			
			}
		}
	if(k[9][0]=='1'&&cKonum[0]==9){
		k[9][0]='K';
			if(cKonum[1]==1){
				printf("|____%c____|",k[9][0]);
				printf("|____%c____|",k[9][1]);
				printf("|_________|");				
				printf("|_________|%d\n",i);			
			}
			else if(cKonum[1]==2){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(cKonum[1]==3){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][1]=='1'&&cKonum[0]==9){
		k[9][1]='K';
			if(cKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|_________|%d\n",i);			
			}
			else if(cKonum[1]==2){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(cKonum[1]==3){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][2]=='1'&&cKonum[0]==9){
		k[9][2]='K';
			if(cKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}
			else if(cKonum[1]==1){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|_________|%d\n",i);			
			}		
			else if(cKonum[1]==3){
				printf("|_________|");
				printf("|_________|",k[9][1]);
				printf("|____%c____|",k[9][2]);
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(k[9][3]=='1'&&cKonum[0]==9){
		k[9][3]='K';
			if(cKonum[1]==0){
				printf("|____%c____|",k[9][0]);
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}
			else if(cKonum[1]==1){
				printf("|_________|");
				printf("|____%c____|",k[9][1]);
				printf("|_________|");
				printf("|____%c____|%d\n",k[9][3],i);			
			}		
			else if(cKonum[1]==2){
				printf("|_________|");
				printf("|_________|");
				printf("|____%c____|",k[9][2]);
				printf("|____%c____|%d\n",k[9][3],i);			
			}
		}
	if(aKonum[0]!=9||bKonum[0]!=9||cKonum[0]!=9){
		if(k[9][0]=='1'){
			k[9][0]='K';
			printf("|____%c____|",k[9][0]);
			printf("|_________|");
			printf("|_________|");
			printf("|_________|%d\n",i);			
		}
		else if(k[9][1]=='1'){
			k[9][1]='K';
			printf("|_________|");
			printf("|____%c____|",k[9][1]);
			printf("|_________|");
			printf("|_________|%d\n",i);			
		}		
		else if(k[9][2]=='1'){
			k[9][2]='K';
			printf("|_________|");
			printf("|_________|");
			printf("|____%c____|",k[9][2]);
			printf("|_________|%d\n",i);			
		}
		else if(k[9][3]=='1'){
			k[9][3]='K';
			printf("|_________|");
			printf("|_________|");
			printf("|_________|");
			printf("|____%c____|%d\n",k[9][3],i);			
		}
	}
	//tablonun s�tun say�s�n�n yazd�r�l���
	for(i=1;i<5;i++){
		printf("     %d     ",i);
	}	
}

