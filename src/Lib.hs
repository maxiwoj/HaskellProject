module Lib
    ( someFunc
    ) where

import Criterion.Main.Options
import Criterion.Main
import Quicksort
import MergeSort

someFunc :: IO ()
someFunc =  defaultMain [
  bench "quicksort 1000" $ nf quicksort [(1::Int)..1000],
  bench "mergeSort 1000" $ nf mergeSort [(1::Int)..1000]
  ]
