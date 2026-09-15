#include<iostream>
using namespace std;
bool isValid(string& s, int st, int end){
  while(st<end){
  if(s[st] == s[end]){
    st++;
    end--;
  }
  else{
    return false;
  }
  }
  return true;
}
int main(){

  string s = "babad";
  int n = s.size()-1;
  int maxlen = 0;
  int start;

  for(int i=0; i<=n; i++){
    for(int j=i; j<=n; j++){
      if(isValid(s, i, j) == true){
        if(maxlen <= (j-i+1)){
          maxlen = j-i+1;
          start = i;
        }
      }

    }
  }
  string ans = s.substr(start,maxlen);
  cout<<ans <<endl;

  return 0; 
}