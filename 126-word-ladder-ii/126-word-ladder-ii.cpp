class Solution {
public:
	using pi = pair<int, string>;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> dict(wordList.begin(), wordList.end());
		if(dict.find(endWord) == dict.end()) return {}; // if endWord is not in dict return

		vector<vector<string>> ans;
		unordered_map<string,int> dis;        
		unordered_map<string,vector<string>> g;

		dict.insert(beginWord);
		dis[beginWord] = 0;
		//build the undirected graph
		for(auto& w : dict){
			for(int i=0; i<w.size(); i++){
				string tmp = w;
				for(char c = 'a'; c<='z'; c++){
					tmp[i] = c;
					if(tmp != w && dict.count(tmp)){
						g[w].push_back(tmp);
					}
				}
			}
		}

//         for(auto& p : g){
//             cout<<p.first<<" -> ";
//             for(string& w : p.second)cout<<w<<" ";
//             cout<<'\n';
//         }

		queue<pi> q;
		q.push({0,beginWord});
		// simple BFS to calculate distance between beginWord to each Word
		while(!q.empty()){
			auto [d, u] = q.front(); q.pop();
			if(dis[u] < d) continue;

			for(auto& v : g[u]){
				if(!dis.count(v)){
					dis[v] = d+1;
					q.push({dis[v], v});
				}else if(dis[v] > dis[u] + 1){
					dis[v] = dis[u]+1;
					q.push({dis[v], v});
				}
			}
		}

		// for(auto& p : dis){
		//     cout<<p.first<<' '<<p.second<<'\n';
		// }

		int ans_depth = dis[endWord] + 1; 
		vector<string> cur {endWord};   
		// traversing the graph from endWord to beginWord
		function<void()> dfs = [&](){
			string& v = cur.back();
			int d = ans_depth - cur.size();
			if(v == beginWord){
				vector<string> t = cur;
				reverse(t.begin(), t.end());
				ans.push_back(move(t));
				return;
			}
			for(auto& u : g[v]){
				if(dis.count(u) && dis[u] == d-1){
					cur.push_back(u);
					dfs();
					cur.pop_back();
				}
			}
		};
		dfs();
		return ans;
	}
};