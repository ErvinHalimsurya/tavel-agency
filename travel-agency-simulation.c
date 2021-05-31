#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct destinasi{
 char transportasi[5][120];
 char hotel[8][120];
 char paket[5][120];
 long int hargatransportasi[5];
 long int hargahotel[8];
 long int detailpaket[5][2];
}; 

struct destinasi hongkong,bali,bangkok,singapore;


void aboutus();
void help();
void brosur();
void menuOrder();
void order();
void postOrder();
void displayPaket();
void displayTransport();
void displayHotel();
void pencarian();
void setup();
void ExitProgram();

void printPaket(char *destinasi, char nama[][120],long int harga [][2]);
void printGeneral(int n, char *destinasi, char nama[][120],long int harga[]);

void wordSearch(char *destinasi,char arr[][120],long int harga[],int n,char key[120]);
void packetWordSearch(char *destinasi,char arr[][120],long int harga[][2],int n,char key[120]);
void priceSearchLess(char *destinasi,char arr[][120],long int harga[],int n,long int key);
void priceSearchMore(char *destinasi,char arr[][120],long int harga[],int n,long int key);
void packetPriceSearchLess(char *destinasi,char arr[][120],long int harga[][2],int n,long int key);
void packetPriceSearchMore(char *destinasi,char arr[][120],long int harga[][2],int n,long int key);
void packetSortAscending(long int harga[][2], int n,char arr[][120],int x);
void packetSortDescending(long int harga[][2], int n,char arr[][120],int x);
void nameSortAscending(long int harga[], int n,char arr[][120]);
void priceSortAscending(long int harga[], int n,char arr[][120]);
void priceSortDescending(long int harga[], int n,char arr[][120]);
char *strcasestr(const char *str, const char *needle);

int hitungharga(long int paket[][2],long int hargahotel[],long int hargatransport[], int paketch,int hotelch,int planech,int jmlhtiket,int jmlhkamar);
void printTiket(char paket[][120], long int hargapaket[][2],char hotel[][120],long int hargahotel[],char transport[][120],long int hargatransport[],int paketch,int hotelch,int planech,  int jmlhtiket,int jmlhkamar,int total);

int main(){
    int menu;
    char tmp[50];
    setup();
    while (1){
        printf("===========================================================================\n");
        printf("||                                Selamat datang                         ||\n");
        printf("||                                      di                               ||\n");
        printf("||                                  Bird Tours                           ||\n");
        printf("===========================================================================\n");
    	printf("Proyek Kelompok Rotan\n");
        printf("\n==== Menu ====\n");
        printf("[1] Tentang Kami\n[2] Brosur\n[3] Pesan Tiket\n[4] Help\n[5] Exit\n :");
        
        scanf("%d",&menu);
        gets(tmp);
         
        switch(menu){
                case 1:
                    system("CLS");
                    aboutus();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    system("CLS");
                    brosur();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    system("CLS");
                    menuOrder();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    system("CLS");
                    help();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                    system("PAUSE");
                    system("CLS");
        }
    }

    return 0;
}

/*Fungi untuk menampilkan informasi tentang kami*/
void aboutus(){
    printf(
    "\n\n"
    "Bird Tour merupakan sebuah perusahaan Tour & Travel yang menyediakan paket-paket wisata dimana pelanggan dapat memilih sendiri metode transportasi dan juga hotel yang ingin digunakan untuk menginap.\n"
    "\n\n"
    );
}

//Fungsi menampilkan menu help dan printnya 
void help(){
    int help;
	char tmp[50];
	
    while(1){
        printf("\t\t==== Menu Help ====\n");
        printf("Fitur mana yang ingin anda ketahui lebih lanjut?\n[1] Tentang Kami\n[2] Brosur\n[3] Pesan Tiket\n[4] Kembali ke menu utama\n :");
        scanf("%d",&help);
        gets(tmp);
        switch (help){
            case 1:
                system("CLS");
                printf("Menu Tentang Kami :\n\n");
                printf("Menu ini akan menampilkan deskripsi tentang perusahaan dan program kami.\n");
                system("PAUSE");
                system("CLS");
                break;
            case 2:
                system("CLS");
                printf("Menu Brosur :\n\n");
                printf(" - Pada menu ini, anda dapat melihat berbagai macam produk yang kami tawarkan.\n"
                "\n - Mulai dari paket wisata dengan berbagai durasi dan tujuan, pilihan penerbangan yang disediakan, serta hotel-hotel yang dapat dipilih pada tujuan wisata.\n"
                "\n - Setelah memilih kategori produk yang ingin ditampilkan, anda kemduian bisa memilih untuk menampilkan list produk berdasarkan urutan-urutan yang tersedia.\n"
                "\n - Tidak hanya itu, pada menu brosur, anda dapat memilih fitur pencarian dimana anda dapat mencari produk dan mem-filter produk berdasarkan kata kunci maupun harga.\n");
                system("PAUSE");
                system("CLS");
                break;
            case 3:
                system("CLS");
                printf("Menu Pemesanan :\n\n");
                printf(" - Setelah anda melihat produk-produk yang ada, anda dapat melakukan pemesanan pada menu ini.\n"
                "\n - Jika masih tidak yakin, anda bisa kembali ke menu utama atau langsung menuju menu brosur dengan memilih opsi 3 atau 2.\n"
                "\n - Jika sudah yakin ingin memesan, opsi 1 akan membawa anda ke menu pemesanan dimana akan diminta:\n   1. Jumlah tiket yang ingin dipesan (1 tiket per orang)\n   2. Jumlah kamar hotel yang ingin dipesan (Jumlah kamar hotel tidak boleh lebih dari jumlah tiket)\n"
                "   3. Memilih destinasi dan juga paket tour yang ingin diinginkan\n   4. penerbangan yang ingin digunakan, dan\n   5. Hotel yang ingin ditempati.\n"
                "\n - Setelah melakukan pemesanan sampai selesai, program akan menampilkan tiket berisi detail pesanan dan total biaya.\n");
                system("PAUSE");
                system("CLS");
                break;
            case 4:
                system("CLS");
                main();
                break;
        }
    }
}

