#include <iostream>
int count=0;
int get_change(int m) {
  if (m>=10){
    count+=1;
    return(get_change(m-10));
  }
  else if(m>=5){
    count+=1;
    return(get_change(m-5));
  }
  else if(m>=1){
    count+=1;
    return(get_change(m-1));
  }
  else{
    return (count);
  }
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
