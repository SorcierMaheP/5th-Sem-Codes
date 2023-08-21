#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int totaltime, starttime;
class Process
{
    int AT;
    int BT;
    string name;
    int WT;
    int TAT;
    int spantime;

public:
    void get(int i)
    {
        cout << "Enter process name." << endl;
        cin >> name;
        cout << "Enter the arrival time and burst time for process " << name << endl;
        cin >> AT >> BT;
    }
    void put()
    {
        cout << setw(7) << name << setw(4) << AT << setw(4) << setw(4) << BT << setw(4) << WT << setw(4) << TAT << endl;
    }
    friend void bubblesort(Process[], int);
    friend void FCFS(Process[], int);
    friend void AvgCalc(Process[], int, float &, float &);
    void Gantt()
    {
        for (int j = 0; j < 2 * BT; j++)
        {
            if (j == BT)
                cout << name;
            else
                cout << "  ";
        }
        cout << "|";
    }
    void ProcessTimes()
    {
        for (int j = 0; j < 2 * BT; j++)
        {
            if (j == BT)
                cout << setfill(' ') << setw(name.length()) << ' ';
            else
                cout << "  ";
        }
        cout << spantime;
    }
};
void bubblesort(Process P[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int exch = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if ((P[j].AT > P[j + 1].AT) or (P[j].AT == P[j + 1].AT && P[j].name > P[j + 1].name))
            {
                Process temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
                exch++;
            }
        }
        if (!exch)
            break;
    }
}
void FCFS(Process P[], int n)
{
    totaltime = starttime = P[0].AT;
    for (int i = 0; i < n; i++)
    {
        P[i].WT = totaltime - P[i].AT;
        P[i].TAT = P[i].WT + P[i].BT;
        totaltime += P[i].BT;
        P[i].spantime = totaltime;
    }
}
void AvgCalc(Process P[], int n, float &AWT, float &ATAT)
{
    for (int i = 0; i < n; i++)
    {
        AWT += P[i].WT;
        ATAT += P[i].TAT;
    }
    AWT /= n;
    ATAT /= n;
}
int main()
{
    Process P[100];
    int n;
    cout << "Enter the number of processes." << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
        P[i].get(i);
    bubblesort(P, n);
    FCFS(P, n);
    cout << setw(7) << "Process" << setw(4) << "AT" << setw(4) << "BT" << setw(4) << "WT" << setw(4) << "TAT" << endl;
    for (int i = 0; i < n; i++)
        P[i].put();
    cout << endl;
    float AWT, ATAT;
    AvgCalc(P, n, AWT, ATAT);
    cout << "AWT: " << AWT << endl
         << "ATAT: " << ATAT;
    cout << endl
         << "|";
    for (int i = 0; i < n; i++)
        P[i].Gantt();
    cout << endl;
    cout << starttime;
    for (int i = 0; i < n; i++)
        P[i].ProcessTimes();
    cout << endl;
    return 0;
}