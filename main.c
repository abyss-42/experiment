#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int id;
    char name[30];
    int score[6];

}STU;

int Input(int * a , STU stu[]);
void Output(STU stu[] , int num  , int numofexam , double a[] , double b[]);
void Sum_avgofstu(STU stu[] ,int num ,int numofexam, double a[] , double b[]);
void Sum_avgofsub(STU stu[] ,int num ,int numofexam );
void Printlist(STU stu[] , int (*compare)(int a , int b) , int num ,int numofexam , double a[] , double b[]);
void Dict(STU stu[],int (*compare)(int a , int b) , int num);
void Search_by_id(STU stu[] , int num ,int numofexam , double a[] ,double b[]);
void Search_by_name(STU stu[] , int num ,int numofexam , double a[] , double b[]);
void Analysis(STU stu[] , int num , int numofexam);
int Descending(int a , int b);
int Ascending(int a , int b);
void Print_by_name(STU stu[] , int num ,int numofexam , double a[] , double b[]);
void Sort(STU stu[] , int num, int numofexam , double a[] , double b[]);
void Printlist2(STU stu[], int (*compare)(int a , int b ) , int num , double a[] , double b[] , int numofexam);

int main()
{

    printf("Number : 200111419\n");
    printf("Name:李泽诚 \n");
    printf("Subject No.8- program No.1\n");

    STU stu[30];

    double sum[30] , avg[30];
    int choice , numofstu , numofexam;
    int flag = 0;

    printf("1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in ascending order by total score of every student\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10.Statistic analysis for every course\n");
    printf("11.List record\n");
    printf("0. Exit\n");
    printf("Please enter your choice:\n");
    scanf("%d" , &choice);

    do{
         if(choice == 1){
            numofstu = Input(&numofexam , stu);
            flag = 1;
            printf("\n");
        }
         if(choice == 2){
            if(!flag) printf("please input record first");
            else{
                Sum_avgofsub(stu , numofstu ,numofexam);
                printf("\n");
            }
        }
         if(choice == 3){
            if(!flag) printf("please input record first");
            else{
                Sum_avgofstu(stu , numofstu , numofexam , sum ,avg);
                printf("\n");
            }
        }
         if(choice == 4){
            if(!flag) printf("please input record first");
            else{
                Printlist(stu , Descending , numofstu , numofexam , sum , avg);
                printf("\n");
            }
        }
         if(choice == 5){
            if(!flag) printf("please input record first");
            else{
                Printlist(stu , Ascending , numofstu , numofexam , sum , avg);
                printf("\n");
            }
        }
         if(choice == 6){
            if(!flag) printf("please input record first");
            else{
                Printlist2(stu , Ascending , numofstu , sum , avg , numofexam);
                printf("\n");
            }
        }
         if(choice == 7){
           if(!flag) printf("please input record first");
            else{
                Print_by_name(stu , numofstu , numofexam , sum , avg);
                printf("\n");
            }
        }
         if(choice == 8){
           if(!flag) printf("please input record first");
            else{
                Search_by_id(stu , numofstu , numofexam , sum ,avg);
                printf("\n");
            }
        }
         if(choice == 9){
            if(!flag) printf("please input record first");
            else
               Search_by_name(stu , numofstu , numofexam , sum , avg);
               printf("\n");
            }

         if(choice == 10){
            if(!flag) printf("please input record first");
            else{
                Analysis(stu, numofstu , numofexam);
                printf("\n");
            }
        }
         if(choice == 11){
            if(!flag) printf("please input record first");
            else{
                Output(stu, numofstu ,numofexam , sum ,avg );
                printf("\n");
            }
        }
         if(choice == 0){
            break;
        }

    }while( scanf("%d" , &choice));
}
/*函数名：Input， 输入：stu[]学生姓名学号成绩信息，*a考试门数，输出：num人数，功能描述：录入每个学生的学号、姓名和考试成绩*/
int Input( int * a , STU stu[]){
    int num,ret1,ret2;
    int numofexam;
    printf("Input number of students\n");
    ret1 = scanf("%d" , &num );
    printf("Input number of exams\n");
    ret2 = scanf("%d" , &numofexam );
    if(ret1 && ret2){
        printf("Input name,student ID and score\n");
        for (int i=0 ; i < num ; i++){
            scanf("%s" , stu[i].name);
            scanf("%d", &stu[i].id);
            for (int j = 0 ; j < numofexam ; j++){
                scanf("%d", &stu[i].score[j]);
            }

        }
        * a = numofexam;
        printf("Input finished\n");
        return num;
    }
    else {
            printf("Input error,please input anain\n");
             return 0;
    }

}
/*函数名：Sum_avgofsub， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam考试门数，输出：无，功能描述：计算课程的总分和平均分*/
void Sum_avgofsub( STU stu[] , int num ,int numofexam){
    double sum , avg;
    for(int i = 0 ; i < numofexam ; i++){
        for (int j =  0 ; j < num ; j++){
            sum += (double)stu[j].score[i];
        }
        avg = sum/(double)num;
        printf("subject%d\t" , i + 1);
        printf("sum = %lf\t" , sum);
        printf("avg = %lf\n" , avg);
        sum = avg = 0;
    }

}
/*函数名：Sum_avgofstu， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam考试门数，输出：无，功能描述：计算各学生的总分和平均分*/
void Sum_avgofstu(STU stu[] , int num ,int numofexam , double a[] , double b[]){
    double sum = 0 , avg;
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < numofexam ; j++){
            sum += (double)stu[i].score[j];
        }
        avg = sum/(double)numofexam;
        a[i] = sum;
        b[i] = avg;
        printf("%d\t" , stu[i].id);
        printf("sum = %lf\t" , sum);
        printf("avg = %lf\n" , avg);
        sum = avg = 0;
    }
}
/*函数名：Printlist， 输入：stu[]学生姓名学号成绩信息，compare排序函数，num人数，输出：无，功能描述：按成绩输出名次表*/
void Printlist(STU stu[] , int (*compare)(int x , int y ) , int num ,int numofexam , double a[] , double b[]){
    int temp;
    char tem[30];

    double sum = 0;
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < numofexam ; j++){
            sum += (double)stu[i].score[j];
        }
        a[i] = sum;
        sum = 0;
    }

    for(int i = 0 ; i < num - 1 ; i++){
        for(int j = 0 ; j < num - 1 ; j++){
            if(compare(a[j] , a[j+1])){

                for(int k = 0 ; k < numofexam ; k++){
                    temp =  stu[j].score[k];
                    stu[j].score[k] = stu[j + 1].score[k];
                    stu[j + 1].score[k] = temp;
                }
                temp = stu[j].id;
                stu[j].id = stu[j + 1].id;
                stu[j + 1].id = temp;
                strcpy(tem , stu[j].name);
                strcpy(stu[j].name, stu[j + 1].name);
                strcpy(stu[j + 1].name, tem);
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    for(int i = 0 ; i < num ; i++){
        printf("%d\t%s\n" , stu[i].id , stu[i].name);
    }
}
/*函数名：Search_by_id， 输入：stu[]学生姓名学号成绩信息，num人数，输出：无，功能描述：按学号查询学生排名及其考试成绩*/
void Search_by_id(STU stu[] , int num , int numofexam , double a[] , double b[]){
    int ID;
    int aa = 1;
    printf("input ID\n");
    scanf ("%d" , &ID);
    Sort(stu, num ,numofexam , a , b);
    for(int i = 0 ; i < num ; i++){
        if(ID == stu[i].id){
                printf("%d\t" ,i + 1 );
                for (int j = 0 ; j < numofexam ; j++){
                    printf("%d\t" ,stu[i].score[j]);
                }
            }
            aa = 0;
        }
    if(aa)printf("Can't find this student\n");
}
/*函数名：Ascending， 输入：两个数a，b，输出：a>b，功能描述：按由低到高排序*/
int Ascending(int a , int b){
    return a > b;
}

/*函数名：Descending， 输入：两个数a，b，输出：a<b，功能描述：按由高到低排序*/
int Descending(int a , int b){
    return a < b;
}
/*函数名：Search_by_name， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam课程门数，a[]总分，输出：无，功能描述：按姓名查询学生排名及其考试成绩*/
void Search_by_name(STU stu[] , int num , int numofexam , double a[] , double b[]){
    int aa = 1;
    char n[30];
    printf("Please input the name\n");
    scanf("%s" , n);
    Sort(stu, num ,numofexam , a , b);
    for(int i = 0 ; i < num ; i++){
        if(! strcmp(n , stu[i].name)){
                printf("%d\t" ,i + 1 );
                for (int j = 0 ; j < numofexam ; j++){
                    printf("%d\t" ,stu[i].score[j]);
                }
            }
            aa = 0;
        }
    if(aa)printf("Can't find this student\n");
}
/*函数名：Print_by_name， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam课程门数，a[]总分，b[]平均分，输出：无，功能描述：按姓名顺序打印成绩表*/
void Print_by_name(STU stu[], int num , int numofexam , double a[] , double b[]){
    char tem[30];
    int temp;
    for(int i = 0 ; i < num - 1 ; i++){
        for(int j = 0 ; j < num - 1 ; j++){
            if(strcmp(stu[j].name, stu[j + 1].name) > 0){
                for(int k = 0 ; k < numofexam ; k++){
                    temp =  stu[j].score[k];
                    stu[j].score[k] = stu[j + 1].score[k];
                    stu[j + 1].score[k] = temp;
                }
                temp = stu[j].id;
                stu[j].id = stu[j + 1].id;
                stu[j + 1].id = temp;
                strcpy(tem , stu[j].name);
                strcpy(stu[j].name, stu[j + 1].name);
                strcpy(stu[j + 1].name, tem);
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    for(int i = 0 ; i < num ; i++){
        printf("%d\t%s\n" , stu[i].id , stu[i].name);
        for (int j = 0 ; j < numofexam ; j++){
            printf("%d\t" ,stu[i].score[j]);
        }
        printf("%lf\t%lf\n" , a[i] , b[i]);
    }
}
/*函数名：Printlist2， 输入：stu[]学生姓名学号成绩信息，compare排序函数，num人数，a[]总分，b[]平均分，numofexam课程门数，输出：无，功能描述：按学号顺序打印成绩表*/
void Printlist2(STU stu[], int (*compare)(int a , int b ) , int num , double a[] , double b[] , int numofexam){
    int temp;
    char tem[30];
    for(int i = 0 ; i < num - 1 ; i++){
        for(int j = 0 ; j < num - 1 ; j++){
            if(compare(stu[j].id , stu[j + 1].id)){
                 for(int k = 0 ; k < numofexam ; k++){
                    temp =  stu[j].score[k];
                    stu[j].score[k] = stu[j + 1].score[k];
                    stu[j + 1].score[k] = temp;
                }
                temp = stu[j].id;
                stu[j].id = stu[j + 1].id;
                stu[j + 1].id = temp;
                strcpy(tem , stu[j].name);
                strcpy(stu[j].name, stu[j + 1].name);
                strcpy(stu[j + 1].name, tem);
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
   for(int i = 0 ; i < num ; i++){
        printf("%d\t%s\n" , stu[i].id , stu[i].name);
        for (int j = 0 ; j < numofexam ; j++){
            printf("%d\t" ,stu[i].score[j]);
        }
        printf("%lf\t%lf\n" , a[i] , b[i]);
    }
}
/*函数名：Sort， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam课程门数，a[]总分，输出：无，功能描述：按由高到低排序*/
void Sort(STU stu[] , int num , int numofexam , double a[] , double b[]){
    int temp;
    char tem[30];
    for(int i = 0 ; i < num - 1 ; i++){
        for(int j = 0 ; j < num - 1 ; j++){
            if(a[j] < a[j+1]){

                for(int k = 0 ; k < numofexam ; k++){
                    temp =  stu[j].score[k];
                    stu[j].score[k] = stu[j + 1].score[k];
                    stu[j + 1].score[k] = temp;
                }
                temp = stu[j].id;
                stu[j].id = stu[j + 1].id;
                stu[j + 1].id = temp;
                strcpy(tem , stu[j].name);
                strcpy(stu[j].name, stu[j + 1].name);
                strcpy(stu[j + 1].name, tem);
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

            }
        }
    }

}
/*函数名：Analysis， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam课程门数，输出：无，功能描述：按优秀（90-100分）、良好（80-89分）、中等（70 - 79分）、及格（60—69分）、不及格(0-
59分)5个类别，统计每个类别的人数以及所占的百分比*/
void Analysis(STU stu[]  , int num , int numofexam){
    int a,b,c,d,e;
    a = b = c = d = e = 0;
    for(int j = 0 ; j < numofexam ; j++){
            for(int i = 0 ; i < num ; i++){
                if(stu[i].score[j] >= 90 && stu[i].score[j] <= 100)a++;
                if(stu[i].score[j] >= 80 && stu[i].score[j] <= 89)b++;
                if(stu[i].score[j] >= 70 && stu[i].score[j] <= 79)c++;
                if(stu[i].score[j] >= 60 && stu[i].score[j] <= 69)d++;
                if(stu[i].score[j] >= 0 && stu[i].score[j] <= 59)e++;
            }
            printf("subject:%d\n" , j + 1);
            printf("优秀人数：%d\t占比：%lf%%\n" , a ,(double)a*100/(double)num);
            printf("良好人数：%d\t占比：%lf%%\n" , b ,(double)b*100/(double)num);
            printf("中等人数：%d\t占比：%lf%%\n" , c ,(double)c*100/(double)num);
            printf("及格人数：%d\t占比：%lf%%\n" , d ,(double)d*100/(double)num);
            printf("不及格人数：%d\t占比：%lf%%\n" , e ,(double)e*100/(double)num);
    }

}
/*函数名：Output， 输入：stu[]学生姓名学号成绩信息，num人数，numofexam课程门数，a[]总分，b[]平均分，输出：无，功能描述：输出每个学生的学号、姓名、考试成绩*/
void Output(STU stu[], int num, int numofexam , double a[] , double b[]){
    for(int i = 0 ; i < num ; i++){
        printf("%d\t%s\n" , stu[i].id , stu[i].name);
        for (int j = 0 ; j < numofexam ; j++){
            printf("%d\t" ,stu[i].score[j]);
        }
        printf("%lf\t%lf\n" , a[i] , b[i]);
    }
}
