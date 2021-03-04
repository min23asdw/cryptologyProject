
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

string text;
int p, q, phi, n, key, pbkey, pvkey;
vector<int> cn;
vector<int> tn;
vector<int> mn;
vector<int> e;
vector<int> d;

void ClearScreen()
{
    cout << string(100, '\n');
}

int gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int k;

    for (int i = 0; i < b; i++)
    {
        k = b - i;
        if (a % k == 0 && b % k == 0)
        {
            return k;
        }
    }
    return 1;
}

bool prime(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
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
    for (int i = 2; i < phi; i++)
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
    for (int i = 0; i < e.size(); i++)
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
    for (int i = 0; i < e.size(); i++)
    {
        cout << "[" << i + 1 << "]\t" << e[i] << "\t" << d[i] << "\n";
    }
}
void encrypt()
{
    for (int i = 0; i < tn.size(); i++)
    {
        cn.push_back(mod(tn[i], e[key - 1], n));
    }
}

void showencryptedtext()
{

    char c[tn.size() + 1];
    for (int i = 0; i < tn.size(); i++)
    {
        c[i] = cn[i];
    }
    c[tn.size() + 1] = '\0';
    cout << "ENCRYPTED MESSAGES : " << c << "\n";
}
void decrypt()
{
    for (int i = 0; i < cn.size(); i++)
    {
        mn.push_back(mod(cn[i], d[key - 1], n));
    }
}

void showdecryptedtext()
{

    char c[mn.size() + 1];
    for (int i = 0; i < mn.size(); i++)
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
        cin >> menu;
        if (menu == "01")
        {
            cout << "INPUT FIRST PRIMENUMBER : ";
            while (true)
            {
                cin >> p;
                if (prime(p))
                {
                    break;
                }
                system ("CLS");
                cout << "TRY AGAIN PLEASE INPUT PRIMENUMBER\nINPUT FIRST PRIMENUMBER : ";
            }
            cout << "INPUT SECOND PRIMENUMBER : ";
            while (true)
            {
                cin >> q;
                if (prime(q) && p != q)
                {
                    break;
                }
                cout << "TRY AGAIN PLEASE INPUT PRIMENUMBER\nINPUT SECOND PRIMENUMBER : ";
            }
            cout << "INPUT YOUR MESSAGES : ";
            cin.ignore();
            getline(cin, text);
            int i;
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
                cin >> key;
                if (key > 0 && key <= e.size())
                {
                    break;
                }
                cout << "TRY AGAIN PLEASE CHOOSE NUMBER OF KEY : ";
            }

            encrypt();
            showencryptedtext();
            decrypt();
            showdecryptedtext();
            cin >> n;
        }
        else if (menu == "02")
        {
            break;
        }
        else
        {
            system ("CLS");
            cout << "\n#########INCORRECT INPUT#########\n\n";
        }
    } while (true);
}