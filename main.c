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
  backtomain:mainmenu();                         //显示主菜单

  if(ID==0)
  {
     printf("请输入密码以获得商品管理权限:\n");
     scanf("%s",password);
	 //输入密码
	 while(strcmp(password,correctpassword)!=0)
	 {
	    printf("密码输入错误，请重新输入:\n");
		scanf("%s",password);
	 }
	 //判断密码正误

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
           //显示供货商端菜单
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
         //显示消费者端菜单
         printf("\n\n\n");
         printf("返回主菜单按0,返回供货商端按1,返回消费者端按2： ");
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
    printf("\t|         请先选择您的身份        |\n");
    printf("\t|                                 |\n");
    printf("\t|                                 |\n");
    printf("\t ----------------------------------\n");
    printf("   please choose your id(0代表供货商，1代表消费者):");
	scanf("%d",&ID);
}
     // 显示主菜单



void showmenu1()
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t ----------------------------------\n");
  printf("\t|      Welcome to this machine    |\n");
  printf("\t|---------------------------------|\n");
  printf("\t|\t1-显示所有商品信息        |\n");
  printf("\t|\t2-直接购买商品            |\n");
  printf("\t|\t3-售后服务                |\n");
  printf("\t|\t4-查询商品信息            |\n");
  printf("\t|\t5-按序查看商品信息        |\n");
  printf("\t|\t6-向购物车中添加商品      |\n");
  printf("\t|\t7-结算购物车中商品        |\n");
  printf("\t|\t8-退出                    |\n");
  printf("\t ----------------------------------\n");
  printf("\n      ENTER YOUR CHOICE(1-6):");
}
    //显示消费者菜单



void showmenu0()
{
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t ----------------------------------\n");
  printf("\t|      Welcome to this machine    |\n");
  printf("\t|---------------------------------|\n");
  printf("\t|\t1-显示所有商品信息        |\n");
  printf("\t|\t2-上架商品                |\n");
  printf("\t|\t3-修改商品信息            |\n");
  printf("\t|\t4-下架商品				 |\n");
  printf("\t|\t5-查询商品信息            |\n");
  printf("\t|\t6-按序查看商品信息        |\n");
  printf("\t|\t7-查看已售清单及营业额    |\n");
  printf("\t|\t8-退出                    |\n");
  printf("\t ----------------------------------\n");
  printf("\n      ENTER YOUR CHOICE(1-6):");
}
    //显示供货商菜单



int ShowAll()       //显示所有商品信息
{
  system("cls");
  FILE *fp;
  int i;

  if((fp=fopen("E:\information.txt","rb"))==NULL)
  {
      printf("can not open the file\n");
      exit(0);
  }
  //判断文件是否能打开
  printf("\n\n\n\n\n");
  printf("\t -------------------------------------------\n");
  printf("\t|          Welcome to this machine          |\n");
  printf("\t|   商品名称   商品颜色   商品大小  商品价格|\n");
  printf("\t|-------------------------------------------|\n");
  for(i=0;(fread(&pros[i],sizeof(struct product),1,fp))!=0;i++)
  {
      printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
  }
  //循环从文件中读入商品信息并打印
  printf("\t -------------------------------------------\n\n\n");

  printf("           总共有%d件商品\n",i);
        if(fclose(fp))
      {
          printf("can not close the file\n");
          exit(0);
      }

      return i;
		//判断文件是否能关闭
}



