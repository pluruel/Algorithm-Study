#include <iostream>
#include <stdio.h>

int buildSet[1001][1001] = { 0, };
int buildBefore[1001][1001] = { 0, };

int main() {
    int amount_test = 0;
    
    
    std::cin >> amount_test;
    
    while (amount_test--) {
        int finalTarget = 0;
        int amount_building = 0;
        int amount_order = 0;
        int buildTime[1001] = { 0, };
        
        int totalBuildTime[1001] = { 0, };
        int needBuild[1001] = { 0, };
        
        bool finished[1001] = { false, };
        
        std::cin >> amount_building >> amount_order;
        
        for (int i = 1; i <= amount_building; i++) {
            std::cin >> buildTime[i];
            totalBuildTime[i] = buildTime[i];
        }
        totalBuildTime[1] = buildTime[1];
        for (int i = 0; i < amount_order; i++) {
            int need;
            int build;
            std::cin >> need >> build;
            
            buildSet[need][++buildSet[need][0]] = build;
            buildBefore[build][++buildBefore[build][0]] = need;
            needBuild[build]++;
        }
        
        
        std::cin >> finalTarget;
        
        
        while (1) {
            int target = -1;
            for (int i = 1; i <= amount_building; i++) {
                if (needBuild[i] == 0 && !finished[i]) {
                    target = i;
                    finished[i] = true;
                    break;
                }
            }
            for (int i = 1; i <= buildSet[target][0]; i++) {
                needBuild[buildSet[target][i]]--;
                
            }
            for (int k = 1; k <= buildBefore[target][0]; k++) {
                int totaltemp = buildTime[target] + totalBuildTime[buildBefore[target][k]];
                totalBuildTime[target] = totaltemp > totalBuildTime[target] ? totaltemp : totalBuildTime[target];
            }
            if (target == finalTarget) {
                break;
            }
            
            
        }
        std::cout << totalBuildTime[finalTarget] << std::endl;
        for (int i = 1; i <= amount_building; i++) {
            int setno = buildSet[i][0];
            for (int k = 0; k <= setno; k++) {
                buildSet[i][k] = 0;
            }
            int beforno = buildBefore[i][0];
            for (int k = 0; k <= beforno; k++) {
                buildBefore[i][k] = 0;
            }
        }
    }
    return 0;
}
