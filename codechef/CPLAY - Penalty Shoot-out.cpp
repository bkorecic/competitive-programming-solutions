#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
  //CPLAY - Penalty Shoot-out
  string linea;
  while(getline(cin,linea)){
    
    int team1 = 0;
    int team2 = 0;
    
    int tirosteam1 = 0;
    int tirosteam2 = 0;
    
    int flag = 1; //1 -> TEAM1          -1 -> TEAM2
    
    for(int i=0; i<linea.length(); i++){
      
      if(flag==1){
        tirosteam1++;
      }
      else{
        tirosteam2++;
      }
      
      if(linea[i] == '1' && flag == 1){
        team1++;
      }
      else if(linea[i] == '1' && flag == -1){
        team2++;
      }
      
      if(i<10){
        
        if(5-tirosteam1 < team2-team1){
          cout << "TEAM-B " << i+1 << endl;
          break;
        }
        if(5-tirosteam2 < team1-team2){
          cout << "TEAM-A " << i+1 << endl;
          break;
        }
        
      }
      
      else{
        
        if(tirosteam1==tirosteam2 && team1>team2){
          cout << "TEAM-A " << i+1 << endl;
          break;
        }
        if(tirosteam1==tirosteam2 && team2>team1){
          cout << "TEAM-B " << i+1 << endl;
          break;
        }
        
      }
      
      flag = flag * -1;
      
      if(i==linea.length()-1){
        cout << "TIE" << endl;
      }
      
    }
    
  }
  
  return 0;
}
