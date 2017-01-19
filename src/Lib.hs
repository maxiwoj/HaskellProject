module Lib
    ( someFunc
    ) where

import Criterion.Main.Options
import Criterion.Main
import Quicksort
import MergeSort
import Regression
import KMP

someFunc :: IO ()
someFunc =  do
  contentNumber10k <- readFile "Csrc/data/NumbersToSort10k.txt"
  let numbersToSort = map readInt . words $ contentNumber10k

  contetKMP <- readFile "Csrc/data/KMP.txt"
  let kmplines = lines contetKMP
  let kmppattern = kmplines !! 0
  let kmpdata = kmplines !! 1

  regressionData <- readFile "Csrc/data/testSetForRegression.txt"
  let regDataXY = makeXY . (map readDouble) . words $ regressionData 

  defaultMain [
      bench "quicksort 10000" $ nf quicksort numbersToSort,
      bench "mergeSort 10000" $ nf mergeSort numbersToSort,
      bench "kmp 1000000" $ nf (findPattern kmppattern) kmpdata,
      bench "Linear Regression 10000 steps" $ nf (regress $ fst regDataXY) $ snd regDataXY
    ]

makeXY :: [Double] -> ([Double], [Double])
makeXY xs = makeXY' xs [] []
  where
    makeXY' [] xs ys = (xs, ys)
    makeXY' (x:y:rest) xs ys = makeXY' rest (xs++[x]) (ys++[y])

readDouble :: String -> Double
readDouble = read

readInt :: String -> Int
readInt = read
