#include<bits/stdc++.h>
using namespace std;
char pmatrix [5][5]={0};

string keywordsingle( string keyword)
{
    unordered_set<char>str;
    string result="";
    for(char ch: keyword)
    {
        if(str.insert(ch).second)
        {
            result+=ch;
        }
    }
return result;

}
string deletestr(string str,char key)
{
     str.erase(remove(str.begin(), str.end(), key), str.end());
     return str;
}


void matrixfuncton(string str)
{
    int n=0;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            pmatrix[i][j]=str[n];
            cout<<pmatrix[i][j]<<" ";
            n++;
        }
        if(n==25)
        {
            break;
        }

        cout<<endl;
    }

}

string chipherLetter(string text , char ch1,char ch2)
{
    string chletter="";
    int index1=text.find(ch1);
    int index2=text.find(ch2);

    int row1=floor(index1/5);
    int row2=floor(index2/5);
    int col1=0,col2=0;
    if(index1%5==0)
    {
    col1=0 ;
    

    }
    else{
   
    double result=((((double(index1) / 5) - double(row1))*10)/2) ;
     col1=result;
    }

    if(index2%5==0)
    {
        col2=0 ;
    }
    else{
        double result2=((((double(index2) / 5) - double(row2))*10)/2) ;
        col2=result2;
    }
 
    if(col1==col2)
    {
        cout<<row1<<" "<<row2<<endl;

        if(row1==4)
        {
            row1=0;
        }
        else{
            row1+=1;
        }


        if(row2==4)
        {
            row2=0;
        }
        else{
            row2+=1;
        }

        chletter+=pmatrix[row1][col1];
        chletter+=pmatrix[row2][col2];
    }

    else if(row1==row2)
        {
    

        if(col1==4)
        {
            col1=0;
        }
        else{
            col1+=1;
        }


        if(col2==4)
        {
            col2=0;
        }
        else{
            col2+=1;
        }

        chletter+=pmatrix[row1][col1];
        chletter+=pmatrix[row2][col2];
    }

    else if(row1!=row2 )
    {
        if(col1>col2)
        {
             chletter+=pmatrix[row2][col1];
             chletter+=pmatrix[row1][col2];

        }
        else{
        chletter+=pmatrix[row1][col2];
        chletter+=pmatrix[row2][col1];

        }


    }
    
    return chletter;

}

string chiphertext(string text, string str)
{
   
    string chiphertext="";
    int j=1;
    for(int i=0;i<str.length()-1;i+=2)
    {
        chiphertext+=chipherLetter(text,str[i],str[j]);
        j+=2;

    }
    return chiphertext;
}
int main()
{
while(1)
{
        string plaintext,keyword;
    cout<<"Enter plain text : ";
    cin>>plaintext;
    cout<<"Enter keyword : ";
    cin>>keyword;
    keyword=keywordsingle(keyword);
    string testtext = "ABCDEFGHJKLMNOPQRSTUVWXYZ";

    for(int i=0;i<keyword.length();i++)
    {
        if(keyword[i]=='I')
        {
            keyword[i]='J';
        }
        testtext=deletestr(testtext,keyword[i]);

    }
    testtext=keyword+testtext;
    cout<<"Matrix : "<<endl;
    matrixfuncton(testtext);

    if(plaintext.length()%2==1)
    {
        plaintext+='Z';
    }
    // cout<<testtext;

    cout<<"\nEncrypt ="<<chiphertext(testtext,plaintext)<<endl;
}

}