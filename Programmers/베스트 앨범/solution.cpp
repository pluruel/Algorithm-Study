#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class muzik {
public:
	int plays;
	int no;
	muzik(int _plays, int _no) : plays(_plays), no(_no) {}

	bool operator < (muzik b) const{
		if (plays == b.plays) return no > b.no;
		return plays < b.plays;
	}
};

class gn {
public:
	string c;
	int p;
	gn(string _c, int _p) : c(_c), p(_p) {}
	bool operator < (gn b) const{
		return p < b.p;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, priority_queue<muzik> > m;
	map<string, int> gs;
	for (int i = 0; i < plays.size(); ++i) {
		if (gs.find(genres[i]) == gs.end()) {
			gs.insert({ genres[i], 0 });
			m.insert({ genres[i], priority_queue<muzik>() });
		}
		gs.find(genres[i])->second += plays[i];
		m.find(genres[i])->second.push(muzik(plays[i], i));
	}
	priority_queue<gn> q;
	for (auto i = gs.begin(); i != gs.end(); i++) {
		q.push(gn(i->first, i->second));
	}

	while (!q.empty()) {
		auto b = q.top();
		q.pop();
		auto c = m.find(b.c);
		for (int i = 0; i < 2 && !c->second.empty(); i++) {
			answer.push_back(c->second.top().no);
			c->second.pop();
		}

	}

	return answer;
}