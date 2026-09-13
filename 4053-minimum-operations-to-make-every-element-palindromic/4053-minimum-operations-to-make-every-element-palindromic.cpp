class Solution {
public:
vector<int>pale,palo;

void f(){
    for(int len =1;len<=9;len++){
        int half= (len+1)/2;
        int s = (len==1)?1:pow(10,half-1);
        int e= pow(10,half);

        for(int x= s;x<e;x++){
            int num =x;
            int t= (len%2 ==1)?x/10:x;
            while(t>0){
                num = num*10+t%10;
                t/=10;
            }
            if(num>1e9) continue;
            if(num%2) palo.push_back(num);
            else pale.push_back(num);
        }
    }
}

int mindiff(int num,vector<int>&pals){
    auto le =lower_bound(pals.begin(),pals.end(),num);
    int ld  = INT_MAX;
    if(le!=pals.end()){
        ld = abs(*le-num);
    }
    if(le!=pals.begin()){
        ld = min(ld,abs(*(le-1)-num));
    }
    return ld;
}
    long long minOperations(vector<int>& nums) {
        long long res=0;
        f();

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int diff;
            if(mp.count(nums[i])){
                diff=mp[nums[i]];
            }
            else{
                diff=(nums[i]%2==0)? mindiff(nums[i],pale):mindiff(nums[i],palo);
            
            mp[nums[i]]=diff;
            }
            res+=diff/2;
        }
        return res;
    
    }
};