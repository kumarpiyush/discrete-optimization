#ifndef HEADERS
#define HEADERS

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdarg>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define DB(args...) { cerr << __LINE__<< ": "; vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c);
void err(vector<string>::iterator it);
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args);

#define ll long long int
#define pb push_back
#define fr(i,n)     for(int i=0;i<n;i++)
#define init(mem,v) memset(mem,v,sizeof(mem))
typedef pair<int,int> pii;

#endif
