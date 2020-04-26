#include <bits/stdc++.h>
#define U 1000000000
#define R_MIN 500000000
using namespace std;

typedef long long ll;

// ofstream attempts("attempts");


int throwDart(const ll & x,const ll & y){
    string result;
    fprintf(stdout,"%lld %lld\n",x,y);
    // attempts << x << " " << y << endl;
    // fflush(stdout);
    getline(cin,result);
    if(result == "CENTER"){
        return 3;
    }else if(result == "HIT"){
        return 1;
    }else if(result == "MISS"){
        return 0;
    }
    return -1;
}

int hitDartboard(long long & x, long long & y){
    string result;
    int rv = 1;
    for(x = -U + R_MIN/2; x < U; x+= R_MIN){
        for(y = -U + R_MIN/2; y < U; y+= R_MIN){
            rv = throwDart(x,y);
            if(rv != 0)return rv;
        }
    }
    return rv; // impossible, dartboard can not be hit
}

int findHorizontal(ll xHit, ll yHit, ll & xLeft, ll & yLeft, ll & xRight, ll & yRight){
    yLeft = yRight = yHit;
    ll xLeftL = -U;
    ll xLeftR = xHit;
    while(xLeftL != xLeftR - 1){
        // attempts << xLeftL << " " << xLeftR << endl;
        ll temp = ( xLeftL + xLeftR ) / 2;
        int res = throwDart(temp, yLeft);
        // attempts << endl;
        if(res == 1)xLeftR = temp;
        else if(res == 0)xLeftL = temp;
        else if(res == 3)return res; // end TC
    }
    xLeft = xLeftR;

    if(xLeft == xHit){
        xRight = xHit;
        return 0;
    }

    ll xRightL = xHit;
    ll xRightR = U;
    while(xRightR != xRightL + 1){
        ll temp = ( xRightL + xRightR ) / 2;
        int res = throwDart(temp, yRight);
        if(res == 1)xRightL = temp;
        else if(res == 0)xRightR = temp;
        else if(res == 3)return 3; // end TC
    }
    xRight = xRightL;

}

int findVertical(ll xHit, ll yHit, ll & xUp, ll & yUp, ll & xDown, ll & yDown){
    xUp = xDown = xHit;
    ll yUpD = yHit;
    ll yUpU = U;
    while(yUpU != yUpD + 1){
        ll temp = ( yUpU + yUpD ) / 2;
        int res = throwDart(xUp, temp);
        if(res == 1)yUpD = temp;
        else if(res == 0)yUpU = temp;
        else if(res == 3)return res; // end TC
    }
    yUp = yUpD;

    if(yUp == yHit){
        yDown = yHit;
        return 0;
    }

    ll yDownU = yHit;
    ll yDownD = -U;
    while(yDownU != yDownD + 1){
        ll temp = (yDownU + yDownD) / 2;
        int res = throwDart(xDown, temp);
        if(res == 1)yDownU = temp;
        else if(res == 0)yDownD = temp;
        else if(res == 3)return res; // end TC. Very Unlikely
    }
    yDown = yDownU;

}

// void report(ofstream & DebugFile, vector<ll> & variables){
//     for(int i = 0; i < variables.size(); i++){
//         if(i%2 == 0) DebugFile << endl;
//         DebugFile << variables[i] << " ";
//     }
//     DebugFile << endl;
// }

typedef int mut;
mut main(){
    ios_base::sync_with_stdio(false);
    setbuf(stdout, NULL);

    // ofstream debugFile("debug");
    // debugFile << endl;

    int T; // number of TCs
    long long A,B; // lower and upper bound of radius
    scanf("%d %lld %lld",&T,&A,&B);

    for(int TC = 0; TC < T; TC++){
        long long x,y;           // first point to hit dartboard
        long long xLeft,yLeft;   // first edgepoint
        long long xRight,yRight; // second edgepoint
        long long xUp,yUp;       // third edgepoint
        long long xDown,yDown;   // fourth edgepoint. In fact not necessary, but why not
        long long xCenter,yCenter;
        if(hitDartboard(x,y) == 3)continue;
        if(findHorizontal(x,y,xLeft,yLeft,xRight,yRight) == 3)continue;
        if(findVertical(x,y,xUp,yUp,xDown,yDown) == 3) continue;
        xCenter = (xLeft + xRight )/2;
        yCenter = (yUp + yDown )/2;

        // vector<ll> variables{x,y,xLeft,yLeft,xRight,yRight,xUp,yUp,xDown,yDown,xCenter,yCenter};
        // report(debugFile, variables);
        int result = throwDart(xCenter, yCenter);
        if(result != 3){ // call Houston
            // debugFile << "No way";
        }
    }

    return 0;
}
