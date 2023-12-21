#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <time.h>
#include<conio.h>
#define n 3// 柜台数
int vip1 = 0;//vip个数
static int i = 1;
int y, z;//y为评分，z为柜台号
float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;//每个柜台的总分
float i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
float ave1 = 0, ave2 = 0, ave3 = 0, ave4 = 0, ave5 = 0;

typedef struct List
{
    int A[n + 1];// 顾客用来办理业务的n个窗口
    int len;//表示数组中的元素个数
}List;

typedef struct Lnode
{//链表节点类型
    int data;
    struct Lnode* next;
}Lnode;

typedef struct Linkqueue
{//链式存储的等候队列类型定义
    Lnode* front;
    Lnode* rear;
}Linkqueue;

List L;
Linkqueue Q;

//初始化数据 银行业务窗口
void Initshuzu()
{
    int i;
    for (i = 1; i <= n; i++)
        L.A[i] = 0;//元素值为0，表示编号为1的窗口当下状态为空
    L.len = 0;
}

//输出数组 银行业务窗口界面
void print1()
{
    //输出办理业务的顾客数组
    int i;
    printf("  正在办理业务的顾客编号为:  一号柜台          二号柜台          三号柜台\n");
    printf("                             ");
    for (i = 1; i <= L.len&&i<=3; i++)
    {
        if (L.A[i] == 0){
            printf("                  ");
            L.len++;
        }
        else
            printf("%d号顾客           ", L.A[i]);
    }
    printf("\n");
}

//输出排队等候队列界面
void print2()
{//输出办理业务排队顾客序列
    int i = 0;
    printf("   正在等候办理业务的顾客编号为：");
    Lnode* s = Q.front->next;//指向等候队列q
    while (s != NULL)
    {
        printf("%d ", s->data);//输出结点s的顾客编号
        s = s->next; i++;
    }
    printf("\n  您的前面一共有%d人在排队，请您稍后！", i);printf("\n");
}


//判断输入的柜台号是否正确
int guitai()
{
    int y = 0;
    scanf("%d", &y);
    if (y < 1 || y > 3)//判断不正确的柜台号
    {
        printf("   您输入的柜台号有误,请重新输入!\n");
        printf("   请输入您所办理业务的柜台号(1-3): ");scanf("%d", &y);
    }
    else
        printf("   您所办理业务的柜台号为%d.\n", y);
    return y;
}

//判断输入的评价分数是否正确
int pingfeng()
{
    int y = 0;
    printf(" 请输入您的评分(1-5) : \n 1分……非常不满意;\n 2分……不满意;\n 3分……一般;\n 4分……满意;\n 5分……非常满意.\n");
    printf("请输入: ");
    scanf("%d", &y);
    if (y < 1 || y>5)//判断输入的分数
    {
        printf(" 您输入的评分有误，请重新输入！\n");
        printf(" 请输入您的评分:(1-5):");
        scanf("%d", &y);
    }
    else
        printf("  您的评分为%d.\n", y);
    return y;
}

//主评分函数
void mygrade(int x)
{
    printf(" 为了改善服务质量，请您对我们的服务进行评价。谢谢!\n");
    y = pingfeng();
    switch (x)
    {
        case 1:sum1 += y; i1++;//1号柜台进行评分处理
            ave1 = sum1 / i1;
            printf(" %d号柜台的平均满意度为%0.2f。感谢您的评分，谢谢!\n", x, ave1);
            break;
        case 2:sum2 += y; i2++;//2号柜台进行评分处理
            ave2 = sum2 / i2;
            printf(" %d号柜台的平均满意度为%0.2f。感谢您的评分，谢谢!\n", x, ave2);
            break;
        case 3:sum3 += y; i3++;//3号柜台进行评分处理
            ave3 = sum3 / i3;
            printf(" %d号柜台的平均满意度为%0.2f。感谢您的评分，谢谢!\n", x, ave3);
            break;
        default: printf(" 您的输入有误，请重新输入！\n");
    }
    _getch();
}

