#include "Options.h"
#include "Components.h"

struct student stu[50];

void menu()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("|-------------学生信息管理系统-------------|\n");
    printf("\t 1. insert \n");
    printf("\t 2. show \n");
    printf("\t 3. search \n");
    printf("\t 4. delete \n");
    printf("\t 5. modify \n");
    printf("\t 6. order \n");
    printf("\t 0. exit \n");
    printf("|-------------学生信息管理系统-------------|\n");
    printf("请选择（0-6）：");
}

void main()
{
    system("color f0\n");
    int n;
    menu();
    scanf("%d", &n);
    while (n)
    {
        switch (n)
        {
            case 1:
                insert();
                break;
            case 2:
                show();
                break;

            case 3:
                search();
                break;
            case 4:
                del();
                break;
            case 5:
                modify();
                break;
            case 6:
                order();
                break;
        }
        getch();
        menu();
        scanf("%d", &n);
    }
}
