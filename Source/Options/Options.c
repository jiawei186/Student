#include "Options.h"
#include "Components.h"

void insert()
{
    int m = areadFile();

    char ch[2];
    printf("输入学生信息（y或n）：");
    scanf("%s", ch);

    while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        printf("number:");
        scanf("%d", &stu[m].num);

        for (int i = 0; i < m; i++)
        {
            if (stu[i].num == stu[m].num)
            {
                printf("学号已存在；按任意键继续：\n");
                getch();
                return;
            }
        }

        inputIn(m);
        m++;

        awriteFile(m);

        printf("%s 的信息已被保存；", stu[m - 1].name);

        printf("是否继续？（y或n)：");
        scanf("%s", ch);
        printf("OK；\n");
    }
}

void show()
{
    int m = areadFile();

    printf("文件中共有%d条记录；\n", m);

    printf("number    name    elective    experiement    required    sum\n");
    
    for (int i = 0; i < m; i++)
    {
        printf(FORMAT, DATA);
    }
}

int search()
{
    int m = areadFile();

    int snum;
    printf("请输入学号：");
    scanf("%d", &snum);

    for (int i = 0; i < m; i++)
    {
        if (snum == stu[i].num)
        {
            printf("number    name    elective    experiment    required    sum\n");
            printf(FORMAT, DATA);
            return i;
        }
    }
    printf("未找到该学生的记录；\n");

    return -1;
}

void del()
{
    int m = areadFile();
    int i = search();

    if (i >= 0)
    {
        char ch[2];
        printf("已找到该学生的记录，是否删除？（y或n）：");
        scanf("%s", ch);

        if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
        {
            for (int j = i; j < m; j++)
            {
                stu[j] = stu[j + 1];
            }
            m--;

            awriteFile(m);

            printf("删除成功；\n");
        }
        else
        {
            printf("已放弃删除；\n");
        }

        return;
    }
}

void modify()
{

    int m = areadFile();
    int i = search();

    if (i >= 0)
    {
        char ch[2];
        printf("已找到该学生的记录，是否修改？（y或n）：");
        scanf("%s", ch);

        if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
        {
            inputIn(i);

            awriteFile(m);

            printf("修改成功；\n");
        }
        else
        {
            printf("已放弃修改；\n");
        }

        return;
    }
}

void order()
{
    struct student t;

    int m = areadFile();

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (stu[i].sum < stu[j].sum) // 以后可以用quicksort来对排序算法进行改进
            {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }
    }

    awriteFile(m);

    printf("保存成功；\n");
}
