#include <iostream>
#include <iomanip>
#include <string>
#include <time.h> 
#include <vector>
#include <numeric>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;


struct Student
{
    string name;
    string lastName;
    int n;
    vector <int> nd;
    int egz;
    double final;

};

string YN()
{
    bool isCorrect = true;
    string yn;

    do
    {
        cin >> yn;
        if (yn.length() == 1 && (tolower(yn[0]) == 'y' || tolower(yn[0]) == 'n')) isCorrect = true;
        else
        {
            cout << "Error! Enter letter 'y' (yes) or 'n' (no): ";
            isCorrect = false;
        }
    } while (!isCorrect);
    return yn;
}

void Sorting(vector <int>& nd)
{
    sort(nd.begin(), nd.end());
}

bool CompareLastNames(Student& a,  Student& b)
{
    return a.lastName < b.lastName;
}

void Sorting(vector <Student>& S)
{
    sort(S.begin(), S.end(), CompareLastNames); 
}

bool isCorrectNumber(string temp, int maxGrade, int minGrade)
{
    bool isCorrectValue = true;

    for (int i = 0; i < temp.length(); i++)
    {
        if (!isdigit(temp[i]))
        {   isCorrectValue = false;
            cout << "Error! ";
            break;
        }
    }
    if (isCorrectValue == true && stoi(temp) < 1 && maxGrade == 0 && minGrade == 0)
    {   isCorrectValue = false;
        cout << "Error! Number must be greater than 0! ";
    }

    else if (isCorrectValue == true && (stoi(temp) < minGrade || stoi(temp) > maxGrade) && maxGrade != 0)
    {   isCorrectValue = false;
        cout << "Error! Number must be in range 0 to 10! ";
    }
    return isCorrectValue;
}

int CorrectNumber(string input, int maxGrade, int minGrade, bool stop)
{
    int x;
    string temp;

    do
    {   cout << input;
        cin >> temp;
        if (temp == "stop" && stop == true) break;
    } while (!isCorrectNumber(temp, maxGrade, minGrade));

    if (temp != "stop")x = stoi(temp);
    else x = -1;
    return x;
}

int CorrectNumber(string input)
{
    int a = CorrectNumber(input, 0, 0, false);
    return a;
}

void Stop(string input, int maxGrade, int minGrade, vector<int>& nd, int& n)
{
    bool stop = true;
    int temp;
    n = 0;

    while (stop)
    {   temp = CorrectNumber(input, maxGrade, minGrade, true);
        if (temp != -1)
        { nd.push_back(temp);
            n++;
        }
        else
        {   if (n == 0)cout << "Error! Enter at least one number! ";
            else stop = false;
        }
    }
}

int RandomGrade()
{
    int grade;
    grade = 1 + rand() % ((10 + 1) - 1);
    return grade;
}

bool isCorrectString(string var)
{
    bool isCorrect = true;

    for (int i = 0; i < var.length(); i++)
    {   if (isalpha(var[i]) == false)
        {isCorrect = false;
            cout << "Error! Name must contain only letters! " << endl;
            break;
        }
        else isCorrect = true;
    }
    return isCorrect;
}

string CorrectString(int x, string input)
{
    string var;
    do
    {   cout << "Enter " << x + 1 << " student's" << input << " : ";
        cin >> var;
    } while (!isCorrectString(var));

    return var;
}

int Sum(int n, vector<int> nd)
{ 
    int sum;
    sum = accumulate(nd.begin(), nd.end(), 0);
    return sum;
}

double Average(int n, vector <int> nd, int egz)
{
    double average = 0.4 * (Sum(n, nd) * 1.0 / n) + 0.6 * egz;
    return average;
}

int Max(vector <Student>& S, int s, bool isTrue)
{
    int max = 0;

    for (int i = 0; i < s; i++)
    {
        if (S[i].lastName.length() > max && isTrue) max = S[i].lastName.length();
        else if (S[i].name.length() > max && !isTrue) max = S[i].name.length();
    }
    return max;
}

double Median(vector <int>nd, int n)
{
    double median;
    Sorting(nd);
    if (n % 2 != 0) median = nd[n / 2];
    else median = (nd[n / 2 - 1] + nd[n / 2]) / 2.0;

    return median;
}

