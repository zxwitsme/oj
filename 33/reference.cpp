 #include <iostream>
 using namespace std;
 
 int find_num_of_ways(int num_of_eggs,int num_of_baskets); //传进鸡蛋的数量与篮子的数量返回放置鸡蛋方法的种数
 
 int main(){
     int t;
     cin>>t;
     while(t--){
         int num_of_eggs,num_of_baskets;
         cin>>num_of_eggs>>num_of_baskets;
         cout<<find_num_of_ways(num_of_eggs,num_of_baskets)<<endl;
     }
     return 0;
 }
 int find_num_of_ways(int num_of_eggs,int num_of_baskets){
     if(num_of_baskets==1||num_of_eggs==1) //只有1个篮子或1个鸡蛋时只有1种放置方法
         return 1;
     if(num_of_baskets>=num_of_eggs) //篮子多余鸡蛋时等于每个篮子放一个鸡蛋的情况（1种）加上把鸡蛋放到比鸡蛋数量少1个篮子的情况数
         return 1+find_num_of_ways(num_of_eggs,num_of_eggs-1);
     else
         return find_num_of_ways(num_of_eggs-num_of_baskets,num_of_baskets)//每个篮子放一个鸡蛋后剩下num_of_eggs-num_of_baskets个鸡蛋放到num_of_baskets个篮子里
                 +find_num_of_ways(num_of_eggs,num_of_baskets-1);//不是全部篮子用上的情况
 }
