#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> 

struct date{
	int Ngay;
	int Thang;
	int Nam;
};

struct GioHang{
	date Ngaysanxuat;
    date Hansudung;
	int Soluongsanpham;
	char Tensanpham[50];
	int Giasanpham;
	int Tonggiasp;
	date ngayhh;
	 
};
typedef GioHang GH;

void Nhapkhohang(GH &gh);
void Xuatkhohang(GH gh);
void Nhapdanhsach(GH *kk,int &n);
void Xuatdanhsach(GH *kk,int n);
void Themsanpham(GH *kk,int &n);
int Timsanphamtheoten(GH *kk,int n,char sanpham[]);
void Sapxepkhohangtheogiatientangdan(GH *kk, int n);
void Sapxepkhohangtheogiatiengiamdan(GH *kk, int n);
void Xoasanpham(GH *kk, int &n, char tenhang[]);
int Tinhtonggiatien(GH *kk,int n);
void Sanphamhethansudung(GH gh);
void Xuatdanhsachsanphamhh(GH *kk, int n);
void SetColor1(int text_color);
void Xuatvaofile(GH *kk, int n);
void Nhaptufile(GH *kk,int &n);


void Nhapkhohang(GH &gh){
	fflush(stdin);
	printf("\nNhap ten san pham: ");
	fgets(gh.Tensanpham,sizeof(gh.Tensanpham),stdin);
	printf("Nhap gia san pham: ");
	scanf("%d",&gh.Giasanpham);
	printf("Nhap so luong san pham: ");
	scanf("%d",&gh.Soluongsanpham);
	printf("Nhap ngay/thang/nam san xuat cua san pham: ");
	scanf("%d %d %d",&gh.Ngaysanxuat.Ngay,&gh.Ngaysanxuat.Thang,&gh.Ngaysanxuat.Nam);
	printf("Nhap han su dung cua san pham: ");
	scanf("%d %d %d",&gh.Hansudung.Ngay,&gh.Hansudung.Thang,&gh.Hansudung.Nam);
	
}

void Xuatkhohang(GH gh){
	printf("\n*Ten san pham: %s",gh.Tensanpham);
	printf("\nDon gia: %d VND",gh.Giasanpham);
	printf("\t\tSo luong: %d",gh.Soluongsanpham);
	printf("\tNSX: %d/%d/%d",gh.Ngaysanxuat.Ngay,gh.Ngaysanxuat.Thang,gh.Ngaysanxuat.Nam);
	printf("\t\tHSS: %d/%d/%d",gh.Hansudung.Ngay,gh.Hansudung.Thang,gh.Hansudung.Nam);
}

void Nhapdanhsach(GH *kk, int &n){
	do{
		printf("\nNhap vao so san pham: ");
		scanf("%d",&n);
	}while(n<0);
	for(int i=0;i<n;i++){
		printf("\n-Nhap vao san phan thu %d:\n",(i+1));
		Nhapkhohang(*(kk+i));
	}

}

void Xuatdanhsach(GH *kk, int n){
	for(int i=0;i<n;i++){
		Xuatkhohang(*(kk+i));
		printf("\n________________________________________________________________________________________\n");
	}
} 

void Themsanpham(GH *kk,int &n){
	n++;
	Nhapkhohang(*(kk+n-1));
}

int Timsanphamtheoten(GH *kk, int n, char sanpham[]){
	int j=0;
	for(int i=0;i<n;i++){
		if(strstr(strupr((kk+i)->Tensanpham), strupr(sanpham))){
			j++;
		}
	}
	return j;
}

void Sapxepkhohangtheogiatientangdan(GH *kk, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if((kk+i)->Giasanpham>(kk+j)->Giasanpham){
				GH temp;
				temp = *(kk+i);
				*(kk+i) = *(kk+j);
				*(kk+j)=temp;
			}
		}
	}
}

void Sapxepkhohangtheogiatiengiamdan(GH *kk, int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if((kk+i)->Giasanpham<(kk+j)->Giasanpham){
				GH temp;
				temp = *(kk+i);
				*(kk+i) = *(kk+j);
				*(kk+j)=temp;
			}
		}
	}
}

void Xoasanpham(GH *kk,int &n, char tenhang[]){
	for(int i=0; i<n ; i++){
		if(strstr((kk+i)->Tensanpham,tenhang)){
			for(int j=i; j<n; j++){
				*(kk+j) = *(kk+j+1);
			}
			n-=1;
			return;
		}
	}
}

int Tinhtonggiatien(GH *kk, int n,GH &gh){
	for(int i=0;i<n;i++){
		gh.Tonggiasp+=((kk+i)->Giasanpham)*((kk+i)->Soluongsanpham);
	}
 return gh.Tonggiasp;
}

void Sanphamhethansudung(GH gh){
	time_t ntime= time(0);	//Khai bao thoi gian
	tm *NOW = localtime(&ntime);	//Lay thoi gian tai may tinh
	int namhientai= NOW->tm_year+1900; 
	int thanghientai=NOW->tm_mon;
	int ngayhientai=NOW->tm_mday;
	gh.ngayhh.Nam=gh.Hansudung.Nam-namhientai;
	gh.ngayhh.Thang=gh.Hansudung.Thang-thanghientai-1;
	gh.ngayhh.Ngay=gh.Hansudung.Ngay-ngayhientai;
	if(gh.ngayhh.Nam<0){
		Xuatkhohang(gh);
	} 
	if(gh.ngayhh.Nam==0){
		if(gh.ngayhh.Thang<0){
			Xuatkhohang(gh);
		}
		if(gh.ngayhh.Thang==0){
			if(gh.ngayhh.Ngay<0){
			Xuatkhohang(gh);
			}
		}
	}
}

