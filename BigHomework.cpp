#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct GioHang{
	char Tenkhachhang[50];
	char Diachi[50];
	int Soluongsanpham;
	char Tensanpham[50];
	int Giasanpham;
};

typedef GioHang SP;

void Nhap(SP &gh);
void Xuat(SP gh);
void NhapGH(SP &sp);
void NhapDSSP(SP &sp);
void XuatDSSP(SP sp[], int n);

void Nhap(SP &gh){
	printf("_______________________________________________________\n\n");
	fflush(stdin);
	printf("Nhap ten khach hang: ");
	gets(gh.Tenkhachhang);
	fflush(stdin);
	printf("Nhap dia chi: ");
	gets(gh.Diachi);
	printf("_______________________________________________________\n");
}

void Xuat(SP gh){
	printf("Ten khach hang: %s\n", gh.Tenkhachhang);
	printf("Dia chi: %s\n", gh.Diachi);
}

void NhapGH(SP &sp){
	fflush(stdin);
	printf("Nhap ten san pham: ");
	gets(sp.Tensanpham);
	printf("Nhap gia tien: ");
	scanf("%d", &sp.Giasanpham);
	printf("Nhap so luong san pham: ");
	scanf("%d", &sp.Soluongsanpham);
}

void NhapDSSP(SP sp[], int n){
	printf("_______________________________________________________\n");
	for (int i=0; i<n; i++){
		printf("\n-San pham thu %d:\n", i+1);
		NhapGH(sp[i]);
	}
	printf("_______________________________________________________\n");
}

void XuatDSSP(SP sp[], int n){
	printf("\n_____________________________________________________\n");
	printf("\nSTT\tTen san pham\tGia tien\tSo luong");
	for(int i=0; i<n; i++){
		printf("\n %d", i+1);
		printf("\t%s", sp[i].Tensanpham);
		printf("\t\t%d", sp[i].Giasanpham);
		printf("\t\t%d", sp[i].Soluongsanpham);	
	}
	printf("\n_____________________________________________________\n");
}

int main(){
	GioHang SP;
	struct GioHang sp[100];
	int key;
	int n;
	bool DaNhap = false;
	while(true){
        system("cls");
        printf("*********************************************************\n");
        printf("**           CHUONG TRINH QUAN LY DON HANG             **\n");
        printf("**                                                     **\n");
        printf("**      1. Tao gio hang                                **\n");
        printf("**      2. Chon hang                                   **\n");
        printf("**      3. Xem chi tiet gio hang                       **\n");
        printf("**      4. Loai bo mot mat hang                        **\n");
        printf("**      5. Ghi toan bo noi dung vao tep nhi phan       **\n");
        printf("**      6. Thoat                                       **\n");
        printf("**                                                     **\n");
        printf("*********************************************************\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d",&key);
		switch(key){
            case 1:
                printf("\nBan da chon Menu 1.Tao gio hang!\n");
                Nhap(SP);
                printf("\nBan da nhap thanh cong!");
                DaNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                printf("\nBan da chon Menu 2.Chon hang!\n\n");
                printf("**Nhap so luong hang: ");
				scanf("%d", &n);
                NhapDSSP(sp,n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(DaNhap){
                    printf("\nBan da chon Menu 3.Xem chi tiet gio hang!\n\n");
                    Xuat(SP);
                    XuatDSSP(sp,n);
                }else{
                    printf("\nNhap Nhap TT khach hang truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