/*Fungsi untuk menu brosur*/
void brosur(){

    int choice;
    char tmp[50];
    while (1){
        printf("\t\t==== Menu Brosur ====");
        printf("\nPilih borsur yang ingin ditampilkan");
        printf("\n[1] Paket \n[2] Penerbangan\n[3] Hotel\n[4] Lakukan pencarian\n[5] Kembali ke menu utama\n :");
        scanf("%d",&choice);
        gets(tmp);
        switch(choice){
                case 1:
                	system("CLS");
                    displayPaket();
                   
                    break;
                case 2:
                    system("CLS");
                    displayTransport();
                    
                    break;
                case 3:
                	system("CLS");
                    displayHotel();
                    
                    break;
                case 4:
                	system("CLS");
                    pencarian();

                    system("PAUSE");
                    system("CLS");
                    
                    break;
                case 5:
                    system("CLS");
                    main();
                    break;

                default:
                    printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                    system("PAUSE");
                    system("CLS");
        }
    }
}


/*Fungsi untuk menu paket*/
void displayPaket(){
    
    int i,sort;
	char tmp[50];
	
    while(1){
        printf("Tampilkan Paket berdasarkan destinasi dan :\n[1] Durasi\n[2] Harga rendah ke tinggi\n[3] Harga tinggi ke rendah\n[4] Kembali ke menu brosur\n :");
        scanf("%d",&sort);
        gets(tmp);
        switch (sort){
            case 1:
                packetSortAscending(hongkong.detailpaket,5,hongkong.paket,0);
                packetSortAscending(bali.detailpaket,5,bali.paket,0);
                packetSortAscending(bangkok.detailpaket,5,bangkok.paket,0);
                packetSortAscending(singapore.detailpaket,5,singapore.paket,0);

                printPaket("Hongkong",hongkong.paket,hongkong.detailpaket);
                printPaket("Bali",bali.paket,bali.detailpaket);
                printPaket("Bangkok",bangkok.paket,bangkok.detailpaket);
                printPaket("Singapur",singapore.paket,singapore.detailpaket);
                system("PAUSE");
                system("CLS");
                brosur();
                break;
            case 2:
                packetSortAscending(hongkong.detailpaket,5,hongkong.paket,1);
                packetSortAscending(bali.detailpaket,5,bali.paket,1);
                packetSortAscending(bangkok.detailpaket,5,bangkok.paket,1);
                packetSortAscending(singapore.detailpaket,5,singapore.paket,1);
                
                printPaket("Hongkong",hongkong.paket,hongkong.detailpaket);
                printPaket("Bali",bali.paket,bali.detailpaket);
                printPaket("Bangkok",bangkok.paket,bangkok.detailpaket);
                printPaket("Singapur",singapore.paket,singapore.detailpaket);
                system("PAUSE");
                system("CLS");
                brosur();
                break;

            case 3:

                packetSortDescending(hongkong.detailpaket,5,hongkong.paket,1);
                packetSortDescending(bali.detailpaket,5,bali.paket,1);
                packetSortDescending(bangkok.detailpaket,5,bangkok.paket,1);
                packetSortDescending(singapore.detailpaket,5,singapore.paket,1);

                printPaket("Hongkong",hongkong.paket,hongkong.detailpaket);
                printPaket("Bali",bali.paket,bali.detailpaket);
                printPaket("Bangkok",bangkok.paket,bangkok.detailpaket);
                printPaket("Singapur",singapore.paket,singapore.detailpaket);
                system("PAUSE");
                system("CLS");
                brosur();
                break;
            case 4:
                system("CLS");
                brosur();
                break;
            default:
                printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                system("PAUSE");
                system("CLS");
                break;

        }
    }
}

/*Fungsi menu untuk menampilkan transportasi*/
void displayTransport(){
    int i,sort;
	char tmp[50];
	
    while(1){
        printf("Tampilkan Penerbangan (Pulang Pergi) berdasarkan:\n[1] Nama\n[2] Harga rendah ke tinggi\n[3] Harga tinggi ke rendah\n[4] kembali ke menu brosur\n :");
        scanf("%d",&sort);
        gets(tmp);
        switch (sort){
            case 1:
                nameSortAscending(hongkong.hargatransportasi,5,hongkong.transportasi);
                nameSortAscending(bali.hargatransportasi,5,bali.transportasi);
                nameSortAscending(bangkok.hargatransportasi,5,bangkok.transportasi);
                nameSortAscending(singapore.hargatransportasi,5,singapore.transportasi);

                printGeneral(5,"Penerbangan ke Hongkong", hongkong.transportasi,hongkong.hargatransportasi);
                printGeneral(5,"Penerbangan ke Bali", bali.transportasi,bali.hargatransportasi);
                printGeneral(5,"Penerbangan ke Bangkok", bangkok.transportasi, bangkok.hargatransportasi);
                printGeneral(5,"Penerbangan ke Singapur", singapore.transportasi, singapore.hargatransportasi);

                system("PAUSE");
                system("CLS");
                return brosur();
                break;
            case 2:
            
                priceSortAscending(hongkong.hargatransportasi,5,hongkong.transportasi);
                priceSortAscending(bali.hargatransportasi,5,bali.transportasi);
                priceSortAscending(bangkok.hargatransportasi,5,bangkok.transportasi);
                priceSortAscending(singapore.hargatransportasi,5,singapore.transportasi);
                
                printGeneral(5,"penerbangan ke Hongkong", hongkong.transportasi,hongkong.hargatransportasi);
                printGeneral(5,"penerbangan ke Bali", bali.transportasi,bali.hargatransportasi);
                printGeneral(5,"penerbangan ke Bangkok", bangkok.transportasi, bangkok.hargatransportasi);
                printGeneral(5,"penerbangan ke Singapur", singapore.transportasi, singapore.hargatransportasi);

                system("PAUSE");
                system("CLS");
                return brosur();
                break;
            case 3:
                priceSortDescending(hongkong.hargatransportasi,5,hongkong.transportasi);
                priceSortDescending(bali.hargatransportasi,5,bali.transportasi);
                priceSortDescending(bangkok.hargatransportasi,5,bangkok.transportasi);
                priceSortDescending(singapore.hargatransportasi,5,singapore.transportasi);

                printGeneral(5,"Penerbangan ke Hongkong", hongkong.transportasi,hongkong.hargatransportasi);
                printGeneral(5,"Penerbangan ke Bali", bali.transportasi,bali.hargatransportasi);
                printGeneral(5,"Penerbangan ke Bangkok", bangkok.transportasi, bangkok.hargatransportasi);
                printGeneral(5,"Penerbangan ke Singapur", singapore.transportasi, singapore.hargatransportasi);
                system("PAUSE");
                system("CLS");
                return brosur();
                break;
            case 4:
                system("CLS");
                brosur();
                break;

            default:
                printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                system("PAUSE");
                system("CLS");
                break;

        }
    }
}