void Xuatdanhsachsanphamhh(GH *kk,int n){
	for(int i=0;i<n;++i){
		Sanphamhethansudung(*(kk+i));
		printf("\n________________________________________________________________________________________\n");
	}
}

void SetColor1(int text_color){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void XoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}

void Xuatvaofile(GH *kk, int n){
	char tenfile[50];
	printf("\nNhap ten file.dia chi ban muon truyen vao: ");
	fflush(stdin);fgets(tenfile,sizeof(tenfile),stdin);XoaXuongDong(tenfile);
	FILE *f;
	f = fopen(tenfile,"wb");
	if(f==NULL){
	printf("Loi mo file de ghi!!!!!!");
	exit(1);
	}
	fwrite(&n,sizeof(n),1,f);
	for(int i=0;i<n;i++){
		fwrite((kk+i),sizeof(GH),1,f);
	}
	fclose(f);	
}

void Nhaptufile(GH *kk,int &n){
	char tenfile[50];
	printf("\nNhap ten file.dia chi ban muon truyen vao: ");
	fflush(stdin);fgets(tenfile,sizeof(tenfile),stdin);XoaXuongDong(tenfile);
	FILE *f;
	f = fopen(tenfile,"rb");
	if(f==NULL){
	printf("Loi mo file de doc!!!!!!");
	exit(1);
	}
	fread(&n,sizeof(n),1,f);
	for(int i=0;i<n;i++){
		fread((kk+i),sizeof(GH),1,f);
	}
	fclose(f);
}

int main(){
	int n,k;
	GH *kk=(GH*)malloc(n*sizeof(GH)),gh;
	bool DaNhap = false;
	SetColor1(5);
	system("color 4");
	int chon;
	while(true){
		system("cls");
		printf("\n*=======================CHUONG TRINH QUAN LY KHO HANG=========================*");
		printf("\n==                                                                           ==");
		printf("\n==                1.Nhap Danh Sach Kho Hang                                  ==");
		printf("\n==                2.Xuat Danh Sach Kho Hang                                  ==");
		printf("\n==                3.Them San Pham Vao Kho Hang                               ==");
		printf("\n==                4.Tim San Pham Bang Ten Trong Kho Hang                     ==");
		printf("\n==                5.Sap Xep San Pham Theo Gia Tien Tang Dan                  ==");
		printf("\n==                6.Sap Xep San Pham Theo Gia Tien Giam Dan                  ==");
		printf("\n==                7.Tong Gia Tien Cua Ca Kho Hang                            ==");
		printf("\n==                8.Xoa San Pham Trong Kho Hang                              ==");
		printf("\n==                9.Nhung San Pham Da Het Han Su Dung                        ==");
		printf("\n==                10.Nhap Danh Sach Kho Hang vao FILE nhi phan               ==");
		printf("\n==                11.Xuat Danh Sach Kho Hang tu FILE  nhi phan               ==");
		printf("\n==                0.Thoat Chuong Trinh                                       ==");
		printf("\n==                                                                           ==");
		printf("\n*=============================================================================*\n");
		printf("NHAP LUA CHON CUA BAN: ");
		scanf("%d",&chon);
		switch(chon){
			case 1:
				Nhapdanhsach(kk,n);
				DaNhap=true;
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 2:
				if(DaNhap){
					Xuatdanhsach(kk,n);
				} else printf("\nBan chua nhap danh sach gio hang!!!!!!!!!!!!!!!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 3:
				Themsanpham(kk,n);
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 4:
				if(DaNhap){
					char sanpham[50];
					printf("\nNhap ten san pham can tim vao: ");
					fflush(stdin); 
					fgets(sanpham, sizeof(sanpham), stdin);
					k=Timsanphamtheoten(kk,n,sanpham);
					if(k>0){
						printf("\n--> Trong kho co chua san pham nay !!!\n");
					}
					else printf("\n--> Trong kho khong co chua san pham nay !!!\n");	
				}else printf("\nBan chua nhap danh sach san pham !!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 5:
				if(DaNhap){
					printf("\n***San pham co gia tang dan***\n");
					Sapxepkhohangtheogiatientangdan(kk,n);
					Xuatdanhsach(kk,n);
				} else printf("\nBan chua nhap danh sach san pham !!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 6:
				if(DaNhap){
					printf("\n***San pham co gia giam dan***\n");
					Sapxepkhohangtheogiatiengiamdan(kk,n);
					Xuatdanhsach(kk,n);
				}else printf("\nBan chua nhap danh sach san pham !!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 7:
				if(DaNhap){
					printf("\n--> Tong gia tien cua ca kho hang la: %d VND\n",Tinhtonggiatien(kk,n,gh));
				} else printf("\nBan chua nhap danh sach san pham !!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 8:
				if(DaNhap){
					char tenhang[30];
					printf("\nNhap ten san pham can xoa: ");
					fflush(stdin); 
					fgets(tenhang, sizeof(tenhang), stdin);
					Xoasanpham(kk,n,tenhang);
					printf("\n--> San pham nay da duoc xoa !!!\n");
				} else printf("\nBan chua nhap danh sach san pham !!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
				break;
			case 9:
				if(DaNhap){
					printf("\n***Nhung san pham da het han su dung***\n");
					Xuatdanhsachsanphamhh(kk,n);
				}else printf("\n\nBan chua nhap danh sach san pham !!!");
				
				printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 10:
            	if(DaNhap){
            		Xuatvaofile(kk,n);
            	}else printf("\n\nBan chua nhap danh sach san pham !!!");
            	
            	printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 11:
            	if(DaNhap){
            		Nhaptufile(kk,n);
            	}else printf("\n\nBan chua nhap danh sach san pham !!!");
            	
            	printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
			case 0:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                getch();
                break;
		}		
	} 
}
