#include "std_lib_facilities.h"
#include "string"
#include "iostream"
#include "stdexcept"
#include "vector"

class Person{
	public:
		Person(){};
		Person(string f, string l, int a): f{f}, l{l}, a{a} {
			if(a<0 || a>=150){
				throw runtime_error("Invalid age");
			}
			string n= f+l;
			for(int i=0; i<n.length(); i++){
				if(n[i]==';' || n[i]==':' || n[i]=='"' || n[i]=='$' || n[i]=='['|| n[i]==']'|| n[i]=='*'|| n[i]=='&'|| n[i]=='^' || n[i]=='%'|| n[i]=='@'|| n[i]=='!'|| n[i]=='#'|| n[i]=='\''){
					throw runtime_error("Invalid name");
				}
			}
		
		};
		string first() {return f;}
		string last() {return l;}
		int age() { return a; }
	private:
		
		string f, l;
		int a;
};

ostream & operator<<(ostream & os, Person & s){  return os << s.first() <<" "<< s.last() << " "<<s.age()<<endl; }
istream & operator>>(istream & is, Person & s){ 
	string f,l;
	int a;
	is >> f >> l >>a;
	s=Person(f,l,a);
	return is;
	}

int main(){

 Person p=Person("Goofy","hmm",63);
 cout<<p.first() <<" "<<p.last() <<" "<< p.age() << endl;

 Person p2;
 cin>>p2;
 cout<<p2;

 vector<Person> vec;
 for(Person p; cin>>p;){
 	if(p.first()=="end") break;
 	vec.push_back(p);
 }
 for(Person p : vec){
 	cout<<p<<endl;
 }

}