/*Fungsi menu untuk menampilkan hotel pada brosur*/
void displayHotel(){
    int i,sort;
	char tmp[50];
    while(1){
        printf("Tampilkan Hotel berdasarkan:\n[1] Nama\n[2] Harga rendah ke tinggi\n[3] Harga tinggi ke rendah\n[4] Kembali ke menu brosur\n :");
        scanf("%d",&sort);
        gets(tmp);
        switch (sort){
            case 1:
                nameSortAscending(hongkong.hargahotel,8,hongkong.hotel);
                nameSortAscending(bali.hargahotel,8,bali.hotel);
                nameSortAscending(bangkok.hargahotel,8,bangkok.hotel);
                nameSortAscending(singapore.hargahotel,8,singapore.hotel);

                printGeneral(8,"Hotel di Hongkong", hongkong.hotel,hongkong.hargahotel);
                printGeneral(8,"Hotel di Bali", bali.hotel,bali.hargahotel);
                printGeneral(8,"Hotel di Bangkok", bangkok.hotel, bangkok.hargahotel);
                printGeneral(8,"Hotel di Singapur", singapore.hotel, singapore.hargahotel);
                system("PAUSE");
                system("CLS");
                return brosur();
                break;
            case 2:
                priceSortAscending(hongkong.hargahotel,8,hongkong.hotel);
                priceSortAscending(bali.hargahotel,8,bali.hotel);
                priceSortAscending(bangkok.hargahotel,8,bangkok.hotel);
                priceSortAscending(singapore.hargahotel,8,singapore.hotel);
                

                printGeneral(8,"Hotel di Hongkong", hongkong.hotel,hongkong.hargahotel);
                printGeneral(8,"Hotel di Bali", bali.hotel,bali.hargahotel);
                printGeneral(8,"Hotel di Bangkok", bangkok.hotel, bangkok.hargahotel);
                printGeneral(8,"Hotel di Singapur", singapore.hotel, singapore.hargahotel);              
                system("PAUSE");
                system("CLS");
                return brosur();
                break;
            case 3:
                priceSortDescending(hongkong.hargahotel,8,hongkong.hotel);
                priceSortDescending(bali.hargahotel,8,bali.hotel);
                priceSortDescending(bangkok.hargahotel,8,bangkok.hotel);
                priceSortDescending(singapore.hargahotel,8,singapore.hotel);


                printGeneral(8,"Hotel di Hongkong", hongkong.hotel,hongkong.hargahotel);
                printGeneral(8,"Hotel di Bali", bali.hotel,bali.hargahotel);
                printGeneral(8,"Hotel di Bangkok", bangkok.hotel, bangkok.hargahotel);
                printGeneral(8,"Hotel di Singapur", singapore.hotel, singapore.hargahotel);
                system("PAUSE");
                system("CLS");
                return brosur();
                break;
            case 4:
                system("CLS");
                brosur();
                break;

            default:
                printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                system("PAUSE");
                system("CLS");
                break;
        }
    }
}

/*Fungsi untuk print daftar paket*/
void printPaket(char *destinasi, char nama[][120],long int harga [][2]){

    int i;
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Paket %s :\n",destinasi);
    for(i=0;i<5;i++){
        printf("[%d] %-75s : Rp. %-10ld	|\n", i+1, nama[i],harga[i][1]);

    }
    printf("-------------------------------------------------------------------------------------------------\n");
}

/*Fungsi untuk print daftar trasnportasi dan juga hotel*/
void printGeneral(int n, char *destinasi, char nama[][120],long int harga[]){
    int i;

    printf("---------------------------------------------------------\n");
    printf("%s : \n",destinasi);
    for(i=0;i<n;i++){
        printf("[%d] %-35s : Rp. %2ld	|\n",i+1, nama[i],harga[i]);
    }
    printf("---------------------------------------------------------\n");
}

