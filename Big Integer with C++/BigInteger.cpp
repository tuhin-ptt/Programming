#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> BigInt;


void Set(BigInt &a) //removes leading zeros from a number.
{
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}


bool operator > (BigInt a, BigInt b)
{
    if(a.size() > b.size())
        return true;
    else if(b.size()>a.size())
        return false;
    else
    {
        int i;
        for(i=a.size()-1; i>=0; i--)  //last element of a is most the significant digit.
        {
            if(a[i]>b[i])
                return true;
            else if(a[i]<b[i])
                return false;
        }
        if(i == -1) return false;  //when both are same. looped till i=0
    }
}



bool operator >= (BigInt a, BigInt b)
{
    if(a.size() > b.size())
        return true;
    else if(b.size()>a.size())
        return false;
    else
    {
        int i;
        for(i=a.size()-1; i>=0; i--)  //last element of a is most the significant digit.
        {
            if(a[i]>b[i])
                return true;
            else if(a[i]<b[i])
                return false;
        }
        if(i == -1) return true;  //when both are same. looped till i=0
    }
}



bool operator < (BigInt a, BigInt b)
{
    if(a.size() > b.size())
        return false;
    else if(b.size()>a.size())
        return true;
    else
    {
        int i;
        for(i=a.size()-1; i>=0; i--)  //last element of a is most the significant digit.
        {
            if(a[i]>b[i])
                return false;
            else if(a[i]<b[i])
                return true;
        }
        if(i == -1) return false;  //when both are same. looped till i=0
    }
}



bool operator <= (BigInt a, BigInt b)
{
    if(a.size() > b.size())
        return false;
    else if(b.size()>a.size())
        return true;
    else
    {
        int i;
        for(i=a.size()-1; i>=0; i--)  //last element of a is most the significant digit.
        {
            if(a[i]>b[i])
                return false;
            else if(a[i]<b[i])
                return true;
        }
        if(i == -1) return true;  //when both are same. looped till i=0
    }
}


bool operator == (BigInt a, BigInt b)
{
    if(a.size() > b.size())
        return false;
    else if(b.size()>a.size())
        return false;
    else
    {
        int i;
        for(i=a.size()-1; i>=0; i--)  //last element of a is most the significant digit.
        {
            if(a[i]>b[i])
                return false;
            else if(a[i]<b[i])
                return false;
        }
        if(i == -1) return true;  //when both are same. looped till i=0
    }
}



void operator << (ostream &out, BigInt a)
{
    for(int i=a.size()-1; i>=0; i--)
    {
        cout<<a[i];
    }
}



int char_to_int(char ch)
{
    switch(ch)
    {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return -1;
    }
}



BigInt Integer(string s)
{
    BigInt ans;
    if(s.size() == 0)
    {
        return ans;
    }
    for(int i=s.size()-1; i>=0; i--)
    {
        ans.push_back(char_to_int(s[i]));  //returns a number in reverse order.
    }
    return ans;
}



BigInt Integer(int a)
{
    BigInt ans;
    if(a==0)
    {
        ans.push_back(0);
        return ans;
    }
    while(a>0)
    {
        ans.push_back(a%10);
        a = a/10;
    }
    return ans;
}



BigInt operator + (BigInt a, BigInt b)  //operator overloading
{
    if(a.size()>b.size())
    {
        int diff = a.size() - b.size();
        for(int i=1; i<=diff; i++)
            b.push_back(0); //b is saved in reverse order. so, adding more zero at the end means adding zeros before the number.
    }
    else if(b.size()>a.size())
    {
        int diff = b.size() - a.size();
        for(int i=1; i<=diff; i++)
            a.push_back(0);  //a is saved in reverse order. so, adding more zero at the end means adding zeros before the number.
    }
    BigInt ans;
    int carry = 0;
    for(int i=0; i<max(a.size(), b.size()); i++)
    {
        int res = a[i] + b[i] + carry;  //for example res = 12
        carry = 0; //reset carry
        carry = res/10;  //then carry = 1
        res = res%10;  //and res = 2 will be added on current position
        ans.push_back(res);
    }
    if(carry) ans.push_back(carry);  //if all digits are added and still there is a carry.
    return ans;

}



