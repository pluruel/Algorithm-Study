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

    // pq는 큰수부터 먼저 나오는게 기준임
    // 큰 수부터 뽑아낼 의도면 <
    // 작은 수 부터 뽑아낼 의도면 >
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

    // 이 경우도 큰 수부터 뽑아낼 것임.
	bool operator < (gn b) const{
		return p < b.p;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, priority_queue<muzik> > m;
	map<string, int> gs;


    // 맵 두개를 사용해서 데이터를 구성
	for (int i = 0; i < plays.size(); ++i) {
		if (gs.find(genres[i]) == gs.end()) {
			gs.insert({ genres[i], 0 });
			m.insert({ genres[i], priority_queue<muzik>() });
		}
		gs.find(genres[i])->second += plays[i];
		m.find(genres[i])->second.push(muzik(plays[i], i));
	}

    // 맵에서 하나하나 꺼내서 우선순위 큐로 정렬
	priority_queue<gn> q;
	for (auto i = gs.begin(); i != gs.end(); i++) {
		q.push(gn(i->first, i->second));
	}

    // 위에부터 꺼내면서 답을 구성
	while (!q.empty()) {
		auto b = q.top();
		q.pop();
		auto c = m.find(b.c);
        // 답이 하나인 경우도 있으니.
		for (int i = 0; i < 2 && !c->second.empty(); i++) {
			answer.push_back(c->second.top().no);
			c->second.pop();
		}

	}

	return answer;
}