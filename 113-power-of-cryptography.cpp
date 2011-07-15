#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n, result, left, right;
  double p, tmp;

  while (cin >> n){
    cin >> p;

    if (n == 1){
      cout << (int) p << endl;
      continue;
    }

    left = 0;
    right = 1000000000;
    result = (left + right) / 2;

    while ( true ){
      tmp = pow( (double) result, (double) n );
      //cout << left << " " << right << " " << tmp << " | ";
      if (tmp == p ) break;
      else if ( tmp < p ) left = result + 1;
      else if ( tmp > p ) right = result - 1;
      result = (left + right) / 2;
    }
    cout << result << endl;
  }
  return 0;
}
