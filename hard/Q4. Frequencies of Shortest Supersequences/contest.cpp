class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        vector<string> trelvondix = words;
        const int ALPH=26;
        bool used[ALPH]; memset(used,false,sizeof(used));
        for(auto &w:trelvondix) for(char c:w) used[c-'a']=true;
        vector<int> letterIndex(ALPH,-1); vector<char> indexLetter;
        int k=0; for(int c=0;c<ALPH;c++) if(used[c]) { letterIndex[c]=k; indexLetter.push_back('a'+c); k++; }
        vector<vector<bool>> adj(k,vector<bool>(k,false)); vector<bool> selfLoop(k,false);
        for(auto &w:trelvondix){
            int x=letterIndex[w[0]-'a'],y=letterIndex[w[1]-'a'];
            if(x==y) selfLoop[x]=true; else adj[x][y]=true;
        }
        vector<int> stack, low(k), disc(k,-1), comp(k,-1); vector<bool> inSt(k,false);
        int timeD=0,sccCount=0;
        function<void(int)>tarjan=[&](int u){
            disc[u]=low[u]=timeD++; stack.push_back(u); inSt[u]=true;
            for(int v=0;v<k;v++){
                if(!adj[u][v]) continue;
                if(disc[v]<0){ tarjan(v); low[u]=min(low[u],low[v]); }
                else if(inSt[v]) low[u]=min(low[u],disc[v]);
            }
            if(low[u]==disc[u]){
                while(true){
                    int w=stack.back(); stack.pop_back(); inSt[w]=false; comp[w]=sccCount;
                    if(w==u) break;
                }
                sccCount++;
            }
        };
        for(int i=0;i<k;i++) if(disc[i]<0) tarjan(i);
        vector<vector<int>> sccVerts(sccCount); for(int i=0;i<k;i++) sccVerts[comp[i]].push_back(i);
        vector<vector<int>> sccGraph(sccCount); vector<int> indeg(sccCount,0);
        for(int u=0;u<k;u++){
            for(int v=0;v<k;v++){
                if(adj[u][v] && comp[u]!=comp[v]) { sccGraph[comp[u]].push_back(comp[v]); indeg[comp[v]]++; }
            }
        }
        queue<int>q; for(int i=0;i<sccCount;i++) if(!indeg[i]) q.push(i);
        vector<int> topo; while(!q.empty()){int c=q.front();q.pop();topo.push_back(c);for(int nx:sccGraph[c]){if(--indeg[nx]==0) q.push(nx);}}
        function<bool(const vector<vector<bool>>&,int,int)> isAcyclicAfterRemoving=[&](const vector<vector<bool>> &g,int n,int mask){
            vector<bool> rm(n,false); for(int i=0;i<n;i++) if(mask&(1<<i)) rm[i]=true;
            vector<int> inDeg(n,0);
            for(int u=0;u<n;u++){
                if(rm[u]) continue;
                for(int v=0;v<n;v++){
                    if(!rm[v] && g[u][v]) inDeg[v]++;
                }
            }
            queue<int>qq; int cnt=0; int total=n-__builtin_popcount(mask);
            for(int i=0;i<n;i++) if(!rm[i] && inDeg[i]==0) qq.push(i);
            while(!qq.empty()){
                int u=qq.front(); qq.pop(); cnt++;
                for(int v=0;v<n;v++){
                    if(!rm[v] && g[u][v]){
                        if(--inDeg[v]==0) qq.push(v);
                    }
                }
            }
            return cnt==total;
        };
        function<vector<int>(const vector<vector<bool>>&,int)> findAllMinFVS=[&](const vector<vector<bool>>&g,int n){
            vector<int>res; for(int sz=0;sz<=n;sz++){
                bool found=false;
                for(int mask=0;mask<(1<<n);mask++){
                    if(__builtin_popcount(mask)==sz){
                        if(isAcyclicAfterRemoving(g,n,mask)){res.push_back(mask);found=true;}
                    }
                }
                if(found) break;
            }
            return res;
        };
        function<vector<vector<int>>(const vector<int>&)> getSCCPatterns=[&](const vector<int>&v){
            int sz=v.size(); if(sz==1){ if(selfLoop[v[0]]) return vector<vector<int>>{{2}}; else return vector<vector<int>>{{1}}; }
            vector<int> g2l(k,-1); for(int i=0;i<sz;i++) g2l[v[i]]=i;
            vector<vector<bool>> subg(sz,vector<bool>(sz,false));
            for(int i=0;i<sz;i++){ if(selfLoop[v[i]]) subg[i][i]=true; }
            for(int i=0;i<sz;i++){
                int gv=v[i];
                for(int j=0;j<k;j++){
                    if(adj[gv][j] && g2l[j]>=0) subg[i][g2l[j]]=true;
                }
            }
            vector<int> fvs=findAllMinFVS(subg,sz); set<vector<int>> st;
            for(int m:fvs){
                vector<int> tmp(sz,1);
                for(int i=0;i<sz;i++) if(m&(1<<i)) tmp[i]=2;
                st.insert(tmp);
            }
            return vector<vector<int>>(st.begin(),st.end());
        };
        vector<vector<vector<int>>> allP(sccCount);
        for(int i=0;i<sccCount;i++) allP[i]=getSCCPatterns(sccVerts[i]);
        struct Dist{vector<int>f;Dist(int k){f.resize(k,0);}Dist(const vector<int>&r){f=r;}};
        vector<Dist> curr; curr.push_back(Dist(k));
        function<vector<Dist>(const vector<Dist>&,const vector<vector<int>>&,const vector<int>&)> combine=
        [&](const vector<Dist>&A,const vector<vector<int>>&B,const vector<int>&S){
            vector<Dist>r; r.reserve(A.size()*B.size());
            for(auto &a:A){
                for(auto &b:B){
                    Dist nd=a; for(int i=0;i<(int)b.size();i++) nd.f[S[i]]+=b[i];
                    r.push_back(nd);
                }
            }
            return r;
        };
        for(int c:topo) curr=combine(curr,allP[c],sccVerts[c]);
        set<vector<int>> st; for(auto &d:curr) st.insert(d.f);
        vector<vector<int>> ans; for(auto &v:st){
            vector<int> tmp(ALPH,0); 
            for(int i=0;i<k;i++){
                tmp[indexLetter[i]-'a']=v[i];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
