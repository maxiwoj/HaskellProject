module MergeSort
  ( mergeSort
  ) where


--Funkcja przyjmujace 2 listy i złaczajaca je sortujac
merge xs [] = xs
merge [] xs = xs
merge (x:xs) (y:ys)
  | (x <= y)      = x : merge xs (y:ys)
  | otherwise     = y : merge (x:xs) ys


--Głowna funkcja odpowiadajaca za sortowanie Merge
mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort (fsthalf xs)) (mergeSort (sndhalf xs)) where
  fsthalf xs = take (length xs `div` 2) xs
  sndhalf xs = drop (length xs `div` 2) xs
