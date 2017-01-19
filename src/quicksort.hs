module Quicksort
  ( quicksort,
    part
  ) where

{-
As input get list of elements that can be ordered. In output there is list sorted using quicksort alghoritm.
-}
quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = (quicksort (getLt parts)) ++ (x:(getEq parts)) ++ (quicksort (getGt parts))
  where
    parts = part xs x

getGt :: (a,b,c) -> a
getGt (x,_,_) = x

getEq :: (a,b,c) -> b
getEq (_,x,_) = x

getLt :: (a,b,c) -> c
getLt (_,_,x) = x

part l y = f [] [] [] l
  where
    f gt eq lt (x:xs) =
      if x > y then f (x:gt) eq lt xs
      else if x == y then f gt (x:eq) lt xs
      else f gt eq (x:lt) xs
    f gt eq lt [] = (gt, eq, lt)
