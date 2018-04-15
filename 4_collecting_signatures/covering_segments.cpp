#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

int findMinimum(vector<Segment> &segments){
int n=segments.size();
int result=99999999-1;
for(int i=0;i<n;i++){
    if(segments[i].end<result){
        result=segments[i].end;
    }
}
return result;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
//  for (size_t i = 0; i < segments.size(); ++i) {
//    points.push_back(segments[i].start);
//    points.push_back(segments[i].end);
//  }
 while(segments.size()>0){
    int r=findMinimum(segments);
    points.push_back(r);
//    std::cout<<r<<"\n";
    for(int j=0;j<segments.size();){
        if(r>=segments[j].start && r<=segments[j].end){
          segments.erase(segments.begin()+j);
        }
        else{
            j+=1;
        }
    }
 }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
