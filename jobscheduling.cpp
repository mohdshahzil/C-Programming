#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Job
{
    char id[6];
    int deadline;
    int profit;
};

void jobSequencing(Job arr[], int n);

int minValue(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    // Job arr[5] = {
    //     {"j1", 2,  60},
    //     {"j2", 1, 100},
    //     {"j3", 3,  20},
    //     {"j4", 2,  40},
    //     {"j5", 1,  20},
    // };

    // int n=5;
    int n;
    cout << "Enter the number of jobs : ";
    cin >> n;
    Job arr[5];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id;
        cin >> arr[i].deadline;
        cin >> arr[i].profit;
    }

    Job temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j + 1].profit > arr[j].profit)
            {
                // swapping
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i].profit << endl;
    }

    jobSequencing(arr, n);

    return 0;
}

void jobSequencing(Job arr[], int n)
{
    int timeSlot[100];

    int filledTimeSlot = 0;

    int dmax = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].deadline > dmax)
        {
            dmax = arr[i].deadline;
        }
    }

    for (int i = 1; i <= dmax; i++)
    {
        timeSlot[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        int k = minValue(dmax, arr[i - 1].deadline);
        while (k >= 1)
        {
            if (timeSlot[k] == -1)
            {
                timeSlot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        if (filledTimeSlot == dmax)
        {
            break;
        }
    }

    for (int i = 1; i <= dmax; i++)
    {
        cout << arr[timeSlot[i]].id << endl;
    }

    int maxProfit = 0;
    for (int i = 1; i <= dmax; i++)
    {
        maxProfit += arr[timeSlot[i]].profit;
    }

    cout << maxProfit << endl;
}