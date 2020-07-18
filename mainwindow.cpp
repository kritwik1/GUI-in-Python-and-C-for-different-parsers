#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <QDebug>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
void E();
void Ed();
void T();
void Td();
void F();
void match();
void first(char c,int jk);
void follow(char c);
void first(char c);
void push(int k);
void pushb(char k);
char TOS();
void pop();
void popb();
void error();
void reduce(int p);
char str[20];
char *pointer;
int a=-1,b=0,c=0,d=0,mo=0,kp=0,kpp=0,moo=0;
char fir[100],f[100];
std::vector<string>ro;
std::vector<string>pr;
std::set<char> gh;
int ii=0,jj=0;

using namespace std;
int axn[][6][2]={

        {{100,5},{-1,-1},{-1,-1},{100,4},{-1,-1},{-1,-1}},

        {{-1,-1},{100,6},{-1,-1},{-1,-1},{-1,-1},{102,102}},

        {{-1,-1},{101,2},{100,7},{-1,-1},{101,2},{101,2}},

        {{-1,-1},{101,4},{101,4},{-1,-1},{101,4},{101,4}},

        {{100,5},{-1,-1},{-1,-1},{100,4},{-1,-1},{-1,-1}},

        {{-1,-1},{101,6},{101,6},{-1,-1},{101,6},{101,6}},

        {{100,5},{-1,-1},{-1,-1},{100,4},{-1,-1},{-1,-1}},

        {{100,5},{-1,-1},{-1,-1},{100,4},{-1,-1},{-1,-1}},

        {{-1,-1},{100,6},{-1,-1},{-1,-1},{100,1},{-1,-1}},

        {{-1,-1},{101,1},{100,7},{-1,-1},{101,1},{101,1}},

        {{-1,-1},{101,3},{101,3},{-1,-1},{101,3},{101,3}},

        {{-1,-1},{101,5},{101,5},{-1,-1},{101,5},{101,5}}

        };
int gotot[12][3]={1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,2,3,-1,-1,-1,-1,9,3,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int aa[10];

char bb[10];

int top=-1,btop=-1,i;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{   int n=0,i=0,j=0,le=0,m=3,k=0,in=0,a=0;
    string s="";
    string p="";
    //vector<vector<string>> pro;
    vector<string> result;
    char l[100]={0};
    QString text = ui->textEdit->toPlainText();
    string str=text.toStdString();
    n=str.length();
    for(i=0;i<str.length();i++){
        if(str[i]=='\n'){
            result.push_back(str.substr(a,i));
             a=i+1;
        }

    }
    for(i=0;i<result.size();i++){
        if(result[i][0]==result[i][2]){
            printf("left recursion");
            for(j=i+1;j<result.size();j++){
                if(result[i][0]==result[j][0]){
                 le=result[i].length();
                //printf("%d\n",le);
                 in=0;
                 for(k=3;k<le;k++){
                    l[in]=result[i][k];
                   // printf("%c",f[in]);
                    in++;
                    //break;
                 }
                // printf("%s",f);
                //printf("%c=%c%c'\n",pro[i][0],pro[j][2],pro[i][0]);
                s=result[i][0];
                s=s+"=";
                s=s+result[j][2];
                s=s+result[i][0]+"'";
                s=s+"\n";
                //s=s+to_string(result[1].length());
                s=s+result[i][0]+"'"+"=";
                s=s+l;
                //p=l;
                s=s+result[i][0]+"'|"+"#";
                //printf("%c'=%s%c'|#\n",pro[i][0],f,pro[i][0]);
                ui->textEdit_2->setText(s.c_str());

                }
            }
        }
    }
    //string d=to_string(n);
//   s=result[1][0];
//   s=s+result[1][2];

   //ui->textEdit_2->setText(s.c_str());
    //n=text[0].toInt();


//        for(int i=0;i<text.length();i++)
//        {
//            text << pro[i];
//        }
//            ui->textEdit_2->setText(pro[1]);
}

void MainWindow::on_Left_factoring_clicked()
{   //QString text = ui->textEdit->toPlainText();
     int i=0,j=0,k=0,p=0,count=0,yu=0,a=0;
    char c;
    char f[20]={0},b[20]={0},v[20]={0};
    int m=0,n=0,l=0;
    string s="";
    //vector<vector<string>> pro;
    vector<string> pro;
    QString text = ui->textEdit->toPlainText();
    string str=text.toStdString();

    for(i=0;i<str.length();i++){
        if(str[i]=='\n'){
            pro.push_back(str.substr(a,i));
             a=i+1;
        }

    }
    n=pro.size();
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
        if(pro[i][0]==pro[j][0] && pro[i][2]==pro[j][2]){
            m=pro[i].length();
            l=pro[j].length()-1;
            //printf("%d\n%d\n",m,l);
            count=0;
            if(m>l){
                for(k=2;k<l;k++){
                    if(pro[i][k]==pro[j][k]){
                        count++;
                    }
                    else{
                        break;
                        }
                    }
                    //printf("%d",count);
                }
            else{
                for(k=2;k<m;k++){
                    if(pro[i][k]==pro[j][k]){
                        count++;
                    }
                    else{
                        break;
                        }
                    }
                   // printf("%d\n",count);
                }


            for(p=0;p<count;p++){
                f[p]=pro[i][p+2];
            }
                for(yu=0,p=count+2;pro[i][p]!='\0';p++,yu++){
                    v[yu]=pro[i][p];
                    //printf("%c\n",v[yu]);
                }
                for(yu=0,p=count+2;pro[j][p]!='\0';p++,yu++){
                    b[yu]=pro[j][p];
                    //printf("%c\n",b[yu]);
                }

            //printf("%c=%s%c'\n",pro[i][0],f,pro[i][0]);*/
            s=pro[i][0];
            s=s+"=";
            //s=to_string(count);
            s=s+f;
            s=s+pro[i][0];
            s=s+"'";

            //s=s+f;
            //s=s+pro[i][0]+"'";
            s=s+"\n";
            //printf("%c'=%s|%s\n",pro[i][0],v,b);
            s=s+pro[i][0];
            s=s+"'";
            s=s+"=";

            s=s+v;
            s=s+"|";
            s=s+b;

            ui->textEdit_2->setText(s.c_str());
        }

    }
    }

