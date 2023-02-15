
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <dos.h>

#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num, stu[i].name, stu[i].elec, stu[i].expe, stu[i].requ, stu[i].sum

#ifndef __MAIN_H__
#define __MAIN_H__

struct student
{
    int num;
    char name[15];
    double elec;
    double expe;
    double requ;
    double sum;
};

extern struct student stu[50];

#endif

void insert(); // input student information
void show(); // output student information

int search(); // search student information
void del(); // delete student information
void modify(); // modify student information
void order(); // sort by total score
