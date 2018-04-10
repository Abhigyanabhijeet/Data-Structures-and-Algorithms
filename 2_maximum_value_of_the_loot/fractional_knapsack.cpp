#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
   int n=weights.size();
   int sum=0;
   double totalValue=0.0;
   for(int l=0;l<n;l++){
    sum+=weights[l];
    totalValue+=values[l];
   }
   if(capacity>sum){
    return totalValue;
   }
   for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        if(values[j]/(double)weights[j]>values[j+1]/(double)weights[j+1]){
            int temp=values[j];
            values[j]=values[j+1];
            values[j+1]=temp;

            temp=weights[j];
            weights[j]=weights[j+1];
            weights[j+1]=temp;
        }
    }
   }
  int index=n-1;
 // for(int k=0;k<n;k++){
  //  std::cout<<values[k]<<"\t"<<weights[k]<<"\n";
 // }

  while(capacity>0){
    if(capacity>=weights[index]){
        capacity-=weights[index];
        weights[index]=0;
        value+=values[index];
   // std::cout<<"here"<<value<<"\n";
    }
    else{
        value+=(values[index]/((double)weights[index]))*capacity;
        weights[index]-=capacity;
        capacity=0;
   // std::cout<<"there"<<value<<"\n";;
    }

    if (weights[index]==0){
        index--;
    }

  }
return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
