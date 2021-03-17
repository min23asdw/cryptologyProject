#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>

using std::string;
using std::vector;

class RSA
{
public:
	string text;
	unsigned int p, q, phi, n, key, pbkey, pvkey;
	vector<int> cn;
	vector<int> tn;
	vector<int> mn;
	vector<int> e;
	vector<int> d;

private:
	void ClearScreen();
	void reset();
	bool isValidNum(const string& input);
	int gcd(unsigned int a, unsigned int b);
	bool prime(unsigned int n);
	int mod(int x, int y, int z);
	void find_e();
	void find_d();
	void show_de();
	void encrypt();
	void showencryptedtext();
	void decrypt();
	void showdecryptedtext();
	void run();
};