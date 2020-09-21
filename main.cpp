#include "dna_calculator.h"

//main -- intially takes a command line argument as input, and then uses
//cin to continue processing files.
int main(int argc, char **argv){
  cout << "FINAL TEST" << endl;
  if(argc != 2){
    cout << "command line requires a file input" << endl;
    cout << "example: " << endl;
    cout << "'./assignment1.exe sequences.txt'" << endl;
  }
  else{
    DNAcalculator *calc1 = new DNAcalculator(argv[1]);
    calc1->runCalculator();
    calc1->outputToFile();
    cout << "your list has been processed." << endl;
    delete calc1;
    string runListCommand, fileName;
    bool run = true;
    while(run == true){
      cout << "run another list?" << "\n";
      cin >> runListCommand;
      if(runListCommand != "n" && runListCommand != "no" && runListCommand != "N"
        && runListCommand != "NO"){
        cout << "enter a file name: " << "\n";
        cin >> fileName;
        DNAcalculator *calc2 = new DNAcalculator(fileName);
        calc2->runCalculator();
        calc2->outputToFile();
        cout << "your list has been processed." << endl;
        delete calc2;
      }else{
        cout << "DONE" << endl;
        break;
      }
    }
  }
  return 0;
}
