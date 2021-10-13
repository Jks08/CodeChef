#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FOR(i,l,r) for(ll i=l;i<r;i++)
#define For(i,r,l) for(ll i=r-1;i>=l;i--)
#define sz(x) x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back
#define ITER(itr, x) for(auto& itr: x)
#define mp make_pair

using namespace std;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
template<typename... Args>
void err(istream_iterator<string> it, Args... args) { ((cerr << *it << " = " << args << " ", it++), ...); cerr << endl;}

typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef pair<ld, ld> dd;
const ld eps = 1e-18;

ld mysqrt(ld d){
    if(d>0) return sqrt(d);
    else return 0;
}

vector<dd> points;
vi strip, pts_y, tmp;
ld dist_sq[4];
int n;

auto get_point(){
    ld x = (dist_sq[1] - dist_sq[2] + dist_sq[0])/(2*points[1].first);
    ld y = mysqrt(dist_sq[1] - x*x);
    return mp(x,y);
};

ld l2 (int l, int r){
    ld dist = (points[l].first - points[r].first) * (points[l].first - points[r].first);
    dist += (points[l].second - points[r].second) * (points[l].second - points[r].second);
    return dist;
};

bool compX(const dd &l, const dd &r) {
    if(l.first != r.first) return l.first < r.first;
    else return l.second < r.second;
};
// bool compY(const dd &l, const dd &r) {return l.second < r.second;};
bool compY(const int &l, const int &r) {
    if(points[l].second != points[r].second) return points[l].second < points[r].second;
    else return points[l].first <= points[r].first;
};

auto brute(int l, int r){
    ld mn = 9e20;
    FOR(i,l,r) FOR(j,i+1,r) mn = min(mn, l2(i,j));
    return mn;
};

ld get_min_dist(int l, int r) {
    if(r-l <= 1) return brute(l, r);
    int mid = (l+r)/2;
    ld d1 = get_min_dist(l, mid);
    ld d2 = get_min_dist(mid, r);
    ld d = min(d1, d2);
    // merge for y
    int lptr = l, rptr = mid, ptr = l;
    while(lptr < mid && rptr < r){
        if(compY(pts_y[lptr], pts_y[rptr])){
            tmp[ptr++] = pts_y[lptr++];
        }
        else tmp[ptr++] = pts_y[rptr++];
    }
    while(lptr < mid) tmp[ptr++] = pts_y[lptr++];
    while(rptr < r) tmp[ptr++] = pts_y[rptr++];

    FOR(i,l,r) pts_y[i] = tmp[i];

    int cnt = 0;
    ld sqrt_d = mysqrt(d);
    FOR(i,l,r) if(abs(points[pts_y[i]].first - points[mid].first) < sqrt_d) strip[cnt++] = pts_y[i];
    // sort(strip.begin(), strip.begin()+cnt, compY);
    FOR(i,0,cnt) for(int j=i+1; j<cnt && (points[strip[j]].second - points[strip[i]].second) < sqrt_d; ++j){
        d = min(d, l2(strip[i],strip[j]));
    }
    return d;
};

void solve(int tc){
    cin >> n;
    points.assign(n, {0,0});
    int pivot[3] = {0, 1, 2};
    cout << "? 1 2" << endl; cout.flush();
    cin >> dist_sq[0];
    points[1] = {sqrt(dist_sq[0]), 0};
    int pt = 2;
    while(pt < n){
        cout << "? 1 " << pt+1 << endl; cout.flush();
        cin >> dist_sq[1];
        cout << "? 2 " << pt+1 << endl; cout.flush();
        cin >> dist_sq[2];
        points[pt] = get_point();
        if(abs(points[pt].second) > eps){
            pivot[2] = pt++;
            break;
        }
        pt++;
    }

    while(pt < n){
        FOR(i,0,3){
            cout << "? " << pivot[i] + 1 << " " << pt+1 << endl; cout.flush();
            cin >> dist_sq[i+1];
        }
        points[pt] = get_point();
        ld d1 = l2(pt, pivot[2]);
        points[pt].second *= -1;
        ld d2 = l2(pt, pivot[2]);
        if(abs(d2-dist_sq[3]) > abs(d1-dist_sq[3])){
            points[pt].second *= -1;
        }
        pt++;
    }
    strip.assign(n, 0);
    tmp.assign(n,0);

    pts_y.assign(n,0);
    sort(all(points), compX);
    FOR(i,0,n) pts_y[i] = i;
    long double min_dist = get_min_dist(0, n);
    cout << "! " << (ll)roundl(min_dist) << endl; cout.flush();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T; FOR(t,0,T){
        solve(t+1);
    }
}
