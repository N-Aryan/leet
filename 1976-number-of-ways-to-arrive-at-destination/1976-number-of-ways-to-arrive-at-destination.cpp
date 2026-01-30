class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        
        for( auto &it : roads){
            adj[it[0]].push_back( { it[1], it[2] } );
            adj[it[1]].push_back( { it[0], it[2] } );

        }
        vector<long long> time(n, LLONG_MAX);
        time[0]=0;

        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > minH;
        minH.push( {0,0} );

        vector<long long> ways(n, 0);
        ways[0]=1;

        while(!minH.empty()){
            auto top= minH.top();
            minH.pop();
            
            long long time_till_now= top.first;
            int curr_city= top.second;

            if(time_till_now > time[curr_city]) continue;

            for( auto & it: adj[curr_city]){
                int nbr=it.first;
                long long time_needed=it.second;

                if(time_till_now + time_needed < time[nbr]){
                    time[nbr]=time_till_now + time_needed;
                    minH.push( {time[nbr],nbr} );
                    ways[nbr]=ways[curr_city];
                }
                else if(time_till_now + time_needed == time[nbr]){
                    ways[nbr] = (ways[nbr] + ways[curr_city]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};