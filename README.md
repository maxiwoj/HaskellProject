# HaskellProject

----
The project was created to simply compare Haskell and C by benchmarking time and processor consuming operations like sorting, 
linear regression or KMP.

----
### Build and run

Before you try to build the project make sure you have stack tool correctly installed and configured.
```bash
git clone https://github.com/maxiwoj/HaskellProject.git
cd HaskellProject
```
To build the project simply type:
```bash
stack build
```
to run it:
```bash
stack exec projectTimeComparision-exe
```
and to run tests:
```bash
stack test
```

----
### Build and run C/C++ sources
```bash
cd Csrc
mkdir obj
make
```
to run on windows:
```bash
./benchmark.exe
```
----
### Documentation
Please note, that the Documentation is already in ./dist/doc/html/projectTimeComparition. Open index.html to open documentation.

To generate the documentation type:
```bash
cabal install criterion
cabal haddock
```


