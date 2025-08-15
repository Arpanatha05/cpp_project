//this is the code of a basic and a scientific  and Hybrid calculator
//here i use multiple inheritance Basic and Scientific calculator are Base class and Hybrid calculator is derived class
#include<iostream>
#include<cmath>
using namespace std;
//this is the basic calculator class(Bsae 1)
int factorial(int x){
    int fact=1;
    for(int i=1;i<=x;i++){
        fact*=i;
    }
    return fact;
}
class Basic_calculator{
    protected:
    int data1;
    int data2;
    char ch;
    public:
    int an;
    float returnval;
    void setdata1(int a,int b,char c){
        data1=a;
        data2=b;
        ch=c;
    }
    void calc1(void){
        if(ch=='+'){
             an=(data1+data2);
            cout<<"the value of the "<< ch <<" operation is:"<<an;
        }
        else if(ch=='-'){
              an=(data1-data2);
            cout<<"the value of the "<< ch <<" operation is:"<<an;
        }
        else if(ch=='*'){
              an=(data1*data2);
            cout<<"the value of the "<< ch <<" operation is:"<<an;
        }else if(ch=='/'){
            if(data2==0){
               cout<<"Error!!!";
            }
            else{
                returnval=float(data1)/data2;
                cout<<"the value of the "<< ch <<" operation is:"<<returnval;
            }
             
        }
        else if(ch=='%'){
            cout<<"The reminder of the two value:"<<data1 % data2<<endl;
        }
        else{
           cout<<"Error!!!";
        }
    }
};
//this is scientific calculator class(Base 2)
class Scientific_calculator{
    protected:
    int data3;
    int data4;
    char ck;
    public:
    int n;
    void setdata2(int a,int b,char c){
        data3=a;
        data4=b;
        ck=c;
    }
    void calc2(void){
        if(ck=='p'||ck=='P'){
            if(data3>=data4){
            n= factorial(data3)/(factorial(data3-data4));
            cout<<"The result of the permutation "<<data3<<"P"<<data4<<" :"<<n;
            }
            else{
                cout<<"Error!!!";
            }
        }
        else if(ck=='c'||ck=='C'){
            if(data3>=data4){
            n= factorial(data3)/(factorial(data3-data4)*factorial(data4));
            cout<<"The result of the combination "<<data3<<"C"<<data4<<" :"<<n;
            }
            else{
                cout<<"Error!!!";
            }
        }
        else if(ck=='x'||ck=='X'){
             n=1;
            for(int i=0;i<data4;i++){
                n=n*data3;
            }
             cout<<"The value of x^y is:"<<n;
        }
         else if(ck=='y'||ck=='Y'){
            int n=1;
            for(int i=0;i<data3;i++){
                n=n*data4;
            }
            cout<<"The value of x^y is:"<<n;
        }
        else if(ck=='s'||ck=='S'){
            cout<<"the sine value of first data:"<<sin(data3)<<endl;
            cout<<"the sine value of second data:"<<sin(data4)<<endl;
        }
        else if(ck=='t'||ck=='T'){
            cout<<"the tan value of first data:"<<tan(data3)<<endl;
            cout<<"the tan value of second data:"<<tan(data4)<<endl;
        }
        else if(ck=='f'||ck=='F'){
            cout<<"the factorial of first data:"<<factorial(data3)<<endl;
            cout<<"the factorial of second data:"<<factorial(data4)<<endl;
        }
       
        else{
            cout<<"Error!!!";
        }
    }

};
//this is hybrid calculator class (Deriverd)
class Hybrid_calculator:public Basic_calculator,public Scientific_calculator{
    public:
    void setdata3(int a, int b,char p){
        data1=a;
        data2=b;
        data3=a;
        data4=b;
         ch=p;
         ck=p;
    }
    void calc3(){
        if(ch=='+' ||ch=='-' ||ch=='*' ||ch=='/'){
            calc1();
        }
        else{
            calc2();
        }
    }
};
int main(){
char s;
cout<<"Enter what type of calculator you want (Enter-Basic-B/Scientific-S/Hybrid-H):";
cin>>s;
if(s=='B'||s=='b'){
int a,b;
char x;
cout<<"Enter the First Number:";
cin>>a;
cout<<"Enter the Second Number:";
cin>>b;
cout<<"Enter + , - , * , / ,% :";
cin>>x;
Basic_calculator d1;
d1.setdata1(a,b,x);
d1.calc1();
}
else if(s=='S'||s=='s'){
int a,b;
char x;
cout<<"Enter the First Number:";
cin>>a;
cout<<"Enter the Second Number:";
cin>>b;
cout<<"Enter p for permutation || c for combination || x for x^y || y for y^x || s for sine || t for tan || f for factorial:";
cin>>x;
Scientific_calculator d2;
d2.setdata2(a,b,x);
d2.calc2();
}
else if(s=='H'||s=='h'){
int a,b;
char x;
cout<<"Enter the First Number:";
cin>>a;
cout<<"Enter the Second Number:";
cin>>b;
cout<<"Enter + ,*,-,/ or Enter p for permutation || c for combination || x for x^y || y for y^x || s for sine || t for tan || f for factorial:";
cin>>x;
 Hybrid_calculator d3;
 d3.setdata3(a,b,x);
 d3.calc3();
}
else{
    cout<<"Error!!!";
}
return 0;
}