#ifndef BENCHABLE_HPP
#define BENCHABLE_HPP

class Benchable {
public:
  virtual void beforeEachBench() =0;  //called before every bench
  virtual void afterEachBench() =0;   //called after every bench
  virtual void toBench() =0;          //time of computing this will be meassured
  virtual void setup() =0;            //called once before first bench
  virtual void clear() =0;            //called once after last bench
};

#endif // BENCHABLE_HPP
