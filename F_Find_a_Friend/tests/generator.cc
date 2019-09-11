#include <iostream>
#include <utility>
#include "./testlib.h"
#include "./constraints.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <map>
#include <set>
#include <random>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

class SuperSet{
private:

    class BIT{
    private://[1,n]
        vector<int> bit;
        int n;
    public:
        BIT(){}
        BIT(int size){
            n = size;
            bit = vector<int>(n+1,0);
        }
        int sum(int i){//[0,i)のsum（内部実装は[1,i]）
            int s = 0;
            while(i > 0){
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }
        void add(int i, int x){
            while(i <= n){
                bit[i] += x;
                i += i & -i;
            }
        }
        void show(){
            cout << "bit:";
            for(int i = 1; i <= n; i++){
                cout << " " << bit[i];
            }
            cout << endl;
        }
    };

    int n;
    BIT bit;
    set<int> st;

public:
    SuperSet(){}
    SuperSet(int size){
        n = size;
        bit = BIT(n);
    }
    void insert(int x){//[0,n)
        st.insert(x);
        bit.add(x,1);
    }
    int search(int ind){
        if(ind > bit.sum(n))return -1;
        int l = 0, r = n+1;
        while(r - l > 1){
            int mid = (l + r)/2;
            if(ind > bit.sum(mid))l = mid;
            else r = mid;
        }
        return l+1;
    }
    int eraseInd(int ind){//[1,st.size()]
        int t = search(ind);
        if(t < 0)return -1;
        bit.add(t,-1);
        st.erase(t);
        return t;
    }
    bool erase(int x){
        if(!st.count(x))return false;
        st.erase(x);
        bit.add(x,-1);
        return true;
    }
    int size(){
        return st.size();
    }
    void show(){
        for(auto x: st){
            cout << " " << x;
        }
        cout << endl;
    }

    /*
    [1,N]の値を管理するset
    - insert(x)
        setにxを追加する
        O(logN)
    - eraseInd(x)
        setに入っている値の小さい方からx番目を削除する(xは1以上要素数以下)
        返り値は削除した要素(存在しない場合は-1)
        たぶん O(log^2N)
    - erase(x)
        setからxを削除する
    - search(x)
        setに入っている値の小さい方からx番目を返す
        たぶん O(log^2N)
    */
};

// aとbをファイルストリームに出力する
// ファイル名は prefix_num.in (ex: 00_sample_00.in)
int a[MAX_M],b[MAX_M],c[MAX_M];

void make(int n, int m, int t){
    //cout << n << " " << m << " " << t << endl;
    int tim[MAX_N+1] = {};
    map<int,int> mp;

    int ma = 1;

    SuperSet in(n+1),out(n+1);//部屋の中にいる人、部屋の外にいる人
    rep(i,n)out.insert(i+1);
    SuperSet tin(n+1),tout(n+1);
    rep(i,m){
        if(in.size() == 0 && tin.size() == 100)ma++;
        //cout << i << " " << ma << " " << t - (m-i-1)/n << endl;
        a[i] = rnd.next(ma, t - (m-i-1)/min(n,100));
        ma = a[i];
        mp[a[i]]++;

        if(i && a[i-1] != a[i]){
            while(tin.size()){
                int tmp = tin.eraseInd(1);
                in.insert(tmp);
            }
            while(tout.size()){
                int tmp = tout.eraseInd(1);
                out.insert(tmp);
            }
        }
        //cout << "!" << a[i] << " " << in.size() << " " << out.size() << " " << tin.size() << " " << tout.size() << endl;
        if(in.size() + tin.size() == 100 || out.size() == 0){//部屋に100人いる or 部屋の外に誰もいない
            c[i] = 0;
        }else if(in.size() == 0){//部屋に誰もいない
            c[i] = 1;
        }else{
            c[i] = rnd.next(MIN_C,MAX_C);
        }
        if(c[i]){//outからtinに移動する
            int ind = rnd.next(1,(int)out.size());
            b[i] = out.search(ind);
            out.erase(b[i]);
            tin.insert(b[i]);
        }else{//inからtoutに移動する
            int ind;
            ind = rnd.next(1,(int)in.size());
            b[i] = in.search(ind);
            in.erase(b[i]);
            tout.insert(b[i]);
        }
        if(mp[a[i]] == n)ma++;
    }
}

void output(int n, int m, int t, const string &prefix, int num){
    make(n,m,t);
    char name[100];
    sprintf(name, "%s_%02d.in", prefix.c_str(), num);
    ofstream ofs(name);
    ofs << n << " " << m << " " << t << endl;
    rep(i,m) ofs << a[i] << " " << b[i] << " " << c[i] << endl;
    ofs.close();
}

int main(){
    // 乱数のシードを設定
    // pidを足すことで、1秒以上間を置かずに起動したときに同じシードになってしまうのを防ぐ
    rnd.setSeed(time(0)+getpid());

    for(int i = 0; i < 10; ++i){
        int n = rnd.next(MIN_N, 10);
        int t = rnd.next(MIN_T, 100);
        int m = rnd.next(MIN_M, (int)min((long long)10,(long long)min(n,100)*t));
        output(n, m, t, "50_small", i);
    }
    for(int i = 0; i < 10; ++i){
        int n = rnd.next(MIN_N, MAX_N);
        int t = rnd.next(MIN_T, MAX_T);
        int m = rnd.next(MIN_M, (int)min((long long)MAX_M,(long long)min(n,100)*t));
        output(n, m, t, "51_large", i);
    }
    for(int i = 0; i < 2; ++i){
        int n = rnd.next(MIN_N, MIN_N);
        int t = rnd.next(MIN_T, MIN_T);
        int m = rnd.next(MIN_M, MIN_M);
        output(n, m, t, "52_min", i);
    }
    for(int i = 0; i < 8; ++i){
        int n = rnd.next(MAX_N, MAX_N);
        int t = rnd.next(MAX_T, MAX_T);
        int m = rnd.next(MAX_M, MAX_M);
        output(n, m, t, "53_max", i);
    }
    for(int i = 0; i < 10; ++i){
        int n = rnd.next(MIN_N, MIN_N);
        int t = rnd.next(MIN_T, MAX_T);
        int m = rnd.next(MIN_M, (int)min((long long)MAX_M,(long long)min(n,100)*t));
        output(n, m, t, "54_Nmin", i);
    }
}
