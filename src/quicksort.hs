module Quicksort
  ( quicksort
  ) where

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = (quicksort less) ++ [x] ++ equals ++ (quicksort more)
  where
    more = [e | e <- xs, e > x]
    less = [e | e <- xs, e < x]
    equals = [e | e <- xs, e == x]
