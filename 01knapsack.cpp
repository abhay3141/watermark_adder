#include <bits/stdc++.h>

using namespace std;

int t[10001][301];

 int solve(int w, int n, int arr[])
    {
        if (w == 0 || n == 0)
            {
                return 0;
            }
        else{

        if (t[w][n] != -1)
        {
            return t[w][n];
        }   
            else
            {
                if(w>=arr[n-1]){
                t[w][n] = max(arr[n - 1] + solve(w - arr[n - 1], n - 1, arr), solve(w, n - 1, arr));
                return t[w][n];
                }
                else{
                    t[w][n] = solve(w,n-1,arr);
                    return t[w][n];
                }
            }
        }
    }   
int main()
{
    int w;
    int n;
    cin >> w >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(t,-1,sizeof(t));
    int result = solve(w, n, a);
    cout << result << endl;
    return 0;
}