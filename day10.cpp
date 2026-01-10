#include <iostream>
using namespace std;

void sort012(int arr[], int n)
{
    // code here
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j]==i)
            {
            cout<<arr[j]<<", ";
            }
        }
    }
}
int main()
{
    int arr[] ={0,2,1,2,0,1};
    int size = 6;
    sort012(arr,6);
    
    return 0;
}