//ui->textEdit_2->setText(text);
}


void MainWindow::on_rd_clicked()
{
    string s="";

    QString text = ui->textEdit->toPlainText();

    string str=text.toStdString();

    pointer=&str[0];

    E();

    if((a!=-1 &&  c==0 && b==0 && d==0)){

        s="String is acceptable";

        ui->textEdit_2->setText(s.c_str());

   } else{

        s="String is unacceptable";

        ui->textEdit_2->setText(s.c_str());

    }

}
void E(){

    T();

    Ed();

    if(*pointer=='$'){

        a++;

    }

}


void T(){

    F();

    Td();

}


void Ed(){

    if(*pointer=='+'){

        b=1;

        match();

        T();

        Ed();

    }

}


void Td(){

    if(*pointer=='*'){

        c=1;

        if(b==0){

        match();

        F();

        Td();

        }

    }

}


void F(){

    if(*pointer=='('){

        b=0;

        c=0;

        d=1;

        match();

        E();

        if(*pointer==')'){

            d=0;

            match();

        }

    }

    else {

        if(*pointer=='i'){

            b=0;

            c=0;

            match();

            if(*pointer=='d'){

                match();

            }

        }

    }

}


void match(){

    ++pointer;

}




void MainWindow::on_fnf_clicked()
{  int i=0,a=0;
    string s="";
    //vector<vector<string>> pro;

    QString text = ui->textEdit->toPlainText();
    string str=text.toStdString();

    for(i=0;i<str.length();i++){
        if(str[i]=='\n'){
            ro.push_back(str.substr(a,i));
             a=i+1;
        }

    }
kp=ro.size();
for(i=0;i<kp;i++){

    mo=0;


    if(!gh.count(ro[i][0])){
        gh.insert(ro[i][0]);
        first(ro[i][0],kp);
        s=s+"first of::";
        s=s+ro[i][0];
        s=s+"-->";

    }
    for(int j=0;j<mo;j++){
        s=s+fir[j];

    }

    ui->textEdit_2->setText(s.c_str());
    s=s+"\n";
}

}
void first(char c,int kp){
if(!isupper(c)){fir[mo++]=c;}
for(int i=0;i<kp;i++){
    if(ro[i][0]==c){
        if(islower(ro[i][2])){fir[mo++]=ro[i][2];}
        else if(ro[i][2]=='$'){fir[mo++]='$';}
        else{ first(ro[i][2],kp);
             for(int lp=2;isupper(ro[i][lp]);lp++){

            for(int hu=0;fir[hu]!='\0';hu++){
                if(fir[hu]=='$'){
                    fir[hu]=',';

                    first(ro[i][lp+1],kp);
                    break;
                }
            }

               /* for(int hu=0;fir[hu]!='\0';hu++){
                if(fir[hu]=='$'){
                    fir[hu]=',';

                    first(pro[i][4],k);
                    break;
                }
            }*/
        }
        }
    }
}
}

