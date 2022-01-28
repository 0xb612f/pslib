#pragma once
#include "core/arr.h"

#define ARG(...) __VA_ARGS__
#define func(RetT,fname,...) function<RetT(__VA_ARGS__)> fname=[&](__VA_ARGS__)->RetT
#define lam(expr,...) [&](__VA_ARGS__){return expr;}
#define lamp(expr,...) [](__VA_ARGS__){return expr;}

template<class T,class U>bool assmin(T& a,U&& b){return a>b?a=b,true:false;}
template<class T,class U>bool assmax(T& a,U&& b){return a<b?a=b,true:false;}
template<class T>int argmin(const Arr<T>& a){return min_element(a.begin(),a.end())-a.begin();}
template<class T>int argmax(const Arr<T>& a){return max_element(a.begin(),a.end())-a.begin();}
Arr<int> permuinv(const Arr<int>& a){Arr<int> r(sz(a));for(int i=0;i<sz(a);i++)r[a[i]]=i;return r;}
template<class T>map<T,Arr<int>> classify(const Arr<T>& a){
	map<T,Arr<int>> r;
	for(int i=0;i<sz(a);i++)
		r[a[i]].pushb(i);
	return r;
}
template<class T> ostream& operator<<(ostream& s,const Arr<T>& a){for(auto i:a)cout<<i<<' ';return s;}
template<class T> ostream& operator<<(ostream& o,const pair<T,T>& x){return o<<x.fi<<' '<<x.se;}
template<class... A,char sepch=' ',char endch='\n'> void PRINT(A...a){((cout<<a<<sepch),...,(cout<<endch));}