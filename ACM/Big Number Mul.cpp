#include <iostream>
#include <string>
using namespace std;
string reverse(string s);
int compare(string s1,string s2);
string clear(string);
string add(string s1,string s2);
string sub(string s1,string s2);
string mul(string s1,string s2);
int main(int argc, char** argv) {
	string str1,str2;
	cin >> str1 >> str2;
	cout << str1 << " + " << str2 << " = " << add(str1,str2) << endl;
	cout << str1 << " - " << str2 << " = " << sub(str1,str2) << endl;
	cout << str1 << " * " << str2 << " = " << mul(str1,str2) << endl;
	// cout << mul(str1,str2);
	return 0;
}
string reverse(string s) {
	string revStr = "";
	for(int i = s.size() - 1;i >= 0;i--) {
		revStr += s[i];
	}
	return revStr;
}
int compare(string s1,string s2) {
	int s1_size = s1.size();
	int s2_size = s2.size();
	if(s1_size > s2_size) return 1;
	else if(s1_size < s2_size) return -1;
	else {
		return s1.compare(s2);
	}
}
string clear(string s) {
	string str="";
	bool sign = true;
	for(int i=0;i < s.size();i++) {
		if(sign) {
			if(s[i]!='0') {
				sign = false;
				str += s[i];
			}
		} else {
			str += s[i];
		}
	}
	return str;
}
string add(string s1,string s2) {
	bool sign1 = true,sign2 = true;
	string str1,str2,result;
	if(s1[0] == '-') {
		sign1 = false;
		str1 = reverse(clear(s1.substr(1)));
	} else {
		str1 = reverse(clear(s1));
	}
	if(s2[0] == '-') {
		sign2 = false;
		str2 = reverse(clear(s2.substr(1)));
	} else {
		str2 = reverse(clear(s2));
	}
	// cout << str1 <<" " << str2 << endl;
	if(sign1 == sign2) {
		int length1 = str1.size();
		int length2 = str2.size();
		if(length1 < length2) {
			str1.swap(str2);
			length1 ^= length2;
			length2 ^= length1;
			length1 ^= length2; 
		}
		result = "";
		char num = 0,add = 0;
		for(int i = 0;i < length1;i++) {
			if(i >= length2) {
				num = str1[i] - '0';
			} else {
				num = str1[i] + str2[i] - 2*'0';
			}
			if(add) {
				num++;
				add = 0;
			}
			if(num > 9) {
				num -= 10;
				add = 1;
			}
			result += num + '0';
		}
		if(add) result += '1';
		if(!sign1) result += '-';
		return reverse(result);
	} else {
		int big = compare(reverse(str1),reverse(str2));
		bool resultSign;
		if(big >= 0) {
			resultSign = sign1;
		} else {
			resultSign = sign2;
			str1.swap(str2);
		}
		// cout << resultSign << endl;
		// cout << str1 << " " << str2 << endl;
		int length1 = str1.size();
		int length2 = str2.size();
		result = "";
		char num = 0,add = 0;
		string tem = "";
		for(int i = 0;i < length1;i++) {
			if(i >= length2) {
				num = str1[i] - '0';
			} else {
				num = str1[i] - str2[i];
			}
			if(add) {
				num--;
				add = 0;
			}
			if(num < 0) {
				num += 10;
				add = 1;
			}
			if(num == 0) {
				tem += num + '0';
			} else {
				result += tem;
				tem = "";
				result += num + '0';
			}
			
		}
		if(!resultSign) result += '-';
		return reverse(result);
	}

}
string sub(string s1,string s2) {
	string str;
	if(s2[0] == '-') {
		str = s2.substr(1);
	} else {
		str = "-" + s2;
	}
	return add(s1,str);
}
string mul(string s1,string s2) {
	if(s1 == ""||s1 == "0") return "0";
	if(s2 == ""||s2 == "0") return "0";
	if(s1.size() < 5) {
		// cout << s1 << "*" << s2 << "=" << to_string(stol(s1)*stol(s2)) << endl;
		return to_string(stol(s1)*stol(s2));
	}
	bool sign1 = true,sign2 = true;
	string str1,str2,result;
	if(s1[0] == '-') {
		sign1 = false;
		str1 = reverse(s1.substr(1));
	} else {
		str1 = reverse(s1);
	}
	if(s2[0] == '-') {
		sign2 = false;
		str2 = reverse(s2.substr(1));
	} else {
		str2 = reverse(s2);
	}
	int subLen = str1.size() - str2.size();
	if(subLen > 0) {
		str2.append(subLen,'0');
	} else {
		subLen = -subLen;
		if(subLen > 0) {
			str1.append(subLen,'0');
		}
	}
	str1 = reverse(str1);
	str2 = reverse(str2);
	// cout << str1 << " " << str2 << endl;
	string a,b,c,d;
	
	if(str1.size()%2!=0) str1 = "0" + str1;
	a = str1.substr(0,str1.size()/2);
	b = str1.substr(str1.size()/2);
	if(str2.size()%2!=0) str2 = "0" + str2;
	c = str2.substr(0,str2.size()/2);
	d = str2.substr(str2.size()/2);

	string t1,t2,t3;
	string ac = mul(a,c);
	string bd = mul(b,d);
	// cout << "ac=" << ac << endl;
	// cout << "bd=" << bd << endl;
	t1 = mul(sub(a,b),sub(d,c));
	// cout << "t1 " << t1 << endl;
	t2 = add(add(t1,ac),bd);
	// cout << add(t1,ac) << " +" << bd << "=" << t2 << endl;
	// cout << "t2 " << t2 << endl;
	string tem1 = ac.append(str1.size(),'0');
	// cout <<"tem1 " <<  tem1 << endl;
	string tem2 = t2.append(str1.size()-str1.size()/2,'0');
	// cout << "tem2" <<  tem2 << endl;
	t3 = add(add(tem1,tem2),bd);
	result = (sign1 != sign2) ? "-" : "";
	bool sign = false;
	for(int i=0;i < t3.size();i++) {
		if(!sign) {
			if(t3[i] != '0') {
				sign = true;
				result += t3[i];
			}
		} else {
			result += t3[i];
		}
	}
	// cout << s1 << "*" << s2 << "=" << result << endl;
	return result;
}