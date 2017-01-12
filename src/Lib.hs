module Lib
    ( someFunc
    ) where

import Criterion.Main.Options
import Criterion.Main
import Quicksort
import MergeSort
import Regression

someFunc :: IO ()
someFunc =  defaultMain [
  bench "quicksort 1000" $ nf quicksort [(1::Int)..1000],
  bench "mergeSort 1000" $ nf mergeSort [(1::Int)..1000],
  bench "Linear Regression 10000 steps" $ nf (regress [(1::Double)..10]) [(11::Double)..20]
  ]