void Add()      //添加商品信息
{
  FILE *fp;
  int i=0;
  int loop=1;     //判断循环是否成立
  system("cls");

  do
  {
	  printf("请输入上架商品的名称，颜色，大小和价格：");
	  scanf("%s%s%s%s",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
	  //从键盘读入商品信息
      if((fp=fopen("E:\information.txt","ab"))==NULL)
      {
          printf("can not open the file\n");
          exit(0);
      }
	  //判断文件是否能打开
      if(fwrite(&pros[i],sizeof(struct product),1,fp)!=1)
      printf("file write error\n");
	  //将数组中的商品信息写入文件，并判断是否写入成功
      if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //判断文件能否关闭
      printf("是否继续输入：(继续按1，停止按0)");
      scanf("%d",&loop);
      //if(loop==0)
        //back=1;
	  //判断是否继续循环
  }while(loop);

}



void Revise()        //修改商品信息
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
  printf("请输入要修改信息的商品名称:\n");
  scanf("%s",name);
   while(fread(&pros[i],sizeof(struct product),1,fp))  //循环读入商品信息
      {
            if(strcmp(name,pros[i].name)!=0)   //判断是否为要修改的商品信息
          {
           fwrite(&pros[i],sizeof(struct product),1,dfp);
           i++;
           //将不需要修改的商品信息写入新文件
          }
        else
            {
              rewind(fp);  //将文件指针重置于开头
              fseek(fp,sizeof(struct product)*(i+1),1);
            //将文件指针置于删除商品之后
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
         //判断文件能否关闭
        remove("e:\information.txt");
        //删除原文件
        rename("e:\delete.txt","e:\information.txt");
        //将新建立文件更名为原文件名
        printf("请输入新的商品信息(名称,颜色,大小和价格): ");
        scanf("%s%s%s%s",newpro.name,newpro.color,newpro.size,newpro.price);
        if((fp=fopen("E:\information.txt","ab"))==NULL)
        {
           printf("can not open the file\n");
           exit(0);
        }
        if(fwrite(&newpro,sizeof(struct product),1,fp)!=1)
            printf("商品信息修改失败\n");
        else
            printf("商品信息修改成功\n\n");

            if(fclose(fp))
         {
             printf("can not close the file\n");
             exit(0);
         }
}



void Delete()            //删除商品信息
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
    //判断文件能否打开
    ShowAll();       //显示商品清单
    printf("请输入您所要下架的商品名称:");
    scanf("%s",name);
    printf("确定下架该商品？\n");
    printf("按1确认，按0取消\n");
    scanf("%d",&confirm);
    if(confirm==1)
       {
           while(fread(&pros[i],sizeof(struct product),1,fp))  //循环读入商品信息
      {
            if(strcmp(name,pros[i].name)!=0)   //判断是否为要删除的商品信息
          {
           fwrite(&pros[i],sizeof(struct product),1,dfp);
           i++;
           //将不需要删除的商品信息写入新文件
          }
        else
            {
              rewind(fp);  //将文件指针重置于开头
              fseek(fp,sizeof(struct product)*(i+1),0);
            //将文件指针置于删除商品之后
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
         //判断文件能否关闭
        remove("e:\information.txt");
        //删除原文件
        rename("e:\delete.txt","e:\information.txt");
        //将新建立文件更名为原文件名
        printf("商品下架成功！\n");
       }
   else
    printf("\n\n已取消商品下架\n");
}


void Search()              //查询商品信息
{
  system("cls");
  int way;
  FILE* fp;
  int i=0;

    //判断文件能否打开
  printf("请选择您想要查找的方式：\n");
  printf("按名称查找请按1，");
  printf("按颜色查找请按2，");
  printf("按大小查找请按3");
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
  int judge=0;     //判断是否查询到的中间变量
  system("cls");
  FILE* fp;
  int i=0;
  char name[10];
  if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //判断文件能否打开
  printf("请输入您想要查询的商品名称：");
  scanf("%s",name);
  for(i=0;fread(&pros[i],sizeof(struct product),1,fp)!=0;i++)
  {
	  //循环从文件中读入商品信息
      if(strcmp(name,pros[i].name)==0)
	  {
		  judge=1;
		  printf("您所查询的商品信息如下：\n");
		  printf("%10s%10s%10s%10s\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
	  }
  }
      if(judge==0)
	  {
	    printf("抱歉，无法查询到该商品信息\n");
	  }
  	  if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //判断文件能否关闭
}

void searchbycolor()
{
  int judge=0;     //判断是否查询到的中间变量
  system("cls");
  FILE* fp;
  int i=0;
  char color[10];
  if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //判断文件能否打开
  printf("请输入您想要查询的商品颜色：");
  scanf("%s",color);
  for(i=0;fread(&pros[i],sizeof(struct product),1,fp)!=0;i++)
  {
	  //循环从文件中读入商品信息
      if(strcmp(color,pros[i].color)==0)
	  {
		  judge=1;
		  printf("您所查询的商品信息如下：\n");
		  printf("%10s%10s%10s%10s\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
	  }
  }
      if(judge==0)
	  {
	    printf("抱歉，无法查询到该商品信息\n");
	  }
  	  if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //判断文件能否关闭
}



void searchbysize()
{

  int judge=0;     //判断是否查询到的中间变量
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
    //判断文件能否打开
  printf("请输入您想要查询的商品大小：");
  scanf("%s",size);
    int j;
    int n;
    int k1;
    int k2;
    struct product temp;

    n=ShowAll();
    low=0;
    high=n-1;
    printf("原商品信息如上\n\n\n");
    while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //从文件中读入商品信息
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k1=convert(pros[j].size);
            k2=convert(pros[j+1].size);
            //将商品尺寸从字符串转化为整型
            if(k1>k2)
            {
                temp=pros[j+1];
                pros[j+1]=pros[j];
                pros[j]=temp;
                //交换相邻的商品位置
            }
        }
    }
    //使用冒泡排序对商品按尺寸大小排序

    while(low<=high)
    {
        mid=(low+high)/2;
        if(convert(pros[mid].size)==convert(size))
        {
            judge=1;
            printf("查找成功，该商品为%s  %s  %s  %s\n",pros[mid].name,pros[mid].color,pros[mid].size,pros[mid].price);
        }
        if(convert(size)>convert(pros[mid].size))
            low=mid+1;
        else
            high=mid-1;
    }
    if(judge==0)
    {
        printf("无法查询到您输入的商品\n");
    }




  	  if(fclose(fp))
      {
         printf("can not close the file\n");
          exit(0);
      }
	  //判断文件能否关闭
}

void Buy()              //购买商品
{
  system("cls");
  FILE *fp;
  FILE *newfp;
  FILE *dfp;
  char buyname[10];
  char buycolor[10];
  char buysize[10];
  int money;            //付款金额
  int change;           //找零金额
  int prices;           //实际价格
  int judge=0;
  int i=0;

  ShowAll();
  printf("请输入您要购买的商品名称：");
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
	//判断文件能否打开
	for(i=0;judge!=1;i++)
	{
      fread(&pros[i],sizeof(struct product),1,fp);
		//循环从文件中读入商品信息至读完为止
	  if((strcmp(buyname,pros[i].name)==0))
	  {
          if(fwrite(&pros[i],sizeof(struct product),1,newfp)!=1)
          printf("file write error\n");
	      judge=1;
		  printf("商品价格为%s,请投入纸币\n",pros[i].price);
		  printf("已收款:");
	      scanf("%d",&money);      //输入收款金额
          prices=convert(pros[i].price);     //将价格从字符串转化为整型
          change=money-prices;       //计算找零金额

          if(change>=0)
		  printf("感谢购买，找您%d元\n",change);
		  else
            {
             printf("还差%d元\n请继续付款\n",-change);
             printf("已收款:");
	         scanf("%d",&money);
             change=money+change;
             printf("感谢购买，找您%d元\n",change);
            }

		  //判断付款金额是否足够
	  }
	}
           i=0;
          if((dfp=fopen("E:\delete.txt","ab"))==NULL)
          {
              printf("can not open the file\n");
              exit(0);
          }
             while(fread(&pros[i],sizeof(struct product),1,fp))  //循环读入商品信息
          {
                 if(strcmp(buyname,pros[i].name)!=0)   //判断是否为要删除的商品信息
             {
               fwrite(&pros[i],sizeof(struct product),1,dfp);
               i++;
           //将不需要删除的商品信息写入新文件
             }
                else
            {
               rewind(fp);  //将文件指针重置于开头
               fseek(fp,sizeof(struct product)*(i+1),0);
            //将文件指针置于删除商品之后
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
         //判断文件能否关闭
        remove("e:\information.txt");
        //删除原文件
        rename("e:\delete.txt","e:\information.txt");
        //将新建立文件更名为原文件名
        printf("商品购买成功！\n");
		   if(fclose(newfp))
		   {
             printf("can not close the file\n");
             exit(0);
		   }
	      if(judge==0)
		  printf("您所要购买的商品不存在\n");
	}


void Service()            //消费者的反馈
{
  FILE *fp;
  char name[10];
  int like;
  int n;
  int i=0;
  struct product temp;

  system("cls");
  n=ShowAll();
  printf("\n\n请输入您要评价的商品名称：");
  scanf("%s",name);
    if((fp=fopen("E:\information.txt","rb"))==NULL)
    {
        printf("can not open the file\n");
        exit(0);
    }
    //判断文件能否打开
  printf("\n\n请给出您的评价（好评按1，差评按0）：");
  scanf("%d",&like);
  while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //从文件中读入商品信息
    for(i=0;i<n;i++)
    {
        if(strcmp(name,pros[i].name)==0)
        break;
    }
    //找到要评价的商品在原清单中的位置
  if(like==1)
  {
     temp=pros[i];
     pros[i]=pros[0];
     pros[0]=temp;
  }
  //将评价商品与第一位商品位置互换
  else
  {
      temp=pros[n-1];
      pros[n-1]=pros[i];
      pros[i]=temp;
  }
  //将评价商品与最后一位商品位置互换
  printf("评价成功\n\n");
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
     printf("\n\n\n\n\n");
     printf("\t -------------------------------------------\n");
     printf("\t|          Welcome to this machine          |\n");
     printf("\t|   商品名称   商品颜色   商品大小  商品价格|\n");
     printf("\t|-------------------------------------------|\n");
        for(i=0;i<n;i++)
      {
          printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
      }
       //循环从文件中读入商品信息并打印
     printf("\t -------------------------------------------\n\n\n");

}

void sort()
{
    system("cls");
    int way;
    system("cls");
    printf("\n\n请选择您要排序的方式：\n");
    printf("按价格升序请按1，按尺寸升序请按2：");
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
    //判断文件能否打开
    n=ShowAll();
    printf("原商品信息如上\n\n\n");
    while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //从文件中读入商品信息
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k1=convert(pros[j].price);
            k2=convert(pros[j+1].price);
            //将商品价格从字符串转化为整型
            if(k1>k2)
            {
                temp=pros[j+1];
                pros[j+1]=pros[j];
                pros[j]=temp;
                //交换相邻的商品位置
            }
        }
    }
    //使用冒泡排序对商品按价格高低排序
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //判断文件能否关闭
     printf("\n\n\n\n\n");
     printf("\t -------------------------------------------\n");
     printf("\t|          Welcome to this machine          |\n");
     printf("\t|   商品名称   商品颜色   商品大小  商品价格|\n");
     printf("\t|-------------------------------------------|\n");
        for(i=0;i<n;i++)
      {
          printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
      }
       //循环从文件中读入商品信息并打印
     printf("\t -------------------------------------------\n\n\n");
     //打印排序后所有商品信息
     printf("\n\n将商品按价格从低到高排序\n");
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
    //判断文件能否打开
    n=ShowAll();
    printf("原商品信息如上\n\n\n");
    while(fread(&pros[i],sizeof(struct product),1,fp)!=0)
    {
        i++;
    }
    //从文件中读入商品信息
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k1=convert(pros[j].size);
            k2=convert(pros[j+1].size);
            //将商品尺寸从字符串转化为整型
            if(k1>k2)
            {
                temp=pros[j+1];
                pros[j+1]=pros[j];
                pros[j]=temp;
                //交换相邻的商品位置
            }
        }
    }
    //使用冒泡排序对商品按尺寸大小排序
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //判断文件能否关闭
     printf("\n\n\n\n\n");
     printf("\t -------------------------------------------\n");
     printf("\t|          Welcome to this machine          |\n");
     printf("\t|   商品名称   商品颜色   商品大小  商品价格|\n");
     printf("\t|-------------------------------------------|\n");
        for(i=0;i<n;i++)
      {
          printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
      }
       //循环从文件中读入商品信息并打印
     printf("\t -------------------------------------------\n\n\n");
     printf("\n\n将商品按尺寸从低到高排序\n");
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
    //判断文件能否打开
      printf("已售商品如下：\n");
      printf("\n\n\n\n\n");
      printf("\t -------------------------------------------\n");
      printf("\t|          Welcome to this machine          |\n");
      printf("\t|   商品名称   商品颜色   商品大小  商品价格|\n");
      printf("\t|-------------------------------------------|\n");
    for(i=0;fread(&pros[i],sizeof(struct product),1,fp)!=0;i++)
    {
        printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
        money=convert(pros[i].price);
        sum=sum+money;
    }
    //读入商品信息并计算营业额之和
    printf("\t -------------------------------------------\n\n\n");
    printf("\n\n目前的营业总额为%d元\n",sum);
    if(fclose(fp))
    {
        printf("can not close the file\n");
        exit(0);
    }
    //判断文件能否关闭
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
   //判断文件能否打开
   while((fread(&pros[i],sizeof(struct product),1,fp))!=0)
   {
       i++;
   }
   //循环读入商品信息
   do
    {
        printf("\n\n请输入您想要添加至购物车的商品名称：");
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
      //查找该商品并写入文件
       printf("继续添加请按1，停止添加请按0：");
        scanf("%d",&loop);
        judge=0;
   }while(loop);

              if(fclose(fp))
          {
             printf("can not close the file\n");
             exit(0);
          }
             //判断文件能否关闭
            if(fclose(sfp))
          {
             printf("can not close the file\n");
             exit(0);
          }
         //判断文件能否关闭
}


void account()       //结算购物车
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
          printf("\t|   商品名称   商品颜色   商品大小  商品价格|\n");
          printf("\t|-------------------------------------------|\n");
          for(i=0;(fread(&pros[i],sizeof(struct product),1,sfp))!=0;i++)
          {
              price=convert(pros[i].price);
              sum=sum+price;
              printf("\t|%10s%10s%10s%10s   |\n",pros[i].name,pros[i].color,pros[i].size,pros[i].price);
          }
          //循环从文件中读入商品信息并打印
          printf("\t -------------------------------------------\n\n\n");
          printf("           购物车中总共有%d件商品\n",i);
          printf("           请支付%d元\n",sum);
          printf("           已收款：");
          scanf("%d",&money);
          loop:change=money-sum;
          if(change>=0)
          {
              printf("  购买成功，找您%d元\n",change);

          }
          else
          {
              printf("购买失败，请继续支付%d元",-change);
              printf("  已收款：");
              scanf("%d",&money);
              sum=-change;
              goto loop;
          }
          for(j=0;j<i;j++)
        {
           fwrite(&pros[j],sizeof(struct product),1,fp);
           //将shoppingcar文件中数据写入soldlist文件
            deletes(pros[j].name);
            //将infomation文件中与shoppingcar重合部分删除
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
    //判断文件能否打开

    while(fread(&products[i],sizeof(struct product),1,fps))  //循环读入商品信息
      {
            if(strcmp(name,products[i].name)!=0)   //判断是否为要删除的商品信息
          {
           fwrite(&products[i],sizeof(struct product),1,dfps);
           i++;
           //将不需要删除的商品信息写入新文件
          }
        else
            {
              rewind(fps);  //将文件指针重置于开头
              fseek(fps,sizeof(struct product)*(i+1),0);
            //将文件指针置于删除商品之后
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
         //判断文件能否关闭
        remove("E:\information.txt");
        //删除原文件
        rename("E:\delete.txt","E:\information.txt");
        //将新建立文件更名为原文件名
}


int convert(char num[])         //将字符串形式的数字转化为整型
{
    int a,b,c,e;
    int sum=0;
    int d=1;
    int i,j;
    c=strlen(num);      //求出字符串长度，即数字位数
    e=c;
    for(i=0;i<c;i++)
    {
        b=num[i]-48;     //将数字从ASCII码转化为整型
        d=1;
        for(j=1;j<e;j++)
        {
            d=d*10;     //乘以位数并相加
        }
        e--;
        sum=sum+b*d;
    }
    return sum;         //返回最终的转化结果
}

