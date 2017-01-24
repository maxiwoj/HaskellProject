{-|
Module      : W
Description : Quicksort algorithm
Copyright   : (c) Tomasz Michalec, 2017

Implementation of quicksort algorithm
-}
module Quicksort
  ( quicksort,
    part
  ) where

{-|
As input get list of elements that can be ordered. In output there is list sorted using quicksort alghoritm.
-}
quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = (quicksort (getLt parts)) ++ (x:(getEq parts)) ++ (quicksort (getGt parts))
  where
    parts = part xs x

-- |Get list of greater elements than pivot
getGt :: (a,b,c) -> a
getGt (x,_,_) = x

-- |Get list of equal elements to pivot
getEq :: (a,b,c) -> b
getEq (_,x,_) = x

-- |Get list of smaller elements than pivot
getLt :: (a,b,c) -> c
getLt (_,_,x) = x

-- |Part list into tuple containing list of greater, equal and smaller elements commparing to pivot
part l y = f [] [] [] l
  where
    f gt eq lt (x:xs) =
      if x > y then f (x:gt) eq lt xs
      else if x == y then f gt (x:eq) lt xs
      else f gt eq (x:lt) xs
    f gt eq lt [] = (gt, eq, lt)
