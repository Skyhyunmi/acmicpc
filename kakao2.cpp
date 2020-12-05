#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
struct ans{
    string str;
    int cnt;
};
vector<ans> temp;

void fun(string str,string make, int cur,int end){
    if(cur == end) {
        for(int i=0;i<temp.size();i++){
            if(!(temp[i].str).compare(str)) temp[i].cnt++;
            else temp.push_back({str,1});
            return;
        }
    }
    fun(str,make,cur+1,end);
    
    fun(str,make.append(str,cur,cur+1),cur+1,end);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    cout<< "?";
    for(int i=0;i<orders.size();i++){
        for(int j=0;j<course.size();j++){
            string make;
            fun(orders[i],make,0,course[j]);
        }
    }
    for(int i=0;i<temp.size();i++){
        if(temp[i].cnt>=2) answer.push_back(temp[i].str);
    }
    return answer;
}
int main(){
    printf("?");
    vector<string> orders={"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course={2,3,4};
    vector<string> answer = solution(orders,course);
    for(int i=0;i<answer.size();i++) cout << answer[i]<< " ";
}