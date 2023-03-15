#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Symbol{
public:
  Symbol() {
    height = 9;
    width = 7;
    symbol = '0';
    Draw();
  };
  Symbol(char sym) {
    height = 9;
    width = 7;
    symbol = sym;
    Draw();  
  }
  Symbol(char sym, int h, int w){
    height = h;
    width = w;
    symbol = sym;
    Draw(); 
  }
  void Update(char sym){
    symbol = sym;
    Draw();
  }
  char GetSymbolAt(int i, int j){
    return display[i][j];
  }
  void Print() {
    for(int i = 0;i<display.size();++i){
      for(int j = 0;j<display[i].size(); ++j){
        cout<<display[i][j];
      }
      cout<<endl;
    }  
  };
private:
  char symbol;
  int height;
  int width;
  vector<vector<char> > display;

  void Draw() {
    Clear();
    switch(symbol){
      case '0':
        Line(1, width-1, 0, 0);
        Line(1, width-1, height-1, 0);
        Line(1, height/2, 0, 1);
        Line(height/2+1, height-1, 0, 1);
        Line(1, height/2, width-1, 1);
        Line(height/2+1, height-1, width-1, 1);
        break;
    case '1':
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '2':
      Line(1, width-1, 0, 0);
      Line(1, width-1, height/2, 0);
      Line(1, width-1, height-1, 0);
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, 0, 1);
      break;
    case '3':
      Line(1, width-1, 0, 0);
      Line(1, width-1, height/2, 0);
      Line(1, width-1, height-1, 0);
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '4':
      Line(1, width-1, height/2, 0);
      Line(1, height/2, 0, 1);
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '5':
      Line(1, width-1, 0, 0);
      Line(1, width-1, height/2, 0);
      Line(1, width-1, height-1, 0);
      Line(1, height/2, 0, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '6':
      Line(1, width-1, 0, 0);
      Line(1, width-1, height/2, 0);
      Line(1, width-1, height-1, 0);
      Line(1, height/2, 0, 1);
      Line(height/2+1, height-1, 0, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '7':
      Line(1, width-1, 0, 0);
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '8':
      Line(1, width-1, 0, 0);
      Line(1, width-1, height/2, 0);
      Line(1, width-1, height-1, 0);
      Line(1, height/2, 0, 1);
      Line(height/2+1, height-1, 0, 1);
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    case '9':
      Line(1, width-1, 0, 0);
      Line(1, width-1, height/2, 0);
      Line(1, width-1, height-1, 0);
      Line(1, height/2, 0, 1);
      Line(1, height/2, width-1, 1);
      Line(height/2+1, height-1, width-1, 1);
      break;
    }

  };

  void Clear() {
    display.assign(height, vector<char>(width, ' '));
  };

  void Line(int start, int end, int h, int dir) {
    ///0 - Горизонтально на строке h    
    if(dir == 0){
      for(int i = start;i<end;++i){
        display[h][i] = '@';
      }
    }
    ///1 - Вертикально на столбце h    
    if(dir == 1){
      for(int i = start;i<end;++i){
        display[i][h] = '@';
      }
    }
  };
};

class Clock{
public:
  Clock() {
    height = 9;
    width = 7;
    h1 = Symbol();
    h2 = Symbol();
    m1 = Symbol();
    m2 = Symbol();
    Clear();
  };
  Clock(int h, int w) {
    height = h;
    width = w;
    h1 = Symbol('0', h, w);
    h2 = Symbol('0', h, w);
    m1 = Symbol('0', h, w);
    m2 = Symbol('0', h, w);
    Clear();
  };
  void Update(int h, int m) {
    minutes = m;
    hours = h;
    h1.Update(h/10 + '0');
    h2.Update(h%10 + '0');
    m1.Update(m/10 + '0');
    m2.Update(m%10 + '0');
    Clear();
    Draw();
  };
  void Print() {
    for(int i = 0;i<display.size();++i){
      for(int j = 0;j<display[i].size(); ++j){
        cout<<display[i][j];
      }
      cout<<endl;
    }  
  };
private:
  int minutes;
  int hours;
  int height;
  int width;
  Symbol h1, h2, m1, m2;
  vector<vector<char> > display;

  void Clear() {
    display.assign(height, vector<char>(width * 4 + 8, ' '));
  };
  
  void Draw() {
    display[height/2 - 1][width*2 + 3] = '@';
    display[height/2 + 1][width*2 + 3] = '@';
    for(int i = 0;i<height;++i){
      for(int j = 0;j<width;++j){
        display[i][j] = h1.GetSymbolAt(i, j);
      }
      for(int j = 0;j<width;++j){
        display[i][j + width + 1] = h2.GetSymbolAt(i, j);
      }
      for(int j = 0;j<width;++j){
        display[i][j + width*2 + 6] = m1.GetSymbolAt(i, j);
      }
      for(int j = 0;j<width;++j){
        display[i][j + width*3 + 7] = m2.GetSymbolAt(i, j);
      }
    }
  };
};

int main() {
  Clock cl;
  time_t now = time(0);
  tm* ltm = localtime(&now);  
  int h = ltm->tm_hour, m = ltm->tm_min;
  cl.Update(h, m);
  cl.Print();
  while(true){
    now = time(0);
    ltm = localtime(&now);
    if(h != ltm->tm_hour || m != ltm->tm_min){
      h = ltm->tm_hour, m = ltm->tm_min;
      cl.Update(h, m);
      cl.Print();
    }
  }
}