#include <iostream>
#include <vector>

using namespace std;

void move_to_initial( vector<int>* v, int i, int start ){
  while ( v[i].back() != start ){
    v[v[i].back()].push_back( v[i].back() );
    v[i].pop_back();
  }
  return;
}

void move_onto(int a, int b, vector<int>* v, int length){
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == a ) {
        move_to_initial( v, i, a );
        v[i].pop_back();
        break;
      }
      if ( v[i][j] == b ){
        move_to_initial( v, i, b );
        v[i].push_back( a );
        break;
      }
    }
  }
  return;
}

void move_over(int a, int b, vector<int>* v, int length){
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == a ) {
        move_to_initial( v, i, a );
        v[i].pop_back();
        break;
      }
      if ( v[i][j] == b ){
        v[i].push_back( a );
        break;
      }
    }
  }
  return;
}

void pile_onto(int a, int b, vector<int>* v, int length){
  vector<int> copy;
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == a ){
        copy = vector<int>( v[i].begin()+j, v[i].end() );
        v[i].erase( v[i].begin()+j, v[i].end() );
      }
    }
  }
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == b ){
        move_to_initial( v, i, b );
        v[i].insert( v[i].end(), copy.begin(), copy.end() );
        break;
      }
    }
  }
  return;
}

void pile_over(int a, int b, vector<int>* v, int length){
  vector<int> copy;
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == a ){
        copy = vector<int>( v[i].begin()+j, v[i].end() );
        v[i].erase( v[i].begin()+j, v[i].end() );
      }
    }
  }
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == b ){
        v[i].insert( v[i].end(), copy.begin(), copy.end() );
        break;
      }
    }
  }
  return;
}

bool in_the_same_pile(int a, int b, vector<int>* v, int length ){
  bool includes_a = false, includes_b = false;
  for (int i=0; i<length; i++){
    for (int j=0; j<v[i].size(); j++){
      if ( v[i][j] == a ) includes_a = true;
      if ( v[i][j] == b ) includes_b = true;
    }
    if (includes_a || includes_b) return includes_a && includes_b;
  }
}

void print_blocks( vector<int>* v, int length ){
  for (int i=0; i<length; i++){
    cout << i << ":";
    for (int j=0; j<v[i].size(); j++){
      cout << " " << v[i][j];
    }
    cout << endl;
  }
  return;
}

int main(){
  vector<int> blocks[25];
  int blocks_length;
  int a, b;
  string command1, command2;

  cin >> blocks_length;

  for (int i=0; i<blocks_length; i++){
    blocks[i].push_back( i );
  }


  while (1){
    cin >> command1;
    if ( command1 == "quit" ) break;
    cin >> a >> command2 >> b;

    if ( a == b || in_the_same_pile(a, b, blocks, blocks_length ) ) continue;
    else if( command1+'_'+command2 == "move_onto" ) move_onto(a, b, blocks, blocks_length);
    else if( command1+'_'+command2 == "move_over" ) move_over(a, b, blocks, blocks_length);
    else if( command1+'_'+command2 == "pile_onto" ) pile_onto(a, b, blocks, blocks_length);
    else if( command1+'_'+command2 == "pile_over" ) pile_over(a, b, blocks, blocks_length);
  }

  print_blocks( blocks, blocks_length );
  return 0;
}
