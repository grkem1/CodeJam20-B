#include <bits/stdc++.h>

using namespace std;

string steps;

bool find_step(long long & x, long long & y){
    if(x == 0){
        if(y == 0)return true;
        if(y == -1){steps.push_back('S');y=0;return true;}
        if(y == 1){steps.push_back('N');y=0;return true;}
    }
    if(y == 0){
        if(x == -1){steps.push_back('W');x=0;return true;}
        if(x == 1){steps.push_back('E');x=0;return true;}
    }
    if(x % 2 != 0 && y % 2 == 0){
        long long x_direction = (x > 0) - (x < 0);
        x = x / 2;
        y = y / 2;
        if( (x + y) % 2 != 0 ){
            steps.push_back(x_direction>0?'E':'W');
        }else{
            x = x + x_direction; // move away from target
            steps.push_back(x_direction>0?'W':'E');
        }
        return true; // reachable by horizontal movement
    }else if(x % 2 == 0 && y % 2 != 0){
        long long y_direction = (y > 0) - (y < 0);
        x = x / 2;
        y = y / 2;
        if( (x + y) % 2 != 0){
            steps.push_back(y_direction>0?'N':'S');
        }else{
            y = y + y_direction; // move away from target
            steps.push_back(y_direction>0?'S':'N');
        }
        return true;  // reachable by vertical movement
    }else{
        return false; // return not reachable
    }
}

// bool verification(long long x_verif, long long y_verif, string path){
//     long long x = 0;
//     long long y = 0;
//     for(int i = 0; i < path.size(); i++){
//         if(path[i] == 'E'){
//             x += pow(2,i);
//         }
//         if(path[i] == 'W'){
//             x -= pow(2,i);
//         }
//         if(path[i] == 'S'){
//             y -= pow(2,i);
//         }
//         if(path[i] == 'N'){
//             y += pow(2,i);
//         }
//     }
//     if(x == x_verif && y == y_verif){
//         return true;
//     }else{
//         return false;
//     }
// }

typedef int mut;
mut main(){

    // ofstream debugFile("debug");
    // debugFile << endl;

    int T;
    long long x, y;
    scanf("%d\n",&T);
    for(int TC = 0; TC < T; TC++){
        scanf("%lld %lld\n",&x,&y);

        long long x_verif = x;
        long long y_verif = y;
        while(x != 0 || y != 0){
            if(!find_step(x,y))break;
        }
        printf("Case #%d: ",TC+1);
        if(x == 0 && y == 0){
            copy( steps.begin(), steps.end(), std::ostream_iterator<char>(cout, ""));
        }else{
            printf("IMPOSSIBLE");
        }
        // debugFile << x << " " << y << endl;
        // debugFile << verification(x_verif, y_verif, steps);
        printf("\n");
        steps.clear();
    }
    return 0;

}
