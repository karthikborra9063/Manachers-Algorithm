#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
using namespace std;
string convert_string(string str)
{
	string converted_str="$#";
	int l=str.length();
	for(int i=0;i<l;i++)
	{
		converted_str+=str[i];
		converted_str+="#";
	}
	converted_str+="@";
	return converted_str;
}
void manachers(string converted_str,string str)
{
	int l=converted_str.length();
	vector<int>p(l);
	int c=1,r=1;
	for(int i=1;i<l-1;i++)
	{
		int mirror=2*c-i;
		if(i<r)
		{
			p[i]=min(r-i,p[mirror]);
		}
		else
		{
			p[i]=0;
		}
		while(converted_str[i-(1+p[i])]==converted_str[i+1+p[i]])
		{
			p[i]++;
		}
		if(i+p[i]>r)
		{
			c=i;
			r=i+p[i];
		}
	}
 int max_len= 0, center_ind = 0;
    for(int i = 0; i < l; i++) {
        if(p[i] > max_len) {
            max_len = p[i];
            center_ind = i;
        }
    }
    int start=(center_ind-max_len)/2;
    int end=start+max_len;
    cout<<"Given string is:"<<str<<endl;
	cout<<"Length of the longest palindromic sub string is:"<<end-start<<endl;
	cout<<"Longest Palindromic sub string is:";
	string res="";
	for(int i=start;i<end;i++)
	{
	res+=str[i];	
	}
	cout<<res<<endl;
}
int main()
{
	string str;

ifstream fp;
fp.open("cpp_input.txt");
if(!fp)
{
	cout<<"hii";
	return 1;
}
getline(fp,str);
fp.close();
	string converted_str=convert_string(str);
	manachers(converted_str,str);
	return 0;
}
