#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = new_id;
    transform(new_id.begin(),new_id.end(), new_id.begin(),
    [](unsigned char c) {return tolower(c);});
    transform(new_id.begin(),new_id.end(), new_id.begin(),
    [](unsigned char c) {
        if(c>='a'&&c<='z') return c;
        else if(c>='0'&&c<='9') return c;
        else if (c=='-' || c=='_' || c=='.') return c;
        return '';});
    return answer;
}