//Fungsi pencarian dengan linear search
void pencarian(){
    int i, choice;
    char key[120];
    char temp;
    long int numkey;
	char tmp[50];
    while(1){
        printf("Lakukan pencarian berdasarkan:\n[1] Kata kunci / Kalimat\n[2] Harga Maksimum\n[3] Harga Minimum\n[4] Kembali ke menu brosur\n :");
        scanf("%d",&choice);
        gets(tmp);
       
        switch (choice){
            case 1:
                    system("CLS");
                    printf("Pencarian berdasarkan kata kunci :\n\n");
                    printf("Masukkan kata kunci yang ingin dicari\n:");
                    scanf("%c",&temp);                         // Untuk mereset input bekas enter sebelumnya
                    scanf("%[^\n]",key);

                    system("CLS");
                    printf("\n\nHasil pencarian berdasarkan kata kunci %s :",key);

                    printf("\n--------------------------------------------");
                    printf("\nPaket :\n");
                    packetWordSearch("Hongkong",hongkong.paket,hongkong.detailpaket,5,key);
                    packetWordSearch("Bali",bali.paket,bali.detailpaket,5,key);
                    packetWordSearch("Bangkok",bangkok.paket,bangkok.detailpaket,5,key);
                    packetWordSearch("Singapur",singapore.paket,singapore.detailpaket,5,key);
                    printf("--------------------------------------------\n");

                    printf("\n--------------------------------------------");
                    printf("\nPenerbangan :\n");
                    wordSearch("Hongkong",hongkong.transportasi,hongkong.hargatransportasi,5,key);
                    wordSearch("Bali",bali.transportasi,bali.hargatransportasi,5,key);
                    wordSearch("Bangkok",bangkok.transportasi,bangkok.hargatransportasi,5,key);
                    wordSearch("Singapur",singapore.transportasi,singapore.hargatransportasi,5,key);
                    printf("--------------------------------------------\n");

                    printf("\n--------------------------------------------");
                    printf("\nHotel :\n");
                    wordSearch("Hongkong",hongkong.hotel,hongkong.hargahotel,8,key);
                    wordSearch("Bali",bali.hotel,bali.hargahotel,8,key);
                    wordSearch("Bangkok",bangkok.hotel,bangkok.hargahotel,8,key);
                    wordSearch("Singapur",singapore.hotel,singapore.hargahotel,8,key);
                    printf("--------------------------------------------\n");


                    system("PAUSE");
                    system("CLS");
                    return brosur();
                    break;
            case 2:
                    system("CLS");
                    printf("Pencarian berdasarkan harga maksimum :\n\n");
                    printf("Masukkan harga maksimum yang ingin digunakan\n:");
                    scanf("%ld",&numkey);

                    system("CLS");
                    printf("\n\nHasil pencarian berdasarkan harga maksimum sebesar Rp. %d :",numkey);

                    printf("\n--------------------------------------------");
                    printf("\nPaket :\n");
                    packetPriceSearchLess("Hongkong",hongkong.paket,hongkong.detailpaket,5,numkey);
                    packetPriceSearchLess("Bali",bali.paket,bali.detailpaket,5,numkey);
                    packetPriceSearchLess("Bangkok",bangkok.paket,bangkok.detailpaket,5,numkey);
                    packetPriceSearchLess("Singapur",singapore.paket,singapore.detailpaket,5,numkey);
                    printf("--------------------------------------------\n");

                    printf("\n--------------------------------------------");
                    printf("\nPenerbangan :\n");
                    priceSearchLess("Hongkong",hongkong.transportasi,hongkong.hargatransportasi,5,numkey);
                    priceSearchLess("Bali",bali.transportasi,bali.hargatransportasi,5,numkey);
                    priceSearchLess("Bangkok",bangkok.transportasi,bangkok.hargatransportasi,5,numkey);
                    priceSearchLess("Singapur",singapore.transportasi,singapore.hargatransportasi,5,numkey);
                    printf("--------------------------------------------\n");

                    printf("\n--------------------------------------------");
                    printf("\nHotel :\n");
                    priceSearchLess("Hongkong",hongkong.hotel,hongkong.hargahotel,8,numkey);
                    priceSearchLess("Bali",bali.hotel,bali.hargahotel,8,numkey);
                    priceSearchLess("Bangkok",bangkok.hotel,bangkok.hargahotel,8,numkey);
                    priceSearchLess("Singapur",singapore.hotel,singapore.hargahotel,8,numkey);
                    printf("--------------------------------------------\n");



                    system("PAUSE");
                    system("CLS");
                    return brosur();
                    break;
            case 3:
                    system("CLS");
                    printf("Pencarian berdasarkan harga minimum :\n\n");
                    printf("Masukkan harga minimum yang ingin digunakan\n:");
                    scanf("%ld",&numkey);

                    system("CLS");
                    printf("\n\nHasil pencarian berdasarkan harga minimum sebesar Rp. %d :",numkey);

                    printf("\n--------------------------------------------");
                    printf("\nPaket :\n");
                    packetPriceSearchMore("Hongkong",hongkong.paket,hongkong.detailpaket,5,numkey);
                    packetPriceSearchMore("Bali",bali.paket,bali.detailpaket,5,numkey);
                    packetPriceSearchMore("Bangkok",bangkok.paket,bangkok.detailpaket,5,numkey);
                    packetPriceSearchMore("Singapur",singapore.paket,singapore.detailpaket,5,numkey);
                    printf("--------------------------------------------\n");

                    printf("\n--------------------------------------------");
                    printf("\nPenerbangan :\n");
                    priceSearchMore("Hongkong",hongkong.transportasi,hongkong.hargatransportasi,5,numkey);
                    priceSearchMore("Bali",bali.transportasi,bali.hargatransportasi,5,numkey);
                    priceSearchMore("Bangkok",bangkok.transportasi,bangkok.hargatransportasi,5,numkey);
                    priceSearchMore("Singapur",singapore.transportasi,singapore.hargatransportasi,5,numkey);
                    printf("--------------------------------------------\n");

                    printf("\n--------------------------------------------");
                    printf("\nHotel :\n");
                    priceSearchMore("Hongkong",hongkong.hotel,hongkong.hargahotel,8,numkey);
                    priceSearchMore("Bali",bali.hotel,bali.hargahotel,8,numkey);
                    priceSearchMore("Bangkok",bangkok.hotel,bangkok.hargahotel,8,numkey);
                    priceSearchMore("Singapur",singapore.hotel,singapore.hargahotel,8,numkey);
                    printf("--------------------------------------------\n");



                    system("PAUSE");
                    system("CLS");
                    return brosur();
                    break;
            case 4:
                system("CLS");
                brosur();
                break;

            default:
                printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                system("PAUSE");
                system("CLS");
                break;
        }
    }
}

/*Fungi menu saat ingin memesan tiker*/
void menuOrder(){
	system("CLS");
	int choice;
	char tmp[50];
	while (1){
        printf("\t\t==== Menu Pemesanan ====");
        printf("\n[1] Pesan Tiket\n[2] Buka Menu Brosur\n[3] Kembali ke menu utama\n :");
        scanf("%d",&choice);
        gets(tmp);
        switch(choice){
            	case 1:
                    system("CLS");
                    order();
                    system("Pause");
                    system("CLS");
                    postOrder();
                    break;
                case 2:
                    system("CLS");
                    brosur();
                    break;
                case 3:
                    system("CLS");
                    main();
                    break;
                default:
                    printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                    system("PAUSE");
                    system("CLS");
        }
    }
}

