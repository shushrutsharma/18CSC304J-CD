#include<bits/stdc++.h>

using namespace std;


int prio(char c) {
	if(c == '*') return 3;
	if(c == '.') return 2;
	if(c == '+') return 1;
	return 0;
}

string infix_to_postfix(string s) {
	stack<char> st;
	st.push('(');
	s += ')';
	int n = s.size();
	string ret;
	for(int i=0; i<n; i++) {
		if(prio(s[i])) {
			while(!st.empty()) {
				if(prio(st.top()) <= prio(s[i])) {
					st.push(s[i]);
					break;
				}
				ret += st.top();
				st.pop();
			}
		} else if(s[i] == '(') {
			st.push(s[i]);
		} else if(s[i] == ')') {
			while(!st.empty()) {
				if(st.top() == '(') {
					st.pop();
					break;
				}
				ret += st.top();
				st.pop();
			}
		} else if(isalpha(s[i])) {
			ret += s[i];
		}
	}
	return ret;	
}
int nodes = 0;
int ALPHABET_SZ = 3;
vector<vector<vector<int>>> transitions(30,vector<vector<int>>(ALPHABET_SZ+1,vector<int>(0)));

pair<int,int> handlePlus(int ss1,int es1,int ss2,int es2)
{
    cout<<"i was called : "<<endl;
    transitions[nodes+1][ALPHABET_SZ].push_back(ss1);
    transitions[nodes+1][ALPHABET_SZ].push_back(ss2);
    transitions[es1][ALPHABET_SZ].push_back(nodes+2);
    transitions[es2][ALPHABET_SZ].push_back(nodes+2);
    nodes = nodes+2;
    return make_pair(nodes-1,nodes);
}

pair<int,int> handleStar(int ss,int es)
{
    cout<<"* was called : "<<endl;
    transitions[es][ALPHABET_SZ].push_back(ss);
    transitions[nodes+1][ALPHABET_SZ].push_back(ss);
    transitions[nodes+1][ALPHABET_SZ].push_back(nodes+2);
    transitions[es][ALPHABET_SZ].push_back(nodes+2);
    nodes = nodes+2;
    return make_pair(nodes-1,nodes);
}

pair<int,int> handleDot(int ss2,int es2,int ss1,int es1)
{
    // cout<<"ss1 : "<<ss1;
    // cout<<"es1 : "<<es1;
    // cout<<"ss2 : "<<ss2;
    // cout<<"es2 : "<<es2;
    
    // cout<<". was called :"<<endl;
    transitions[es1][ALPHABET_SZ].push_back(ss2);
    return make_pair(ss1,es2);
}

pair<int,int> handleSingle(int alphabet)
{
    transitions[nodes+1][alphabet-'a'].push_back(nodes+2);
    nodes = nodes+2;
    return make_pair(nodes-1,nodes);
}
void postfix_to_e_nfa(string s)
{
    stack<pair<int,int>> st;
    for(int i=0;i<s.length();i++)
    {
        // cout<<"NODES : "<<nodes<<endl;
        if(s[i] == '*')
        {
            pair<int,int> r = st.top();
            st.pop();
            st.push(handleStar(r.first,r.second));
        }
        else if(s[i]=='+')
        {
            pair<int,int> r1 = st.top();
            st.pop();
            pair<int,int> r2 = st.top();
            st.pop();
            st.push(handlePlus(r1.first,r1.second,r2.first,r2.second));
        }
        else if(s[i]=='.')
        {
            cout<<"NODES BEFORE CALL : "<<nodes<<endl;
            pair<int,int> r1 = st.top();
            st.pop();
            pair<int,int> r2 = st.top();
            st.pop();
            st.push(handleDot(r1.first,r1.second,r2.first,r2.second));
            cout<<" NODES AFTER CALL : "<<nodes<<endl;
        }
        else
        {
            st.push(handleSingle(s[i]));
        }
    }
}

int main()
{
    cout << "Enter regular expression : ";
	string regex; cin >> regex;
	regex = infix_to_postfix(regex);
    // cout<<"REGULAR  EXPRESSION : "<<regex<<endl;
    postfix_to_e_nfa(regex);
    for(int i=0;i<=nodes;i++)
    {
        for(int j=0;j<=ALPHABET_SZ;j++)
        {
            char c = 'a';
            for(int k=0;k<transitions[i][j].size();k++)
                cout<<"q["<<i<<","<<(j==ALPHABET_SZ?'E':char(c+j))<<"] -> "<<transitions[i][j][k]<<"  "<<endl;
        }
    }
    return 0;
}