class Solution {
public:
    void nextPermutation(vector<int>& a) {
        //find the pivot
        int pivot = -1;
        int n=a.size();
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
            pivot=i;
            break;
        }
        }
        if(pivot==-1){
            reverse(a.begin(), a.end()); // in place changes
            return;
        }

        //2nd step : next larger element
        for (int i=n-1; i>pivot; i--){
            if(a[i] > a[pivot]){
                swap(a[i], a[pivot]);
                break;
            }
        }

        //3rd step : reverse (piv+1 to n-1)
        //reverse(a.begin()+pivot+1, a.end())

        int i=pivot+1, j=n-1;
        while(i<=j){
            swap(a[i++],a[j--]);
        }
    }
};