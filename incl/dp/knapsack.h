#pragma once
#include "core/base.h"

//not tested
Arr<int> sos(const Arr<int>&a){
	int n=sz(a);
	Arr<int> r(1<<n);
	for(int i=1;i<(1<<n);i++)
		r[i]=r[i&(i-1)]+a[flg2(i&-i)];
	return r;
}

#include "misc/bithelper.h"
//if sum(weight) bounded n, O(N*sqrt(N)/64)
//https://codeforces.com/contest/1856/submission/218074245
Bitset subset_sum_dyn(const Arr<int>& wa){
	int wsum=reduce(wa.begin(),wa.end());
	Arr<pint> a;
	for(const auto& [k,v]:classify(wa)){
		u64 cnt=sz(v);
		for(int i=0;cnt>=(1ull<<i);i++){
			cnt-=(1ull<<i);
			a.emplace_back(k,1ull<<i);
		}
		if(cnt)
			a.emplace_back(k,cnt);
	}
	Bitset dp(wsum+1);
	dp.on(0);
	for(int i=0;i<sz(a);i++){
		dp|=dp>>(a[i].fi*a[i].se);
		// dp.or_shiftR(a[i].fi*a[i].se);
	}
	return dp;
}