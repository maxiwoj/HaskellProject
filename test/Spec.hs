import Test.QuickCheck
import Quicksort
import MergeSort
import Data.List

-- main :: IO ()
main = do
  quickCheck prop_merge
  quickCheck prop_mergeSort
  quickCheck prop_partFromQS

-- prop_merge :: [Int] -> [Int] -> Bool
prop_merge n m = (merge (sort n) (sort m)) == (sort (n ++ m))
  where types = (n :: [Int], m :: [Int])


-- nie wiem, czy tak mogę, bo mergeSort uzywa funkcji merge, skad nie jest to test jednostkowy metody
-- prop_mergeSort :: [Int] -> Bool
prop_mergeSort n = (mergeSort n) == (sort n)
  where types = n :: [Int]

-- przez to ze wrzucasz na poczatek listy w tej funkcji, to trzeba reversowec w testach
prop_partFromQS xs y = (part xs y) == (reverse (filter (> y) xs), reverse (filter (== y) xs), reverse (filter (< y) xs))
  where types = (xs :: [Int], y :: Int)
