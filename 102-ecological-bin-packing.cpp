#include <iostream>
#define BROWN 0
#define GREEN 1
#define CLEAR 2


using namespace std;

int main(){
  int bottles[3][3];
  string result;
  int min, tmp;

  while (cin >> tmp){
    bottles[0][0] = tmp;
    for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        if (i==0 && j==0) continue;
        cin >> bottles[i][j];
      }
    }

    min = bottles[0][BROWN]+bottles[1][BROWN]+bottles[0][CLEAR]+bottles[2][CLEAR]+bottles[1][GREEN]+bottles[2][GREEN];
    result = "GCB";

    if ((tmp = bottles[0][BROWN]+bottles[2][BROWN]+bottles[0][CLEAR]+bottles[1][CLEAR]+bottles[1][GREEN]+bottles[2][GREEN]) <= min ){
      min = tmp;
      result = "GBC";
    }
    if ((tmp = bottles[0][BROWN]+bottles[1][BROWN]+bottles[1][CLEAR]+bottles[2][CLEAR]+bottles[0][GREEN]+bottles[2][GREEN]) <= min ){
      min = tmp;
      result = "CGB";
    }
    if ((tmp = bottles[0][BROWN]+bottles[2][BROWN]+bottles[1][CLEAR]+bottles[2][CLEAR]+bottles[0][GREEN]+bottles[1][GREEN]) <= min ){
      min = tmp;
      result = "CBG";
    }
    if ((tmp = bottles[1][BROWN]+bottles[2][BROWN]+bottles[0][CLEAR]+bottles[1][CLEAR]+bottles[0][GREEN]+bottles[2][GREEN]) <= min ){
      min = tmp;
      result = "BGC";
    }
    if ((tmp = bottles[1][BROWN]+bottles[2][BROWN]+bottles[0][CLEAR]+bottles[2][CLEAR]+bottles[0][GREEN]+bottles[1][GREEN]) <= min ){
      min = tmp;
      result = "BCG";
    }
    cout << result << " " << min << endl;
  }
  return 0;
}
