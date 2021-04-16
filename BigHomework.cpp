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
	int STT;
};

typedef GioHang SP;

void Nhap(SP &gh);
void Xuat(SP gh);
void NhapGH(SP &sp);
void NhapDSSP(SP &sp);
void XuatDSSP(SP sp[], int n);
void ThemSPtheoSTT(SP sp[], int &n);
void XoaSPtheoSTT(SP sp[], int &n);
void TimSPTheoTen(SP sp[], int n);
void GhiFile(SP sp[], int n, char FileName[]);

void Nhap(SP &gh){
	printf("_________________________________________________________________\n\n");
	fflush(stdin);
	printf("Nhap ten khach hang: ");
	gets(gh.Tenkhachhang);
	fflush(stdin);
	printf("Nhap dia chi: ");
	gets(gh.Diachi);
	printf("So san pham trong gio hang la 0. Hay tao gio hang o Menu 2!\n");
	printf("_________________________________________________________________\n");
}

void Xuat(SP gh){
	printf("Ten khach hang: %s\n", gh.Tenkhachhang);
	printf("Dia chi: %s", gh.Diachi);
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
	printf("_________________________________________________________________\n");
	for (int i=0; i<n; i++){
		printf("\n-San pham thu %d:\n", i+1);
		NhapGH(sp[i]);
	}
	printf("_________________________________________________________________\n");
}

void XuatDSSP(SP sp[], int n){
	printf("\n_______________________________________________________________\n");
	printf("\n|STT\t|Ten san pham \t|Gia tien \t\t|So luong");
	for(int i=0; i<n; i++){
		printf("\n|%d", i+1);
		printf("\t|%s", sp[i].Tensanpham);
		printf("\t\t|%d", sp[i].Giasanpham);
		printf("\t\t\t|%d", sp[i].Soluongsanpham);
	}
	printf("\n_______________________________________________________________\n");
}

void ThemSPtheoSTT(SP sp[], int &n){
	int Stt;
	SP gh;
	do{
		printf("\nNhap STT cua san pham can them: ");
		scanf("%d",&Stt);
		if(Stt<1 || Stt>n+1)
		{
			printf("\nVi tri them pham nam trong doan STT tu [1;%d]", n+1);
		}
	}while(Stt<1 || Stt>n+1);
	Stt--;
	printf("\n-Nhap thong tin san pham can them:\n");
	NhapGH(gh);
	for(int i=n-1; i>=Stt; i--)
	{
		sp[i+1] = sp[i];
	}
    sp[Stt]=gh;
	n++;
	printf("\n--> San pham da duoc them. Xem lai gio hang o Menu 3\n");
}

void XoaSPtheoSTT(SP sp[], int &n){
	int Stt;
    do{
		printf("\n-Nhap STT cua san pham muon xoa: ");
		scanf("%d",&Stt);
		if(Stt<1 || Stt>n){
			printf("\nKhong ton tai STT cua san pham muon xoa");
		}
	}while(Stt<1 || Stt>n);
	Stt--;
    for(int i= Stt+1; i<n; i++){
		   sp[i-1]=sp[i];
	}
    n--;
    printf("\n--> San pham da duoc xoa. Xem lai gio hang o Menu 3\n");
}

void TimSPTheoTen(SP sp[], int n){
	char Tensp[50];
	int found=1;
	printf("\n-Nhap ten san pham can tim: ");
	fflush(stdin);
	gets(Tensp);
	for(int i= 0; i<n; i++){
		if(strcmp(sp[i].Tensanpham,Tensp)==0){
			printf("\n|STT\t|Ten san pham \t|Gia tien \t\t|So luong");
			printf("\n|%d", i+1);
			printf("\t|%s", sp[i].Tensanpham);
			printf("\t\t|%d", sp[i].Giasanpham);
			printf("\t\t\t|%d", sp[i].Soluongsanpham);;
			found=0;
		}
	}
	if(found)
		{
			printf("\nKhong co san pham ten *%s* trong gio hang\n",Tensp);
		}
}

void GhiFile(SP sp[], int n, char FileName[]){
    FILE *fn;
    fn = fopen (FileName,"w");
    fprintf(fn, "%s%20s%20s%20s\n","STT", "Ten san pham", "Gia tien", "So luong");
    for(int i = 0;i < n;i++){
        fprintf(fn, "%d%15s%25d%20d\n", i+1, sp[i].Tensanpham, sp[i].Giasanpham, sp[i].Soluongsanpham);
    }
    fclose (fn);
}
 
int main(){
	GioHang SP;
	struct GioHang sp[100];
	char FileName[] = "DSSP.txt";
	int key;
	int n;
	bool DaNhap = false;
	while(true){
        system("cls");
        printf("**************************************************************\n");
        printf("***                                                        ***\n");
        printf("***           CHUONG TRINH QUAN LY DON HANG                ***\n");
        printf("***                                                        ***\n");
        printf("***      1. Tao gio hang                                   ***\n");
        printf("***      2. Chon hang                                      ***\n");
        printf("***      3. Xem chi tiet gio hang                          ***\n");
        printf("***      4. Them mot san pham vao gio hang                 ***\n");
        printf("***      5. Loai bo mot san pham trong gio hang            ***\n");
        printf("***      6. Tim kiem mot san pham theo ten                 ***\n");
        printf("***      7. Ghi toan bo noi dung vao file DSSP.txt         ***\n");
        printf("***      8. Thoat chuong trinh                             ***\n");
        printf("***                                                        ***\n");
        printf("**************************************************************\n");
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
            	if(DaNhap){
                	printf("\nBan da chon Menu 2.Chon hang!\n\n");
                	printf("**Nhap so luong hang: ");
					scanf("%d", &n);
                	NhapDSSP(sp,n);
                } else{
                	printf("\nBan can nhap thong tin trong menu 1 truoc !!!");
				}
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(DaNhap){
                    printf("\nBan da chon Menu 3.Xem chi tiet gio hang!\n\n");
                    Xuat(SP);
                    XuatDSSP(sp,n);
                } else{
                    printf("\nBan can nhap thong tin trong menu 1 truoc !!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
            	if(DaNhap){
            		printf("\nBan da chon Menu 4.Them mot san pham vao gio hang!\n");
            		XuatDSSP(sp,n);
            		ThemSPtheoSTT(sp,n);
            	} else{
                	printf("\nBan can nhap thong tin trong menu 1 truoc !!!\n");
				}
				printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
            	if(DaNhap){
            		printf("\nBan da chon Menu 5.Loai bo mot san pham trong gio hang!\n");
        			XuatDSSP(sp,n);
        			XoaSPtheoSTT(sp,n);
            	} else{
                	printf("\nBan can nhap thong tin trong menu 1 truoc !!!\n");
				}
				printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
            	if(DaNhap){
            		printf("\nBan da chon Menu 6.Tim kiem mot san pham trong gio hang!\n");
                    TimSPTheoTen(sp,n);
                } else{
                	printf("\nBan can nhap thong tin trong menu 1 truoc !!!\n");
				}
            	printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 7:
            	if(DaNhap){
            		printf("\nBan da chon Menu 7.Ghi toan bo noi dung vao file!\n");
            		printf("\n--> Da duoc ghi vao file co ten *DSSP.txt*\n");
					GhiFile(sp,n,FileName);
                } else{
                	printf("\nBan can nhap thong tin trong menu 1 truoc !!!\n");
				}
            	printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 8:
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

