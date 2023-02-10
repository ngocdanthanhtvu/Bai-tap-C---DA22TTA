#include<stdio.h>
#include<stdlib.h>
struct SINHVIEN
{
	char mssv[10], hoten[30], gioitinh[4];
	int namsinh, somonhoc;
	float*diem;
};
typedef struct SINHVIEN SV;

void nhap(SV *sv);
void xuat(SV sv);

int main()
{
	SINHVIEN a;
	nhap(&a);
	xuat(a);
	return 0;
}
void xuat(SV sv)
{
	printf("\n%s\t%s\t%d\t%s\n", sv.mssv, sv.hoten, sv.namsinh, sv.gioitinh);
	printf("\nDiem so %d mon hoc: ", sv.somonhoc);
	int i = 0;
	while(i<sv.somonhoc)
	{
		printf("%5.1f", *(sv.diem+i));
		i++;
	}
}
void nhap(SV *sv)
{
	printf("\nNhap ma so sinh vien: ");
	fflush(stdin);
	scanf("%s", sv->mssv);
	
	printf("\nNhap ho ten sinh vien: ");
	fflush(stdin);
	gets(sv->hoten);
	
	printf("\nNhap nam sinh: ");
	scanf("%d", &sv->namsinh);
	
	printf("\nNhap gioi tinh: ");
	fflush(stdin);
	scanf("%s", sv->gioitinh);
	
	printf("\nNhap so mon hoc: ");
	scanf("%d", &sv->somonhoc);
	
	//Cap phat vung nho cho thanh phan diem
	sv->diem = (float*)malloc(sizeof(float)*sv->somonhoc);
	int i = 0;
	while(i<sv->somonhoc)
	{
		printf("\nNhap diem mon thu %d: ", i+1);
		scanf("%f", sv->diem+i);
		i++;
	}
}
