#include "std_lib_facilities.h"

	template <typename T> 
	struct S
	{
	private:
		T val;
	public:
		S (T t):val{t} {}

		S& operator=(const T& t) {val=t; return *this;}
		T& get() {return val;}
		const T& get_const() const {return val;} 
	};
	
	template <typename T>
	void read_val(T& v) {cin >> v;}

int main(){

	S<int> s_int(15);
	cout << s_int.get() << endl;
	
	S<char> s_char('f');
	cout << s_char.get() << endl;

	S<double> s_double(5.5);
	cout << s_double.get() << endl;

	S<string> s_string("mumumu");
	cout << s_string.get() << endl;

	S<vector<int>>s_vector({1,2,3});
	vector<int> A = s_vector.get();
	for(auto x:A)
		cout << x << " ";
	cout << endl;

	cout << "Give a char: ";
	read_val(s_char.get());
	cout << s_char.get() << endl;

	cout << "Give a string: ";
	read_val(s_string.get());
	cout << s_string.get() << endl;

	cout<<"Give a double: ";
	read_val(s_double.get());
	cout<<s_double.get()<<endl;

return 0;
}
