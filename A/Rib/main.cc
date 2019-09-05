#include<iostream>
using namespace std;
int main(){
  int X,T,S;
  cin>>X>>T>>S;
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    if(s=="nobiro")X=max(X+T,0);
    else if(s=="tidime")X=max(X+S,0);
    else X=0;
  }
  cout<<X<<endl;
  return 0;
}