/*Fungsi proses pemesanan (dipisah dari menu order agar lebih rapih)*/
//paketch = paket choice
void order(){
    int i,tujuan,paketch,hotelch,planech,jmlhtiket,jmlhkamar,total;
	char tmp[50];
	
	while(1){
    	printf("Masukkan jumlah tiket yang ingin dipesan (1 tiket per orang)\n: ");
    	scanf("%d",&jmlhtiket);
    	gets(tmp);
    	
		if(jmlhtiket<0){
			printf("[Masukkan input berupa angka positif]\n");
		}
		else{
			break;
		}
	}

    while(1){

        printf("\nMasukkan jumlah kamar hotel yang ingin dipesan \n: ");
        scanf("%d",&jmlhkamar);
        gets(tmp);
        if (jmlhtiket<jmlhkamar){
            printf("[Jumlah tiket tidak boleh lebih banyak dari jumlah kamar dan tidak boleh berupa input huruf]\n");
        }
		else if(jmlhtiket<0){
			printf("[Masukkan input berupa angka positif]\n");
		}
        else{
            break;
        }
    }

    printf("\nSihlakan pilih destinasi tour yang dinginkan :\n[1] Hongkong\n[2] Bali\n[3] Bangkok\n[4] Singapur\n : ");
    scanf("%d",&tujuan);

    switch (tujuan){
        case 1:
            printf("\n  ========================================== Paket ============================================\n");
            printPaket("Hongkong",hongkong.paket,hongkong.detailpaket);
            printf("\nSihlakan pilih paket yang anda inginkan \n : ");
            scanf("%d",&paketch);
            printf("\n  ======================= Hotel =======================\n");
            printGeneral(8,"Hotel di Hongkong", hongkong.hotel,hongkong.hargahotel);
            printf("\nSihlakan pilih hotel yang ingin anda pesan\n : ");
            scanf("%d",&hotelch);
            printf("\n  ==================== Penerbangan ====================\n");
            printGeneral(5,"Penerbangan menuju Hongkong", hongkong.transportasi,hongkong.hargatransportasi);
            printf("\nSihlakan pilih penerbangan yang ingin anda gunakan\n : ");
            scanf("%d",&planech);
            total=hitungharga(hongkong.detailpaket,hongkong.hargahotel, hongkong.hargatransportasi, paketch, hotelch, planech, jmlhtiket, jmlhkamar);

            system("CLS");
            printTiket(hongkong.paket,hongkong.detailpaket,hongkong.hotel,hongkong.hargahotel,hongkong.transportasi,hongkong.hargatransportasi, paketch, hotelch, planech,   jmlhtiket,jmlhkamar, total);
            break;
        case 2:
            printf("\n  ========================================== Paket ============================================\n");
            printPaket("Bali",bali.paket,bali.detailpaket);
            printf("\nSihlakan pilih paket yang anda inginkan \n:");
            scanf("%d",&paketch);
            printf("\n======================= Hotel ======================\n");
            printGeneral(8,"Hotel di Bali", bali.hotel,bali.hargahotel);
            printf("\nSihlakan pilih hotel yang ingin anda pesan\n : ");
            scanf("%d",&hotelch);
            printf("\n  ==================== Penerbangan ====================\n");
            printGeneral(5,"Penerbangan menuju Bali", bali.transportasi,bali.hargatransportasi);
            printf("\nSihlakan pilih penerbangan yang ingin anda gunakan\n : ");
            scanf("%d",&planech);
            total=hitungharga(bali.detailpaket,bali.hargahotel, bali.hargatransportasi, paketch, hotelch, planech, jmlhtiket, jmlhkamar);

            system("CLS");
            printTiket(bali.paket,bali.detailpaket,bali.hotel,hongkong.hargahotel,bali.transportasi,bali.hargatransportasi, paketch, hotelch, planech,   jmlhtiket,jmlhkamar, total);
            break;

        case 3:
            printf("\n  ========================================== Paket ============================================\n");
            printPaket("Bangkok",bangkok.paket,bangkok.detailpaket);
            printf("\nSihlakan pilih paket yang anda inginkan \n:");
            scanf("%d",&paketch);
            printf("\n======================= Hotel =======================\n");
            printGeneral(8,"Hotel di Bangkok", bangkok.hotel,bangkok.hargahotel);
            printf("\nSihlakan pilih hotel yang ingin anda pesan\n : ");
            scanf("%d",&hotelch);
            printf("\n  ==================== Penerbangan ====================\n");
            printGeneral(5,"Penerbangan menuju Bangkok", bangkok.transportasi,bangkok.hargatransportasi);
            printf("\nSihlakan pilih penerbangan yang ingin anda gunakan\n : ");
            scanf("%d",&planech);
            total=hitungharga(bangkok.detailpaket,bangkok.hargahotel, bangkok.hargatransportasi, paketch, hotelch, planech, jmlhtiket, jmlhkamar);
            
            system("CLS");
            printTiket(bangkok.paket,bangkok.detailpaket,bangkok.hotel,bangkok.hargahotel,bangkok.transportasi,bangkok.hargatransportasi, paketch, hotelch, planech,   jmlhtiket,jmlhkamar, total);
            break; 

        case 4:
            printf("\n  ========================================== Paket ============================================\n");
            printPaket("Singapur",singapore.paket,singapore.detailpaket);
            printf("\nSihlakan pilih paket yang anda inginkan \n:");
            scanf("%d",&paketch);
            printf("\n  ======================= Hotel =======================\n");
            printGeneral(8,"Hotel di Singapur", singapore.hotel,singapore.hargahotel);
            printf("\nSihlakan pilih hotel yang ingin anda pesan\n : ");
            scanf("%d",&hotelch);
            printf("\n  ==================== Penerbangan ====================\n");
            printGeneral(5,"Penerbangan menuju Singapur", singapore.transportasi,singapore.hargatransportasi);
            printf("\nSihlakan pilih penerbangan yang ingin anda gunakan\n : ");
            scanf("%d",&planech);
            total=hitungharga(singapore.detailpaket,singapore.hargahotel, singapore.hargatransportasi, paketch, hotelch, planech, jmlhtiket, jmlhkamar);
            
            system("CLS");
            printTiket(singapore.paket,singapore.detailpaket,singapore.hotel,singapore.hargahotel,singapore.transportasi,singapore.hargatransportasi, paketch, hotelch, planech,   jmlhtiket,jmlhkamar, total);
            break;     
    }



}

//Fungsi untuk menampilkan menu setelah melakukan pemesanan
void postOrder(){
    int repeat;
    char tmp[50];

    while(1){
        printf("Apakah anda ingin kembali ke menu utama?\n[1] Iya\n[2] Tidak (Exit) \n : ");
        scanf("%d",&repeat);
        gets(tmp);
        switch (repeat){
            case 1:
                system("CLS");
                main();
                break;
            case 2:
                ExitProgram();
                exit(0);
                break;
            default:
                printf("\n[ERROR] Invalid Input\nMasukkan input angka sesuai opsi\n\n");
                system("PAUSE");
                system("CLS");
                break;
        }
    }

}

/*FUngi untuk keluar dari program*/
void ExitProgram()
{
	system("CLS");
    printf("Exiting...\n");
    printf(" ----------------------------------------\n");
    printf("|   Developed By Kelompok Rotan (23)     |\n");
    printf("|----------------------------------------|\n");
	printf("|   1. Ervin Halimsurya	1806195173       |\n"
		   "|   2. Jonathan Richard	1806147930       |\n");
    printf(" ----------------------------------------\n\n");
}

//Pencarian berdasarkan kata kunci dengan linear search
void wordSearch(char *destinasi,char arr[][120],long int harga[],int n,char key[120]){
    int i;
    char temp;


    printf("\n");
    for (i = 0; i < n; i++){
        if (strcasestr(arr[i],key)!=NULL){
            printf("  %-15s",destinasi);
            printf("[%d] %-35s Rp. %d\n",i+1, arr[i],harga[i]);
        }

    }
}



//pencarian berdasarkan harga maksimum dengan linear search
void priceSearchLess(char *destinasi,char arr[][120],long int harga[],int n,long int key){
    int i;
    char temp;

    printf("\n");
    for (i = 0; i < n; i++){
        if (harga[i] <= key){
            printf("  %-15s",destinasi);
            printf("[%d] %-35s Rp. %d\n",i+1, arr[i],harga[i]);
        }

    }
}

