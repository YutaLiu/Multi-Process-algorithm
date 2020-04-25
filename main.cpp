//
//  main.cpp
//  A2
//
//  Created by 劉育達 on 2020/4/22.
//  Copyright © 2020 劉育達. All rights reserved.
//

#include <iostream>

using namespace std;
int FindMax(int arr[], int n)
{
    int result = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] > result){
            result = arr[i];
        }
    }
    return result;
}
  
bool Count(int time, int K, int job[], int n)
{
    int cnt = 1;
    int curr_time = 0;
    for (int i = 0; i < n;)
    {
        if (curr_time + job[i] > time) {
            curr_time = 0;
            cnt++;
        }
        else {
            curr_time += job[i];
            i++;
        }
    }
    return (cnt <= K);
}

int Computation(int thread, int job[], int n)
{
    int end = 0, start = 0;
    for (int i = 0; i < n; ++i){
        end += job[i];
    }
    int ans = end;
    int job_max = FindMax(job, n);
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid >= job_max && Count(mid, thread, job, n))
        {
            ans = min(ans, mid);  
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
  
int main()
{
    int job[] = {3,10,3,4};
    int thread = 3;
    printf("ans = %d\n", Computation(thread, job, sizeof(job)/sizeof(job[0])));
    return 0;
}

