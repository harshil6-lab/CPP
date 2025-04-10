#include<iostream>
#include<string>
using namespace std;

class rectangle
{
    float length;
    float width;
    
    public:
    rectangle():length(0) , width(0){}
    
    void setDimensions(int l, int w){ length = l ; width = w; }
    void area(){ cout<<"Area = "<<length*width<<endl; }
    void perimeter(){ cout<<"Perimeter = "<<2*(length*width)<<endl; }
};

int main()
{
    rectangle r[100];
    int i=0,j=0 , l , w;
    cout<<"\nHow Many Area/Perimeter Are You Find ? ";
    cin>>j;
    for(int i=0 ; i<j ; i++)
    {
    cout<<"\n\nEnter Length And Width of Rectangle = ";
    cin>>l>>w;
    r[i].setDimensions(l,w);
    r[i].area();
    r[i].perimeter();
    }
    cout<<"\n\n24CE049_Harshil"<<endl;
    return 0;
}