//pencarian berdasarkan harga minimum dengan linear search
void priceSearchMore(char *destinasi,char arr[][120],long int harga[],int n,long int key){
    int i;
    char temp;

    printf("\n");
    for (i = 0; i < n; i++){
        if (harga[i] >= key){
            printf("  %-15s",destinasi);
            printf("[%d] %-35s Rp. %d\n",i+1, arr[i],harga[i]);
        }
    }
}

//Pencarian berdasarkan kata kunci untuk paket karena harga paket disimpan pada array 2d
void packetWordSearch(char *destinasi,char arr[][120],long int harga[][2],int n,char key[120]){
    int i;
    char temp;


    printf("\n");
    for (i = 0; i < n; i++){
        if (strcasestr(arr[i],key)!=NULL){
            printf("  %-15s",destinasi);
            printf("[%d] %-80s Rp. %d\n",i+1, arr[i],harga[i][1]);
        }

    }
}

//pencarian berdasarkan harga maksimum untuk paket karena harga paket menggunakan 2d array
void packetPriceSearchLess(char *destinasi,char arr[][120],long int harga[][2],int n,long int key){
    int i;
    char temp;

    printf("\n");
    for (i = 0; i < n; i++){
        if (harga[i][1] <= key){
            printf("  %-15s",destinasi);
            printf("[%d] %-80s RP. %d\n",i+1, arr[i],harga[i][1]);
        }

    }
}

//pencarian berdasarkan harga minimum untuk paket karena harga paket menggunakan 2d array
void packetPriceSearchMore(char *destinasi,char arr[][120],long int harga[][2],int n,long int key){
    int i;
    char temp;

    printf("\n");
    for (i = 0; i < n; i++){
        if (harga[i][1] >= key){
            printf("  %-15s",destinasi);
            printf("[%d] %-80s RP. %d\n",i+1, arr[i],harga[i][1]);
        }

    }
}

//Fungsi untuk melakukan compare string tanpa memperdulikan spasi dan huruf kapital
char *strcasestr(const char *haystack, const char *needle) {
    size_t i;

    //Kondisi spesial jika needle kosong
    if (!*needle){
        return (char*)haystack;
    }
    //Lakukan pencarian string needle pada string di haystack
    for (; *haystack; haystack++) {
        //perbandingan menggunakan toupper agar string yang dibandingkan semuanya kapital, sehingga mengabaikan string awal kapital atau tidak
        if (toupper((unsigned char)*haystack) == toupper((unsigned char)*needle)) {
            //perbandingan huruf-huruf berikutnya ketika huruf awal sudah sama
            //looping sampai huruf terakhir pada needle
            for (i = 1;; i++) {
                //jika tidak ada huruf berikutnya pada needle, berarti sudah ada kesamaan
                if (!needle[i]){
                    return (char*)haystack;
                }
                //Jika huruf berikutnya tidak sama maka hentikan loop
                if (toupper((unsigned char)haystack[i]) != toupper((unsigned char)needle[i])){
                    break;
                }
            }
        }
    }
    //jika tidak ada kesamaan sama sekali return null
    return NULL;
}



/*Fungsi yang menghitung total harga*/
int hitungharga(long int paket[][2],long int hargahotel[],long int hargatransport[], int paketch,int hotelch,int planech,int jmlhtiket,int jmlhkamar){
    int hargatotal;

    hargatotal=((paket[paketch-1][1]+hargatransport[planech-1])*jmlhtiket)+(hargahotel[hotelch-1]*paket[paketch-1][0]*jmlhkamar);

    return hargatotal;
}

//Fungsi untuk menampilkan tiket-tiket yang dipesan
void printTiket(char paket[][120], long int hargapaket[][2],char hotel[][120],long int hargahotel[],char transport[][120],long int hargatransport[],int paketch,int hotelch,int planech,  int jmlhtiket,int jmlhkamar, int total){
    int i,j;
    printf("----------------------------------------------------------\n");
    printf("||                         Tiket                        ||\n");

    for(i=0;i<jmlhtiket;i++){
        printf("----------------------------------------------------------\n");
        printf("                          Tiket -%d\n",i+1);
        printf("----------------------------------------------------------\n");



        printf ("Paket    \t\t: %s \nHarga Paket     \t: Rp. %ld \n",paket[paketch-1],hargapaket[paketch-1][1]);


        printf ("\nPenerbangan         \t: %s\n",transport[planech-1]);
        printf ("Harga Penerbangan   \t: Rp. %ld\n",hargatransport[planech-1]);



    }
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    printf("                        Tiket Hotel                         ");
    printf("\n----------------------------------------------------------\n");
    printf ("Hotel         \t\t: %s\n",hotel[hotelch-1]);
    printf ("Harga Hotel per malam \t: Rp. %ld\n",hargahotel[hotelch-1]);
    printf("Jumlah kamar \t\t: %d\n",jmlhkamar);
    printf("----------------------------------------------------------\n");
    printf("Total harga \t\t: Rp. %ld\n",total);
    printf("----------------------------------------------------------\n");
}



//fungsi sorting terpisah untuk paket (Bubble sort)
void packetSortAscending(long int detail[][2], int n,char arr[][120],int x) { 
   int i, j; 
   char tmp[1][120];
   
   for (i = 0; i < n-1; i++){  
       for (j = 0; j < n-i-1; j++){ 
           if (detail[j][x] > detail[j+1][x]){
                long int temp = detail[j][x]; 
                detail[j][x] = detail[j+1][x]; 
                detail[j+1][x] = temp; 

                strcpy(tmp[0],arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],tmp[0]);
           }
       }
    }
}

//Fungsi sorting terpisah untuk paket (Bubble sort)
void packetSortDescending(long int detail[][2], int n,char arr[][120],int x) { 
   int i, j; 
   char tmp[1][120];

   for (i = 0; i < n-1; i++){  
       for (j = 0; j < n-i-1; j++){ 
           if (detail[j][1] < detail[j+1][x]){
                long int temp = detail[j][x]; 
                detail[j][x] = detail[j+1][x]; 
                detail[j+1][x] = temp; 

                strcpy(tmp[0],arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],tmp[0]);
           }
       }
    }
}

