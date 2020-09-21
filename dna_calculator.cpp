#include "dna_calculator.h"

//Constructs a DNA calculator, take file name as input
DNAcalculator::DNAcalculator(string fileName){
  file = fileName;
  lines = 0;
  sum = 0;
  numBigrams = 0;
  squares_sum = 0;
  countA = 0;
  countC = 0;
  countT = 0 ;
  countG = 0;

  countAA = 0;
  countAC = 0;
  countAT = 0;
  countAG = 0;

  countCA = 0;
  countCC = 0;
  countCT = 0;
  countCG = 0;

  countTA = 0;
  countTC = 0;
  countTT = 0;
  countTG = 0;

  countGA = 0;
  countGC = 0;
  countGT = 0;
  countGG = 0;

  probAA = 0;
  probAC = 0;
  probAT = 0;
  probAG = 0;

  probCA = 0;
  probCC = 0;
  probCT = 0;
  probCG = 0;

  probTA = 0;
  probTC = 0;
  probTT = 0;
  probTG = 0;

  probGA = 0;
  probGC = 0;
  probGT = 0;
  probGG = 0;
}

//Calculates the mean by dividing total nucleotides by number o lines
void DNAcalculator::calcMean(){
  mean = sum/lines;
}

//Calculates the probability of finding each nucleotide within the file
void DNAcalculator::calcNucleotideProbability(){
  probA = countA/sum;
  probC = countC/sum;
  probT = countT/sum;
  probG = countG/sum;
}

//Calculates the probability of finding each bigram within the file
void DNAcalculator::calcBigramProbability(){

  probAA = countAA/numBigrams;
  probAC = countAC/numBigrams;
  probAT = countAT/numBigrams;
  probAG = countAG/numBigrams;

  probCA = countCA/numBigrams;
  probCC = countCC/numBigrams;
  probCT = countCT/numBigrams;
  probCG = countCG/numBigrams;

  probTA = countTA/numBigrams;
  probTC = countTC/numBigrams;
  probTT = countTT/numBigrams;
  probTG = countTG/numBigrams;

  probGA = countGA/numBigrams;
  probGC = countGC/numBigrams;
  probGT = countGT/numBigrams;
  probGG = countGG/numBigrams;
}

//Calculates variance.
//Takes the squared sum and divides it by the amount of lines. Subtracts this
//quantity from the
void DNAcalculator::calcVariance(){
  double item1 = (sum*sum)/lines;
  double item2 = squares_sum;
  double item3 = item2 - item1;
  variance = item3/(lines);
}

//Calculates standard deviation.
//Takes the square root of the variance.
void DNAcalculator::calcStDeviation(){
  stdeviation = sqrt(variance);
}

//Processes the file line by line.
void DNAcalculator::processFile(){
  ifstream myfile (file);
  string line;
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      lines += 1;
      sum += line.length() - 1;
      squares_sum += (line.length()-1)*(line.length()-1);
      char current;
      char next;
      for(int i = 0; i < line.length()-1; i++){
        current = tolower(line.at(i));
        if(!isspace(current)){
          if(current == 'a'){
            countA += 1;
          }
          if(current == 'c'){
            countC += 1;
          }
          if(current == 't'){
            countT += 1;
          }
          if(current == 'g'){
            countG += 1;
          }
        }
      }
      //if the line length is odd, then add the first character to the end
      //of the string. this way, the last bigram is counted as the last
      //nucleotide + the first
      // cout << (line.length()-1)%2 << endl;
      string bigramline = line;
      if((bigramline.length()-1)%2 == 1){
        // cout << bigramline.at(0) << endl;
        bigramline.at(line.length()-1) = bigramline.at(0);
        // cout << bigramline << endl;
      }
      for(int i = 0; i < bigramline.length()-1; i += 2){
        string bigram = "";
        bigram += tolower(bigramline.at(i));
        bigram += tolower(bigramline.at(i+1));
        // cout << bigram << endl;
        if(bigram == "aa"){
          countAA += 1;
        }
        if(bigram == "ac"){
          countAC += 1;
        }
        if(bigram == "at"){
          countAT += 1;
        }
        if(bigram == "ag"){
          countAG += 1;
        }
        if(bigram == "ca"){
          countCA += 1;
        }
        if(bigram == "cc"){
          countCC += 1;
        }
        if(bigram == "ct"){
          countCT += 1;
        }
        if(bigram == "cg"){
          countCG += 1;
        }
        if(bigram == "ta"){
          countTA += 1;
        }
        if(bigram == "tc"){
          countTC += 1;
        }
        if(bigram == "tt"){
          countTT += 1;
        }
        if(bigram == "tg"){
          countTG += 1;
        }
        if(bigram == "ga"){
          countGA += 1;
        }
        if(bigram == "gc"){
          countGC += 1;
        }
        if(bigram == "gt"){
          countGT += 1;
        }
        if(bigram == "gg"){
          countGG += 1;
        }
        numBigrams += 1;
      }
    }
    myfile.close();
    calcMean();
    calcNucleotideProbability();
    calcBigramProbability();
    calcVariance();
    calcStDeviation();
  }
  else{
    cout << 0 << endl;
  }
}

