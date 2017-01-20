module MergeSort
  ( mergeSort,
    merge
  ) where


--Function takes 2 sorted lists and merges them into one sorted list
merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs --If one of the list is empty function returns the not empty list
merge [] xs = xs
merge (x:xs) (y:ys)
  | (x <= y)      = x : merge xs (y:ys)
  | otherwise     = y : merge (x:xs) ys --the first element is the smaller one


--Głowna funkcja odpowiadajaca za sortowanie Merge
mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort (fsthalf xs)) (mergeSort (sndhalf xs)) where
  --checked multiple functions dividing list in half, but the fastest ones were:
  fsthalf = take (length xs `div` 2)
  sndhalf = drop (length xs `div` 2)