/*Fungsi untuk melakukan sorting berdasarkan harga dari kecil ke besar (Bubble sort)*/ 
void priceSortAscending(long int harga[], int n,char arr[][120]) { 
   int i, j; 
   char tmp[1][120];
   
   for (i = 0; i < n-1; i++){  
       for (j = 0; j < n-i-1; j++){ 
           if (harga[j] > harga[j+1]){
                long int temp = harga[j]; 
                harga[j] = harga[j+1]; 
                harga[j+1] = temp; 

                strcpy(tmp[0],arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],tmp[0]);
           }
       }
    }
}

/*Fungsi untuk melakukan sorting berdasarkan harga dari besar ke kecil (Bubble sort)*/
void priceSortDescending(long int harga[], int n,char arr[][120]) { 
   int i, j; 
   char tmp[1][120];

   for (i = 0; i < n-1; i++){  
       for (j = 0; j < n-i-1; j++){ 
           if (harga[j] < harga[j+1]){
                long int temp = harga[j]; 
                harga[j] = harga[j+1]; 
                harga[j+1] = temp; 

                strcpy(tmp[0],arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],tmp[0]);
           }
       }
    }
}


/*Fungi untuk melakukan sorting berdasarkan nama secara ascending (Bubble sort)*/
void nameSortAscending(long int harga[], int n,char arr[][120]) 
{ 
   int i, j;

   char tmp[1][120];
   
   for (i = 0; i < n-1; i++){  
       for (j = 0; j < n-i-1; j++){ 
           if (strcmp(arr[j],arr[j+1])>0){

                strcpy(tmp[0], arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], tmp[0]);
                
                long int temp = harga[j]; 
                harga[j] = harga[j+1]; 
                harga[j+1] = temp; 
           }
       }
    }

} 





