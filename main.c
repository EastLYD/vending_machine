#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>

struct product
{
    char name[10];
    char color[10];
    char size[10];
    char price[10];
}pros[1000];
int count=0;
int ID;
int convert(char num[]);
int back=3;
void mainmenu();
void showmenu1();
void showmenu0();
int  ShowAll();
void Add();
void Revise();
void Delete();
void Search();
void Buy();
void Service();
void sort();
void sortbyprice();
void sortbysize();
void searchbycolor();
void searchbyname();
void searchbysize();
void turnover();
void shoppingcar();
void account();
void deletes(char name[]);

int main()
{
  int n;
  char password[20];
  char *correctpassword="123456";
  backtomain:mainmenu();                         //��ʾ���˵�

  if(ID==0)
  {
     printf("�����������Ի����Ʒ����Ȩ��:\n");
     scanf("%s",password);
	 //��������
	 while(strcmp(password,correctpassword)!=0)
	 {
	    printf("���������������������:\n");
		scanf("%s",password);
	 }
	 //�ж���������

     backtomenu0:showmenu0();
      scanf("%d",&n);
     // while(n)
     //   {
            switch(n){
            case 1:ShowAll();
            break;
            case 2:Add();
            break;
            case 3:Revise();
            break;
            case 4:Delete();
            break;
            case 5:Search();
            break;
            case 6:sort();
            break;
            case 7:turnover();
            break;
            case 8:exit(0);
            default:break;
            }
         // scanf("%d",&n);
       // }
    }
           //��ʾ�����̶˲˵�
   else
       {
      backtomenu1:  showmenu1();
        scanf("%d",&n);
     //   while(n)
         // {
            switch(n){
            case 1:ShowAll();
            break;
            case 2:Buy();
            break;
            case 3:Service();
            break;
            case 4:Search();
            break;
            case 5:sort();
            break;
			case 6:shoppingcar();
			break;
			case 7:account();
			break;
			case 8:exit(0);
			break;
            default:break;
            }
          //}
       }
         //��ʾ�����߶˲˵�
         printf("\n\n\n");
         printf("�������˵���0,���ع����̶˰�1,���������߶˰�2�� ");
         scanf("%d",&back);
         if(back==0)
         goto backtomain;
         else if(back==1)
         goto backtomenu0;
         else if(back==2)
         goto backtomenu1;

       return 0;
}


void mainmenu()
{

    system("cls");
    printf("\n\n\n\n\n");
    printf("\t ----------------------------------\n");
    printf("\t|      Welcome to this machine    |\n");
    printf("\t|---------------------------------|\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t|         ����ѡ���������        |\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t ----------------------------------\n");
    printf("   please choose your id(0�������̣�1����������):");
	scanf("%d",&ID);
}
     // ��ʾ���˵�



void showmenu1()
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t ----------------------------------\n");
  printf("\t|      Welcome to this machine    |\n");
  printf("\t|---------------------------------|\n");
  printf("\t|\t1-��ʾ������Ʒ��Ϣ        |\n");
  printf("\t|\t2-ֱ�ӹ�����Ʒ            |\n");
  printf("\t|\t3-�ۺ����                |\n");
  printf("\t|\t4-��ѯ��Ʒ��Ϣ            |\n");
  printf("\t|\t5-����鿴��Ʒ��Ϣ        |\n");
  printf("\t|\t6-���ﳵ�������Ʒ      |\n");
  printf("\t|\t7-���㹺�ﳵ����Ʒ        |\n");
  printf("\t|\t8-�˳�                    |\n");
  printf("\t ----------------------------------\n");
  printf("\n      ENTER YOUR CHOICE(1-6):");
}
    //��ʾ�����߲˵�



void showmenu0()
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t ----------------------------------\n");
  printf("\t|      Welcome to this machine    |\n");
  printf("\t|---------------------------------|\n");
  printf("\t|\t1-��ʾ������Ʒ��Ϣ        |\n");
  printf("\t|\t2-�ϼ���Ʒ                |\n");
  printf("\t|\t3-�޸���Ʒ��Ϣ            |\n");
  printf("\t|\t4-�¼���Ʒ				 |\n");
  printf("\t|\t5-��ѯ��Ʒ��Ϣ            |\n");
  printf("\t|\t6-����鿴��Ʒ��Ϣ        |\n");
  printf("\t|\t7-�鿴�����嵥��Ӫҵ��    |\n");
  printf("\t|\t8-�˳�                    |\n");
  printf("\t ----------------------------------\n");
  printf("\n      ENTER YOUR CHOICE(1-6):");
}
    //��ʾ�����̲˵�



