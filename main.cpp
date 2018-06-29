//
//  main.cpp
//  poject2
//
//  Created by 20161104571 on 18/6/29.
//  Copyright © 2018年 20161104571. All rights reserved.
//

# include<iostream>
# include<iomanip>
# define N  20   //评委的人数最多为20
# define M  50   //参赛选手的人数最多为50
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

float CountAthleteScore(int , float ave, int n, float s[], int m);
void Sort(float a[], int n);
void Print(float a[], int n,int bh[]);
float b[M];
int bh[M];

int main()
{
    /*ifstream fin("/Users/timeless/Desktop/选手信息表.csv表.csv"); //打开文件流操作
    string line;
    while(getline(fin, line)) //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        cout <<"原始字符串："<< line << endl; //整行输出
        istringstream sin(line);//将整行字符串line读入到字符串流istringstream中
        vector<string> fields;//声明一个字符串向量
        string field;
        while (getline(sin, field, ','))//将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        }
        string name = Trim(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
         string age= Trim(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量age
         string birthday = Trim(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量birthday
         cout<<"处理之后的字符串："<<name<<"\t"<<age << "\t" << birthday << endl;
    }
    return EXIT_SUCCESS;*/
    
    
    int i=0;
    int n,m,r;
    
    float s[N],a[M],ave=0.0;
    cout<<"******欢迎使用评分系统******"<<endl;
    cout<<"   请输入评委个数（>=3)：";
    cin>>n;
    cout<<"   请输入参赛选手个数(>=2)：";
    cin>>m;
    cout<<endl;
    
    
    for(i=0;i<m;i++)
    {cout<<"       选手参赛中     "<<endl;
        cout<<"       编号为：";
        cin>>bh[i];
        a[r++]=CountAthleteScore(bh[i], ave, n,s, m);
    }
    
    
    
    cout<<m<<"这位选手的平均成绩分别是："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    Sort(a, m);
    Print( a, n,bh);
    return 0;
    
}


float CountAthleteScore(int , float ave, int n, float s[], int m)
{
    int j,k;
    static int w=0;
    float t,sum=0.0;
    ave=0.0;
    
    cout<<"请输入该选手的成绩："<<endl;
    for(k=0;k<n;k++)//不加花括号会出现错误
    {
        cout<<endl;
        cout<<"输入第"<<k+1<<"位评委给分: ";
        cin>>s[k];
        if((s[k]>10)||(s[k]<0))
        {
            cout<<"第"<<k+1<<"位评委输入时出现错误,请重新输入"<<endl;
            k--;
        }
    }
    
    
    
    for(k=0;k<n-1;k++)     //对每位选手的成绩排序，以便去掉最低分和最高分;
    {
        for(j=k+1;j<n;j++)
            if(s[k]<s[j])
            {
                t=s[k];
                s[k]=s[j];
                s[j]=t;
            }
    }
    cout<<"对评委给分由高到低进行排序："<<endl;
    for(k=0;k<n;k++)
        cout<<s[k]<<"  ";
    cout<<endl;
    cout<<"去掉一个最高分"<<s[0]<<",一个最低分"<<s[n-1]<<",后的结果："<<endl;
    for(k=0;k<n-2;k++)
        
    {
        cout<<s[k+1]<<"  ";
        sum=sum+s[k+1];
    }
    cout<<endl;
    ave= sum/float(n-2);
    b[w++]=ave;
    cout<<"该选手平均分="<<ave<<endl;
    return ave;
    cout<<"*************************"<<endl;
    
}
void Sort(float a[],  int m)
{
    
    int j;
    int r;
    float t;
    for(r=0;r<m-1;r++)     //对平均成绩进行排序;
    {
        for(j=0;j<m-1-r;j++)
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    }
    cout<<"由高到低排序后的成绩为："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    cout<<"************************"<<endl;
    cout<<"************************"<<endl;
}


void Print(float a[], int m,int bh[])
{
    int i;
    if((a[0]!=a[1])&&a[1]!=a[2])
        
    {
        if(m>2){
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军:   ";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[0]<<endl;
            cout<<"亚军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[1]<<endl;
            cout<<"季军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[2]<<endl;
        }
        else{
            
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[0]<<endl;
            cout<<"亚军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[1]<<endl;
        }
    }
    
    else if((a[0]==a[1])&&(a[1]!=a[2]))
    {
        cout<<"**两位选手并列第一"<<endl;
        if(m>2)
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"  ";
            }
            cout<<"成绩为："<<a[1]<<endl;
            cout<<"亚军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<bh[i];
            cout<<"成绩为："<<a[2]<<endl;
            
        }
        else
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<bh[i];cout<<"   ";
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]!=a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第二"<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<"冠军   编号为："<<bh[i];
            cout<<"成绩为："<<a[0]<<endl;
            
            cout<<"亚军   编号为：";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<bh[i]<<"   ";
            }
            
            cout<<"成绩为："<<a[2]<<endl;
        }
        else
        {
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<"冠军   编号为："<<bh[i]<<"   ";}
            cout<<"成绩为："<<a[0]<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<"亚军   编号为："<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]==a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[0]<<endl;
            
        }
        else
        {
            cout<<"**两位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            
        }
    }
}
using namespace std;
//删除字符串中空格，制表符tab等无效字符
string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

