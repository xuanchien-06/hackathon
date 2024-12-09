#include<stdio.h>

int main(){
	int arr[50];
	int choice,n,position,value;
	int max,max_2,min,min_2;
	int dem =0,x,index =0;
	
	do{
		printf("\nMenu\n");
		printf("1.Nhap so luong va gia tri cho cac phan tu\n");
		printf("2.In mang(arr[0]=...,\n)");
		printf("3.Dem so hoan hao\n");
		printf("4.Dem so luong so nguyen to\n");
		printf("5.Tim gia tri lon thu 2\n");
		printf("6.Tim gia tri nho thu 2\n");
		printf("7.Them phan tu tai vi tri\n");
		printf("8.Xoa phan tu tai vi tri\n");
		printf("9.Sap xep tang dan (sap xep theo chen)\n");
		printf("10.Sap xep giam dan (sap xep chen)\n");
		printf("11.Tim kiem phan tu (tim kiem nhi phan)\n");
		printf("12.Xoa phan tu trung lap va in phan tu doc nhat\n");
		printf("13.Sap xep va hien thi so chan dung truoc, so le dung sau\n");
		printf("14.Dao nguoc mang\n");
		printf("15.Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 1://Nhap so luong va gia tri cho cac phan tu
				printf("Nhap so luong mang: ");
				scanf("%d",&n);
				printf("Nhap phan gia tri cho cac phan tu:\n");
				for(int i=0;i<n;i++){
					printf("Phan tu thu %d: ",i);
					scanf("%d",&arr[i]);
				}
				break;
			case 2://in mang arr[0]=...
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				for(int i=0;i<n;i++){
					printf("arr[%d]=%d\n",i,arr[i]);
				}
			printf("\n");
			break;
			case 3://dem so hoan hao
					if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				for(int i=0 ;i<n ;i++){
					int sum = 0;
					int m = arr[i];
					for(int j=1; j<n;j++){
						if(m%j==0){
							sum += j;
						}
						if(m==sum){
							dem++;
						}
					}
				}
				printf("tong cac so hoan hao la: %d",dem);
			
				break;
			case 4://Dem so nguyen to
					if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				for(int i=0;i<=n;i++){
					int isprime=1;
					if(arr[i]<=1){
						isprime=0;
					}else{
						for(int j=2;j*j<=arr[i];j++){
							if(arr[i]%j==0){
								isprime=0;
								break;
							}
						}
					}
					if(isprime){
						printf("%d",arr[i]);
					}
				}
				printf("\n");
				break;
			case 5://Tim gia tri lon thu 2
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				max=arr[0];
				for(int i=0;i<n;i++){
					if(arr[i]>max){
						max_2=max;
						max=arr[i];
					}
				}
				printf("Gia tri lon thu 2 cua mang la: %d",max_2);
				break;
//				case 5:
//					max=arr[0];
//					for(int i=0;i<n;i++){
//						if(arr[i]>max){
//							max_2=max;
//							max=arr[i];
//						}
//					}
//					printf("Gia tri lon thu 2 cua mang la:%d",max_2);
//					break;
			case 6://Tim gia tri nho thu 2
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				min = arr[0];
				for(int i=0 ; i<n ; i++){
					if(min > arr[i]){
						min_2 = min;
						min = arr[i];
					}
				}
				printf("Gia tri nho thu 2 cua mang la: %d",min_2);
				break;
			case 7://Them phan tu tai vi tri
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				printf("Nhap vi tri muon them: ");
				scanf("%d",&position);
				printf("Nhap gia tri muon them: ");
				scanf("%d",&value);
				if(position<0||position>n){
					printf("Vi tri muon them khong hop le");
				}
				for(int i=n;i>position;i--){
					arr[i]=arr[i-1];
				}
				arr[position]=value;
				n++;
				for(int i=0;i<n;i++){
					printf("%d\t",arr[i]);
				}
				printf("\n");
				break;
			case 8://xoa phan tu tai vi tri
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				printf("Nhap vi tri muon xoa: ");
				scanf("%d",&position);
				if(position<0||position>n){
					printf("Vi tri muon nhap khong hop le");
				}
				for (int i=position ; i<n-1 ; i++){
					arr[i]=arr[i+1];
				}
				n--;
				for(int i=0 ; i<n ; i++){
					printf("%d\t",arr[i]);
				}
				printf("\n");
				break;
			case 9://Sap xep tang dan (sap xep theo chen)
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				for(int i=1 ; i<n ; i++){
					int key = arr[i];
					int j = i - 1;
					while(j >= 0 && arr[j]>key){
						arr[j+1]=arr[j];
						j = j - 1;
					}
					arr[j+1] = key;
				}
				
				printf("Mang da duoc sap xep: ");
				for(int i=0 ; i<n ; i++){
					printf("%d",arr[i]);
				}
				printf("\n");
				break;
			case 10://Sap xep giam dan (sap xep chen)
				if(n==0){
					printf("Chua khoi tao mang");
					continue;
				}
				for(int i=1 ; i<n ; i++){
					int reduce = arr[i];
					int l = l - 1;
					while(l >= 0 && arr[l]<reduce){
						arr[l+1]=arr[l];
						l = l - 1;
					}
					arr[l+1] = reduce;
				}
				
				printf("Mang da duoc sap xep: ");
				for(int i=0 ; i<n ; i++){
					printf("%d\t",arr[i]);
				}
				printf("\n");
				break;
			case 11://tim kiem phan tu
				printf("Nhap gia tri muon tim: ");
				scanf("%d",&x);
				for(int i=0; i<n; i++){
					if(arr[i]==x){
						printf("So can tim o vi tri: %d",i);
						index = 1;
					}
				}
				if(index = 0){
					printf("So can tim khong co trong mang");
				}
				break;
			case 15://thoat
				printf("Thoat chuong trinh");
				break;
			default:
				printf("lua chon khong hop le");		
		}
	}
	while(choice!=15);
	return 0;
}