int ShowAll()       //��ʾ������Ʒ��Ϣ
{
  system("cls");
  FILE *fp;
  int i;

  if((fp=fopen("E:\information.txt","rb"))==NULL)
  {
      printf("can not open the file\n");
      exit(0);
  }
  //�ж��ļ��Ƿ��ܴ�
  printf("\n\n\n\n\n");
  printf("\t -------------------------------------------\n");
  printf("\t|          Welcome to this machine          |\n");
  printf("\t|   ��Ʒ����   ��Ʒ��ɫ   ��Ʒ��С  ��Ʒ�۸�|\n");
  printf("\t|-------------------------------------------|\n");
  for(i=0;(fread(&pros[i],sizeof(struct product),1,fp))!=0;i++)
  {
      printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
  }
  //ѭ�����ļ��ж�����Ʒ��Ϣ����ӡ
  printf("\t -------------------------------------------\n\n\n");

  printf("           �ܹ���%d����Ʒ\n",i);
        if(fclose(fp))
      {
          printf("can not close the file\n");
          exit(0);
      }

      return i;
		//�ж��ļ��Ƿ��ܹر�
}



void Add()      //�����Ʒ��Ϣ
{
  FILE *fp;
  int i=0;
  int loop=1;     //�ж�ѭ���Ƿ����
  system("cls");

  do
  {
	  printf("�������ϼ���Ʒ�����ƣ���ɫ����С�ͼ۸�");
	  scanf("%s%s%s%s",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
	  //�Ӽ��̶�����Ʒ��Ϣ
      if((fp=fopen("E:\information.txt","ab"))==NULL)
      {
          printf("can not open the file\n");
          exit(0);
      }
	  //�ж��ļ��Ƿ��ܴ�
      if(fwrite(&pros[i],sizeof(struct product),1,fp)!=1)
      printf("file write error\n");
	  //�������е���Ʒ��Ϣд���ļ������ж��Ƿ�д��ɹ�
      if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //�ж��ļ��ܷ�ر�
      printf("�Ƿ�������룺(������1��ֹͣ��0)");
      scanf("%d",&loop);
      //if(loop==0)
        //back=1;
	  //�ж��Ƿ����ѭ��
  }while(loop);

}



void Revise()        //�޸���Ʒ��Ϣ
{
  system("cls");
  FILE* fp;
  FILE* dfp;
  int i=0;
  int j;
  char name[10];
  struct product newpro;

    if((fp=fopen("E:\information.txt","rb+"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if((dfp=fopen("E:\delete.txt","ab"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }

  ShowAll();
  printf("������Ҫ�޸���Ϣ����Ʒ����:\n");
  scanf("%s",name);
   while(fread(&pros[i],sizeof(struct product),1,fp))  //ѭ��������Ʒ��Ϣ
      {
            if(strcmp(name,pros[i].name)!=0)   //�ж��Ƿ�ΪҪ�޸ĵ���Ʒ��Ϣ
          {
           fwrite(&pros[i],sizeof(struct product),1,dfp);
           i++;
           //������Ҫ�޸ĵ���Ʒ��Ϣд�����ļ�
          }
        else
            {
              rewind(fp);  //���ļ�ָ�������ڿ�ͷ
              fseek(fp,sizeof(struct product)*(i+1),1);
            //���ļ�ָ������ɾ����Ʒ֮��
            //fseek(fp,0,1);
            }
       }

	        if(fclose(fp))
         {
             printf("can not close the file\n");
             exit(0);
         }
            if(fclose(dfp))
         {
            printf("can not close the file\n");
            exit(0);
         }
         //�ж��ļ��ܷ�ر�
        remove("e:\information.txt");
        //ɾ��ԭ�ļ�
        rename("e:\delete.txt","e:\information.txt");
        //���½����ļ�����Ϊԭ�ļ���
        printf("�������µ���Ʒ��Ϣ(����,��ɫ,��С�ͼ۸�): ");
        scanf("%s%s%s%s",newpro.name,newpro.color,newpro.size,newpro.price);
        if((fp=fopen("E:\information.txt","ab"))==NULL)
        {
           printf("can not open the file\n");
           exit(0);
        }
        if(fwrite(&newpro,sizeof(struct product),1,fp)!=1)
            printf("��Ʒ��Ϣ�޸�ʧ��\n");
        else
            printf("��Ʒ��Ϣ�޸ĳɹ�\n\n");

            if(fclose(fp))
         {
             printf("can not close the file\n");
             exit(0);
         }
}



void Delete()            //ɾ����Ʒ��Ϣ
{
  system("cls");
  FILE* fp;
  FILE* dfp;
  int i=0;
  int j;
  char name[10];
  int judge=0;
  int confirm;

  if((fp=fopen("E:\information.txt","rb+"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if((dfp=fopen("E:\delete.txt","ab"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
    ShowAll();       //��ʾ��Ʒ�嵥
    printf("����������Ҫ�¼ܵ���Ʒ����:");
    scanf("%s",name);
    printf("ȷ���¼ܸ���Ʒ��\n");
    printf("��1ȷ�ϣ���0ȡ��\n");
    scanf("%d",&confirm);
    if(confirm==1)
       {
           while(fread(&pros[i],sizeof(struct product),1,fp))  //ѭ��������Ʒ��Ϣ
      {
            if(strcmp(name,pros[i].name)!=0)   //�ж��Ƿ�ΪҪɾ������Ʒ��Ϣ
          {
           fwrite(&pros[i],sizeof(struct product),1,dfp);
           i++;
           //������Ҫɾ������Ʒ��Ϣд�����ļ�
          }
        else
            {
              rewind(fp);  //���ļ�ָ�������ڿ�ͷ
              fseek(fp,sizeof(struct product)*(i+1),0);
            //���ļ�ָ������ɾ����Ʒ֮��
           // fseek(fp,sizeof(struct product),1);
             // fseek(fp,0,1);
            }
       }
	        if(fclose(fp))
         {
             printf("can not close the file\n");
             exit(0);
         }
            if(fclose(dfp))
         {
            printf("can not close the file\n");
            exit(0);
         }
         //�ж��ļ��ܷ�ر�
        remove("e:\information.txt");
        //ɾ��ԭ�ļ�
        rename("e:\delete.txt","e:\information.txt");
        //���½����ļ�����Ϊԭ�ļ���
        printf("��Ʒ�¼ܳɹ���\n");
       }
   else
    printf("\n\n��ȡ����Ʒ�¼�\n");
}


void Search()              //��ѯ��Ʒ��Ϣ
{
  system("cls");
  int way;
  FILE* fp;
  int i=0;

    //�ж��ļ��ܷ��
  printf("��ѡ������Ҫ���ҵķ�ʽ��\n");
  printf("�����Ʋ����밴1��");
  printf("����ɫ�����밴2��");
  printf("����С�����밴3");
  scanf("%d",&way);
  switch(way)
  {
      case 1:searchbyname();
      break;
      case 2:searchbycolor();
      break;
      case 3:searchbysize();
      break;
      default:break;
  }
}

void searchbyname()
{
  int judge=0;     //�ж��Ƿ��ѯ�����м����
  system("cls");
  FILE* fp;
  int i=0;
  char name[10];
  if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
  printf("����������Ҫ��ѯ����Ʒ���ƣ�");
  scanf("%s",name);
  for(i=0;fread(&pros[i],sizeof(struct product),1,fp)!=0;i++)
  {
	  //ѭ�����ļ��ж�����Ʒ��Ϣ
      if(strcmp(name,pros[i].name)==0)
	  {
		  judge=1;
		  printf("������ѯ����Ʒ��Ϣ���£�\n");
		  printf("%10s%10s%10s%10s\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
	  }
  }
      if(judge==0)
	  {
	    printf("��Ǹ���޷���ѯ������Ʒ��Ϣ\n");
	  }
  	  if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //�ж��ļ��ܷ�ر�
}

void searchbycolor()
{
  int judge=0;     //�ж��Ƿ��ѯ�����м����
  system("cls");
  FILE* fp;
  int i=0;
  char color[10];
  if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
  printf("����������Ҫ��ѯ����Ʒ��ɫ��");
  scanf("%s",color);
  for(i=0;fread(&pros[i],sizeof(struct product),1,fp)!=0;i++)
  {
	  //ѭ�����ļ��ж�����Ʒ��Ϣ
      if(strcmp(color,pros[i].color)==0)
	  {
		  judge=1;
		  printf("������ѯ����Ʒ��Ϣ���£�\n");
		  printf("%10s%10s%10s%10s\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
	  }
  }
      if(judge==0)
	  {
	    printf("��Ǹ���޷���ѯ������Ʒ��Ϣ\n");
	  }
  	  if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //�ж��ļ��ܷ�ر�
}



void searchbysize()
{

  int judge=0;     //�ж��Ƿ��ѯ�����м����
  system("cls");
  FILE* fp;
  int i=0;
  char size[10];
  int low;
  int mid;
  int high;
  if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
  printf("����������Ҫ��ѯ����Ʒ��С��");
  scanf("%s",size);
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    n=ShowAll();
    low=0;
    high=n-1;
    printf("ԭ��Ʒ��Ϣ����\n\n\n");
    while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //���ļ��ж�����Ʒ��Ϣ
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k1=convert(pros[j].size);
            k2=convert(pros[j+1].size);
            //����Ʒ�ߴ���ַ���ת��Ϊ����
            if(k1>k2)
            {
                temp=pros[j+1];
                pros[j+1]=pros[j];
                pros[j]=temp;
                //�������ڵ���Ʒλ��
            }
        }
    }
    //ʹ��ð���������Ʒ���ߴ��С����

    while(low<=high)
    {
        mid=(low+high)/2;
        if(convert(pros[mid].size)==convert(size))
        {
            judge=1;
            printf("���ҳɹ�������ƷΪ%s  %s  %s  %s\n",pros[mid].name,pros[mid].color,pros[mid].size,pros[mid].price);
        }
        if(convert(size)>convert(pros[mid].size))
            low=mid+1;
        else
            high=mid-1;
    }
    if(judge==0)
    {
        printf("�޷���ѯ�����������Ʒ\n");
    }




  	  if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //�ж��ļ��ܷ�ر�
}

void Buy()              //������Ʒ
{
  system("cls");
  FILE *fp;
  FILE *newfp;
  FILE *dfp;
  char buyname[10];
  char buycolor[10];
  char buysize[10];
  int money;            //������
  int change;           //������
  int prices;           //ʵ�ʼ۸�
  int judge=0;
  int i=0;

  ShowAll();
  printf("��������Ҫ�������Ʒ���ƣ�");
  scanf("%s",buyname);
    if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if((newfp=fopen("E:\soldlist.txt","ab"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
	//�ж��ļ��ܷ��
	for(i=0;judge!=1;i++)
	{
      fread(&pros[i],sizeof(struct product),1,fp);
		//ѭ�����ļ��ж�����Ʒ��Ϣ������Ϊֹ
	  if((strcmp(buyname,pros[i].name)==0))
	  {
          if(fwrite(&pros[i],sizeof(struct product),1,newfp)!=1)
          printf("file write error\n");
	      judge=1;
		  printf("��Ʒ�۸�Ϊ%s,��Ͷ��ֽ��\n",pros[i].price);
		  printf("���տ�:");
	      scanf("%d",&money);      //�����տ���
          prices=convert(pros[i].price);     //���۸���ַ���ת��Ϊ����
          change=money-prices;       //����������

          if(change>=0)
		  printf("��л��������%dԪ\n",change);
		  else
            {
             printf("����%dԪ\n���������\n",-change);
             printf("���տ�:");
	         scanf("%d",&money);
             change=money+change;
             printf("��л��������%dԪ\n",change);
            }

		  //�жϸ������Ƿ��㹻
	  }
	}
           i=0;
          if((dfp=fopen("E:\delete.txt","ab"))==NULL)
          {
              printf("can not open the file\n");
              exit(0);
          }
             while(fread(&pros[i],sizeof(struct product),1,fp))  //ѭ��������Ʒ��Ϣ
          {
                 if(strcmp(buyname,pros[i].name)!=0)   //�ж��Ƿ�ΪҪɾ������Ʒ��Ϣ
             {
               fwrite(&pros[i],sizeof(struct product),1,dfp);
               i++;
           //������Ҫɾ������Ʒ��Ϣд�����ļ�
             }
                else
            {
               rewind(fp);  //���ļ�ָ�������ڿ�ͷ
               fseek(fp,sizeof(struct product)*(i+1),0);
            //���ļ�ָ������ɾ����Ʒ֮��
           // fseek(fp,sizeof(struct product),1);
              //fseek(fp,0,1);
            }
         }

	        if(fclose(fp))
         {
             printf("can not close the file\n");
             exit(0);
         }
            if(fclose(dfp))
         {
            printf("can not close the file\n");
            exit(0);
         }
         //�ж��ļ��ܷ�ر�
        remove("e:\information.txt");
        //ɾ��ԭ�ļ�
        rename("e:\delete.txt","e:\information.txt");
        //���½����ļ�����Ϊԭ�ļ���
        printf("��Ʒ����ɹ���\n");
		   if(fclose(newfp))
		   {
             printf("can not close the file\n");
             exit(0);
		   }
	      if(judge==0)
		  printf("����Ҫ�������Ʒ������\n");
	}


void Service()            //�����ߵķ���
{
  FILE *fp;
  char name[10];
  int like;
  int n;
  int i=0;
  struct product temp;

  system("cls");
  n=ShowAll();
  printf("\n\n��������Ҫ���۵���Ʒ���ƣ�");
  scanf("%s",name);
    if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
  printf("\n\n������������ۣ�������1��������0����");
  scanf("%d",&like);
  while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //���ļ��ж�����Ʒ��Ϣ
    for(i=0;i<n;i++)
    {
        if(strcmp(name,pros[i].name)==0)
        break;
    }
    //�ҵ�Ҫ���۵���Ʒ��ԭ�嵥�е�λ��
  if(like==1)
  {
     temp=pros[i];
     pros[i]=pros[0];
     pros[0]=temp;
  }
  //��������Ʒ���һλ��Ʒλ�û���
  else
  {
      temp=pros[n-1];
      pros[n-1]=pros[i];
      pros[i]=temp;
  }
  //��������Ʒ�����һλ��Ʒλ�û���
  printf("���۳ɹ�\n\n");
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
     printf("\n\n\n\n\n");
     printf("\t -------------------------------------------\n");
     printf("\t|          Welcome to this machine          |\n");
     printf("\t|   ��Ʒ����   ��Ʒ��ɫ   ��Ʒ��С  ��Ʒ�۸�|\n");
     printf("\t|-------------------------------------------|\n");
        for(i=0;i<n;i++)
      {
          printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
      }
       //ѭ�����ļ��ж�����Ʒ��Ϣ����ӡ
     printf("\t -------------------------------------------\n\n\n");

}

void sort()
{
    system("cls");
    int way;
    system("cls");
    printf("\n\n��ѡ����Ҫ����ķ�ʽ��\n");
    printf("���۸������밴1�����ߴ������밴2��");
    scanf("%d",&way);
    switch(way)
    {
        case 1:sortbyprice();
        break;
        case 2:sortbysize();
        break;
        default:break;
    }
}

void sortbyprice()
{
    FILE *fp;
    int i=0;
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
    n=ShowAll();
    printf("ԭ��Ʒ��Ϣ����\n\n\n");
    while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //���ļ��ж�����Ʒ��Ϣ
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k1=convert(pros[j].price);
            k2=convert(pros[j+1].price);
            //����Ʒ�۸���ַ���ת��Ϊ����
            if(k1>k2)
            {
                temp=pros[j+1];
                pros[j+1]=pros[j];
                pros[j]=temp;
                //�������ڵ���Ʒλ��
            }
        }
    }
    //ʹ��ð���������Ʒ���۸�ߵ�����
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ�ر�
     printf("\n\n\n\n\n");
     printf("\t -------------------------------------------\n");
     printf("\t|          Welcome to this machine          |\n");
     printf("\t|   ��Ʒ����   ��Ʒ��ɫ   ��Ʒ��С  ��Ʒ�۸�|\n");
     printf("\t|-------------------------------------------|\n");
        for(i=0;i<n;i++)
      {
          printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
      }
       //ѭ�����ļ��ж�����Ʒ��Ϣ����ӡ
     printf("\t -------------------------------------------\n\n\n");
     //��ӡ�����������Ʒ��Ϣ
     printf("\n\n����Ʒ���۸�ӵ͵�������\n");
}

void sortbysize()
{
    FILE *fp;
    int i=0;
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
    n=ShowAll();
    printf("ԭ��Ʒ��Ϣ����\n\n\n");
    while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //���ļ��ж�����Ʒ��Ϣ
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k1=convert(pros[j].size);
            k2=convert(pros[j+1].size);
            //����Ʒ�ߴ���ַ���ת��Ϊ����
            if(k1>k2)
            {
                temp=pros[j+1];
                pros[j+1]=pros[j];
                pros[j]=temp;
                //�������ڵ���Ʒλ��
            }
        }
    }
    //ʹ��ð���������Ʒ���ߴ��С����
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ�ر�
     printf("\n\n\n\n\n");
     printf("\t -------------------------------------------\n");
     printf("\t|          Welcome to this machine          |\n");
     printf("\t|   ��Ʒ����   ��Ʒ��ɫ   ��Ʒ��С  ��Ʒ�۸�|\n");
     printf("\t|-------------------------------------------|\n");
        for(i=0;i<n;i++)
      {
          printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
      }
       //ѭ�����ļ��ж�����Ʒ��Ϣ����ӡ
     printf("\t -------------------------------------------\n\n\n");
     printf("\n\n����Ʒ���ߴ�ӵ͵�������\n");
}


void turnover()
{
    system("cls");
    FILE *fp;
    int i;
    int sum=0;
    int money;

    if((fp=fopen("E:\soldlist.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��
      printf("������Ʒ���£�\n");
      printf("\n\n\n\n\n");
      printf("\t -------------------------------------------\n");
      printf("\t|          Welcome to this machine          |\n");
      printf("\t|   ��Ʒ����   ��Ʒ��ɫ   ��Ʒ��С  ��Ʒ�۸�|\n");
      printf("\t|-------------------------------------------|\n");
    for(i=0;fread(&pros[i],sizeof(struct product),1,fp)!=0;i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
        money=convert(pros[i].price);
        sum=sum+money;
    }
    //������Ʒ��Ϣ������Ӫҵ��֮��
    printf("\t -------------------------------------------\n\n\n");
    printf("\n\nĿǰ��Ӫҵ�ܶ�Ϊ%dԪ\n",sum);
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ�ر�
}

void shoppingcar()
{
   FILE *sfp;
   FILE *fp;
   int n;
   int i=0;
   int judge=0;
   system("cls");
   n=ShowAll();
   char name[10];
   int loop=1;
   if((sfp=fopen("E:\shoppingcar.txt","ab"))==NULL)
   {
       printf("can not open the file");
       exit(0);
   }
   if((fp=fopen("E:\information.txt","rb"))==NULL)
   {
       printf("can not open the file\n");
       exit(0);
   }
   //�ж��ļ��ܷ��
   while((fread(&pros[i],sizeof(struct product),1,fp))!=0)
   {
       i++;
   }
   //ѭ��������Ʒ��Ϣ
   do
    {
        printf("\n\n����������Ҫ��������ﳵ����Ʒ���ƣ�");
        scanf("%s",name);
        for(i=0;judge!=1;i++)
      {
           if(strcmp(name,pros[i].name)==0)
         {
           judge=1;
           fwrite(&pros[i],sizeof(struct product),1,sfp);
         }
           else
           continue;
      }
      //���Ҹ���Ʒ��д���ļ�
       printf("��������밴1��ֹͣ����밴0��");
        scanf("%d",&loop);
        judge=0;
   }while(loop);

              if(fclose(fp))
          {
             printf("can not close the file\n");
             exit(0);
          }
             //�ж��ļ��ܷ�ر�
            if(fclose(sfp))
          {
             printf("can not close the file\n");
             exit(0);
          }
         //�ж��ļ��ܷ�ر�
}


void account()       //���㹺�ﳵ
{
    FILE *sfp;
    FILE *fp;
    int i;
    int sum=0;
    int price;
    int money;
    int change;
    int j;
    system("cls");
    if((sfp=fopen("E:\shoppingcar.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    if((fp=fopen("E:\soldlist.txt","ab"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
          printf("\n\n\n\n\n");
          printf("\t -------------------------------------------\n");
          printf("\t|          Welcome to this machine          |\n");
          printf("\t|   ��Ʒ����   ��Ʒ��ɫ   ��Ʒ��С  ��Ʒ�۸�|\n");
          printf("\t|-------------------------------------------|\n");
          for(i=0;(fread(&pros[i],sizeof(struct product),1,sfp))!=0;i++)
          {
              price=convert(pros[i].price);
              sum=sum+price;
              printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
          }
          //ѭ�����ļ��ж�����Ʒ��Ϣ����ӡ
          printf("\t -------------------------------------------\n\n\n");
          printf("           ���ﳵ���ܹ���%d����Ʒ\n",i);
          printf("           ��֧��%dԪ\n",sum);
          printf("           ���տ");
          scanf("%d",&money);
          loop:change=money-sum;
          if(change>=0)
          {
              printf("  ����ɹ�������%dԪ\n",change);

          }
          else
          {
              printf("����ʧ�ܣ������֧��%dԪ",-change);
              printf("  ���տ");
              scanf("%d",&money);
              sum=-change;
              goto loop;
          }
          for(j=0;j<i;j++)
        {
           fwrite(&pros[j],sizeof(struct product),1,fp);
           //��shoppingcar�ļ�������д��soldlist�ļ�
            deletes(pros[j].name);
            //��infomation�ļ�����shoppingcar�غϲ���ɾ��
        }

        if(fclose(sfp))
          {
             printf("can not close the file\n");
             exit(0);
          }
        if(fclose(fp))
          {
             printf("can not close the file\n");
             exit(0);
          }
        remove("E:\shoppingcar.txt");
}

void deletes(char name[])
{
  FILE* fps;
  FILE* dfps;
  int i=0;
  int j;
  int judge=0;
  int confirm;
  struct product products[50];

   if((fps=fopen("E:\information.txt","rb+"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
   if((dfps=fopen("E:\delete.txt","ab"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //�ж��ļ��ܷ��

    while(fread(&products[i],sizeof(struct product),1,fps))  //ѭ��������Ʒ��Ϣ
      {
            if(strcmp(name,products[i].name)!=0)   //�ж��Ƿ�ΪҪɾ������Ʒ��Ϣ
          {
           fwrite(&products[i],sizeof(struct product),1,dfps);
           i++;
           //������Ҫɾ������Ʒ��Ϣд�����ļ�
          }
        else
            {
              rewind(fps);  //���ļ�ָ�������ڿ�ͷ
              fseek(fps,sizeof(struct product)*(i+1),0);
            //���ļ�ָ������ɾ����Ʒ֮��
           // fseek(fp,sizeof(struct product),1);
             // fseek(fp,0,1);
            }
       }
	        if(fclose(fps))
         {
             printf("can not close the file\n");
             exit(0);
         }
            if(fclose(dfps))
         {
            printf("can not close the file\n");
            exit(0);
         }
         //�ж��ļ��ܷ�ر�
        remove("E:\information.txt");
        //ɾ��ԭ�ļ�
        rename("E:\delete.txt","E:\information.txt");
        //���½����ļ�����Ϊԭ�ļ���
}


int convert(char num[])         //���ַ�����ʽ������ת��Ϊ����
{
    int a,b,c,e;
    int sum=0;
    int d=1;
    int i,j;
    c=strlen(num);      //����ַ������ȣ�������λ��
    e=c;
    for(i=0;i<c;i++)
    {
        b=num[i]-48;     //�����ִ�ASCII��ת��Ϊ����
        d=1;
        for(j=1;j<e;j++)
        {
            d=d*10;     //����λ�������
        }
        e--;
        sum=sum+b*d;
    }
    return sum;         //�������յ�ת�����
}