void MainWindow::on_pushButton_2_clicked()
{
    int i=0,a=0;
        string s="";
        //vector<vector<string>> pro;

        QString text = ui->textEdit->toPlainText();
        string str=text.toStdString();

        for(i=0;i<str.length();i++){
            if(str[i]=='\n'){
                pr.push_back(str.substr(a,i));
                 a=i+1;
            }

        }
    kpp=pr.size();
    for(i=0;i<kpp;i++){

        moo=0;


        if(!gh.count(pr[i][0])){
            gh.insert(pr[i][0]);
            follow(pr[i][0]);
            s=s+"follow of::";
            s=s+pr[i][0];
            s=s+"-->";

        }
        for(int j=0;j<moo;j++){
            s=s+f[j];

        }


        s=s+"\n";
    }
    //s=s.substr(0,s.length()-1);
    for(int k=0;k<s.length();k++){
        if(s[k] == '='){
            s[k]=' ';
        }
    }
    ui->textEdit_2->setText(s.c_str());
}
void follow(char c)
{
 if(pr[0][0]==c)f[moo++]='$';
 for( ii=0;ii<pr.size();ii++)
 {
  for(int jj=2;jj<pr[ii].length();jj++)
  {
   if(pr[ii][jj]==c)
   {
    if(pr[ii][jj+1]!='\0')first(pr[ii][jj+1]);

    if(pr[ii][jj+1]=='\0'&&c!=pr[ii][0])
     follow(pr[ii][0]);

   }
  }
 }
}
void first(char c)
{
      int k=0;
                 if(!(isupper(c)))f[moo++]=c;
                 for(k=0;k<pr.size();k++)
                 {
                 if(pr[k][0]==c)
                 {
                 if(pr[k][2]=='#') follow(pr[ii][0]);
                 else if(islower(pr[k][2]))f[moo++]=pr[k][2];
                 else first(pr[k][2]);
                 }
                 }

}


void MainWindow::on_pushButton_3_clicked()
{

    string s="";
    string p="";

    int j,st,ic;

       char an;

      // clrscr();

       QString text = ui->textEdit->toPlainText();

       string ip=text.toStdString();

       push(0);

       //display();

       //printf("\t%s\n",ip);

       for(j=0;ip[j]!='\0';)

       {

     st=TOS();

     an=ip[j];

     if(an>='a'&&an<='z') ic=0;

     else if(an=='+') ic=1;

     else if(an=='*') ic=2;

     else if(an=='(') ic=3;

     else if(an==')') ic=4;

     else if(an=='$') ic=5;

     else {

        error();

        break;

     }

       if(axn[st][ic][0]==100)

        {

          pushb(an);

          push(axn[st][ic][1]);

          //display();

          j++;

          //display1(ip,j);

        }

       if(axn[st][ic][0]==101)

        {

          reduce(axn[st][ic][1]);

          //display();

          //display1(ip,j);

        }

       if(axn[st][ic][1]==102)

        {

       //printf("Given String is accepted \n");
       p="String is unacceptable";

        ui->textEdit_2->setText(p.c_str());

     //  getch();

          break;

        }

       else

       {

       //printf("Given String is rejected \n");
       s="String is acceptable";

        ui->textEdit_2->setText(s.c_str());

          break;

        }

      }

}
void push(int k)

{

  if(top<9)

    aa[++top]=k;

}
void pushb(char k)

{

  if(btop<9)

    bb[++btop]=k;

}
char TOS()

{

   return aa[top];

}
void pop()

{

   if(top>=0)

     top--;

}
void popb()

{

   if(btop>=0)

     bb[btop--]='\0';

}
void error()

{

  printf("Syntax Error");

}
void reduce(int p)

{

   int len,k,ad;

   char src,*dest;

   switch(p)

   {

 case 1:dest="E+T";

        src='E';

        break;

 case 2:dest="T";

        src='E';

        break;

 case 3:dest="T*F";

        src='T';

        break;

 case 4:dest="F";

        src='T';

        break;

 case 5:dest="(E)";

        src='F';

        break;

 case 6:dest="i";

        src='F';

        break;

 default:dest="\0";

  src='\0';

  break;

   }

   for(k=0;k<strlen(dest);k++)

   {

     pop();

     popb();

   }

   pushb(src);

   switch(src)

   {

 case 'E':ad=0;

   break;

 case 'T':ad=1;

   break;

 case 'F':ad=2;

   break;

 default: ad=-1;

   break;

   }

  push(gotot[TOS()][ad]);

}