//VIP用户认证
void vip(int x)
{
    int i, a = x, k = 0;
    char ch[5];
    switch (a)
    {
        case 1:
        {
            printf("   请输入您的卡号: ");  scanf("%d", &i);
            printf("   请输入您的5位密码：");
            while (ch[k - 1] != ' ')//回车为结束符
            {
                ch[k] = _getch(); k++;
                printf("*");
            }
            //符合VIP的具体账户和密码
            if (i == 100 && ch[0] == '1' && ch[1] == '1' && ch[2] == '1' && ch[3] == '1')
            {
                printf("\n 尊敬的VIP顾客您好，请你直接到VIP区办理业务!\n");
                vip1++;
            }
            else if (i == 200 && ch[0] == '2' && ch[1] == '2' && ch[2] == '2' && ch[3] == '2')
            {
                printf("\n 尊敬的VIP顾客您好，请你直接到VIP区办理业务!\n");
                vip1++;
            }
            else if (i == 300 && ch[0] == '3' && ch[1] == '3' && ch[2] == '3' && ch[3] == '3')
            {
                printf("\n 尊敬的VIP顾客您好，请你直接到VIP区办理业务!\n");
                vip1++;
            }
            else if (i == 400 && ch[0] == '4' && ch[1] == '4' && ch[2] == '4' && ch[3] == '4')
            {
                printf("\n 尊敬的VIP顾客您好，请你直接到VIP区办理业务!\n");
                vip1++;
            }
            else if (i == 500 && ch[0] == '5' && ch[1] == '5' && ch[2] == '5' && ch[3] == '5')
            {
                printf("\n 尊敬的VIP顾客您好，请你直接到VIP区办理业务!\n");
                vip1++;
            }
            else printf("\n 您的输入有误 \n");
            break;
        }//结束case1
        default:break;
    }//结束switch
}//结束vip

//时间函数
void mytime()
{
    time_t timep;
    time(&timep);
    printf("               现在时刻：%s", ctime(&timep));
}

//进队列
void Enqueue(Linkqueue* Q, int elem)
{//elem进等待顾客队列
    Lnode* s;
    s = (Lnode*)malloc(sizeof(Lnode));
    s->data = elem;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}
//顾客到达事件算法
void daoda(int x)
{
    int i = L.len + 1;
    int a1=0, addr=0;
    for (int ax = 1; ax <= n; ax++)
    {
        if (L.A[ax] != 0)//判断是否有0位填充
            a1++;
        else
            addr = ax;//确认零位填充的位置
    }
    if (L.len < n)//如果数组L长度小于柜台数
    {//将到达顾客的编号存入数组
        L.A[i] = x;
        i++; L.len++;
    }
    else if(a1<=n-1){//判断是否有0位填充
        L.A[addr] = x;
    }
    else Enqueue(&Q, x);//顾客进入等待序列
}
//出队列
int Dlqueue(Linkqueue* Q)
{
    Lnode* t;
    int x;
    if (Q->front == Q->rear)
    {
        printf("队列为空!\n");
        exit(1);
    }
    else
    {
        //等待顾客t出队列
        if (Q->front->next == NULL) {
            x = 0;
        }
        else {
            t = Q->front->next;
            Q->front->next = t->next;
            x = t->data;
            free(t);
        }

        return x;
    }
}
//顾客离开事件算法
void likai(int x)
{
    int i = 0, j = 1;
    int y;
    do
    {
        if (x > L.len)
        {
            printf(" 输入有误！\n 请重新输入：");
            scanf("%d", &x);
            j++;
        }
        else for (i = 0; i <= L.len; i++)
            {
                if (i == x)
                {
                	if(L.A[x]!=0){
                    	printf("  尊敬的%d号顾客您好！\n", L.A[x]);
                    	L.A[i] = 0;
                   	 	L.len--;
                    	if (Q.front != Q.rear)
                    	{
                       	 y = Dlqueue(&Q);//x出队等待
                       	 L.A[i] = y;
                      	  L.len++;
                    	}
					}
                    else{
                    	printf(" 输入有误！\n 请重新输入：");
          			    scanf("%d", &x);
            			j++;
					}
                }
            }
    } while (i == 0 && j < 3);
    if (j == 3)
    {
        printf("再见！欢迎下次光临！");
        exit(1);
    }
}
//初始化队列
void  Initqueue()
{
    Q.front = Q.rear = (Lnode*)malloc(sizeof(Lnode));
    Q.front->next = NULL;
}

