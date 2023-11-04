#include <bits/stdc++.h>
using namespace std;

void Two_complement(string &ans)
{
    int i;
    int n = ans.length();
    for (i = n - 1; i >= 0; i--)
        if (ans[i] == '1')
            break;
    if (i == -1)
        ans = '1' + ans;
    for (int k = i - 1; k >= 0; k--)
    {
        if (ans[k] == '1')
            ans[k] = '0';
        else
            ans[k] = '1';
    }
}

string Airthmetic_shift(string D)
{
    string ans = "";
    ans = ans + D[0];
    for (int i = 0; i < D.size(); i++)
    {
        ans = ans + D[i];
    }
    return ans;
}

string Addition(string a, string b)
{
    string ans = "";
       reverse(a.begin(),a.end());
       reverse(b.begin(),b.end());
       if(a.size() > b.size())
       swap(a,b);
       int carry = 0;
       for(int i=0;i<a.size();i++)
       {
           int add = ((a[i]-'0') + (b[i] - '0') + carry);
           carry = add/2;
           add = add%2;
           ans += (add + '0');
       }
       for(int i=a.size();i<b.size();i++)
       {
           int add = ((b[i] - '0') + carry);
           carry = add/2;
           add = add % 2;
           ans += (add + '0');
       }
       reverse(ans.begin(),ans.end());
       return ans;
}
void Convert_number_in_Binary(int first_number, int second_number, string &first, string &second)
{
    int n1 = first_number;
    int n2 = second_number;
    if (first_number < 0 && second_number < 0)
    {
        first_number = first_number * (-1);
        second_number = second_number * (-1);
    }
    else if (second_number < 0)
    {
        second_number = second_number * (-1);
    }
    else if (first_number < 0)
    {

        first_number = first_number * (-1);
    }
    while (first_number != 0)
    {
        int n = first_number % 2;
        first.push_back(n + '0');
        first_number = first_number / 2;
    }
    while (second_number != 0)
    {
        int n = second_number % 2;
        second.push_back(n + '0');
        second_number = second_number / 2;
    }
    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());
    if (first.length() > second.length())
    {
        for (int i = second.length(); i < first.length(); i++)
        {
            second = '0' + second;
        }
    }
    else
    {
        for (int i = first.length(); i < second.length(); i++)
        {
            first = '0' + first;
        }
    }
    first = '0' + first;
    second = '0' + second;
    int n = first.length();
    if (n1 < 0 && n2 < 0)
    {
        Two_complement(first);
        Two_complement(second);
    }
    else if (n1 < 0)
    {
        Two_complement(first);
    }
    else if (n2 < 0)
    {
        Two_complement(second);
    }
    return;
}
void final_answer(string ans, int n)
{
    int n1 = 0, i, flag = 0;
    if (ans[0] == '1')
    {
        cout<<"Result in AC Register is (-)ve :"<<"\t"<<ans<<endl;
        flag = 1;
        Two_complement(ans);
    }
    for (int i = 0; i < n; i++)
    {
        n1 = (n1 * 2) + (ans[i] - '0');
    }
    if (flag == 1)
    {
        ans[0] = '1';
        n1 = n1 * (-1);
    }
    cout<<endl;
    cout << "Multiplication of Number is:"
         << "\t" << ans << endl;
    cout << "Decimal equivalent is:"
         << "\t" << n1 <<endl;;
}
int main()
{
    string A, temp, str1{}, r = "", Q{}, B{}, e = "", v = "";
    int first_number, second_number;
    cout << "Enter Multiplicand: ";
    cin >> first_number;
    cout << "Enter Multiplier: ";
    cin >> second_number;
    Convert_number_in_Binary(first_number, second_number, B, Q);
    cout << "Multiplicand is (BR Register) :"
         << "\t" << B << endl;
    str1 = B;
    Two_complement(str1);
    cout << "Two's Complement of Multiplicand is (BR + 1):"
         << "\t" << str1 << endl;
    cout << "Multiplier is (QR Register):"
         << "\t" << Q << endl;
    // Multiplicand Store in Q -- first_number
    //  Multiplier stored in B -- second_number
    cout << "Booth Algorithm Result :" << endl;
    cout << "Operation"
         << "\t"
         << "\t"
         << "AC Result"
         << "\t"
         << "\t"
         << "QR Register"
         << "\t"
         << "\t"
         << "Q(n+1) Bit" << endl;
    temp = Q;
    Q = Q + '0';
    for (int i = 0; i < Q.size() - 1; i++)
    {
        A = A + '0';
    }
    cout << "Initial"
         << "\t"
         << "\t"
         << "\t" << A << "\t"
         << "\t"
         << "\t" << temp << "\t"
         << "\t"
         << "\t"
         << "0" << endl;
    A = A + temp;

    for (int i = Q.size() - 1; i >= 1; i--)
    {
        int flag = 0;
        // subtract(BR).
        if (Q[i - 1] == '1' && Q[i] == '0')
        {
            r = "";
            for (int i = 0; i < (A.size() / 2); i++)
            {
                r = r + A[i];
            }
            r = Addition(r, str1);
            for (int i = 0; i < r.size(); i++)
            {
                flag = 1;
                A[i] = r[i];
            }
        }
        //Addition of (BR)
        else if (Q[i - 1] == '0' && Q[i] == '1')
        {
            r = "";
            for (int i = 0; i < (A.size() / 2); i++)
            {
                r = r + A[i];
            }
            r = Addition(r, B);
            cout << "Addition (BR)"
                 << "\t"
                 << "\t" << B << endl;
            cout << "             "
                 << "\t"
                 << "\t" << r << endl;
            for (int i = 0; i < r.size(); i++)
            {
                A[i] = r[i];
            }
        }

        if (flag == 1)
        {
            cout << "Subtract (BR)"
                 << "\t"
                 << "\t" << str1 << endl;
            cout << "             "
                 << "\t"
                 << "\t" << r << endl;
        }
        A = Airthmetic_shift(A);
        for (int i = 0; i < (A.size() / 2); i++)
        {
            e = e + A[i];
        }
        for (int i = (A.size() / 2); i < A.size() - 1; i++)
        {
            v = v + A[i];
        }
        cout << "Airthmetic Shift(ashr)"
             << "\t" << e << "\t"
             << "\t"
             << "\t" << v << "\t"
             << "\t"
             << "\t" << A[A.size() - 1] << endl;
        A.pop_back();
        e = "";
        v = "";
    }
    int y = A.length();
    final_answer(A, A.length());

    return 0;
}