#include "Options.h"
#include "Components.h"

int areadFile()
{
    int amount = 0;

    FILE *fp;
    if ((fp = fopen("data.txt", "ab+")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        return 0;
    }

    while (!feof(fp))
    {
        if (fread(&stu[amount], LEN, 1, fp) == 1)
        {
            amount++;
        }
    }

    fclose(fp);

    return amount;
}

void awriteFile(int amount)
{
    FILE *fp;
    if ((fp = fopen("data.txt", "wb+")) == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        return;
    }

    for (int i = 0; i < amount; i++)
    {
        if (fwrite(&stu[i], LEN, 1, fp) != 1)
        {
            printf("���������¼�޷����棻");
            getch();
        }
    }
    
    fclose(fp);
}

void inputIn(int i)
{
    printf("name:");
    scanf("%s", stu[i].name);

    printf("elective:");
    scanf("%lf", &stu[i].elec);

    printf("experiment:");
    scanf("%lf", &stu[i].expe);

    printf("required course:");
    scanf("%lf", &stu[i].requ);

    stu[i].sum = stu[i].elec + stu[i].expe + stu[i].requ;
}
