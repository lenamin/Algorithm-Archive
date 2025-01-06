// LeetCode 433. Minimum Genetic Mutation 
#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // endGene이 bank에 존재하는지 아닌지 먼저 검색 (없으면 -1)
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) return -1;
       
        unordered_set<string> visited;
        queue<pair<string, int>> q; // <gene, steps>
        q.push({startGene, 0});
        visited.insert(startGene);

        vector<char> w = {'A', 'C', 'G', 'T'}; // 사용 가능한 문자 정의 

        // BFS 탐색 시작 
        while (!q.empty()) {
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop(); // 큐 비운다 

            if (gene == endGene) { return steps; } // 현재 gene이 endGene과 같으면 현재까지 더한 steps 반환
            
            for (int i = 0; i < gene.size(); i++) { // 각 gene에 대해서 
                string candidateGene = gene;
                for (int j = 0; j < w.size(); j++) { // 사용가능한 모든 문자를 넣어본다 
                    candidateGene[i] = w[j];
                    
                    if (find(bank.begin(), bank.end(), candidateGene) != bank.end() && find(visited.begin(), visited.end(), candidateGene) == visited.end()) {
                        q.push({candidateGene, steps + 1});
                        visited.insert(candidateGene);
                    }
                }
            }
        }
        return -1;
    }
};