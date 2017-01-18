module Lib
    ( someFunc
    ) where

import Criterion.Main.Options
import Criterion.Main
import Quicksort
import MergeSort
import Regression

someFunc :: IO ()
someFunc =  do
  contentNumber10k <- readFile "Csrc/data/NumbersToSort10k.txt"
  let numbersToSort  = map readInt . words $ contentNumber10k
  defaultMain [
      bench "quicksort 10000" $ nf quicksort numbersToSort,
      bench "mergeSort 10000" $ nf mergeSort numbersToSort,
      bench "Linear Regression 10000 steps" $ nf (regress [(1::Double)..10]) [(11::Double)..20]
    ]


readInt :: String -> Int
readInt = read
