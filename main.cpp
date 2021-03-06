#include <iostream>
#include <queue>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

#include "Event.h"
#include "BankQueue.h"
#include "SupermarketQueue.h"


void showpq(std::priority_queue <Event> gq)
{
  std::priority_queue <Event> g = gq;
  while (!g.empty())
    {
      std::cout << "  " << g.top().timeOfEvent ;
      g.pop();
    }
  std::cout << '\n';
}

void showvector(std::vector<double> gq)
{
  std::vector <double> g = gq;
  for (double num : g)
    {
      std::cout << "  " << num ;
    }
  std::cout << '\n';
}

double percentile(std::vector<double> seq,double percentile)
{
  std::sort(seq.begin(), seq.end());
  double realIndex=percentile * (seq.size()-1);
  int index= (int)realIndex;
  double frac = realIndex-index;
  if(index+1<seq.size())
    return seq.at(index) * (1-frac) + seq.at(index+1) * frac;
  else
    return seq.at(index);
}


int main(int argc, char **argv) {
  assert(argc == 4);
  double customerPerMinute = std::stod(argv[1]); // arrival per minute
  double serviceTime = std::stod(argv[2]); // service time from 0 to serviceTime mins
  int seed = std::stoi(argv[3]);

  srand(seed);
  BankQueue bq = BankQueue(customerPerMinute, serviceTime, seed);
  SupermarketQueue sq = SupermarketQueue(customerPerMinute, serviceTime, seed);
  std::vector<double> bankWaitTimes = bq.run();
  std::vector<double> supermarketWaitTimes = sq.run();

  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << "Bank service times in minutes:" << std::endl;
  std::cout << "10th %tile: "  << percentile(bankWaitTimes, .10)/60 << std::endl;
  std::cout << "50th %tile: " << percentile(bankWaitTimes, .50)/60 << std::endl;
  std::cout << "90th %tile: " << percentile(bankWaitTimes, .90)/60 << std::endl;


  std::cout << "Supermarket service times in minutes:" << std::endl;
  std::cout << "10th %tile: "  << percentile(supermarketWaitTimes, .10)/60 << std::endl;
  std::cout << "50th %tile: " << percentile(supermarketWaitTimes, .50)/60 << std::endl;
  std::cout << "90th %tile: " << percentile(supermarketWaitTimes, .90)/60 << std::endl;

  return 0;
}