//主函数，设定界面颜色，调用工作区模块函数
int main()
{
    system("color 1f");//屏幕颜色设定
    system("mode con:cols=90 lines=35");
    time_t a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, start, end;
    double b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0, b10 = 0, allsum = 0, average = 0, xi = 0;
    double A[10] = { 0,0,0,0,0,0,0,0,0,0 };
    int c, x, v = 0, w = 0;//v为办理顾客的计数，w为已办理业务的顾客计数
    Initshuzu();
    Initqueue();
    double sum = 0;
    while (1)
    {
        printf("\n**********欢迎光临**********\n");
        printf("\n                           \n");
        printf("         1  顾客到达\n");
        printf("         2  顾客离开\n");
        printf("         3  查看业务办理\n");
        printf("         4  查看排队情况\n");
        printf("         5  系统查询\n");
        printf("         6  退出\n\n");
        mytime();
        printf("\n 提示：请按回车进行下一步操作\n");
        printf("\n                           \n");
        printf("*****************************\n");
        printf("请输入：");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
            {
                system("cls");
                printf("\n************顾客到达界面************\n\n");
                int k = 0, a;
                printf("请选择你的顾客类型:VIP顾客请按1;普通顾客请按2.\n");
                printf("请输入:");
                scanf("%d", &a);
                if (a == 1)
                {
                    //调用VIP函数
                    vip(a); _getch();
                }
                else
                {
                    v++;
                    printf("  尊敬的普通顾客，您的业务号为%d.\n", v);
                    daoda(v);//调用到达函数
                    if (v == 1)
                    {
                        a1 = time(NULL);//顾客编号为1的到达时间
                        mytime();//显示v=1的到达时间
                        system("pause");
                    }
                    else if (v == 2)
                    {
                        a2 = time(NULL);//顾客编号为2的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 3)
                    {
                        a3 = time(NULL);//顾客编号为3的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 4)
                    {
                        a4 = time(NULL);//顾客编号为4的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 5)
                    {
                        a5 = time(NULL);//顾客编号为5的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 6)
                    {
                        a6 = time(NULL);//顾客编号为6的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 7)
                    {
                        a7 = time(NULL);//顾客编号为7的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 8)
                    {
                        a8 = time(NULL);//顾客编号为8的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 9)
                    {
                        a9 = time(NULL);//顾客编号为9的到达时间
                        mytime();
                        system("pause");
                    }
                    else if (v == 10)
                    {
                        a10 = time(NULL);//顾客编号为10的到达时间
                        mytime();
                        system("pause");
                    }
                    else
                    {
                        printf(" 请稍后拿号，谢谢！");//超过10个顾客，请稍后
                        system("pause");
                    }
                }
                system("cls");
                break;
            }//endcase1

            case 2:
            {
                system("cls");
                printf("\n************顾客离开界面************\n\n");
                printf(" 请输入离开顾客的柜台编号：");
                x=guitai();
                likai(x);//调用离开函数
                mygrade(x);//调用评价函数
                w++;
                if (x == 1)
                {
                    end = time(NULL); A[0] = difftime(end, a1);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[0]);
                }
                else if (x == 2)
                {
                    end = time(NULL); A[1] = difftime(end, a2);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[1]);
                }
                else if (x == 3)
                {
                    end = time(NULL); A[2] = difftime(end, a3);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[2]);
                }
                else if (x == 4)
                {
                    end = time(NULL); A[3] = difftime(end, a4);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[3]);
                }
                else if (x == 5)
                {
                    end = time(NULL); A[4] = difftime(end, a5);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[4]);
                }
                else if (x == 6)
                {
                    end = time(NULL); A[5] = difftime(end, a6);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[5]);
                }
                else if (x == 7)
                {
                    end = time(NULL); A[6] = difftime(end, a7);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[6]);
                }
                else if (x == 8)
                {
                    end = time(NULL); A[7] = difftime(end, a8);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[7]);
                }
                else if (x == 9)
                {
                    end = time(NULL); A[8] = difftime(end, a9);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[8]);
                }
                else if (x == 10)
                {
                    end = time(NULL); A[9] = difftime(end, a10);
                    printf(" 您办理业务所用时间为%0.2f 秒.\n", A[9]);
                }
                allsum += A[0];
                _getch(); system("cls");
                break;
            }//case 2

            case 3:
            {
                system("cls");
                printf("\n************业务查询界面************\n\n");
                print1();//调用银行窗口业务查询输出函数
                _getch();
                system("cls");
                break;
            }
            case 4:
            {
                system("cls");
                printf("\n************排队查询界面************\n\n");
                print2();//调用银行窗口业务查询输出函数
                _getch();
                system("cls");
                break;
            }
            case 5:
            {system("cls");
                printf("\n************系统查询界面************\n\n");
                char cool[5];
                int i = 0, k = 0;
                printf("请输入您的卡号："); scanf("%d", &i);
                printf("请输入您的5位密码：");
                while (cool[k - 1] != ' ')
                {
                    cool[k] = _getch(); k++; printf("*");
                }
                if (i == 000 && cool[0] == '1' && cool[1] == '1' && cool[2] == '1' && cool[3] == '1')
                {
                    average = allsum / w;
                    printf("\n 至今已由 %d 位普通顾客，%d 位VIP顾客成功办理业务！", w, vip1);
                    printf("\n 普通顾客业务办理总用时 %0.2f秒，平均用时%0.2f秒\n", allsum, average);
                }
                _getch(); system("cls");
                break;
            }
                return 0;
                _getch(); system("cls");
            case 6:
                return 0;
                _getch(); system("cls");
            default:printf(" 输入有误！请重新输入：\n"); _getch();
                system("cls");
        }

    }
}