//Runs the calculator by processing the input file
void DNAcalculator::runCalculator(){
  processFile();
}

//Chooses a random nucleotide. Chances are based of off the original
//probabilities
char DNAcalculator::randNucleotide(){
  double randIndex = rand();
  double randValue = randIndex/RAND_MAX;
  // cout << randValue << endl;
  if(0 < randValue && randValue < probA){
    // cout << "a" << endl;
    return 'a';
  }else if(probA < randValue && randValue < probA + probC){
    // cout << "c" << endl;
    return 'c';
  }else if(probA + probC < randValue && randValue < probA + probC + probT){
    // cout << "t" << endl;
    return 't';
  }else{
    // cout << "g" << endl;
    return 'g';
  }
}

//Builds a string of nucelotides of a specified length. Nucleotides are
//chosen at random through the rand function
string DNAcalculator::nucleotideString(int length){
  string str = "";
  for(int i = 0; i < length; ++i){
    str += randNucleotide();
  }
  return str;
}

//Generates an int value from a gaussian distribution taking into account
//the mean and variance of the original set of nucleotide strings
int DNAcalculator::gaussianLengthGenerator(){
  double randIndex = rand();
  double distrb1 = randIndex/RAND_MAX;
  double randIndex2 = rand();
  double distrb2 = randIndex2/RAND_MAX;
  double gaussian = sqrt(-2*(log(distrb1)))*cos(2*M_PI*distrb2);
  int length = ((stdeviation*gaussian) + mean);
  // cout << length << endl;
  return length;
}

//Print all information out to a new file
void DNAcalculator::outputToFile(){
  ofstream outFile;
  outFile.open("krishna.out.txt");
  outFile << "Krishna Narayan" << "\n";
  outFile << "Student ID: 2327205" << "\n";
  outFile << "Assignment 1: C++ Review -- CPSC350-03" << "\n";
  outFile << "Due: September 21, 2020" << "\n";
  outFile << "\n";

  outFile << "-----'" + file + "'" << " statistics summary-----" << "\n";
  outFile << "lines: " << lines << "\n";
  outFile << "sum: " << sum << "\n";
  outFile << "mean: " << mean << "\n";
  outFile << "variance: " << variance << "\n";
  outFile << "standard deviation: " << stdeviation << "\n";
  outFile << "\n";

  outFile << "-----nucleotide counter-----" << "\n";
  outFile << "A count: " << countA << "\n";
  outFile << "C count: " << countC << "\n";
  outFile << "T count: " << countT << "\n";
  outFile << "G count: " << countG << "\n";
  outFile << "\n";

  outFile << "-----nucleotide probability-----" << "\n";
  outFile << "A probability: " << probA << "\n";
  outFile << "C probability: " << probC << "\n";
  outFile << "T probability: " << probT << "\n";
  outFile << "G probability: " << probG << "\n";
  outFile << "\n";

  outFile << "-----bigram counter-----" << "\n";
  outFile << "AA probability: " << probAA << "\n";
  outFile << "AC probability: " << probAC << "\n";
  outFile << "AT probability: " << probAT << "\n";
  outFile << "AG probability: " << probAG << "\n";
  outFile << "\n";

  outFile << "CA probability: " << probCA << "\n";
  outFile << "CC probability: " << probCC << "\n";
  outFile << "CT probability: " << probCT << "\n";
  outFile << "CG probability: " << probCG << "\n";
  outFile << "\n";

  outFile << "TA probability: " << probTA << "\n";
  outFile << "TC probability: " << probTC << "\n";
  outFile << "TT probability: " << probTT << "\n";
  outFile << "TG probability: " << probTG << "\n";
  outFile << "\n";

  outFile << "GA probability: " << probGA << "\n";
  outFile << "GC probability: " << probGC << "\n";
  outFile << "GT probability: " << probGT << "\n";
  outFile << "GG probability: " << probGG << "\n";
  outFile << "\n";


  outFile << "-----DNA string generation-----" << "\n";
  for(int i = 0; i < 1000; ++i){
    outFile << nucleotideString(gaussianLengthGenerator()) << "\n";
  }

  // outFile << randNucleotideTester() << "\n";

  outFile.close();
}
