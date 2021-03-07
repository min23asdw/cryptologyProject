
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

string text;
unsigned int p, q, phi, n, key, pbkey, pvkey;
vector<int> cn;
vector<int> tn;
vector<int> mn;
vector<int> e;
vector<int> d;

void ClearScreen()
{
    cout << string(100, '\n');
}

void reset()
{
    cn.clear();
    tn.clear();
    mn.clear();
    e.clear();
    d.clear();
    p = 0;
    q = 0;
    phi = 0;
    n = 0;
    key = 0;
    pbkey = 0;
    pvkey = 0;
}

bool isValidNum(const string &input)
{
    for(unsigned int i = 0; i < input.size(); i++)
    {
        if(input[i] > 57 || input[i] < 48)
            return false;
    }
    return true;
}

int gcd(unsigned int a, unsigned int b)
{
    if (a < b)
    {
        unsigned int temp = a;
        a = b;
        b = temp;
    }
    unsigned int k;

    for (unsigned int i = 0; i < b; i++)
    {
        k = b - i;
        if (a % k == 0 && b % k == 0)
        {
            return k;
        }
    }
    return 1;
}

bool prime(unsigned int n)
{
    if (n == 1)
    {
        return false;
    }

    for (unsigned int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int mod(int x, int y, int z)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y % 2 == 0)
    {
        int u = mod(x, y / 2, z);
        return (u * u) % z;
    }
    else
    {
        return ((x % z) * mod(x, y - 1, z)) % z;
    }
}
void find_e()
{
    int k = 0;
    for (unsigned int i = 2; i < phi; i++)
    {
        if (gcd(phi, i) == 1)
        {
            e.insert(e.begin() + k, i);
            k++;
        }
    }
}
void find_d()
{
    int count;
    for (unsigned int i = 0; i < e.size(); i++)
    {
        count = 0;
        while (true)
        {
            if ((count * e[i]) % phi == 1)
            {
                d.push_back(count);
                break;
            }
            count++;
        }
    }
}
void show_de()
{
    cout << "VALUE OF e AND d\nNUMBER\te\td\n";
    for (unsigned int i = 0; i < e.size(); i++)
    {
        cout << "[" << i + 1 << "]\t" << e[i] << "\t" << d[i] << "\n";
    }
}
void encrypt()
{
    for (unsigned int i = 0; i < tn.size(); i++)
    {
        cn.push_back(mod(tn[i], e[key - 1], n));
    }
}

void showencryptedtext()
{

    char c[tn.size() + 1];
    for (unsigned int i = 0; i < tn.size(); i++)
    {
        c[i] = cn[i];
    }
    c[tn.size() + 1] = '\0';
    cout << "ENCRYPTED MESSAGES : " << c << "\n";
}
void decrypt()
{
    for (unsigned int i = 0; i < cn.size(); i++)
    {
        mn.push_back(mod(cn[i], d[key - 1], n));
    }
}

void showdecryptedtext()
{

    char c[mn.size() + 1];
    for (unsigned int i = 0; i < mn.size(); i++)
    {
        c[i] = mn[i];
    }
    c[mn.size() + 1] = '\0';
    cout << "DECRYPTED MESSAGES : " << c << "\n";
}

int main()
{
    string menu;
    do
    {

        cout << "RSA (CRYPTOSYSTEM)\n||||||||||||||||||||||\nSELECT YOUR OPTION\n[01] START RSA (CRYPTOSYSTEM)\n[02] EXIT\nINPUT YOUR OPTION : ";
        getline(cin, menu);
        if (menu == "01")
        {
            string input;
            cout << "INPUT FIRST PRIMENUMBER : ";
            while (true)
            {
                getline(cin, input);
                if(isValidNum(input))
                {
                    p = stoi(input);
                    if (prime(p))
                    {
                        break;
                    }
                }
                system("CLS");
                cout << "TRY AGAIN PLEASE INPUT PRIMENUMBER\nINPUT FIRST PRIMENUMBER : ";
            }
            cout << "INPUT SECOND PRIMENUMBER : ";
            while (true)
            {
                getline(cin, input);
                if(isValidNum(input))
                {
                    q = stoi(input);
                    if (prime(q) && p != q)
                    {
                        break;
                    }
                }
                cout << "TRY AGAIN PLEASE INPUT PRIMENUMBER\nINPUT SECOND PRIMENUMBER : ";
            }
            cout << "INPUT YOUR MESSAGES : ";
            getline(cin, text);
            unsigned int i;
            for (i = 0; i <= text.length(); i++)
            {
                tn.push_back(text[i]);
            }
            n = p * q;
            phi = (p - 1) * (q - 1);
            cout << "n = " << n << "\nphi = " << phi << "\n";
            find_e();
            find_d();
            show_de();
            while (true)
            {
                cout << "\nCHOOSE NUMBER OF KEY : ";
                getline(cin, input);
                
                if(isValidNum(input))
                {
                    key = stoi(input);
                    if (key > 0 && key <= e.size())
                    {
                        break;
                    }
                }
                cout << "TRY AGAIN PLEASE CHOOSE NUMBER OF KEY : ";
            }

            encrypt();
            showencryptedtext();
            decrypt();
            showdecryptedtext();
            cout << "\n";
            reset();
        }
        else if (menu == "02")
        {
            break;
        }
        else
        {
            system("CLS");
            cout << "\n#########INCORRECT INPUT#########\n\n";
        }
    } while (true);
}