/*Database  program, berisi paket, transportasi, dan hotel*/
void setup(){
    int i;
    for(i=0;i<8;i++){
    switch(i){
        case 0:

            strcpy(hongkong.paket[i],"Paket 3 hari, Hongkong City Tour");
            hongkong.detailpaket[i][0] = 3;
            hongkong.detailpaket[i][1] = 2400000;
            strcpy(bali.paket[i],"Paket 3 hari, Jimbaran, Kuta, Denpasar City Tour");
            bali.detailpaket[i][0] = 3;
            bali.detailpaket[i][1] = 1200000;
            strcpy(bangkok.paket[i],"Paket 3 hari, Bangkok City Tour ");
            bangkok.detailpaket[i][0] = 3;
            bangkok.detailpaket[i][1] = 1200000;
            strcpy(singapore.paket[i],"Paket 3 hari, Singapore City Tour");
            singapore.detailpaket[i][0] = 3;
            singapore.detailpaket[i][1] = 1100000;

            strcpy(hongkong.transportasi[i],"Air Asia QZ 5431, AK 287");
            hongkong.hargatransportasi[i] = 1640000;
            strcpy(bali.transportasi[i],"Air Asia QZ 6654");
            bali.hargatransportasi[i] = 1840000;
            strcpy(bangkok.transportasi[i],"Air Asia QZ 454");
            bangkok.hargatransportasi[i] = 1540000;
            strcpy(singapore.transportasi[i],"Air Asia QZ 329");
            singapore.hargatransportasi[i] = 814000;

    
            strcpy(hongkong.hotel[i],"Asia Boutique Hotel");
            hongkong.hargahotel[i] = 480000;
            strcpy(bali.hotel[i],"Airy Kuta");
            bali.hargahotel[i] = 240000;
            strcpy(bangkok.hotel[i],"Baiyoke Boutique Hotel");
            bangkok.hargahotel[i] = 340000;
            strcpy(singapore.hotel[i],"Boutique Hotel");
            singapore.hargahotel[i] = 340000;
            
            break;
    
        case 1:
            strcpy(hongkong.paket[i], "Paket 4 hari, Hongkong City Tour" );
            hongkong.detailpaket[i][0] = 4;
            hongkong.detailpaket[i][1] = 3960000;
            strcpy(bali.paket[i],"Paket 4 hari, Jimbaran, Kuta, Wilderness, Denpasar City Tour");
            bali.detailpaket[i][0] = 4;
            bali.detailpaket[i][1] = 1800000;
            strcpy(bangkok.paket[i],"Paket 4 hari, Bangkok City Tour, Ayutthaya");
            bangkok.detailpaket[i][0] = 4;
            bangkok.detailpaket[i][1] = 1500000;
            strcpy(singapore.paket[i],"Paket 4 hari, Singapore City Tour");
            singapore.detailpaket[i][0] = 4;
            singapore.detailpaket[i][1] = 1300000;


            strcpy(hongkong.transportasi[i],"Cathay Pacific CX 226");
            hongkong.hargatransportasi[i] = 7800000;
            strcpy(bali.transportasi[i],"Citilink Indonesia QG 987");
            bali.hargatransportasi[i] = 1640000;
            strcpy(bangkok.transportasi[i],"Citilink Indonesia QG 332");
            bangkok.hargatransportasi[i] = 840000;
            strcpy(singapore.transportasi[i],"Citilink Indonesia QG 199");
            singapore.hargatransportasi[i] = 1240000;

    
            strcpy(hongkong.hotel[i],"Big Hotel");
            hongkong.hargahotel[i] = 190000;
            strcpy(bali.hotel[i],"Alexa Hotel");
            bali.hargahotel[i] = 450000;
            strcpy(bangkok.hotel[i],"Baiyoke Bridge Hotel");
            bangkok.hargahotel[i] = 540000;
            strcpy(singapore.hotel[i],"Charles Hughman Hotel");
            singapore.hargahotel[i] = 940000;
    
            break;

    case 2 :
            strcpy(hongkong.paket[i], "Paket 5 hari, Hongkong and Macau City Tour");
            hongkong.detailpaket[i][0] = 5;
            hongkong.detailpaket[i][1] = 4800000;
            strcpy(bali.paket[i],"Paket 5 hari, Jimbaran, Kuta, Wilderness, Nusa Penida, Denpasar City Tour");
            bali.detailpaket[i][0] = 5;
            bali.detailpaket[i][1] = 2400000;
            strcpy(bangkok.paket[i],"Paket 5 hari, Bangkok City Tour, Pattaya");
            bangkok.detailpaket[i][0] = 5;
            bangkok.detailpaket[i][1] = 2500000;
            strcpy(singapore.paket[i],"Paket 5 hari, Singapore City Tour");
            singapore.detailpaket[i][0] = 5;
            singapore.detailpaket[i][1] = 1800000;

            strcpy(hongkong.transportasi[i],"Garuda Indonesia GA 653");
            hongkong.hargatransportasi[i] = 5400000;
            strcpy(bali.transportasi[i],"Garuda Indonesia GA 221");
            bali.hargatransportasi[i] = 3440000;
            strcpy(bangkok.transportasi[i],"Garuda Indonesia GA 561");
            bangkok.hargatransportasi[i] = 3840000;
            strcpy(singapore.transportasi[i],"Garuda Indonesia GA 529");
            singapore.hargatransportasi[i] = 2140000;

            
            strcpy(hongkong.hotel[i],"Dragon Homestay");
            hongkong.hargahotel[i] = 176000;
            strcpy(bali.hotel[i],"Buleleng Hotel");
            bali.hargahotel[i] = 1340000;
            strcpy(bangkok.hotel[i],"Baiyoke Sky Hotel");
            bangkok.hargahotel[i] = 1240000;
            strcpy(singapore.hotel[i],"Flora Hotel");
            singapore.hargahotel[i] = 1340000;
    
            break;
    
        case 3 : 
            strcpy(hongkong.paket[i], "Paket 6 hari, Hongkong, Macau, and Shenzhen City Tour" );
            hongkong.detailpaket[i][0] = 6;
            hongkong.detailpaket[i][1] = 6700000;
            strcpy(bali.paket[i],"Paket 6 hari, Jimbaran, Kuta, Denpasar City Tour, Lombok");
            bali.detailpaket[i][0] = 6;
            bali.detailpaket[i][1] = 3400000;
            strcpy(bangkok.paket[i],"Paket 6 hari, Bangkok City Tour, Pattaya, Ayutthaya");
            bangkok.detailpaket[i][0] = 6;
            bangkok.detailpaket[i][1] = 3200000;

            strcpy(hongkong.transportasi[i],"Malindo Air OD 124, OD 228");
            hongkong.hargatransportasi[i] = 1200000;
            strcpy(bali.transportasi[i],"Lion Air JT 765");
            bali.hargatransportasi[i] = 1240000;
            strcpy(bangkok.transportasi[i],"Thai Airways TG 998");
            bangkok.hargatransportasi[i] = 4840000;


            strcpy(singapore.transportasi[i],"Singapore Airlines SQ 329");
            singapore.hargatransportasi[i] = 3140000;
            strcpy(singapore.paket[i],"Paket 6 hari, Singapore City Tour, Johor Bahru");
            singapore.detailpaket[i][0] = 7;
            singapore.detailpaket[i][1] = 3200000;

            strcpy(hongkong.hotel[i],"Golden Lotus Hotel") ;
            hongkong.hargahotel[i] = 1800000 ;
            strcpy(bali.hotel[i],"Denpasar Grand Hotel");
            bali.hargahotel[i] = 1650000;
            strcpy(bangkok.hotel[i],"Baiyoke Homestay");
            bangkok.hargahotel[i] = 112000;
            strcpy(singapore.hotel[i],"Marina Bay Sands");
            singapore.hargahotel[i] = 3400000;

            break;
    
        case 4 :
            strcpy(hongkong.transportasi[4],"Thai Airways TG 663, TG 331");
            hongkong.hargatransportasi[i] =  6870000;
            strcpy(hongkong.paket[i], "Paket 7 hari, Hongkong, Macau, Shenzhen and Guangzhou City Tour");
            hongkong.detailpaket[i][0] = 7;
            hongkong.detailpaket[i][1] = 7500000;

            strcpy(bali.transportasi[i],"Sriwijaya Air SJ 153");
            bali.hargatransportasi[i] = 1940000;
            strcpy(bali.paket[i],"Paket 7 hari, Jimbaran, Kuta, Nusa Penida, Denpasar City Tour");
            bali.detailpaket[i][0] = 7;
            bali.detailpaket[i][1] = 4800000;

            strcpy(bangkok.transportasi[i],"Thai Smile");
            bangkok.hargatransportasi[i] = 2840000;
            strcpy(bangkok.paket[i],"Paket 11 hari, Bangkok City Tour, Pattaya, Ayutthaya,Chiang Mai, Chiang Rai");
            bangkok.detailpaket[i][0] = 11;
            bangkok.detailpaket[i][1] = 7200000;

            strcpy(singapore.transportasi[i],"Tiger Airways JQ 329");
            singapore.hargatransportasi[i] = 414000;
            strcpy(singapore.paket[i],"Paket 7 hari, Singapore City Tour, Johor Bahru");
            singapore.detailpaket[i][0] = 7;
            singapore.detailpaket[i][1] = 5200000;

            strcpy(hongkong.hotel[i],"Hongkong First Way Hotel");
            hongkong.hargahotel[i] = 285000; 
            strcpy(bali.hotel[i],"Garuda Hotel");
            bali.hargahotel[i] = 760000;
            strcpy(bangkok.hotel[i],"Baiyoke First Hotel");
            bangkok.hargahotel[i] = 2140000;
            strcpy(singapore.hotel[i],"Novotel Singapore");
            singapore.hargahotel[i] = 549000;

            break; 

        case 5:
        
            strcpy(hongkong.hotel[i],"Hotel Chek Lap Kok") ;
            hongkong.hargahotel[i] = 7600000; 
            strcpy(bali.hotel[i],"Hard Rock Bali");
            bali.hargahotel[i] = 2400000;
            strcpy(bangkok.hotel[i],"Cherprang Areekul Hotel");
            bangkok.hargahotel[i] = 140000;
            strcpy(singapore.hotel[i],"Orchid Homestay");
            singapore.hargahotel[i] = 140000;

            break;
    
        case 6:
            strcpy(hongkong.hotel[i],"Jiangsia Homestay") ;
            hongkong.hargahotel[i] = 220000 ; 
            strcpy(bali.hotel[i],"Hilton Bali");
            bali.hargahotel[i] = 4800000;
            strcpy(bangkok.hotel[i],"Kaimook Hotel");
            bangkok.hargahotel[i] = 540000;
            strcpy(singapore.hotel[i],"Raffles Hotel");
            singapore.hargahotel[i] = 890000;

            break;
    
        case 7:
            strcpy(hongkong.hotel[i],"Luo Jin Hotel") ;
            hongkong.hargahotel[i] = 980000; 
            strcpy(bali.hotel[i],"Homestay Lia");
            bali.hargahotel[i] = 124000;
            strcpy(bangkok.hotel[i],"Tune Hotel Bangkok");
            bangkok.hargahotel[i] = 320000;
            strcpy(singapore.hotel[i],"Singapore Grand Hotel");
            singapore.hargahotel[i] = 6190000;

            break;

        }
    }
}