void Print(vector <Student> S, int s, string output)
{
    Sorting(S);
    string line = "";
    int maxLastName = Max(S, s, true);
    int maxName = Max(S, s, false);
    line.append(maxLastName + maxName + 40, '-');
    cout << endl << left << setw(maxLastName + 10) << "Last name" << setw(maxName + 10) << "Name" << "Final (" << output << ")" << endl << line << endl;
    for (int i = 0; i < s; i++) cout << left << setw(maxLastName + 10) << S[i].lastName << setw(maxName + 10) << S[i].name << fixed << setprecision(2) << S[i].final << endl;
    cout << endl;
}

void MainFunction(int i, vector <Student>& S, char yn, bool final)
{
    string inputName = " name";
    string inputLastName = " last name";
    string input_n = "Enter the number of homework tasks: ";
    string input_nd = "Enter homework grades: ";
    string input_egz = "Enter exam grade: ";

    int maxGrade = 10, minGrade = 1;
    double median;

    S[i].name = CorrectString(i, inputName);
    S[i].lastName = CorrectString(i, inputLastName);
    S[i].name[0] = toupper(S[i].name[0]);
    S[i].lastName[0] = toupper(S[i].lastName[0]);

    cout << "Do you want to enter the number of grades? (y/n) ";
    char ynGrades = (YN()[0]);

    if (ynGrades == 'y')
    {   S[i].n = CorrectNumber(input_n);
        cout << "Do you want to enter grades manually? (y/n) ";
        ynGrades = (YN()[0]);
        if (ynGrades == 'y') { for (int j = 0; j < S[i].n; j++) S[i].nd.push_back(CorrectNumber(input_nd, maxGrade, minGrade, false)); }
        
        else{   for (int j = 0; j < S[i].n; j++) S[i].nd.push_back(RandomGrade());
                cout << "Generated grades: ";
                for (int j = 0; j < S[i].n - 1; j++) cout << S[i].nd[j] << ", ";
                cout << S[i].nd[S[i].n - 1] << "." << endl;
            }
    }
    else
    {   int j = 0;
        cout << "Enter grades (to end the cycle, enter 'stop'). " << endl;
        Stop(input_nd, maxGrade, minGrade, S[i].nd, S[i].n);
    }

    cout << "Do you want to enter exam grade manually? (y/n) ";
    ynGrades = (YN()[0]);

    if (ynGrades == 'y')  S[i].egz = CorrectNumber(input_egz, maxGrade, minGrade, false);
    else
    {   S[i].egz = RandomGrade();
        cout << "Generated exam grade: " << S[i].egz << endl;
    }

    if (final)  S[i].final = Average(S[i].n, S[i].nd, S[i].egz);
    else  S[i].final = Median(S[i].nd, S[i].n);
}

void ManualInput(int s, vector <Student>& S, char yn, bool final)
{
    for (int i = 0; i < s; i++) MainFunction(i, S, yn, final);
}

void UnknownInput(int& s, vector <Student>& S, char yn, bool final)
{
    bool Continue = true;

    while (Continue)
    {   MainFunction(s, S, yn, final);
        cout << "Do you want to add another student? (y/n) ";
        char ynContinue = (YN()[0]);
        if (ynContinue == 'n')
        {   Continue = false;
            break;
        }
        else
        {   s++;
            S.resize(s + 1);
        }
    }
}

int main()
{
    srand(time(0));
    
    string input_s = "Enter the number of students: ";
    string outputMedian = "median";
    string outputAverage = "mean";
    int s = 0;
    vector <Student> S;
    bool final;

    cout << "Do you want the final grade to be mean (average)? (y/n) ";
    char yn = (YN())[0];

    if (yn == 'y') final = true;
    else final = false;
    
    //cout << "Do you want to enter data manually? (y/n) ";
    //yn = (YN())[0];
    if (yn)
    {   cout << "Do you want to enter the number of students? (y/n) ";
        yn = (YN())[0];

        if (yn == 'y')
        {   s = CorrectNumber(input_s);
            S.resize(s + 1);
            ManualInput(s, S, yn, final);
        }
        else
        {   S.resize(s + 1);
            UnknownInput(s, S, yn, final);
            s++;
        }
    }

   /* else
    {
	IMU DUOMENISIS .txt
    }*/

   /* cout << "Do you want the final grade to be mean (average)? (y/n) ";
    yn = (YN())[0];

    if (yn == 'y')  S[i].final = Average(S[i].n, S[i].nd, S[i].egz);
    else  S[i].final = Median(S[i].nd, S[i].n);
    */
    if (final)Print(S, s, outputAverage);
    else Print(S, s, outputMedian);

    S.clear();

    return 0;
}