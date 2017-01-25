# HaskellProject

The project was created to simply compare Haskell and C by benchmarking time and processor consuming operations like sorting, 
linear regression or KMP.

###Documentation
To get the documentation type 'cabal install criterion' and then 'cabal haddock'.

###Build and run
To build the project simply type 'stack build', to run it 'stack exec projectTimeComparision-exe' and to run tests: 'stack test'

To build C/C++ sources change directory to Csrc and make directory obj if not exist. Then run 'make' to build sources using makefile. To run type './benchmark.exe'.
