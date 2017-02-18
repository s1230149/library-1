#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Chien{
  static const int MAX=1<<18;
  int n,dat[2*MAX-1],laz[2*MAX-1];
  Chien(){}
  Chien(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++) dat[i]=laz[i]=0;
  }
  inline void eval(int len,int k){
    if(k*2+1<n*2-1){
      laz[k*2+1]+=laz[k];
      laz[k*2+2]+=laz[k];
    }
    dat[k]+=laz[k]*len;
    laz[k]=0;
  }
  int update(int a,int b,int x,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return dat[k]+laz[k]*(r-l);
    if(a<=l&&r<=b) return dat[k]+(laz[k]+=x)*(r-l);
    eval(r-l,k);
    return dat[k]=update(a,b,x,k*2+1,l,(l+r)/2)+update(a,b,x,k*2+2,(l+r)/2,r);
  }
  int query(int a,int b,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b) return dat[k];
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return vl+vr;
  }
  int update(int a,int b,int x){
    return update(a,b,x,0,0,n);
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};
signed main(){
  int n,q;
  cin>>n>>q;
  Chien ch(n);
  for(int i=0;i<q;i++){
    int c,s,t,x;
    cin>>c;
    if(c){
      cin>>s>>t;
      cout<<ch.query(s-1,t)<<endl;
    }else{
      cin>>s>>t>>x;
      ch.update(s-1,t,x);
    }
  }
}

/*
verified on 2017/02/18
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
*/
