#include "Options.h"
#include "Components.h"

void insert()
{
    int m = areadFile();

    char ch[2];
    printf("����ѧ����Ϣ��y��n����");
    scanf("%s", ch);

    while (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
    {
        printf("number:");
        scanf("%d", &stu[m].num);

        for (int i = 0; i < m; i++)
        {
            if (stu[i].num == stu[m].num)
            {
                printf("ѧ���Ѵ��ڣ��������������\n");
                getch();
                return;
            }
        }

        inputIn(m);
        m++;

        awriteFile(m);

        printf("%s ����Ϣ�ѱ����棻", stu[m - 1].name);

        printf("�Ƿ��������y��n)��");
        scanf("%s", ch);
        printf("OK��\n");
    }
}

void show()
{
    int m = areadFile();

    printf("�ļ��й���%d����¼��\n", m);

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
    printf("������ѧ�ţ�");
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
    printf("δ�ҵ���ѧ���ļ�¼��\n");

    return -1;
}

void del()
{
    int m = areadFile();
    int i = search();

    if (i >= 0)
    {
        char ch[2];
        printf("���ҵ���ѧ���ļ�¼���Ƿ�ɾ������y��n����");
        scanf("%s", ch);

        if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
        {
            for (int j = i; j < m; j++)
            {
                stu[j] = stu[j + 1];
            }
            m--;

            awriteFile(m);

            printf("ɾ���ɹ���\n");
        }
        else
        {
            printf("�ѷ���ɾ����\n");
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
        printf("���ҵ���ѧ���ļ�¼���Ƿ��޸ģ���y��n����");
        scanf("%s", ch);

        if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)
        {
            inputIn(i);

            awriteFile(m);

            printf("�޸ĳɹ���\n");
        }
        else
        {
            printf("�ѷ����޸ģ�\n");
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
            if (stu[i].sum < stu[j].sum) // �Ժ������quicksort���������㷨���иĽ�
            {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }
    }

    awriteFile(m);

    printf("����ɹ���\n");
}
