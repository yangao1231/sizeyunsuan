
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <windef.h>
#include <math.h>
#include<fstream>
#include<iomanip>
using namespace std;
 
 
double nums[100];
char str[100];
int n, Max, flag, q = 1;
int decimal,         ///�Ƿ�����С��
    brackets,        ///�Ƿ���������
    fst,              ///�Ƿ�д���ļ�
    pos = 0,         ///posΪ + - * /��λ��
    pos1 = -1,        ///pos1,pos2Ϊ����λ��
    pos2 = -1;
ofstream ofile;
 
 void randomNumber()                                   /***********nums�������������н����ֵ�����*************************/
 {
    flag = rand() % 3 + 2;
    for(int i = 0; i < flag; i++)
    {
        if(decimal)
        {
            nums[i] = (rand() % Max) + (rand() % 100 *0.01);
        }
        else
        {
            nums[i] = (rand() % Max) + 1;
        }
    }
 }
 
 void randomBrackets()                               /**********������ŵ�λ��****************************************/
 {
     pos1 = -1;
     pos2 = -1;
     if(brackets)
     {
       while(1)
       {
         pos1 = rand() % flag;
         pos2 = rand() % flag;
         if(abs(pos1-pos2))
         {
            pos1 = min(pos1, pos2);
            pos2 = max(pos1, pos2);
            break;
         }
       }
       if(flag == 2)
       {
            pos1 = -1;
            pos2 = -1;
       }
    }
 }
 
 void priduction()                                  /************�����ʽ***********************************/
 {
    for(int i = 0; i < flag; i++)
    {
        int k = rand()% pos;                  ///str[i]Ϊ����ķ���
        if(i == pos1 && pos1!=pos2)
        {
            cout<< "("<<" ";
            fst && ofile<<"("<<" ";
        }
        cout << nums[i] << " ";
        fst && ofile<<nums[i]<<" ";
        if(i == pos2 && pos1!=pos2)
        {
            cout<< ")" <<" ";
            fst && ofile<<")"<<" ";
        }
        if(i != flag-1)
        {
            cout<< str[k] << " ";
            fst && ofile<<str[k]<<" ";
        }
    }
 
 }
 
 
 
int main(){
    ofile.open("G:\lwt.txt" );
    cout << "��������Ŀ�����Լ���Ŀ�г��ֵ������:" << endl;
    cin >> n >> Max;
    cout << "��������Ҫ���������+-*/��"<<endl;
    getchar();
    gets(str);
    cout << "�Ƿ���ҪС������1/0��";
    cin  >> decimal;
    cout << "�Ƿ���Ҫ���ţ���1/0��";
    cin >> brackets;
    cout <<"�Ƿ�д���ļ�����1/0��";
    cin >> fst;
 
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
           str[pos++] = str[i];                       ///str �����������н����ֵķ���
        }
    }
 
    while(n--)
    {
        randomNumber();
        randomBrackets();
        fst && ofile<<"(" << q << ")"<< "  ";
        cout << "(" << q++ << ")"<< "  ";
        priduction();
        cout<< endl;
        fst && ofile<<endl;
 
    }
    ofile.close();
    return 0;
}