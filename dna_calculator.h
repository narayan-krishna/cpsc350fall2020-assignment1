#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

//Creates an object that takes in a file with multiple DNA lines as inputs.
//Returns a series of statistics as well as 1000 lines of DNA nucleotides that,
//in their generation, follow the relative mean and variance of the given input.
//Also calculates probabilities of bigrams and nucleotides
class DNAcalculator{

  private:
    string file;

    int lines;
    double sum;

    int squares_sum;

    //stats

    double mean;
    double variance;
    double stdeviation;

    //counters

    int countA;
    int countC;
    int countT;
    int countG;

    int countAA;
    int countAC;
    int countAT;
    int countAG;

    int countCA;
    int countCC;
    int countCT;
    int countCG;

    int countTA;
    int countTC;
    int countTT;
    int countTG;

    int countGA;
    int countGC;
    int countGT;
    int countGG;

    //probability

    double probA;
    double probC;
    double probT;
    double probG;

    double probAA;
    double probAC;
    double probAT;
    double probAG;

    double probCA;
    double probCC;
    double probCT;
    double probCG;

    double probTA;
    double probTC;
    double probTT;
    double probTG;

    double probGA;
    double probGC;
    double probGT;
    double probGG;

  public:
    DNAcalculator(string fileName);
    void calcMean();
    void calcNucleotideProbability();
    void calcBigramProbability();
    void calcVariance();
    void calcStDeviation();
    void processFile();
    void runCalculator();
    char randNucleotide();
    string nucleotideString(int length);
    int gaussianLengthGenerator();
    void outputToFile();
};
