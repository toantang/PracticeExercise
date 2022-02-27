#include <iostream>
#include <string.h>
using namespace std;
#define MAXLEN 1000

struct SNL
{
    char sign;//dấu, nếu số âm thì sign=-1
    char len;//chiều dài
    char num[MAXLEN];//lưu các chữ số
};

void initSNL(SNL &n);//Khởi tạo số nguyên lớn
void str2snl(char *str, SNL &n);//Chuyển một chuỗi kí tự thành số nguyên lớn
void scanSNL(SNL &n);//Đọc số nguyên lớn từ bàn phím
void printSNL(SNL &n);//In số nguyên lớn ra màn hình
int cmpu(SNL &a, SNL &b);//So sánh 2 số nguyên lớn không xét dấu
int cmp(SNL &a, SNL &b);//So sánh 2 số nguyên lớn, nếu a>b trả về 1, a=b trả về 0, a<b trả về -1
void addu(SNL &s, SNL &a, SNL &b);//Cộng không xét dấu
void add(SNL &s, SNL &a, SNL &b);//Cộng có xét dấu
void subu(SNL &s, SNL &a, SNL &b);//Trừ không xét dấu
void sub(SNL &s, SNL &a, SNL &b);//Trừ có xét dấu
void mul(SNL &r, SNL &a, SNL &b);//Nhân hai số nguyên lớn
void div(SNL &r, SNL a, SNL b);//Phép chia số nguyên lớn

void InitSNL(SNL &n)
{
    for (int i=0; i<MAXLEN; i++) n.num[i]=0;
    n.len=0;
    n.sign=1;
}
void str2snl(char *str, SNL &n)
{
    int i;
    if (str[0]=='-')
    {
        n.sign=-1;
        str++; //bỏ qua kí tự đầu tiên
    }
    else
        n.sign=1;

    n.len=strlen(str);//Chiều dài (số chữ số) của số nguyên lớn

    for (i=0; i<n.len; i++)
        n.num[i]=str[n.len-i-1]-'0';//Chuyển từng kí tự thành số
}

int cmpu(SNL &a, SNL &b)
{

    if (a.len>b.len)//Số nào dài hơn thì số đó lớn hơn
        return 1;
    else if (a.len<b.len)
        return -1;
    else//Trường hợp chiều dài 2 số bằng nhau
    {
        int len=a.len-1;
        while (len>=0)
        {
            //So sánh từ chữ số
            if (a.num[len]>b.num[len])
                return 1;
            else if (a.num[len]<b.num[len])
                return -1;
            else
                len--;
        }
    }
    return 0;
}

int cmp(SNL &a, SNL &b)
{
    if (a.sign * b.sign<0) return a.sign;
    return a.sign * cmpu(a,b);
}

void scanSNL(SNL &n)//Đọc SNL từ bàn phím
{
    char *t=new char[MAXLEN];
    cin>>t;
    str2snl(t,n);
    delete []t;
}

void printSNL(SNL &n)
{
    if (n.sign<0) cout<<"-";
    for (int i=n.len-1; i>=0; i--) cout<<(int)n.num[i];
}

void addu(SNL &s, SNL &a, SNL &b)
{
    InitSNL(s);
    s.len=a.len>b.len?a.len:b.len;
    char m=0;//biến nhớ
    for (int i=0; i<s.len; i++)
    {
        s.num[i]=a.num[i]+b.num[i]+m;
        if (s.num[i]>9)
        {
            s.num[i] -= 10;
            m=1;
        }
        else
            m=0;
    }
    if (m)
    {
        s.num[s.len]=1;
        s.len++;
    }
}

void add(SNL &s, SNL &a, SNL &b)
{
    if (a.sign*b.sign>0)//Nếu a và b cùng dấu
    {
        addu(s,a,b);
        s.sign=a.sign;//Dấu của s cũng là dấu của a hoặc b
    }
    else
    {
        int t=cmpu(a,b);
        if (t==1)
        {
            subu(s,a,b);
            s.sign=a.sign;
        }
        else if (t==-1)
        {
            subu(s,b,a);
            s.sign=b.sign;
        }
        else
            InitSNL(s);

    }
}

void subu(SNL &r, SNL &a, SNL &b)
{
    InitSNL(r);
    r.len=a.len>b.len?a.len:b.len;
    int m=0;
    for (int i=0; i<r.len; i++)
    {
        if (a.num[i]<b.num[i]+m)
        {
            r.num[i]=10+a.num[i]-b.num[i]-m;
            m=1;
        }
        else
        {
            r.num[i]=a.num[i]-b.num[i]-m;
            m=0;
        }
    }
    while (r.num[r.len-1]==0) r.len--;
}

void sub(SNL &r, SNL &a, SNL &b)
{
    b.sign=-b.sign;
    add(r,a,b);
    b.sign=-b.sign;
}

void mul(SNL &r, SNL &a, SNL &b)
{
    InitSNL(r);
    for (int i=0; i<b.len; i++)
        for (int j=0; j<b.num[i]; j++)
            for (int k=0; k<a.len; k++)
            {
                r.num[k+i] += a.num[k];
                if (r.num[k+i]>9)
                {
                    r.num[k+i] -= 10;
                    r.num[k+i+1]++;
                }
            }
            r.len=a.len+b.len;
            while (r.num[r.len-1]==0) r.len--;
            r.sign=a.sign*b.sign;
}

void div(SNL &r, SNL a, SNL b)
{
    InitSNL(r);
    r.len=a.len-b.len+1;
    if (a.len>=b.len)
    {
        int blen=b.len;
        int i;
        if (a.len>b.len)
        {
            i=a.len-1;
            int x=a.len-b.len;
            while (i>=0)
            {
                if (i>=x)
                    b.num[i]=b.num[i-x];
                else
                    b.num[i]=0;
                i--;
            }
        }
        b.len=a.len;
        SNL d;
        i=1;
        while (b.len>=blen)
        {
            while (cmpu(a,b)>-1)
            {
                subu(d,a,b);
                r.num[r.len-i]++;
                a=d;
            }
            b.len--;
            i++;
            for (int k=0; k<b.len; k++) b.num[k]=b.num[k+1];
            b.num[b.len]=0;
        }
        while (r.num[r.len-1]==0) r.len--;
    }
    r.sign=a.sign*b.sign;
}

int main()
{
    SNL a,b,c;
    InitSNL(a);
    InitSNL(b);
    InitSNL(c);

    cout<<"Nhap so nguyen a: "; scanSNL(a);
    cout<<"Nhap so nguyen b: "; scanSNL(b);

    add(c,a,b);
    cout<<endl<<"a + b = "; printSNL(c);
    sub(c,a,b);
    cout<<endl<<"a - b = "; printSNL(c);

    mul(c,a,b);
    cout<<endl<<"a * b = "; printSNL(c);

    div(c,a,b);
    cout<<endl<<"a / b = "; printSNL(c);

    cout<<endl;
    system("pause");
    return 0;
}
