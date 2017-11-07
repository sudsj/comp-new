#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Debug(x) cout << "> " << #x << " : " << x << "\n";
#define DebugArr(a,n) For(i,0,n) cout << i << " : " << a[i] << "\n";
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define ForD(i,a,b) for(int i=(a);i>(b);i--)
#define tests int t; cin>>t; while(t--)
#define Imax INT_MAX
#define Imin INT_MIN
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define sz(a) int((a).size())
#define pb push_back
#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
/////////////////////////////////////////////////////////////////////

int main()
{
    int n; char c;
    cin >> n;
    stack <int> opr;stack <double> opd;
    int prt[] = {0,1,1,2,3,3,4};
    int neg = 1;
    //push () into operand stack
    // int opr[n] = {0};//operator
    // int prt = {};
    // int opd[n] = {0};//operand
    int in = 0,brkts=0,flag=0,num=0,prevopr=1;//stores if previous was operator
    c = 'A'; int minuses = 1;int mnegs = 0; int lastop = 0;
    //8 = ) 7 = ( 6 = -ve 5 = % 4 = / 3 = * 2 = + 1 = -
    std::vector<int> input(n);
    std::vector<int> isopr(n);
    while(c != EOF){
        c = getchar();
        if(c >= 37 && c <= 47 ){
            //operator
            if(c == 37){
                lastop = 1;
                //%
                if(minuses > 0){
                    flag = 1;
                }
                minuses = 0;
                if(prevopr == 1){
                    flag = 1;
                }
                prevopr = 1; isopr[in] = 1;
                input[in] = 5; in ++;
            }else if(c == 40){ lastop = 1;
                // (
                minuses = 0;
                prevopr = 1; isopr[in] = 1;
                input[in] = 7; in ++;
                brkts += 1;
            }else if(c == 41){
                // )
                if(prevopr == 1){
                    flag = 1;
                }
                if(minuses > 0){
                    flag = 1;
                }
                prevopr = 0; isopr[in] = 1;
                input[in] = 8; in ++;
                brkts -= 1;
                if(brkts < 0) flag = 1;
                minuses = 0;
            }else if(c == 42){
                lastop = 1;
                //*
                if(prevopr == 1){
                    flag = 1;
                }
                if(minuses > 0){
                    flag = 1;
                }
                prevopr = 1; isopr[in] = 1;
                input[in] = 3; in ++;
                minuses = 0;
            }else if(c == 43){
                lastop = 1;
                // +
                if(prevopr == 1){
                    flag = 1;
                }
                if(minuses > 0){
                    flag = 1;
                }
                prevopr = 1; isopr[in] = 1;
                input[in] = 2; in ++;
                minuses = 0;
            }else if(c == 45){
                lastop = 1;
                // -
                minuses += 1;
                if(minuses > 2){
                    flag = 1;
                }
                if(prevopr == 1){
                    // -ve sign
                    prevopr = 1; isopr[in] = 1;
                    input[in] = 6; in ++;
                    mnegs += 1;
                    minuses = 5;//to prevent any more negative sign just after
                }else{
                   prevopr = 1; isopr[in] = 1;
                    input[in] = 1; in ++; 
                } 
            }else if(c == 47){
                lastop = 1;
                // /
                if(prevopr == 1){
                    flag = 1;
                }
                if(minuses > 0){
                    flag = 1;
                }
                prevopr = 1; isopr[in] = 1;
                input[in] = 4; in ++;
                minuses = 0;
            }
        }else if(c >= 48 && c <= 57){
            lastop = 0;
            //numbers
            num = c - '0';minuses = 0;
            c = getchar();
            while(c >= 48 && c <= 57){
                num *= 10;
                num += c - '0';
                c = getchar();
            }
            prevopr = 0; isopr[in] = 0;
            if(in != 0){
                if(isopr[in-1] != 1){
                    flag = 1;
                }
            }
            input[in] = num; in ++;
        }
    }
    if(lastop == 1){
        flag = 1;
    }
    if(brkts != 0){
        flag = 1;
    }
    //if(isopr[0] == 1 && input[0] != )
    int opsum = 0;
    //input successful
    For(i,0,n){
        if(isopr[i] == 1) opsum++;
    }
    //opsum -= mnegs;
    int numsss = n - opsum;
    //if(numsss < opsum + 1) flag = 1;
    if(n == 1){
        if(opsum != 0){ flag = 1;
        }else{
            //input is operand
            cout << input[0];
            goto brk;
        }
    }
    if(n == 2){
        if(opsum != 1){ flag = 1;
        }else{
            if(input[0] != 6){//first is not -ve sign
                flag = 1;
                cout << "Malformed expression";
                goto brk;
            }
            //input is operand
            //input[1] *= -1;
            if(input[0] == 6) input[1] *= -1;
            cout << input[1];
            goto brk;
        }
    }
    if(flag == 1){
        //brackets wrong
        cout << "Malformed expression";
        goto brk;
    }
    
    int optr,curr; double op1,op2,ans; int one,two;//for % operator
    For(i,0,n){
        if(isopr[i] == 0){
            //operand
            input[i] *= neg; neg = 1;
            opd.push(input[i]);
        }else{//8 = ) 7 = ( 6 = -ve 5 = % 4 = / 3 = * 2 = + 1 = -
            if(input[i] == 6){
                neg *= -1;
            }else if(input[i] == 7){//opening brackets
               opr.push(input[i]); 
           }else if(input[i] == 8){
                //closing bracket encountered
                while(opr.top() != 7){
                    optr = opr.top();
                    op2 = opd.top();
                    opd.pop();
                    op1 = opd.top();
                    opd.pop();
                    if(optr == 1){
                        ans = op1 - op2;
                    }else if(optr == 2){
                        ans = op1 + op2;
                    }else if(optr == 3){
                        ans = op1*op2;
                    }else if(optr == 4){
                        ans = op1/op2;
                    }else if(optr == 5){
                        one = op1;
                        two = op2;
                        ans = one%two;
                    }
                    opd.push(ans);
                    opr.pop();
                    optr = opr.top();
                }
                opr.pop();//remove open bracket
           }else{
                //regular expressions //9 - 5 - 9
                curr = input[i];
                //what if its the first operator and the opr stack is empty
                if(opr.empty()){
                    opr.push(curr);
                }else{
                    optr = opr.top();
                    if(prt[curr] > prt[optr]){
                        opr.push(curr);
                    }else{
                        //curr <= optr in priority
                        while(prt[curr] <= prt[optr] && optr != 7 && !opr.empty()){
                            opr.pop();
                            op2 = opd.top();
                            opd.pop();
                            op1 = opd.top();
                            opd.pop();
                            if(optr == 1){
                                ans = op1 - op2;
                            }else if(optr == 2){
                                ans = op1 + op2;
                            }else if(optr == 3){
                                ans = op1*op2;
                            }else if(optr == 4){
                                ans = op1/op2;
                            }else if(optr == 5){
                                one = op1;
                                two = op2;
                                ans = one%two;
                            }
                            opd.push(ans);
                            if(!opr.empty()){
                               optr = opr.top(); 
                           }else{
                            break;
                           }
                        }
                        opr.push(input[i]); 
                    }
                }
                
           }
            
        }
    }

    while(!opr.empty()){
        optr = opr.top();
        opr.pop();
        op2 = opd.top();
        opd.pop();
        op1 = opd.top();
        opd.pop();
        if(optr == 1){
            ans = op1 - op2;
        }else if(optr == 2){
            ans = op1 + op2;
        }else if(optr == 3){
            ans = op1*op2;
        }else if(optr == 4){
            ans = op1/op2;
        }else if(optr == 5){
            one = op1;
            two = op2;
            ans = one%two;
        }
        opd.push(ans);
    }

    //can check for opd to be of size 1
    ans = opd.top();
    opd.pop();
    if(!opd.empty()){
        flag = 2;
        goto brk;
    }else{
        cout << ans;
    }
    
    brk : ;
    if(flag == 2){
        cout << "Malformed expression";
    }
    return 0;
}
