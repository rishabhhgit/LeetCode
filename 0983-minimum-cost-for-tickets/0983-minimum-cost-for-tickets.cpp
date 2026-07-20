class Solution {
public:
    int arr[366];
    int check(int i,vector<int>& days, vector<int>& costs){
        if(i>=days.size()) return 0;
        if(arr[i]!=-1) return arr[i];

        int day1=costs[0]+check(i+1,days,costs);

        int j=i;
        int max_days=7+days[j];

        while(j<days.size() && max_days>days[j]){
            j++;
        }

        int day2=costs[1]+check(j,days,costs);

        int k=i;
        max_days=days[k]+30;

        while(k<days.size() && max_days>days[k]){
            k++;
        }

        int day3=costs[2]+check(k,days,costs);

        return arr[i]=min({day1,day2,day3});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(arr,-1,sizeof(arr));
        return check(0,days,costs);
    }
};