BigInt operator - (BigInt a, BigInt b)
{
    char sign = '?';  //if a is greater then sign is '+' otherwise sign is '-'
    if(a.size()>b.size())
    {
        sign = '+';
        int diff = a.size() - b.size();
        for(int i=1; i<=diff; i++)
            b.push_back(0);
    }
    else if(b.size()>a.size())
    {
        sign = '-';
        int diff = b.size() - a.size();
        for(int i=1; i<=diff; i++)
            a.push_back(0);
    }
    else
    {
        for(int i=a.size()-1; i>=0; i--)  //last element of a is most the significant digit.
        {
            if(a[i]>b[i])
            {
                sign = '+';
                break;
            }
            else if(a[i]<b[i])
            {
                sign = '-';
                break;
            }
        }
    }

    BigInt ans;
    int borrow = 0;

    if(sign == '?') //if two numbers are equal.
    {
       ans.push_back(0);
       return ans;
    }

    if(sign == '+')  //i.e. if a is greater.
    {
        for(int i=0; i<a.size(); i++)
        {
            //amra jevabe khata kolome biog kori arki.
            int res;
            if(a[i] >= (b[i] + borrow)){
                res = a[i] - (b[i] + borrow);
                borrow = 0;
            }
            else{
                res = (a[i]+10) - (b[i] + borrow);
                borrow = 1;
            }
            ans.push_back(res);
        }
        Set(ans);
        return ans;  //there is no overflow borrow in subtraction
    }
    if(sign == '-')  //i.e. if b is greater.
    {
        for(int i=0; i<b.size(); i++)
        {
            int res;
            if(b[i] >= (a[i] + borrow)){
                res = b[i] - (a[i] + borrow);
                borrow = 0;
            }
            else{
                res = (b[i]+10) - (a[i] + borrow);
                borrow = 1;
            }
            ans.push_back(res);
        }
        Set(ans);
        ans[ans.size()-1] = -ans[ans.size()-1]; /*since b is greater hence result will be negative.
        to do this add a negative sign to most significant digit.*/
        return ans;
    }
}



void operator ++ (BigInt &a)  //prefix increment.
{
    BigInt one;
    one.push_back(1);
    a = a + one;
}



void operator -- (BigInt &a)  //prefix increment.
{
    BigInt one;
    one.push_back(1);
    a = a - one;
}


BigInt operator * (BigInt a, BigInt b)
{
    BigInt ans(a.size() + b.size(), 0);

    for(int i=0; i<b.size(); i++)  //for every digit of b
    {
        int mul_carry = 0;
        int sum_carry = 0;
        int j;
        for(j=0; j<a.size(); j++) //multiplies one digit of b with all digits of a.
        {
            // digit wise multiplication
            int res = b[i]*a[j] + mul_carry;
            mul_carry = res/10;
            res = res%10;

            // digit wise addition
            int temp = ans[i+j]+res+sum_carry;
            ans[i+j] = temp%10;  /*this array adds multiplied result digit wise. index i+j is used which left shifts the addition
            process after every round of multiplication similar way as we use zero or cross to shift left after every round of
            multiplication. here insertion and addition are done simultaneously.*/
            sum_carry = temp/10;
        }
        if(mul_carry)
        {
            ans[i+j] += mul_carry; //adds overflow carry of multiplication to the next digit. here value of j = 1 + previous j
        }
        if(sum_carry)

        {
            ans[i+j] += sum_carry;//adds overflow carry of addition to the next digit.
        }

    }
    Set(ans);
    return ans;
}



BigInt operator / (BigInt a, int b)  // returns BigInt/int.
{
    BigInt ans;
    if(b==0)
    {
        ans.push_back(-1);
        return ans;
    }

    int i = a.size()-1;
    int temp = a[i];  //taking first digit of a. remember that a is in reverse order so last digit is the most significant digit.
    while(temp<b) //taking a part of the number a that is larger then divisor b. amra vag jevabe kori arki.
    {
        temp = temp*10 + a[--i];
    }
    while(i>=0)
    {
        int res = temp/b;
        ans.push_back(res);  //quotient. it is not in reverse order.
        temp = (temp%b)*10 + a[--i]; //bring next digit from dividend into reminder to divide again.
    }
    if(ans.size()==0) ans.push_back(0);

    int s = ans.size()-1;
    for(int i=0; i<ans.size()/2; i++)  //Since BigInt stores a number in reverse order hence we are arranging ans in reverse.
    {
        int temp = ans[i];
        ans[i] = ans[s-i];
        ans[s-i] = temp;
    }
    return ans;
}



BigInt operator / (BigInt a, BigInt b)  // returns BigInt/BigInt.   function overloading.
{
    BigInt ans;
    BigInt zero;
    zero.push_back(0);
    if(b == zero)
    {
        ans.push_back(-1);
        return ans;
    }
    else
    {
        ans.push_back(0);
        for( ; a>=b; a = a - b, ++ans);
        return ans;
    }

}



int main()
{
    string number1 = "106106106";
    string number2 = "203040";
    BigInt a = Integer(number1);
    BigInt b = Integer(number2);
    BigInt res = a / b;
    cout<<res;
    cout<<endl;
    res = a + b;
    cout<<res;
    cout<<endl;
    res = a - b;
    cout<<res;
    cout<<endl;
    res = a * b;
    cout<<res;
    cout<<endl;
    ++a;
    cout<<a;
    cout<<endl;
    --b;
    cout<<b;
    cout<<endl;
    //you can also compare two BigInt number with >, <, >=, <=, ==
}

